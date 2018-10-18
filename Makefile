all:    lib tests 

lib:	lib/libcontraction.a
	
lib/libcontraction.a: lib/*.cpp includes/*.h
	@echo "making lib..."; make -C lib all

tests:	tests/*.cpp includes/*.h tests/main tests/gamma

tests/main: lib/libcontraction.a tests/main.cpp includes/*.h lib/*.cpp
	@echo "making tests/main..."; make -C tests main

tests/gamma: lib/libcontraction.a tests/gamma.cpp includes/*.h lib/*.cpp
	@echo "making tests/gamma..."; make -C tests gamma
clean:	
	@echo "making clean tests..."; make -C tests clean; make -C lib clean
