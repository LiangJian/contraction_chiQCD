#ifndef __GAMMA__
#define __GAMMA__

#include <Eigen/Sparse>
#include <vector>
#include <complex>

#define I_ std::complex<int>(0,1)

namespace contraction{

  typedef Eigen::Triplet<std::complex<double> > Trip;
  typedef Eigen::SparseMatrix<std::complex<double> > sm;

  int gamma_init(std::vector<sm>&g);
  int gamma_init_PS(std::vector<sm>&g);

  class Gammas{
  public:
    std::vector<sm> g;
    std::vector<sm> g_ps;
    Eigen::Matrix<double,4,4> R_c2ps;
    Eigen::Matrix<double,4,4> R_ps2c;

    Gammas(){
	gamma_init(g);
	gamma_init_PS(g_ps);
	R_c2ps<<0,1,0,-1, -1,0,1,0, 0,-1,0,-1, 1,0,1,0;
	R_c2ps/=sqrt(2.0);
	R_ps2c = -R_c2ps;
    }
  };
}

#endif
