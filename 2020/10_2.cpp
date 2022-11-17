#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
int main()
{
	int x;
	std::vector<int> v;
	while(std::cin >> x)
	{
		v.push_back(x);
	}
	v.push_back(0);
	sort(v.begin(),v.end());
	v.push_back(v[v.size()-1]+3);
	
	int count = 0;
	long long r = 1;
	
	for (int i = 1; i < (int)v.size(); i++)
	{
		if(v[i] - v[i-1] == 1)
			count++;
		else
		{
			if(count == 1)
				r *= 1;
			else if(count == 2)
				r *=2;
			else if(count == 3)
				r *= 4;
			else if(count == 4)
				r *= 7;

			count = 0;
		}
	}
		
	std::cout << r << '\n';
	
}
