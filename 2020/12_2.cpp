#include <iostream>
#include <stdlib.h>


int main()
{
	int x = 0, y = 0;
	int wx = 10, wy = 1;
	
	
	std::string line;
	while(std::getline(std::cin, line))
	{	
		char inst = line[0];
		int value = stoi(line.substr(1,line.size()));
		if(inst == 'L')
			for (int i=0; i<(value/90); i++) {
				std::swap(wx, wy);
				wx *= -1;
			}
		else if(inst ==  'R')
			for (int i=0; i<(value/90); i++) {
				std::swap(wx, wy);
				wy *= -1;
			}
		else if(inst == 'F')
		{
			x+=(value * wx);
			y+=(value *wy);
		}
		else if(inst == 'N')
		{  
			wy+=value;
		}
		else if(inst == 'W')
		{  
			wx-=value;
		}
		else if(inst == 'S')
		{  
			wy-=value;
		}
		else if(inst == 'E')
		{  
			wx+=value;
		}	
	}
	std::cout << abs(x)+abs(y) << '\n';
}
