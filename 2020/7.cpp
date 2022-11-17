#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::string> lines;
std::unordered_set<std::string> colors;

void check(std::string color)
{
	for(auto x : lines)
	{
		auto posN = x.find(" bags contain");
		if(x.substr(posN,x.size()).find(color) != std::string::npos)
		{
			if(!colors.count(x.substr(0,posN)))
			{
				colors.insert(x.substr(0,posN));
				check(x.substr(0,posN));
				
			}
		}
	}
}

int main()
{
	std::string line;
	while(std::getline(std::cin, line))
	{
		std::string no = "no other bags";
		if(line.find(no) != std::string::npos)
			continue;
			
		lines.push_back(line);		
	}
	check("shiny gold");
	std::cout << colors.size() << '\n';
}
