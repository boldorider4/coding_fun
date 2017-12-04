
#ifndef PROJECT_CAPACITOR_H
#define PROJECT_CAPACITOR_H

#include <vector>
#include <string>
#include <cmath>
#include "CapacitorConstant.h"

/* bad practice */
using namespace std;

typedef long tDaysSinceYearZero;

class FieldCatcher : public CapacitorConstant<double>
{
  /* all enums with capital initial */
  typedef enum { Initializing, Terminating, transition, overloaded, empty } STATE;

public:
  FieldCatcher();

  /* remove underscore for consistency */
  double get_currentPower() const;

  /*
   * find the nearest power of timepoints and interpolate the resulting power value
   * i.e. we have 1980, 2000, 2020
   * find 1990 will yield 1980 and 2000
   */
  double getTimePoint(tDaysSinceYearZero year);

  /* this should be void */
  double addTimePointPowerPair(double powerValue, tDaysSinceYearZero timePoint);

  /* this should be void */
  double addUniqueTimePointByName(tDaysSinceYearZero timePoint, string name);

  /*
   *  find a time point in our list of timepoints
   */
  /* move this directly before the other definition */
  string getTimePoint(tDaysSinceYearZero timePoint) const;

protected:
  /* should be type tDaysSinceYearZero */
  long   m_targetTime;
  double m_currentPower;
  /* better change the storage of timePoints and power, for instancec with a vector of pairs */
  std::vector<tDaysSinceYearZero> m_timePoints;

  /*
   * unique timepoints associated with a string
   */
  /* should be a set if unique timepoints are inserted */
  std::vector<std::pair<tDaysSinceYearZero, string>> m_timePointAsString;

  STATE m_state;
  std::vector<double> power;
};

#endif
