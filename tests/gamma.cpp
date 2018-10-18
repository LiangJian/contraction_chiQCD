#include "../includes/gamma.h"
#include <iostream>
using namespace contraction;

int main(int ac , char *av[])
{

  Gammas ga;

  //std::cout<<ga.g[1]<<std::endl; 
  //std::cout<<ga.g[2]<<std::endl; 
  //std::cout<<ga.g[3]<<std::endl; 
  //std::cout<<ga.g[4]<<std::endl; 
  //std::cout<<ga.g[5]<<std::endl;

  //std::cout<<ga.g[1]*ga.g[1]<<std::endl; 
  //std::cout<<ga.g[2]*ga.g[2]<<std::endl; 
  //std::cout<<ga.g[3]*ga.g[3]<<std::endl; 
  //std::cout<<ga.g[4]*ga.g[4]<<std::endl; 
  //std::cout<<ga.g[5]*ga.g[5]<<std::endl;

  std::cout<<ga.g[1]*ga.g[2]*ga.g[3]*ga.g[4] - ga.g[5]<<std::endl; 
  std::cout<<ga.g_ps[1]*ga.g_ps[2]*ga.g_ps[3]*ga.g_ps[4] - ga.g_ps[5]<<std::endl;

  std::cout<<ga.R_ps2c.adjoint()*ga.g_ps[1]*ga.R_ps2c + ga.g[1]<<std::endl;
  std::cout<<ga.R_ps2c.adjoint()*ga.g_ps[2]*ga.R_ps2c + ga.g[2]<<std::endl;
  std::cout<<ga.R_ps2c.adjoint()*ga.g_ps[3]*ga.R_ps2c + ga.g[3]<<std::endl;
  std::cout<<ga.R_ps2c.adjoint()*ga.g_ps[4]*ga.R_ps2c + ga.g[4]<<std::endl;
  std::cout<<ga.R_ps2c.adjoint()*ga.g_ps[5]*ga.R_ps2c + ga.g[5]<<std::endl;
  
  return 0;
}
