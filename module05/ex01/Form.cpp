#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other)
    : _name(other._name),
      _signed(other._signed),
      _gradeToSign(other._gradeToSign),
      _gradeToExecute(other._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        _signed = other._signed;
    std::cout << "Form copy assignment operator called" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

const std::string &Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradeToSign;
}

int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}
const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
    if (f.getSigned())
        os << f.getName() << " form is signed with grade to sign = "
           << f.getGradeToSign() << " and grade to execute = " << f.getGradeToExecute();
    else
        os << f.getName() << " form is not signed with grade to sign = "
           << f.getGradeToSign() << " and grade to execute = " << f.getGradeToExecute();
    return os;
}
