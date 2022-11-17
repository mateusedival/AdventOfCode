#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	int acc = 0;
	std::vector<std::string> lines;
	std::string line;
	std::unordered_map<int,int> flag;
	while(std::getline(std::cin,line))
	{
		lines.push_back(line);
	}
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
	}
	std::cout << acc << '\n';
}
