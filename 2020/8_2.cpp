#include <iostream>
#include <vector>
#include <unordered_map>

int acc = 0;

bool isInf(std::vector<std::string> lines)
{
	acc = 0;
	std::unordered_map<int,int> flag;
	int i = 0;
	while(!flag[i])
	{
		int value;
		if(lines[i].find("+") != std::string::npos)
			value = stoi(lines[i].substr(lines[i].find("+")+1,lines[i].size()));
		else
			value = stoi(lines[i].substr(lines[i].find("-"),lines[i].size()));
		if(lines[i][0] == 'a')
			acc += value, flag[i]++, i++;
		else if(lines[i][0] == 'n')
			flag[i]++,i++;
		else
			flag[i]++, i += value;
		
		if(i >= (int)lines.size())
			return false;
	}
	return true;
}



int main()
{
	
	std::vector<std::string> lines;
	std::string line;
	
	while(std::getline(std::cin,line))
	{
		lines.push_back(line);
	}
	
	for (int i = 0; i < (int)lines.size(); i++)
	{
		if(lines[i][0] == 'j')
		{
			lines[i][0] = 'n';
			if(!isInf(lines))
				break;
			else
				lines[i][0] = 'j';
		}
		
		else if(lines[i][0] == 'n')
		{
			lines[i][0] = 'j';
			if(!isInf(lines))
				break;
			else
				lines[i][0] = 'n';	
		}
	}
	
	
	
	std::cout << acc << '\n';
}
