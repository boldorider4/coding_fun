#include "errorCode.h"
#include "Observer.h"
#include "Producer.h"
#include <iostream>


int main() {

  OccRetval retval, retval2;
  Producer producer("First producer");
  Producer producerTwo("Second producer");

  retval = producer.Start();
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  retval2 = producerTwo.Start();

  if (retval == OccRetval::thread_error) {
    std::cout << "First producer - thread not started" << std::endl;
  } else {
    std::cout << "First producer - thread started" << std::endl;
  }

  if (retval2 == OccRetval::thread_error) {
    std::cout << "Second producer - thread not started" << std::endl;
  } else {
    std::cout << "Second producer - thread started" << std::endl;
  }

  std::this_thread::sleep_for(std::chrono::milliseconds(4100));

  retval = producer.Stop();

  if (retval == OccRetval::thread_error) {
    std::cout << "First producer - thread not stopped" << std::endl;
  } else {
    std::cout << "First producer - thread stopped" << std::endl;
  }

  retval2 = producerTwo.Stop();

  if (retval2 == OccRetval::thread_error) {
    std::cout << "Second producer - thread not stopped" << std::endl;
  } else {
    std::cout << "Second producer - thread stopped" << std::endl;
  }

  retval2 = producerTwo.Stop();

  if (retval2 == OccRetval::thread_error) {
    std::cout << "Second producer - thread not stopped" << std::endl;
  } else {
    std::cout << "Second producer - thread stopped" << std::endl;
  }

  return 0;
}
