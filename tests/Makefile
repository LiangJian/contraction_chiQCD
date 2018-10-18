include ../make.inc

CXX += $(INCL) 

HEADS = ../includes/gamma.h\
	../includes/handle_input.h\
	../includes/lattice_type.h\
	../includes/layout.h

exe = main gamma

all: $(exe)

main: main.cpp $(HEADS) ../lib/libcontraction.a
	$(CXX) $(CXXFLAGS) main.cpp -o main $(LIB)

gamma: gamma.cpp $(HEADS) ../lib/libcontraction.a
	$(CXX) $(CXXFLAGS) gamma.cpp -o gamma $(LIB)

../lib/libcontraction.a:
	make -C ../lib all

clean:
	rm -rf *.o $(exe)
