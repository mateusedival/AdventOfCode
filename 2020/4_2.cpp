#include <iostream>
#include <sstream>
#include <ctype.h>

int main()
{
	std::string str;
	
	bool cid = false;
	int fields = 0;
	
	int qtd = 0;
	while(std::getline(std::cin,str))
	{
		if(str == "")
		{
			if(fields == 8 || (fields == 7 && !cid))
				qtd++;

			fields = 0;
			cid = false;
			continue;
		}
		std::stringstream ss(str);
		std::string token;
		while(ss >> token)
		{
			std::string aux = token.substr(0,3);
			
			if(aux == "byr")
			{
				int ibyr = stoi(token.substr(4,token.size()));
				if(ibyr >= 1920 and ibyr <= 2002)
					fields++;
			}
			else if(aux == "iyr")
			{
				int iiyr = stoi(token.substr(4,token.size()));
				if(iiyr >= 2010 and iiyr <= 2020)
					fields++;
			}
			else if(aux == "eyr")
			{
				int ieyr = stoi(token.substr(4,token.size()));
				if(ieyr >= 2020 and ieyr <= 2030)
					fields++;
			}
			else if(aux == "hgt")
			{
				
				std::string f = token.substr(token.size()-2,token.size());
				if(f == "in")
				{
					int tam = stoi(token.substr(4,6));
					if(tam >= 59 and tam <=76)
						fields++;
				}
				else if(f == "cm")
				{
					int tam = stoi(token.substr(4,7));
					if(tam >=150 and tam <=193)
						fields++;
				}
			}
			else if(aux == "hcl")
			{
				std::string hcl = token.substr(4,token.size());
				if(hcl[0] != '#' || hcl.size() != 7)
					continue;
				int flag = true;
				for (int i = 1; i < (int)hcl.size(); i++)
				{
					if(!isdigit(hcl[i]) and hcl[i] > 'f')
						flag = false;
				}
				if(flag)
					fields++;
			}
			else if(aux == "ecl")
			{
				std::string v[7] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
				std::string color = token.substr(4,token.size());
				int flag = false;
				for(auto s : v)
					if(s == color)
						flag = true;
				if(flag)
					fields++;
			}
			else if(aux == "pid")
			{
				std::string pid = token.substr(4,token.size());
				if(pid.size() != 9)
					continue;
				int flag = true;
				for (int i = 0; i < (int)pid.size(); i++)
				{
					if(!isdigit(pid[i]))
					{
						flag = false;
						break;
					}
				}
				if(flag)
					fields++;
			}
			else if(aux == "cid")
				fields++,cid = true;
		}
	}
	if(fields == 8 || (fields == 7 && !cid))
		qtd++;
	std::cout << qtd << '\n';

}
