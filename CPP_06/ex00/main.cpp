#include "ScalarConverter.hpp"

int main(int argc, char **av)
{
    // if (argc != 2)
    // {
    //     std::cerr << "Usage: ./ScalarTypes <literal>" << std::endl;
    //     return 1;
    // }
	(void)argc;
    try
    {
        ScalarConverter::convert(av[1]);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

