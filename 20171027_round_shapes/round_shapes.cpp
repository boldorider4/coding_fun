#include <cmath>
#include <iostream>

double round_shapes(int x1, int y1, int r1, int x2, int y2, int r2) {
  /* sanity checks */
  if (r1 < 0 || r2 < 0) {
    std::cerr << "radii must be positive" << std::endl;
    return -1;
  }

  double circleDistance = std::sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

   /* edge cases 1: one circle is inside other circle
      I chose exactly that many decimal digits to satisfy the precision requirement
      when one of the radius is 200000 */
  if (circleDistance <= std::abs(r1 - r2)) {
    return 3.141592653589793 * std::min(r1,r2)*std::min(r1,r2);
  }

   /* edge cases 2: the two circle are not intersecting */
  if (circleDistance >= r1 + r2) {
    return 0;
  }

  /* calculating mutual chord length: this calculation results from significant factorization.
     Likelihood of having made a mistake is very high. Please check the code just to
     make sense of the algorithm */
  double mutualChordLength = 2 * std::sqrt(std::abs(r1*r1 - \
                             (.5 * (circleDistance + (r1 * r1 - r2 * r2) / circleDistance)) * \
                             (.5 * (circleDistance + (r1 * r1 - r2 * r2) / circleDistance))));

  /* calculating distance between center of circle and center-point of chord: applying
     trivial Pythagorean theorem */
  double distanceChordCenter1 = std::abs(.5 * (circleDistance + (r1*r1 - r2*r2) / circleDistance));
  double distanceChordCenter2 = std::abs(.5 * (circleDistance + (r2*r2 - r1*r1) / circleDistance));

  /* calculating angle at center of circle, spreading over the triangle: using basic
     trigonometry */
  double alpha1 = std::atan2(mutualChordLength * .5, distanceChordCenter1);
  double alpha2 = std::atan2(mutualChordLength * .5, distanceChordCenter2);

  /* final area calculation: summing both circle slices (half-moons) */
  return ((alpha1 * r1*r1 + alpha2 * r2*r2) - .5 * mutualChordLength*circleDistance);
}

int main() {

  double center_x1 = 1;
  double center_y1 = .5;
  double radius1 = 10;
  double center_x2 = 9;
  double center_y2 = 7;
  double radius2 = 5;
  std::cout << "center_x1 " << center_x1 << std::endl;
  std::cout << "center_y1 " << center_y1 << std::endl;
  std::cout << "radius1 " << radius1 << std::endl;
  std::cout << "center_x2 " << center_x2 << std::endl;
  std::cout << "center_y2 " << center_y2 << std::endl;
  std::cout << "radius2 " << radius2 << std::endl;
  std::cout << "round shape " << round_shapes(center_x1, center_y1, radius1, center_x2, center_y2, radius2) \
            << std::endl << std::endl;

  center_x1 = 2;
  center_y1 = 2;
  radius1 = 3;
  center_x2 = 5;
  center_y2 = 5;
  radius2 = 3;
  std::cout << "center_x1 " << center_x1 << std::endl;
  std::cout << "center_y1 " << center_y1 << std::endl;
  std::cout << "radius1 " << radius1 << std::endl;
  std::cout << "center_x2 " << center_x2 << std::endl;
  std::cout << "center_y2 " << center_y2 << std::endl;
  std::cout << "radius2 " << radius2 << std::endl;
  /* show equal 5.1371 */
  std::cout << "round shape " << round_shapes(center_x1, center_y1, radius1, center_x2, center_y2, radius2) \
            << std::endl  << std::endl;

  center_x1 = 0;
  center_y1 = 0;
  radius1 = 10;
  center_x2 = 5;
  center_y2 = 5;
  radius2 = 20;
  std::cout << "center_x1 " << center_x1 << std::endl;
  std::cout << "center_y1 " << center_y1 << std::endl;
  std::cout << "radius1 " << radius1 << std::endl;
  std::cout << "center_x2 " << center_x2 << std::endl;
  std::cout << "center_y2 " << center_y2 << std::endl;
  std::cout << "radius2 " << radius2 << std::endl;
  std::cout << "round shape " << round_shapes(center_x1, center_y1, radius1, center_x2, center_y2, radius2) \
            << std::endl  << std::endl;

  center_x1 = 5;
  center_y1 = 5;
  radius1 = 20;
  center_x2 = 0;
  center_y2 = 0;
  radius2 = 10;
  std::cout << "center_x1 " << center_x1 << std::endl;
  std::cout << "center_y1 " << center_y1 << std::endl;
  std::cout << "radius1 " << radius1 << std::endl;
  std::cout << "center_x2 " << center_x2 << std::endl;
  std::cout << "center_y2 " << center_y2 << std::endl;
  std::cout << "radius2 " << radius2 << std::endl;
  std::cout << "round shape " << round_shapes(center_x1, center_y1, radius1, center_x2, center_y2, radius2) \
            << std::endl  << std::endl;

  return 0;
}
