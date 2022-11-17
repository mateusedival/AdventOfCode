#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<std::string> lines;

int check(std::string color)
{
	int total = 0;
	
	for(auto x : lines)
	{
		auto posN = x.find(" bags contain");
		
		if(x.substr(0,posN).find(color) != std::string::npos)
		{
			std::string itens = x.substr(posN+14,x.size());
			
			std::vector<std::string> it;
			std::string aux = "";
			for (int i = 0; i < (int)itens.size(); i++)
			{
				if(itens[i] == ',' or itens[i] == '.')
					it.push_back(aux),i++,aux = "";
				else
					aux+=itens[i];
			}
			for(auto item : it)
			{
				
				std::string name = item[item.size()-1] == 'g' ? item.substr(2,item.size()-6):item.substr(2,item.size()-7);
				int qtd  = stoi(item.substr(0,1));
				total += (qtd + qtd*check(name));
			}
		}
	}
	return total;
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
	int total = check("shiny gold");
	std::cout << total << '\n';
}
