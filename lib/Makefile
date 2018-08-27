all:	libcontraction.a

libcontraction.a:	gamma.o
	ar cr libcontraction.a  gamma.o

include ../make.inc
CXX += $(INCL) -c

gamma.o: gamma.cpp $(HEADS)
	$(CXX) gamma.cpp

clean:
	rm -rf *.o *.a
