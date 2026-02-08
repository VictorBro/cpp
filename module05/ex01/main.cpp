#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "========== BUREAUCRAT TESTS ==========" << std::endl;

    std::cout << std::endl << "=== Valid Bureaucrat ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 42);
        std::cout << bob << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Bureaucrat Grade Too High ===" << std::endl;
    try
    {
        Bureaucrat high("High", 0);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Bureaucrat Grade Too Low ===" << std::endl;
    try
    {
        Bureaucrat low("Low", 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "========== FORM TESTS ==========" << std::endl;

    std::cout << std::endl << "=== Valid Form ===" << std::endl;
    try
    {
        Form tax("Tax Return", 50, 25);
        std::cout << tax << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Form Grade Too High ===" << std::endl;
    try
    {
        Form bad("BadForm", 0, 50);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Form Grade Too Low ===" << std::endl;
    try
    {
        Form bad("BadForm", 50, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Sign Form (success) ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 10);
        Form permit("Building Permit", 50, 25);
        std::cout << permit << std::endl;
        alice.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Sign Form (grade too low) ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 100);
        Form permit("Top Secret", 10, 5);
        std::cout << bob << std::endl;
        std::cout << permit << std::endl;
        bob.signForm(permit);
        std::cout << permit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "=== Sign Form (exact grade) ===" << std::endl;
    try
    {
        Bureaucrat exact("Exact", 50);
        Form form("Exact Form", 50, 50);
        exact.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
