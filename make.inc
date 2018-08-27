CXX = mpicxx-openmpi-mp
CXXFLAGS = -O3 -std=c++11 
INCL=-I/Users/lj/packages/eigen -I/opt/local/include 
LIB=-L/opt/local/lib -lboost_program_options-mt -lboost_mpi-mt ../lib/libcontraction.a
