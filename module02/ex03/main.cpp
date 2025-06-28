#include "Point.hpp"
#include <iostream>
#include <iomanip>

void testCase(const std::string& description, 
              const Point& a, const Point& b, const Point& c, 
              const Point& point, bool expectedResult) {
    bool result = bsp(a, b, c, point);
    bool correct = (result == expectedResult);
    
    std::cout << std::left << std::setw(60) << description << ": ";
    std::cout << (result ? "Inside" : "Outside") << " (";
    std::cout << (correct ? "CORRECT" : "WRONG") << ")" << std::endl;
}

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    
    std::cout << "=== STANDARD TRIANGLE TESTS ===" << std::endl;
    testCase("Point inside triangle", a, b, c, Point(1.0f, 1.0f), true);
    testCase("Point outside triangle", a, b, c, Point(6.0f, 6.0f), false);
    testCase("Point on vertex", a, b, c, b, false);
    testCase("Point on edge", a, b, c, Point(2.5f, 0.0f), false);
    
    std::cout << "\n=== LINE TRIANGLE TESTS ===" << std::endl;
    // Horizontal line
    Point h1(-5.0f, 0.0f);
    Point h2(0.0f, 0.0f);
    Point h3(5.0f, 0.0f);
    testCase("Horizontal line triangle - point on line", h1, h2, h3, Point(1.0f, 0.0f), false);
    testCase("Horizontal line triangle - point off line", h1, h2, h3, Point(1.0f, 1.0f), false);
    
    // Vertical line
    Point v1(0.0f, -5.0f);
    Point v2(0.0f, 0.0f);
    Point v3(0.0f, 5.0f);
    testCase("Vertical line triangle - point on line", v1, v2, v3, Point(0.0f, 1.0f), false);
    testCase("Vertical line triangle - point off line", v1, v2, v3, Point(1.0f, 1.0f), false);
    
    // Different quadrants
    std::cout << "\n=== CROSS-QUADRANT TRIANGLE TESTS ===" << std::endl;
    Point q1(-5.0f, -5.0f);  // Third quadrant
    Point q2(5.0f, -5.0f);   // Fourth quadrant
    Point q3(0.0f, 5.0f);    // First quadrant
    testCase("Triangle across 3 quadrants - inside", q1, q2, q3, Point(0.0f, 0.0f), true);
    testCase("Triangle across 3 quadrants - outside", q1, q2, q3, Point(-6.0f, 0.0f), false);
    
    // All negative coordinates
    std::cout << "\n=== NEGATIVE COORDINATES TESTS ===" << std::endl;
    Point n1(-5.0f, -5.0f);
    Point n2(-1.0f, -5.0f);
    Point n3(-3.0f, -1.0f);
    testCase("Triangle in negative space - inside", n1, n2, n3, Point(-3.0f, -4.0f), true);
    testCase("Triangle in negative space - outside", n1, n2, n3, Point(-6.0f, -6.0f), false);
    
    return 0;
}
