#ifndef GUITAR_H
#define GUITAR_H

#include <string>
#include <vector>


namespace mvc {

  struct Guitar {
    Guitar() = default;
    std::string brand;
    std::string model;
    int nStrings;
    std::vector<int> stringGauge;
    std::string topWood;
    std::string bodyWood;
    std::string neckWood;
    std::string neckJointType;
    std::string bridgeType;
  };
}

#endif /* GUITAR_H */
