/*
   lattice_type.h
   Aug 2018
*/

#ifndef __LAYOUT__
#define __LAYOUT__

#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

namespace mpi = boost::mpi;
namespace contraction{

    enum Layout_type{
	trivial,
	checkerboard
    };

    class Layout{
    public:
      int Vs = 0;
      int V = 0;
      int size_on_site = 0;
      Layout(int nx, int ny, int nz, int nt, Layout_type layout_type, mpi::communicator world){
	  Vs = nx * ny * nz;
	  V = Vs * nt;
	  size_on_site = V / world.size();
	  if(size_on_site * world.size() != V){
	      std::cout<<"wrong MPI size for layout"<<std::endl;
	      exit(1);
	  }
	  if(layout_type == trivial){
	  }
      };
    };
}
#endif
