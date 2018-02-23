#include "errorCode.h"
#include "GuitarRepository.h"
#include "CsvGuitarWriter.h"
#include "GuitarController.h"

int main() {
  mvc::GuitarRepository guitarRepository;
  mvc::CsvGuitarWriter guitarWriter;
  mvc::GuitarController guitarController(&guitarRepository);

  guitarRepository.registerNewGuitar("Gibson", "Les Paul", 6, {1,2,3,4,5,6},
				     "alder", "mohagony", "alder", "set-in",
				     "tailpiece");

  guitarRepository.registerNewGuitar("Fender", "Stratocaster", 6, {1,2,3,4,5,6},
				     "alder", "mohagony", "alder", "bolt-on",
				     "floating-tremolo");
  return 0;
}
