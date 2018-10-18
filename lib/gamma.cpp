#include "../includes/gamma.h"

namespace contraction{

  int gamma_init(std::vector<sm>&g){
      std::vector<Trip> tripletList;
      Eigen::SparseMatrix<std::complex<double> > mat(4,4);

      //gamma 0 (unit)
      tripletList.push_back(Trip(0,0,1));
      tripletList.push_back(Trip(1,1,1));
      tripletList.push_back(Trip(2,2,1));
      tripletList.push_back(Trip(3,3,1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(0) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 1
      tripletList.push_back(Trip(0,3,std::complex<double>(0,1)));
      tripletList.push_back(Trip(1,2,std::complex<double>(0,1)));
      tripletList.push_back(Trip(2,1,std::complex<double>(0,-1)));
      tripletList.push_back(Trip(3,0,std::complex<double>(0,-1)));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(1) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 2
      tripletList.push_back(Trip(0,3,-1));
      tripletList.push_back(Trip(1,2,1));
      tripletList.push_back(Trip(2,1,1));
      tripletList.push_back(Trip(3,0,-1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(2) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 3
      tripletList.push_back(Trip(0,2,std::complex<double>(0,1)));
      tripletList.push_back(Trip(1,3,std::complex<double>(0,-1)));
      tripletList.push_back(Trip(2,0,std::complex<double>(0,-1)));
      tripletList.push_back(Trip(3,1,std::complex<double>(0,1)));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(3) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 4
      tripletList.push_back(Trip(0,2,1));
      tripletList.push_back(Trip(1,3,1));
      tripletList.push_back(Trip(2,0,1));
      tripletList.push_back(Trip(3,1,1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(4) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 5
      tripletList.push_back(Trip(0,0,1));
      tripletList.push_back(Trip(1,1,1));
      tripletList.push_back(Trip(2,2,-1));
      tripletList.push_back(Trip(3,3,-1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(4) = (mat);
      g.push_back(mat);
      tripletList.clear();

      return 0;
  }

  int gamma_init_PS(std::vector<sm>&g){
      std::vector<Trip> tripletList;
      Eigen::SparseMatrix<std::complex<double> > mat(4,4);

      //gamma 0 (unit)
      tripletList.push_back(Trip(0,0,1));
      tripletList.push_back(Trip(1,1,1));
      tripletList.push_back(Trip(2,2,1));
      tripletList.push_back(Trip(3,3,1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(0) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 1
      tripletList.push_back(Trip(0,3,std::complex<double>(0,-1)));
      tripletList.push_back(Trip(1,2,std::complex<double>(0,-1)));
      tripletList.push_back(Trip(2,1,std::complex<double>(0,1)));
      tripletList.push_back(Trip(3,0,std::complex<double>(0,1)));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(1) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 2
      tripletList.push_back(Trip(0,3,-1));
      tripletList.push_back(Trip(1,2,1));
      tripletList.push_back(Trip(2,1,1));
      tripletList.push_back(Trip(3,0,-1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(2) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 3
      tripletList.push_back(Trip(0,2,std::complex<double>(0,-1)));
      tripletList.push_back(Trip(1,3,std::complex<double>(0,1)));
      tripletList.push_back(Trip(2,0,std::complex<double>(0,1)));
      tripletList.push_back(Trip(3,1,std::complex<double>(0,-1)));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(3) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 4
      tripletList.push_back(Trip(0,0,1));
      tripletList.push_back(Trip(1,1,1));
      tripletList.push_back(Trip(2,2,-1));
      tripletList.push_back(Trip(3,3,-1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(4) = (mat);
      g.push_back(mat);
      tripletList.clear();

      //gamma 5
      tripletList.push_back(Trip(0,2,-1));
      tripletList.push_back(Trip(1,3,-1));
      tripletList.push_back(Trip(2,0,-1));
      tripletList.push_back(Trip(3,1,-1));
      mat.setFromTriplets(tripletList.begin(), tripletList.end());
      //g.at(4) = (mat);
      g.push_back(mat);
      tripletList.clear();

      return 0;
  }
}
