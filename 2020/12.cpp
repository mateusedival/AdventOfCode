#include <iostream>
#include <stdlib.h>

int rotate(int degree, char inst, int direction)
{
	if(direction == 0)
	{
		if(inst == 'L')
		{
			if(degree == 90)
				return 3;
			else if(degree == 180)
				return 2;
			else if(degree == 270)
				return 1;
		}
		else
		{
			if(degree == 90)
				return 1;
			else if(degree == 180)
				return 2;
			else if(degree == 270)
				return 3;
		}
	}
	else if(direction == 1)
	{
		if(inst == 'L')
		{
			if(degree == 90)
				return 0;
			else if(degree == 180)
				return 3;
			else if(degree == 270)
				return 2;
		}
		else
		{
			if(degree == 90)
				return 2;
			else if(degree == 180)
				return 3;
			else if(degree == 270)
				return 0;
		}
	}
	else if(direction == 2)
	{
		if(inst == 'L')
		{
			if(degree == 90)
				return 1;
			else if(degree == 180)
				return 0;
			else if(degree == 270)
				return 3;
		}
		else
		{
			if(degree == 90)
				return 3;
			else if(degree == 180)
				return 0;
			else if(degree == 270)
				return 1;
		}
	}
	else if(direction == 3)
	{
		if(inst == 'L')
		{
			if(degree == 90)
				return 2;
			else if(degree == 180)
				return 1;
			else if(degree == 270)
				return 0;
		}
		else
		{
			if(degree == 90)
				return 0;
			else if(degree == 180)
				return 1;
			else if(degree == 270)
				return 2;
		}
	}
}

int main()
{
	int x = 0, y = 0;
	
	// east = 0, south = 1, west = 2, north = 3
	int direction = 0;
	
	std::string line;
	while(std::getline(std::cin, line))
	{
		char inst = line[0];
		int value = stoi(line.substr(1,line.size()));
		if(inst == 'L' or inst ==  'R')
			direction = rotate(value, inst, direction);
		else if(inst == 'F')
		{
			switch(direction)
			{
				case 0:
					x+=value;
					break;
				case 1:
					y-=value;
					break;
				case 2:
					x-=value;
					break;
				case 3:
					y+=value;
					break;
			}
		}
		else if(inst == 'N')
		{  
			y+=value;
		}
		else if(inst == 'W')
		{  
			x-=value;
		}
		else if(inst == 'S')
		{  
			y-=value;
		}
		else if(inst == 'E')
		{  
			x+=value;
		}	
	}
	std::cout << abs(x)+abs(y) << '\n';
}
