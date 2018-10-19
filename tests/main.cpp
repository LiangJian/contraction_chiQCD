#include "../includes/handle_input.h"
#include "../includes/lattice_type.h"
#include "../includes/layout.h"
#include "../includes/print.h"
#include <boost/program_options.hpp>
#include <boost/mpi/environment.hpp>
#include <boost/mpi/communicator.hpp>

namespace mpi = boost::mpi;
using namespace contraction;

int main(int ac , char *av[])
{

  mpi::environment env;
  mpi::communicator world;
  COUT << "MPI with " << world.size()
            << " core(s)." << std::endl;
 
  handle_inputs hi("input");
  hi.add("nx", 0);
  hi.add("ny", 0);
  hi.add("nz", 0);
  hi.add("nt", 0);
  hi.read();
  if(world.rank()==0) hi.list();

  Layout layout(hi.pw["nx"].as<int>(),hi.pw["ny"].as<int>(),hi.pw["nz"].as<int>(),hi.pw["nt"].as<int>(),trivial,world);

  Lattice_color_spin_matrix<double> p1(&layout, "");
  p1.mock();
  prop_d p2(&layout, "");
  p2.mock();

  return 0;
}
