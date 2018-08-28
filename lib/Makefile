all:	libcontraction.a

libcontraction.a:	gamma.o layout.o
	ar cr libcontraction.a  gamma.o layout.o

include ../make.inc
CXX += $(INCL) -c

gamma.o: gamma.cpp $(HEADS)
	$(CXX) gamma.cpp

alyout.o: layout.cpp $(HEADS)
	$(CXX) layout.cpp

clean:
	rm -rf *.o *.a
