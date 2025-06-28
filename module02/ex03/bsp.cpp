#include "Point.hpp"

// float area(Point const A, Point const B, Point const C)
// {
// 	float ret = (A.getX() * ((B.getY() - C.getY()))
// 		+ B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY())).toFloat();
// 	ret /= 2.0f;
// 	return (ret < 0 ? -ret : ret);
// }

// bool bsp( Point const a, Point const b, Point const c, Point const point)
// {
//     float A1 = area(a, b, point);
// 	//std::cout << "area size A1 is " << A1 << std::endl;
// 	float A2 = area(b, c, point);
// 	//std::cout << " area size A2 is " << A2 << std::endl;
// 	float A3 = area(c, a, point);
// 	//std::cout << "area size A3 is " << A3 << std::endl;
// 	float BigT = area(a, b, c);
// 	//std::cout << "area size BigT is " << BigT << std::endl;
// 	std::cout << "A1 + A2 + A3 == BIGT ??\n"<< std::endl;
// 	std::cout << A1 << " + "<< A2 << " + " << A3 << " == " << BigT << std::endl;
// 	return (BigT == (A1 + A2 + A3));
// }

// Helper function to calculate the sign of triangle area
// Positive if p is on left side of line ab, negative if on right side
Fixed sign(Point const &p1, Point const &p2, Point const &p3)
{
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

// Function to check if point is inside triangle
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    // Calculate area signs
    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    // Check if point is strictly inside (all signs are the same)
    bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    // If we have both positive and negative signs, or any sign is zero
    // the point is on an edge or vertex, or outside
    return !(has_neg && has_pos) && (d1 != 0) && (d2 != 0) && (d3 != 0);
}
