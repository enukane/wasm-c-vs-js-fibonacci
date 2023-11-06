#include <stdio.h>
#include <emscripten/emscripten.h>

int main() {
    printf("Hello World\n");
    return 0;
}

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN int js_fibonacci(int);

EXTERN EMSCRIPTEN_KEEPALIVE void myFunction(int argc) {
	    printf("MyFunction-Called %d\n", argc);
	    printf("hogehoge\n");
}

//EXTERN EMSCRIPTEN_KEEPALIVE int c_fibonacci(int num)
EXTERN int c_fibonacci(int num)
{
	printf("%d\n", num);
	if (num == 0) {
		return 0;
	} else if (num == 1) {
		return 1;
	} else {
		//return c_fibonacci(num - 1) + c_fibonacci(num - 2);
		int a = EM_ASM_INT({
				return js_fibonacci($0 - 1)
				}, num);
		int b = EM_ASM_INT({
				return js_fibonacci($0 - 2)
				}, num);
		return a + b;
		//return js_fibonacci(num - 1) + js_fibonacci(num - 2);
	}
}
