#include <iostream>
#include <bitset>
#include <unordered_map>
#include <string>

typedef long long ll;

std::unordered_map<ll,ll> mem;

void written(std::string address, ll value, int x)
{
	if(x == 0)
	{	
		std::bitset<36> aux(address);
		mem[aux.to_ullong()] = value;
		return;
	}
	for(int i = 0; i < 36;i++)
	{
		if(address[i] == 'X')
		{
			address[i] = '1';
			written(address, value, x-1);
			address[i] = '0';
			written(address, value, x-1);
			break;
		}
	}
}

int main()
{
	std::string line;
	std::string mask;
	
	while(std::getline(std::cin, line))
	{
		ll address;
		ll value;
		
		if(line.substr(0,4) == "mask")
		{
			mask = line.substr(7,line.size());
			continue;
		}
		else
		{
			address = stoi(line.substr(line.find("[")+1,line.find("]")));
			value = stoi(line.substr(line.find("=")+1,line.size()));
		}
		
		std::bitset<36> aux(address);
		std::string result = aux.to_string();
		
		int x= 0;
		for(int i = 0 ; i < 36; i++)
		{
			if(mask[i] == 'X')
				result[i] = 'X', x++;
			else if(mask[i] == '1')
				result[i] = '1';
		}
		written(result, value, x);
		
	}
	
	ll soma = 0;
	for(auto it : mem)
		soma += it.second;
	std::cout<< soma << "\n";
}
