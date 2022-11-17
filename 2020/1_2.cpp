#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <tuple>

std::tuple<int,int,int> trioSum(const std::vector<int> &v, int sum)
{
	
	for(int i = 0; i < (int)v.size(); i++)
	{
		std::unordered_set<int> u;
		const int resto = sum - v[i];
		for(int j = i + 1; j < (int)v.size(); j++)
		{
			if(u.count(v[j]))
				return std::make_tuple (v[j],resto-v[j],v[i]);
			else
				u.insert(resto-v[j]);
		}
	}
	return std::make_tuple (-1,-1,-1);
}



int main()
{
	std::vector<int> v;

	int x;

	while(std::cin >> x)
	{
		v.push_back(x);
	}
	
	auto r = trioSum(v,2020);
	std::cout << std::get<0>(r) << " " << std::get<1>(r)  << " " << std::get<2>(r)<< "\n";
	std::cout << std::get<0>(r)*std::get<1>(r)*std::get<2>(r) << "\n";
	

}
