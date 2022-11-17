#include <iostream>

int main()
{
	std::string line;
	
	std::getline(std::cin,line);
	int trees = 0;
	int pos = 3;
	while(std::getline(std::cin,line))
	{
		if(line[pos] == '#')
			trees++;
		
		pos = (pos+3)%line.size();
	}
	std::cout << trees << '\n';
}
