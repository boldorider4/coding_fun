#include "SuperInt.h"


bool SuperInt::operator<(SuperInt& arg) {
  return true;
}


bool SuperInt::operator>(SuperInt& arg) {
  return true;
}


bool SuperInt::operator==(SuperInt& arg) {
  return true;
}


bool SuperInt::operator<=(SuperInt& arg) {
  return true;
}


bool SuperInt::operator>=(SuperInt& arg) {
  return true;
}


std::ostream& operator<<(std::ostream& os, SuperInt& arg) {
  for (auto intVal : arg.value) {
    os << intVal;
  }

  return os;
}
