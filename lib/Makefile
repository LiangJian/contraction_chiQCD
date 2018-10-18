all:	libcontraction.a

libcontraction.a:	gamma.o layout.o lattice_type.o
	ar cr libcontraction.a  gamma.o layout.o lattice_type.o

include ../make.inc
CXX += $(INCL) -c

gamma.o: gamma.cpp $(HEADS)
	$(CXX) $(CXXFLAGS) gamma.cpp

alyout.o: layout.cpp $(HEADS)
	$(CXX) $(CXXFLAGS)  layout.cpp

lattice_type.o: lattice_type.cpp $(HEADS)
	$(CXX) $(CXXFLAGS)  lattice_type.cpp

clean:
	rm -rf *.o *.a
