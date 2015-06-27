///
/// C++ interview quiz.
/// 
/// What shall be printed as 'x' value?
///

#include <iostream>
#include <stdexcept>

int x = 0;

#define TRACE_CALL std::cout << __PRETTY_FUNCTION__ << std::endl

class Base {
 public:
    Base() { TRACE_CALL; ++x; }
    Base(const Base &) { TRACE_CALL; --x; }
    Base(Base &&) { TRACE_CALL; x += 2; }
    virtual ~Base() { TRACE_CALL; x -= 3; }
    Base & operator=(const Base &) { TRACE_CALL; x += 5; return *this; }
    Base & operator=(Base &&) { TRACE_CALL; x -=2; return *this; }
};

class Derived: public Base {
 public:
    Derived() { TRACE_CALL; x += 2; }
    Derived(const Derived &other): Base(other) { TRACE_CALL; x += 3; }
    Derived(Derived &&other): Base(other) { TRACE_CALL; x -= 2; }
    ~Derived() { TRACE_CALL; --x; }
    Derived & operator=(const Derived &) { TRACE_CALL; x += 2; return *this; }
    Derived & operator=(Derived &&) { TRACE_CALL; x -= 3; return *this; }
};

int main() try {
    Base b = Derived();
    Derived d(std::move(Derived()));
    d = Derived();
    b = d;
    throw std::logic_error("You shall not pass!");
    return 0;
} catch (...) {
    std::cout << x << std::endl;
    return 1;
}
