#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Valid Bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "=== Grade Too High (constructor) ===" << std::endl;
    try
    {
        Bureaucrat high("High", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "=== Grade Too Low (constructor) ===" << std::endl;
    try
    {
        Bureaucrat low("Low", 151);
        std::cout << low << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "=== Increment Grade ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 2);
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << alice << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "=== Decrement Grade ===" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 149);
        std::cout << charlie << std::endl;
        charlie.decrementGrade();
        std::cout << charlie << std::endl;
        charlie.decrementGrade();
        std::cout << charlie << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl
              << "=== Copy & Assignment ===" << std::endl;
    try
    {
        Bureaucrat original("Original", 50);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy << std::endl;

        Bureaucrat assigned("Assigned", 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
