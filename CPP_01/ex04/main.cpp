#include <iostream>
#include <fstream>

std::string replaceline(std::string line, std::string s1, std::string s2)
{
	std::string new_line;
	size_t startPos = 0;
	size_t foundPos;

	while ((foundPos = line.find(s1, startPos)) != std::string::npos)
	{
		new_line.append(line, startPos, foundPos - startPos);
		new_line.append(s2);
		startPos = foundPos + s1.length();
	}
	new_line.append(line, startPos, line.length() - startPos);
	return (new_line);

}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		return(std::cout << "Error. Please input the file name, a first string "
				  << "and a second string in the following order!\n", 1);
	}
	std::fstream file;
    file.open(av[1], std::ios::in);
	if (!file.is_open())
		return(std::cout << "Error opening file." << std::endl, 1);
	else
	{
	std::ofstream fileReplace((std::string(av[1]) + ".replace").c_str());
    if (!fileReplace.is_open())
        return (std::cout << "Error opening file." << std::endl, 1);
    std::string line;
    if (file.is_open())
	{
	while (getline(file, line))
	{
        fileReplace << replaceline(line, av[2], av[3]) << std::endl;
    }
	}
	fileReplace.close();
	file.close();
}
}