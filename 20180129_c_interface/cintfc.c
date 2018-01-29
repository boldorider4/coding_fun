#include "extern_impl.h"
#include <stdio.h>


struct public_data {
  int data;
};

typedef void (*fcn_pointer_t)(int* data_out);

struct interface {
  fcn_pointer_t access_data;
};

typedef struct public_data public_data_t;
typedef struct interface interface_t;

void set_interface_methods(interface_t* intfc, fcn_pointer_t method) {
  intfc->access_data = method;
}


int main() {

  interface_t intfc = {0};
  int accessed_data = 0;

  set_interface_methods(&intfc, &extern_access_data);
  intfc.access_data(&accessed_data);

  printf("The accessed data is 0x%x\n", accessed_data);

  return 0;
}
