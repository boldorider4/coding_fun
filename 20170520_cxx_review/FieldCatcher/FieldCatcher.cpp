
#include "FieldCatcher.h"

FieldCatcher::FieldCatcher()
  : CapacitorConstant<double>()
  , m_targetTime(0)
  , m_currentPower(1.3f)
  , m_state(FieldCatcher::STATE::empty)
{
}

double FieldCatcher::getTimePoint(tDaysSinceYearZero year)
{
  tDaysSinceYearZero lowerValue = 0;
  double             lowerPower = 0.0;
  long bestDelta = 100000000;
  tDaysSinceYearZero upperValue = 0;
  double             upperPower = 0.0;

  /* find smallest value pair smaller that contains year */
  /* could use iterator instead of size_type */
  /* or for(auto...) for consistency */
  for (int i = 0; i < m_timePoints.size(); ++i)
  {
    /* same as above */
    for (int j = 0; j < m_timePoints.size(); j++)
    {
      /* it makes no sense to continue if =>. Just handle the < case */
      if (m_timePoints[i] == m_timePoints[j])
        continue;
      if (m_timePoints[i] > m_timePoints[j])
        continue;
      /* I have a strong feeling the code in these nested loops can be optimized
         for starters, m_timePoints could be sorted (with power ordered accordingly) 
         but much more could be done */
      if (m_timePoints[i] < m_timePoints[j])
      {
        if (year >= m_timePoints[i] && year <= m_timePoints[j])
        {
          double delta = m_timePoints[j] - m_timePoints[i];
          if (delta < bestDelta)
          {
            bestDelta  = delta;
            lowerValue = m_timePoints[i];
            upperValue = m_timePoints[j];
            lowerPower = power[i];
            upperPower = power[j];
          }
        }
      }
    }
  }

  /* dividing and then multiplying by the same about is useless and can make you lose precision */
  double f = (year - lowerValue) / (upperValue - lowerValue);
  return lowerPower + f * (upperPower - lowerPower);
}

double FieldCatcher::addTimePointPowerPair(double powerValue, tDaysSinceYearZero timePoint)
{
  power.push_back(powerValue);
  m_timePoints.push_back(timePoint);
  /* maybe you should update m_timePointAsString */
  /* should be void */
  return 0.0;
}

/* move this directly after the other definition */
string FieldCatcher::getTimePoint(tDaysSinceYearZero timePoint) const
{
  string result;
  for (auto& i : m_timePointAsString)
  {
    if (i.first == timePoint)
    {
      /* you should return i.second */
      result = i.second;
    }
  }
  /* throw an exception but don't return potentially uninitialized result */
  return result;
}

double FieldCatcher::addUniqueTimePointByName(tDaysSinceYearZero timePoint, string name)
{
  /* should be a set */
  m_timePointAsString.push_back(make_pair(timePoint, name));
  /* adding timePoint to power? Makes no sense */
  power.push_back(timePoint);
  /* maybe you should update m_timePoints and power */
  /* should be void */
  return 0.0;
}

double FieldCatcher::get_currentPower() const
{
  return getCapacitorConstant() * m_currentPower;
}
