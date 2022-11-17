#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

std::pair<int,int> pairSum(const std::vector<int> &v, int sum)
{
	std::unordered_set<int> u;
	
	for(int x : v)
		if(u.count(x))
			return {x,sum-x};
		else
			u.insert(sum-x);
	return {-1,-1};
}



int main()
{
	std::vector<int> v;

	int x;

	while(std::cin >> x)
	{
		v.push_back(x);
	}
	
	std::pair<int,int> r = pairSum(v,2020);
	std::cout << r.first << " " << r.second << "\n";
	std::cout << r.first*r.second << "\n";
	

}
