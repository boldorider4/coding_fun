#include <iostream>

typedef struct
{
  int int_field;
  int* int_pointer;
} FooStruct;

int main()
{
  FooStruct this_foostruct;

  this_foostruct.int_field = 0xdeadbeef;
  this_foostruct.int_pointer = new int();
  int * safe_delete = this_foostruct.int_pointer;

  std::cout << "BEFORE" << std::endl;
  std::cout << "this_foostruct.int_field = " << this_foostruct.int_field << std::endl;
  std::cout << "this_foostruct.int_pointer = " << std::hex << this_foostruct.int_pointer << std::endl;

  this_foostruct = {0};
  delete safe_delete;

  std::cout << "AFTER" << std::endl;
  std::cout << "this_foostruct.int_field = " << this_foostruct.int_field << std::endl;
  std::cout << "this_foostruct.int_pointer = " << std::hex << this_foostruct.int_pointer << std::endl;

  return 0;
}
