#ifndef GUITAR_REPOSITORY_H
#define GUITAR_REPOSITORY_H

#include "errorCode.h"
#include "Guitar.h"
#include <string>
#include <vector>


namespace mvc {

  class GuitarRepository {
  public:
    GuitarRepository() = default;
    ~GuitarRepository() = default;
    /* Model interface to make queries */
    MvcRetval getGuitarsForBrand(std::vector<Guitar>& guitarOut, const std::string& brand);
    MvcRetval getGuitarsForModel(std::vector<Guitar>& guitarOut, const std::string& model);
    /* functions to extend datebase */
    MvcRetval registerNewGuitar(const std::string brand,
				const std::string model,
				const int nStrings,
				const std::vector<int> stringGauge,
				const std::string topWood,
				const std::string bodyWood,
				const std::string neckWood,
				const std::string neckJointType,
				const std::string bridgeType);

  private:
    std::vector<Guitar> guitarRows;
  };
}

#endif /* GUITAR_REPOSITORY_H */
