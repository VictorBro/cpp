# C++ Modules (42 School)

A series of C++ exercises from Module 00 to Module 08, designed to introduce Object-Oriented Programming and the C++ standard library. All code compiles with `c++ -Wall -Wextra -Werror -std=c++98`.

## Modules

| Module | Topic | Exercises |
|--------|-------|-----------|
| **00** | Basics | Strings, classes, member functions, stdio streams, initialization lists |
| **01** | Memory | `new`/`delete`, references, pointers to members, `switch` |
| **02** | Ad-hoc polymorphism | Operator overloading, Orthodox Canonical Form, fixed-point numbers |
| **03** | Inheritance | Single & multiple inheritance, diamond problem |
| **04** | Subtype polymorphism | Abstract classes, pure virtual functions, interfaces |
| **05** | Exceptions | `try`/`catch`/`throw`, nested exception classes, Bureaucrat & Forms |
| **06** | C++ casts | `static_cast`, `reinterpret_cast`, `dynamic_cast` |
| **07** | Templates | Function templates, class templates (`Array<T>`) |
| **08** | STL | Containers (`vector`, `list`, `deque`, `stack`), iterators, `<algorithm>` |

## Building

Each exercise has its own `Makefile`:

```bash
cd module05/ex02
make        # build
make re     # rebuild
make clean  # remove object files
make fclean # remove everything
make leak   # run with valgrind
```

## Key Concepts

- **Orthodox Canonical Form** — default constructor, copy constructor, copy assignment operator, destructor (Module 02+)
- **Exception safety** — custom exceptions inheriting from `std::exception` (Module 05)
- **Abstract classes** — pure virtual methods, interface segregation (Module 04)
- **Template metaprogramming** — function & class templates with generic types (Module 07)
- **STL usage** — containers, iterators, and algorithms applied where appropriate (Module 08)
