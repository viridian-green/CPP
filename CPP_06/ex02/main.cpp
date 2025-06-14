#include "Base.hpp"

int main()
{
    //srand changes the 'seed' of the rand function
    std::srand(static_cast<unsigned int>(time(nullptr)));
    Base* ptr = Base::generate();
    std::cout << "Generated type: ";
    ptr->identify(ptr);
    Base *temp = Base::generate();
    Base &ref = *temp;
    std::cout << "Generated type: ";
    ref.identify(&ref);
    delete ptr;

}