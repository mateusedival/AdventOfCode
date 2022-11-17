#include <iostream>
#include <set>

int main()
{
	std::string line;
	int sum = 0;
	std::set<char> yes;
	while(std::getline(std::cin,line))
	{
		if(line == "")
		{
			sum += yes.size();
			yes.clear();
			continue;
		}
		for(int i = 0; i < (int)line.size();i++)
			yes.insert(line[i]);
	}
	sum += yes.size();
	std::cout << sum << '\n';
}
