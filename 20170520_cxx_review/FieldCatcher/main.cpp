#include <iostream>
#include "FieldCatcher.h"

int main()
{
  std::cout << "Run a Field Catcher test" << std::endl;

  /*
   * 736406 is Mar 16, 2017
   */
  FieldCatcher t;

  /**
   * these values depend on sun - activity
   */
  t.addTimePointPowerPair(-20.0, 736406 - 200 * 365);
  t.addTimePointPowerPair(-10.0, 736406 - 150 * 365);
  t.addTimePointPowerPair(-5.0, 736406 - 51 * 365);
  t.addTimePointPowerPair(0.0, 736406);
  t.addTimePointPowerPair(+5.0, 736406 + 50 * 365);
  t.addTimePointPowerPair(+15.0, 736406 + 100 * 365);
  t.addTimePointPowerPair(+20.0, 736406 + 200 * 365);
  t.addUniqueTimePointByName(730121, "y2k bug, short before midnight");
  t.addUniqueTimePointByName(730122, "y2k bug, midnight");
  t.addUniqueTimePointByName(734178, "Alice born");
  t.addUniqueTimePointByName(736406, "today");
  float power = static_cast<float>(t.getTimePoint(736406 - 50 * 365));
  printf("%s:%20.20f\n", "Power", power);
  return 0;
}
