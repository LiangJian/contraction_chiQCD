#include "../includes/layout.h"

namespace contraction{
  Position Layout::get_site_position(int rank, int local_offset){
      int g_offset = get_site_global_offset(rank, local_offset);
      int x = g_offset%this->nx;
      int y = g_offset/this->nx%this->ny;
      int z = g_offset/this->nx/this->ny%this->nz;
      int t = g_offset/this->nx/this->ny/this->nz;
      return Position(this, x,y,z,t);
  }
}
