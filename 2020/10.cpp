#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int x;
	std::vector<int> v;
	while(std::cin >> x)
	{
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	
	int one = 0, three = 1;
	if(v[0] == 1)
		one++;
	else if(v[0] == 3)
		three++;
	for(int i = 1; i < (int)v.size(); i++)
	{
		if(v[i] - v[i-1] == 1)
			one++;
		else if(v[i] - v[i-1] == 3)
			three++;
	}
	std::cout << one * three << '\n';
}
