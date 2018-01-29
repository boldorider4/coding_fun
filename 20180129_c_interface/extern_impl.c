#include "extern_impl.h"


static int private_data = 0xdeadbeef;


void extern_access_data(int* data_out) {
  *data_out = private_data;
}
