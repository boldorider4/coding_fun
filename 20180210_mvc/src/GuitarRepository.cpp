#include "GuitarRepository.h"


namespace mvc {

  MvcRetval GuitarRepository::getGuitarsForBrand(std::vector<Guitar>& guitarOut, const std::string& brand) {

    for (const auto &guitarRow : guitarRows) {
      if (guitarRow.brand == brand) {
	guitarOut.push_back(guitarRow);
      }
    }
    
    return MvcRetval::no_error;
  }


  MvcRetval GuitarRepository::getGuitarsForModel(std::vector<Guitar>& guitarOut, const std::string& model) {

    for (const auto &guitarRow : guitarRows) {
      if (guitarRow.model == model) {
	guitarOut.push_back(guitarRow);
      }
    }

    return MvcRetval::no_error;
  }


  MvcRetval GuitarRepository::registerNewGuitar(const std::string brand,
						const std::string model,
						const int nStrings,
						const std::vector<int> stringGauge,
						const std::string topWood,
						const std::string bodyWood,
						const std::string neckWood,
						const std::string neckJointType,
						const std::string bridgeType) {

    Guitar guitar;
    guitar.brand = brand;
    guitar.model = model;
    guitar.nStrings = nStrings;
    guitar.stringGauge = stringGauge;
    guitar.topWood = topWood;
    guitar.bodyWood = bodyWood;
    guitar.neckWood = neckWood;
    guitar.neckJointType = neckJointType;
    guitar.bridgeType = bridgeType;

    guitarRows.emplace_back(guitar);

    return MvcRetval::no_error;
  }
}
