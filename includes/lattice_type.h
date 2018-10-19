/*
   lattice_type.h
   Aug 2018
*/

#ifndef __LATTICE_TYPE__
#define __LATTICE_TYPE__

#include <Eigen/Dense>
#include "layout.h"
#include <memory>

namespace mpi = boost::mpi;

namespace contraction{

  enum io_type{
      KY,
      HERE
  };

  template<typename T>
  class Color_vector:public Eigen::Matrix< std::complex<T>, 3, 1>{
  public:
      Color_vector(void):Eigen::Matrix< std::complex<T>, 3, 1>(){}
      template<typename OtherDerived>
      Color_vector(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 3, 1>(other)
      { }
      template<typename OtherDerived>
      Color_vector& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 3, 1>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Spin_vector:public Eigen::Matrix< std::complex<T>, 4, 1>{
  public:
      Spin_vector(void):Eigen::Matrix< std::complex<T>, 4, 1>(){}
      template<typename OtherDerived>
      Spin_vector(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 4, 1>(other)
      { }
      template<typename OtherDerived>
      Spin_vector& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 4, 1>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Color_matrix:public Eigen::Matrix< std::complex<T>, 3, 3>{
  public:
      Color_matrix(void):Eigen::Matrix< std::complex<T>, 3, 3>(){}
      template<typename OtherDerived>
      Color_matrix(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 3, 3>(other)
      { }
      template<typename OtherDerived>
      Color_matrix& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 3, 3>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Spin_matrix:public Eigen::Matrix< std::complex<T>, 4, 4>{
  public:
      Spin_matrix(void):Eigen::Matrix< std::complex<T>, 4, 4>(){}
      template<typename OtherDerived>
      Spin_matrix(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 4, 4>(other)
      { }
      template<typename OtherDerived>
      Spin_matrix& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 4, 4>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Color_spin_vector:public Eigen::Matrix< std::complex<T>, 12, 1>{
  public:
      Color_spin_vector(void):Eigen::Matrix< std::complex<T>, 12, 1>(){}
      template<typename OtherDerived>
      Color_spin_vector(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 12, 1>(other)
      { }
      template<typename OtherDerived>
      Color_spin_vector& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 12, 1>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Color_spin_matrix:public Eigen::Matrix< std::complex<T>, 12, 12>{
  public:
      Color_spin_matrix(void):Eigen::Matrix< std::complex<T>, 12, 12>(){}
      template<typename OtherDerived>
      Color_spin_matrix(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 12, 12>(other)
      { }
      template<typename OtherDerived>
      Color_spin_matrix& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 12, 12>::operator=(other);
	  return *this;
      }
  };
  
  template<typename T>
  class Spin_color_vector:public Eigen::Matrix< std::complex<T>, 12, 1>{
  public:
      Spin_color_vector(void):Eigen::Matrix< std::complex<T>, 12, 1>(){}
      template<typename OtherDerived>
      Spin_color_vector(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 12, 1>(other)
      { }
      template<typename OtherDerived>
      Spin_color_vector& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 12, 1>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Spin_color_matrix:public Eigen::Matrix< std::complex<T>, 12, 12>{
  public:
      Spin_color_matrix(void):Eigen::Matrix< std::complex<T>, 12, 12>(){}
      template<typename OtherDerived>
      Spin_color_matrix(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, 12, 12>(other)
      { }
      template<typename OtherDerived>
      Spin_color_matrix& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, 12, 12>::operator=(other);
	  return *this;
      }
  };
  
  template<typename T>
  class Vector:public Eigen::Matrix< std::complex<T>,  Eigen::Dynamic, 1>{
  public:
      Vector(void):Eigen::Matrix< std::complex<T>, Eigen::Dynamic, 1>(){}
      template<typename OtherDerived>
      Vector(const Eigen::MatrixBase<OtherDerived>& other)
	: Eigen::Matrix< std::complex<T>, Eigen::Dynamic, 1>(other)
      { }
      template<typename OtherDerived>
      Vector& operator=(const Eigen::MatrixBase <OtherDerived>& other)
      {
	  this->Eigen::Matrix< std::complex<T>, Eigen::Dynamic, 1>::operator=(other);
	  return *this;
      }
  };

  template<typename T>
  class Lattice_vector{
  public:
    std::unique_ptr<Vector<T>[]> vectors;
    Lattice_vector(Layout * layout){
	vectors =  std::unique_ptr<Vector<T>[]>(new Vector<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_color_vector{
  public:
    std::unique_ptr<Color_vector<T>[]> color_vectors;
    Lattice_color_vector(Layout * layout){
	color_vectors =  std::unique_ptr<Color_vector<T>[]>(new Color_vector<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_spin_vector{
  public:
    std::unique_ptr<Spin_vector<T>[]> spin_vectors;
    Lattice_spin_vector(Layout * layout){
	spin_vectors =  std::unique_ptr<Spin_vector<T>[]>(new Spin_vector<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_color_spin_vector{
  public:
    std::unique_ptr<Color_spin_vector<T>[]> color_spin_vectors;
    Lattice_color_spin_vector(Layout * layout){
	color_spin_vectors =  std::unique_ptr<Color_spin_vector<T>[]>(new Color_spin_vector<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_spin_color_vector{
  public:
    std::unique_ptr<Spin_color_vector<T>[]> spin_color_vectors;
    Lattice_spin_color_vector(Layout * layout){
	spin_color_vectors = std::unique_ptr<Spin_color_vector<T>[]>(new Spin_color_vector<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_color_matrix{
  public:
    std::unique_ptr<Color_matrix<T>[]> color_matrixs;
    Lattice_color_matrix(Layout * layout){
	color_matrixs = std::unique_ptr<Color_matrix<T>[]>(new Color_matrix<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_spin_matrix{
  public:
    std::unique_ptr<Spin_matrix<T>[]> spin_matrixs;
    Lattice_spin_matrix(Layout * layout){
	spin_matrixs = std::unique_ptr<Spin_matrix<T>[]>(new Spin_matrix<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  class Lattice_color_spin_matrix{
  public:
    std::string filename;
    Layout *layout;
    std::unique_ptr<Color_spin_matrix<T>[]> color_spin_matrixs;
    Lattice_color_spin_matrix(Layout * layout_, std::string filename_):layout(layout_){
	color_spin_matrixs = std::unique_ptr<Color_spin_matrix<T>[]>(new Color_spin_matrix<T>[layout->size_on_site]); //c++11
	//color_spin_matrixs = std::make_unique(new Color_spin_matrix<T>[layout->size_on_site]); //c++14
	filename = filename_;
    }
    void load(std::string filename_);
    void mock();
  };

  template<typename T>
  void load_prop(Lattice_color_spin_matrix<T>* prop, std::string filename="", int ionum=1, io_type type=KY, bool mock=true){
      // KY format of prop: 4(src) 3(src) R/I 4(snk) 3(snk) V(t z y x) 
      if(mock){
	for(int i=0;i<prop->layout->size_on_site;i++)
	  (prop->color_spin_matrixs[i]) =  Eigen::MatrixXcd::Random(12,12);
	  //std::cout<<prop->color_spin_matrixs[i]<<std::endl;
      }else{
	if(prop->layout->world.rank() == 0) std::cout<<"TODO!"<<std::endl;
	exit(1);
      }
  }

  template<typename T>
  class Lattice_spin_color_matrix{
  public:
    std::unique_ptr<Spin_color_matrix<T>[]> spin_color_matrixs;
    Lattice_spin_color_matrix(Layout * layout){
	spin_color_matrixs = std::unique_ptr<Spin_color_matrix<T>[]>(new Spin_color_matrix<T>[layout->size_on_site]);
    }
  };

  template<typename T>
  void Lattice_color_spin_matrix<T>::load(std::string filename_){
      if(filename != "" && filename == filename_){
          load_prop(this, filename);
      }else if(filename_ != ""){
          load_prop(this, filename_);
      }else{
          if(layout->world.rank() == 0) std::cout<<"wrong file name."<<std::endl;
          exit(1);
      }
  }

  template<typename T>
  void Lattice_color_spin_matrix<T>::mock(){
      load_prop(this, "", 1,KY,true);
  }

  typedef Lattice_color_spin_matrix<double> prop_d;
  typedef Lattice_color_spin_matrix<float> prop_f;
}

#endif
