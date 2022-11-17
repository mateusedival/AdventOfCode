#include <iostream>
#include <map>

int main()
{
	std::string line;
	int sum = 0;
	std::map<char,int> yes;
	int count = 0;
	
	while(std::getline(std::cin,line))
	{
		if(line == "")
		{
			for(auto it : yes)
				if(it.second == count)
					sum++;
			count = 0;
			yes.clear();
			continue;
		}
		count++;
		for(int i = 0; i < (int)line.size();i++)
			yes[line[i]]++;
		
	}
	for(auto it : yes)
		if(it.second == count)
			sum++;
	std::cout << sum << '\n';
}
