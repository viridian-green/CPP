#include "ScalarConverter.hpp"

int main(int argc, char **av)
{
    // if (argc != 2)
    // {
    //     std::cerr << "Usage: ./ScalarTypes <literal>" << std::endl;
    //     return 1;
    // }

    try
    {
        ScalarConverter::convert("é");
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

