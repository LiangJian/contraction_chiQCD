/*
   lattice_type.h
   Aug 2018
*/

#include <Eigen/Dense>
#include "../includes/lattice_type.h"

namespace mpi = boost::mpi;

namespace contraction{

  enum io_type{
      KY,
      HERE
  };

  template<typename T>
  void load_prop(Lattice_color_spin_matrix<T>* prop, std::string filename, io_type type, int ionum){
      // KY format of prop: 4(src) 3(src) R/I 4(snk) 3(snk) V(t z y x) 
      int a =0;
  }

  template<typename T>
  class Lattice_color_spin_matrix{
  public:
    std::string filename;
    std::unique_ptr<Color_spin_matrix<T>> color_spin_matrixs;
    Lattice_color_spin_matrix(Layout layout, std::string filename_){
	color_spin_matrixs = new Color_spin_matrix<T>(layout.size_on_site);
	filename = filename_;
    }
    void load(std::string filename_){
	if(filename != "" && filename == filename_){
	    load_prop(*this, filename);
	}else if(filename == ""){
	    load_prop(*this, filename_);
	}else{
	    exit(1);
	}
    }
  };
}
