A contraction code, based on Eigen, boost and c++11.

In the tests dir:

gamma.cpp is a test file to address the gamma definitions. We have chiral basis and PS basis. 
The overlap propagators are under the PS basis. But it would be more efficient to use chiral basis.
The converting matrix is also tested.
main.cpp is a general test file for input, operations and output.

In the lib/includes dir:

handle_input.h contains wrap of the boost routines for handling inputs.
lattice_type.h(.cpp) are files that define something like color matrix or propagators.
layout.h(.cpp) are files aiming to define the mpi layout.
gamma.h(cpp) are files related to gammas.

some guidelines
1) Use more modern c++ featurs (c++11,14).
2) Other than the definitions of the types in the lattice_type.h(.cpp), backend library (like Eigen) should not appear. This guarantees the possibility of changing backend library in the future.
3) ...

