#include <iostream>
#include <deque>
#include <set>


int main()
{
	long long x;
	
	std::deque<long long> s;
	while(std::cin >> x)
	{
		s.push_back(x);
	}
	
	for (int z = 0; z < (int)s.size(); z++)
	{
		int soma = s[z];
		std::set<long long> c;
		c.insert(s[z]);
		for (int j = z+1; j < (int)s.size(); j++)
		{
			soma+=s[j];
			c.insert(s[j]);
			if(soma > 1504371145)
			{
				break;
			}
			else if(soma == 1504371145)
			{
				std::cout << *c.begin() +*(--c.end()) << '\n';
			}
			
		}
		
	}
	
}
