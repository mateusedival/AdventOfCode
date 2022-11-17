#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	std::string line;
	getchar();
	std::getline(std::cin,line);
	
	int idc = 0;
	int dist = 999999999;
	
	while(line.find(",") != std::string::npos)
	{
		int value;
		if(line.substr(0,line.find(",")) == "x")
		{
			line = line.substr(line.find(",")+1,line.size());
			continue;
		}
		else
		{
			value = stoi(line.substr(0,line.find(",")));
			line = line.substr(line.find(",")+1,line.size());
		}
		int m = (n/value) + 1;

		if(m*value < dist)
		{
			dist = m*value;
			idc = value;
		}
	}
	if(line != "x")
	{
		int value = stoi(line);
		int m = (n/value) + 1;

		if(m*value  < dist)
		{
			dist = m*value;
			idc = value;
		}
	}
	
	std::cout <<  (dist-n) * idc  << '\n';

}
