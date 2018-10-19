CXX = CC 
CXXFLAGS = -O3 -w -std=c++14
INCL=-I/scratch3/scratchdirs/jliang/test_contraction/Armadillo_Eigen/eigen-eigen-b3f3d4950030 -I/opt/local/include -I/usr/common/software/boost/1.63/intel/sandybridge/include 
LIB=-L/opt/local/lib ../lib/libcontraction.a -mkl -mkl=parallel -L/usr/common/software/boost/1.63/intel/sandybridge/lib -lboost_program_options -lboost_mpi 
