compile:
	rm -rf build
	mkdir build
	cmake -S . -B build
	cmake --build build
run :
	./build/app/main

