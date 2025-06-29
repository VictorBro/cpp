#include "Point.hpp"

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
