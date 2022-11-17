#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>

typedef std::pair<int,int> ii;

#define p1 first 
#define p2 second

int main()
{
	std::string input;
	std::getline(std::cin, input);
	
	std::vector<int> v;
	
	while(input.find(",") != std::string::npos)
	{
		int x = stoi(input.substr(0,input.find(",")));
		input = input.substr(input.find(",")+1,input.size());
		v.push_back(x);
	}
	int x = stoi(input.substr(0,input.size()));
	v.push_back(x);
	
	std::unordered_map<int,ii> mem;
	
	int turn = 1;
	
	for(auto it : v)
		mem[it] = {turn,turn}, turn++;
		
	int last = x;
	bool first = true;
	
	for(; turn <= 2020; turn++)
	{
		
		if(first)
		{
			last = 0;
			if(mem.count(0))
			{
				mem[0].p1 = mem[0].p2;
				mem[0].p2 = turn;
				first = false;
			}	
			else
				mem[0] = {turn,turn}, first = true;
		}
		else
		{
	
			last = mem[last].p2 - mem[last].p1;
			if(mem.count(last))
			{
				mem[last].p1 = mem[last].p2;
				mem[last].p2 = turn;
			}
			else
				mem[last] = {turn,turn}, first = true;
		}
		
		
	}
	std::cout <<	 last << '\n';

}
