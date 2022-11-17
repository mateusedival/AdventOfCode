#include <iostream>
#include <vector>




int main()
{
	std::string cube[51][51][51];
	int m = 25;
	
	std::string line;
	int i = 0;
	while(std::getline(std::cin, line))
	{
		for(int j = 0;j < (int)line.size(); j++)
		{
			cube[m+i][m+j][m] = line[j];
		}
		
		i++;
	}
	
	for (int i = m; i < m+8; i++)
	{
		for(int j = m; j < m+8; j++)
			std::cout << cube[m+i][m+j][m] << " ";
		puts("");
	}
	

}
