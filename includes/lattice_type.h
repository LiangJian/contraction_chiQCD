/*
   lattice_type.h
   Aug 2018
*/

#ifndef __LATTICE_TYPE__
#define __LATTICE_TYPE__

#include <Eigen/Dense>
#include "layout.h"

namespace mpi = boost::mpi;

namespace contraction{

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
    std::unique_ptr<Vector<T>> vectors;
    Lattice_vector(Layout layout){
	vectors = new Vector<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_color_vector{
  public:
    std::unique_ptr<Color_vector<T>> color_vectors;
    Lattice_color_vector(Layout layout){
	color_vectors = new Color_vector<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_spin_vector{
  public:
    std::unique_ptr<Spin_vector<T>> spin_vectors;
    Lattice_spin_vector(Layout layout){
	spin_vectors = new Spin_vector<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_color_spin_vector{
  public:
    std::unique_ptr<Color_spin_vector<T>> color_spin_vectors;
    Lattice_color_spin_vector(Layout layout){
	color_spin_vectors = new Color_spin_vector<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_spin_color_vector{
  public:
    std::unique_ptr<Spin_color_vector<T>> spin_color_vectors;
    Lattice_spin_color_vector(Layout layout){
	spin_color_vectors = new Spin_color_vector<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_color_matrix{
  public:
    std::unique_ptr<Color_matrix<T>> color_matrixs;
    Lattice_color_matrix(Layout layout){
	color_matrixs = new Color_matrix<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_spin_matrix{
  public:
    std::unique_ptr<Spin_matrix<T>> spin_matrixs;
    Lattice_spin_matrix(Layout layout){
	spin_matrixs = new Spin_matrix<T>(layout.size_on_site);
    }
  };

  template<typename T>
  class Lattice_color_spin_matrix;

  template<typename T>
  void load_prop(Lattice_color_spin_matrix<T>* prop, std::string filename);

  template<typename T>
  class Lattice_spin_color_matrix{
  public:
    std::unique_ptr<Spin_color_matrix<T>> spin_color_matrixs;
    Lattice_spin_color_matrix(Layout layout){
	spin_color_matrixs = new Spin_color_matrix<T>(layout.size_on_site);
    }
  };

  typedef Lattice_color_spin_matrix<double> prop_d;
  typedef Lattice_color_spin_matrix<float> prop_f;
}

#endif
