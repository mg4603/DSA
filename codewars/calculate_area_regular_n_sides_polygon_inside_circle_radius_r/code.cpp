#include <assert.h>
#include <iostream>

#include <cmath>


double areaOfPolygonInsideCircle (double circleRadius , int numberOfSides )
{
  const double PI =  3.14159265;
  return  round(1000 * numberOfSides * circleRadius * circleRadius / 2 * sin(2 * PI / numberOfSides)) / 1000; 
}

void check_Integer_Positive_Values()
{
    assert(areaOfPolygonInsideCircle(3,3) == 11.691);
    assert(areaOfPolygonInsideCircle(2,4) == 8);
    assert(areaOfPolygonInsideCircle(4,5) == 38.042);
}
void check_Integer_double_Radius_Values()
{
    assert(areaOfPolygonInsideCircle(7.5,3) == 73.071);
    assert(areaOfPolygonInsideCircle(5.8,7) == 92.053);
    assert(areaOfPolygonInsideCircle(9.7,9) == 272.159);
}

int main()
{
    check_Integer_double_Radius_Values();
    check_Integer_Positive_Values();
}