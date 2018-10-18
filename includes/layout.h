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

    class Position;

    class Layout{
    public:
      int Vs;
      int V;
      int size_on_site;
      Layout_type layout_type;
      int nx;
      int ny;
      int nz;
      int nt;

      Layout(int nx_, int ny_, int nz_, int nt_, Layout_type layout_type_, mpi::communicator world){
	  layout_type = layout_type_;
	  nx = nx_;
	  ny = ny_;
	  nz = nz_;
	  nt = nt_;
	  Vs = nx * ny * nz;
	  V = Vs * nt;
	  size_on_site = V / world.size();
	  if(size_on_site * world.size() != V){
	      std::cout<<"wrong MPI size for layout"<<std::endl;
	      exit(1);
	  }
      }
      /*************************************
       * order of the space-time: t z y x !
       * ***********************************/

      int get_site_global_offset(int it, int iz, int iy, int ix){
	  if(layout_type==trivial){
	      return ((it * nz + iz) * ny + iy) * nx + ix;
	  }else if(layout_type==checkerboard){
	      return (((it * nz + iz) * ny + iy) * nx + ix)/2 + (ix + iy + iz + it)%2 * V / 2;
	  }else{
	      return -1;
	  }
	  return -1;
      }

      int get_site_rank(int it, int iz, int iy, int ix){
	  int tmp = get_site_global_offset(it, iz, iy, ix);
	  if(tmp != -1){
	      return tmp % size_on_site;
	  }
	  return -1;
      }

      int get_site_local_offset(int it, int iz, int iy, int ix){
	  int tmp = get_site_global_offset(it, iz, iy, ix);
	  if(tmp != -1){
	      return tmp / size_on_site;
	  }
	  return -1;
      }

      int get_site_global_offset(int rank, int local_offset){
	  return rank * size_on_site + local_offset;
      }

      Position get_site_position(int rank, int local_offset);
      
    };

    class Position{
    public:
	int x=0;
	int y=0;
	int z=0;
	int t=0;
	Layout* layout;
	Position(class Layout* layout_){layout = layout_;}
	int get_site_rank(){
	    return layout->get_site_rank(t,z,y,x);
	}
	int get_site_local_offset(){
	    return layout->get_site_local_offset(t,z,y,x);
	}
	int get_site_global_offset(){
	    return layout->get_site_global_offset(t,z,y,x);
	}
    };

}
#endif
