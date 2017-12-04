/* same comment about include protectors */
#pragma once

/*
 * this small class holds the capacitor factor for the vehicle.
 * small vehicles have for example 1.0, skateboards 0.01, big trucks 25.0
 */
template <typename calc_type>
class CapacitorConstant
{
public:
  CapacitorConstant()
  {
  }

  /* get and set should be protected */
  void setCapacitorFactor(const calc_type& factor)
  {
    m_foundResult = factor;
  }

  double getCapacitorConstant() const
  {
    return m_foundResult;
  }

  /* should be private */
  calc_type m_foundResult;
};
