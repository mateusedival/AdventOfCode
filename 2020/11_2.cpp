#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<int,int> ii;

#define p1 first
#define p2 second

std::vector<std::string> seats;

bool isInside(int width,int height, int x, int y)
{
	if(x >= 0 and y >=0 and x < width and y < height)
		return true;
	return false;
}

bool adjFree(int x, int y,int width, int height)
{
	ii neighbours[8] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
	for (int z = 0; z < 8; z++)
	{
		int p = neighbours[z].p1;
		int q = neighbours[z].p2;
		
		int i = x+p, j = y+q;
		while(isInside(width, height, i, j))
		{
			if(seats[j][i] == '#')
				return false;
			else if(seats[j][i] == 'L')
				break;
			i+=p,j+=q;
		}
	}
	return true;
}

bool adjOcup(int x, int y,int width, int height)
{
	ii neighbours[8] = {{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0}};
	int count = 0;
	for (int z = 0; z < 8; z++)
	{
		int p = neighbours[z].p1;
		int q = neighbours[z].p2;
		
		int i = x+p, j = y+q;
		while(isInside(width, height, i, j))
		{
			if(seats[j][i] == '#')
			{
				count++;
				break;
			}
			else if(seats[j][i] == 'L')
				break;
			i+=p,j+=q;
		}
	}
	if(count < 5)
		return false;
	return true;
}

int main()
{
	std::string line;

	while(std::getline(std::cin,line))
		seats.push_back(line);
		
	int width = seats[0].size(),height = seats.size();

	bool change = true;
	while(change)
	{
		change = false;
		std::vector<std::string> newseats(seats);
		
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if(seats[i][j] == 'L')
				{
					if(adjFree(j,i,width, height))
						change = true, newseats[i][j] = '#';
				}
				else if(seats[i][j] == '#')
				{
					if(adjOcup(j,i,width, height))
						change = true, newseats[i][j] = 'L';
				}	
			}
			
		}
		seats = newseats;
	}
	int count = 0;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)

			if(seats[i][j] == '#')
				count++;

	std::cout << count << '\n';
}
