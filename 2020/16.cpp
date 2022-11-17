#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int,int> ii;
#define p1 first
#define p2 second


int check(std::vector<ii> ranges, std::vector<int> values)
{
	bool checked = false;
	for(auto i : values)
	{
		checked = false;
		for(auto it : ranges)
		{
			if(i > it.p1 and i < it.p2)
				checked = true;
		}
		if(!checked)
			return i;
	}
	return 0;
}


int main()
{
	std::string line;
	std::vector<ii> ranges;
	//tickets fields
	while(std::getline(std::cin, line), line != "")
	{
		line = line.substr(line.find(":")+1,line.size());
		std::string frange = line.substr(1,line.find("or")-1);
		std::string srange = line.substr(line.find("or")+2,line.size());
		int low,high;
		
		low = stoi(frange.substr(0,frange.find("-")));
		high = stoi(frange.substr(frange.find("-")+1,frange.size()));
		ranges.push_back({low,high});
		low = stoi(srange.substr(0,srange.find("-")));
		high = stoi(srange.substr(srange.find("-")+1,srange.size()));
		ranges.push_back({low,high});
	}


	//my ticket
	std::getline(std::cin, line);
	while(std::getline(std::cin, line), line != "")
	{
		
	}
	
	int sum = 0;

	//others tickets
	std::getline(std::cin, line);
	while(std::getline(std::cin, line), line != "")
	{
		std::vector<int> v;
		while(line.find(",") != std::string::npos)
		{
			int value = stoi(line.substr(0,line.find(",")));
			v.push_back(value);
			line = line.substr(line.find(",")+1,std::string::npos);	
		}
		int value = stoi(line.substr(0,std::string::npos));
		v.push_back(value);
		sum+=check(ranges,v);
	}
	std::cout << sum << '\n';
	
}
