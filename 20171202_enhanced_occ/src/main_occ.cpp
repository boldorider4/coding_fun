#include "errorCode.h"
#include "InteractiveConsole.h"
#include "OccurrenceCounter.h"
#include <list>
#include <chrono>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>


using namespace OccurrenceCounter;
using Time = std::chrono::high_resolution_clock;
using TimeMs = std::chrono::microseconds;


void freeResources(std::list<OccurrenceCounter::OccurrenceCounter*>& counterList) {
  for (auto counterIt : counterList) {
    if (counterIt != nullptr) {
      delete counterIt;
    }
  }
}


int main() {

  std::list<OccurrenceCounter::OccurrenceCounter*> counterList;
  bool caseInsensitive = false;

  printWelcomeMessage();

  while(true) {

    std::string parsedString;
    OccRetval retval = parseInteractiveArguments(&parsedString, &caseInsensitive);

    if (retval == OccRetval::must_exit) {
      freeResources(counterList);
      return EXIT_SUCCESS;
    } else if (retval == OccRetval::file_parsed) {

      auto elementToRemove = counterList.begin();
      for (; elementToRemove != counterList.end(); ++elementToRemove) {
        if (!(*elementToRemove)->getFileName()->compare(parsedString)) {
          counterList.erase(elementToRemove);
          break;
        }
      }

      try {

        OccurrenceCounter::OccurrenceCounter* pOcc = new OccurrenceCounter::OccurrenceCounter(parsedString);
        retval = pOcc->init();

        if (retval == OccRetval::file_is_not_open) {
          std::cerr << "File " << parsedString << " does not exist or is not a regular file" << std::endl;
        } else {
          counterList.push_back(pOcc);
        }

      } catch (const std::invalid_argument& ia_e) {

        std::cerr << ia_e.what() << std::endl;
        freeResources(counterList);
        return EXIT_FAILURE;

      } catch (const std::ifstream::failure& f_e) {

        std::cerr << f_e.what() << std::endl;
        freeResources(counterList);
        return EXIT_FAILURE;

      }

    } else if (retval == OccRetval::word_parsed) {

      if (counterList.empty()) {
        std::cerr << "No file has been added" << std::endl;
      } else {

        TimeMs tLapse(0);

        for (auto counterIt : counterList) {

          int count;
          auto tInit = Time::now();
          retval = counterIt->countWord(&count, parsedString, caseInsensitive);
          auto tFinal = Time::now();

          if (retval == OccRetval::file_reading_error) {
            std::cerr << "Error reading file" << std::endl;
          } else if (retval == OccRetval::no_error) {
            std::cout << "In " << *counterIt->getFileName() << ": " << count << " occurrences" << std::endl;
          }

          tLapse += std::chrono::duration_cast<TimeMs>(tFinal - tInit);

        }

        std::cout << "The search took " << tLapse.count() << " microseconds" << std::endl;

      }

    } else if (retval != OccRetval::no_error) {
      std::cerr << "Unhandled return value" << std::endl;
      freeResources(counterList);
      return EXIT_FAILURE;
    }
  }

  freeResources(counterList);
  return EXIT_SUCCESS;
}
