#include <iostream>
#include <deque>
#include <utility>
#include <unordered_set>


bool pairSum(const std::deque<long long> &v, long long sum)
{
	std::unordered_set<long long> u;
	
	for(int x : v)
		if(u.count(x))
			return true;
		else
			u.insert(sum-x);
	return false;
}



int main()
{
	long long x;
	
	int preamble = 0;
	
	std::deque<long long> previous;
	while(std::cin >> x)
	{
		if(preamble < 25)
			preamble++, previous.push_back(x);
		
		else
		{
			if(!pairSum(previous,x))
			{
				std::cout << x << '\n';
				break;
			}
			else
				previous.push_back(x),previous.pop_front();
		}
		
	}
}
