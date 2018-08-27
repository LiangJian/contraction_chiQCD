all:    lib tests 

lib:	lib/*.cpp lib/libcontraction.a
	
lib/libcontraction.a:
	@echo "making lib..."; make -C lib all

tests:	lib tests/*.cpp includes/*.h tests/main

tests/main: tests/main.cpp includes/*.h
	@echo "making tests..."; make -C tests main

clean:	
	@echo "making clean tests..."; make -C tests clean; make -C lib clean
