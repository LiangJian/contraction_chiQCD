#include "../includes/handle_input.h"
#include "../includes/lattice_type.h"
#include "../includes/layout.h"
#include <boost/program_options.hpp>
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

namespace mpi = boost::mpi;
using namespace contraction;

int main(int ac , char *av[])
{

  mpi::environment env;
  mpi::communicator world;
  std::cout << "MPI with " << world.size()
            << " core(s)." << std::endl;
 
  handle_inputs hi("input");
  hi.add("nx", 0);
  hi.add("ny", 0);
  hi.add("nz", 0);
  hi.add("nt", 0);
  hi.read();
  hi.list();

  //Layout layout(hi.pw["nx"].as<int>(),hi.pw["ny"].as<int>(),hi.pw["nz"].as<int>(),hi.pw["nt"].as<int>(),trivial,world);

  Color_vector<double> cv1;
  cv1 << 1, 2, 3;
  std::cout<<cv1<<std::endl;
  
  Color_matrix<double> cm1;
  auto cv2 = cm1 * cv1;
  
  return 0;
}
