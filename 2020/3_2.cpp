#include <iostream>

int main()
{
	std::string line;
	
	std::getline(std::cin,line);
	int trees[5] = {};
	int inc[5] = {1,3,5,7,1};
	int pos[5] = {1,3,5,7,1};
	
	bool flag = false;
	while(std::getline(std::cin,line))
	{
		for (int i = 0; i < 4; i++)
		{
			if(line[pos[i]] == '#')
				trees[i]++;
			pos[i] = (pos[i]+inc[i])%line.size();
		}
		if(!flag)
			flag = !flag;
		else
		{
			if(line[pos[4]] == '#')
				trees[4]++;
			pos[4] = (pos[4]+inc[4])%line.size();
			flag = !flag;
		}
		
	}
	
	long long r = 1;
	for(int x : trees)
		r*=x;
	std::cout << r << '\n';

}
