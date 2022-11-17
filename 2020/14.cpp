#include <iostream>
#include <bitset>
#include <unordered_map>

int main()
{
	std::string line;
	std::string mask;
	std::unordered_map<int,long long> mem;
	
	while(std::getline(std::cin, line))
	{
		int ind;
		int value;
		
		if(line.substr(0,4) == "mask")
		{
			mask = line.substr(7,line.size());
			continue;
		}
		else
		{
			ind = stoi(line.substr(line.find("[")+1,line.find("]")));
			value = stoi(line.substr(line.find("=")+1,line.size()));
		}
		
		std::bitset<36> result(value);
		
		for(int i = 0 ; i < 36; i++)
		{
			if(mask[i] == '0')
				result.reset(35-i);
			else if(mask[i] == '1')
				result.set(35-i);
		}
		mem[ind] = result.to_ullong();
	}
	
	long long soma = 0;
	for(auto it : mem)
		soma += it.second;
	std::cout<< soma << "\n";
}
