hello.html: hello.c shell_minimal.html
	emcc -o hello.html hello.c --shell-file shell_minimal.html -s NO_EXIT_RUNTIME=1 -sEXPORTED_RUNTIME_METHODS=ccall,cwrap -s EXPORTED_FUNCTIONS=_main,_c_fibonacci #--js-library library.js

.PHONY: clean
clean:
	rm hello.html
	rm hello.wasm
	rm hello.js
