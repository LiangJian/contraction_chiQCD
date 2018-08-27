#ifndef __GAMMA__
#define __GAMMA__

#include <Eigen/Sparse>
#include <vector>
#include <complex>

#define I_ std::complex<int>(0,1)


namespace contraction{
  typedef Eigen::Triplet<std::complex<int> > Trip;
  //std::vector<Trip> tripletList; 
  typedef Eigen::SparseMatrix<std::complex<int> > sm;
  //std::vector<sm> g;
  int gamma_init(std::vector<sm>&g);
}

#endif
