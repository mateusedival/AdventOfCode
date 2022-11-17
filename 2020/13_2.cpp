#include <iostream>
#include <vector>
#include <utility>

#define p1 first 
#define p2 second

int main()
{
	int n;
	std::cin >> n;
	std::string line;
	getchar();
	std::getline(std::cin,line);
	std::vector<std::pair<int,int>> busId;
	int offset = 0;
	while(line.find(",") != std::string::npos)
	{
		int value;
		if(line.substr(0,line.find(",")) == "x")
		{
			line = line.substr(line.find(",")+1,line.size());
			offset++;
			continue;
		}
		else
		{
			value = stoi(line.substr(0,line.find(",")));
			line = line.substr(line.find(",")+1,line.size());
		}
		busId.push_back({value,offset});
		offset++;
	}
	if(line != "x")
	{
		int value = stoi(line);
		busId.push_back({value,offset});
		offset++;
	}
	
	bool flag = false;
	long long i = 1000000000000;
	while(true)
	{
		long long base = busId[0].p1 *i;
		flag = true;
		for(auto it : busId)
		{
			if((base + it.p2)%it.p1 != 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			break;
		i++;
	}
	std::cout << i*busId[0].p1 << '\n';
}
