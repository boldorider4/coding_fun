#include <iostream>
#include <string>
#include <memory>


class Obj {
public:
  Obj(std::string name) : objectName(name) {}
  ~Obj() {
    std::cout << "Obj " << objectName << " was destroyed" << std::endl;
  }
private:
  std::string objectName;
};

  
std::unique_ptr<Obj> testNoMove(std::string name) {
  std::unique_ptr<Obj> upObj = std::make_unique<Obj>(name);

  return upObj;
}

  
std::unique_ptr<Obj> testMove(std::string name) {
  std::unique_ptr<Obj> upObj = std::make_unique<Obj>(name);

  return std::move(upObj);
}


int main() {

  std::unique_ptr<Obj> retval1 = testNoMove("testNoMoveObj");
  std::unique_ptr<Obj> retval2 = testMove("testMoveObj");

  std::cout << "items not yet destroyed";

  return 0;
}
