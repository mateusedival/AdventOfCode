#include <iostream>

int main()
{
	std::string str;
	int hiId = -1;
	bool seats[839] = {};
	
	while(std::cin >> str)
	{
		
		int rowHi = 127,rowLow = 0;
		int colHi = 7, colLow = 0;
		int i;
		for(i = 0; i < 7; i++)
		{
			if(str[i] == 'F')
				rowHi -=(((rowHi- rowLow)/2)+1);
			else
				rowLow +=(((rowHi- rowLow)/2)+1);
		}
		for(;i < (int)str.size(); i++)
		{
			if(str[i] == 'L')
				colHi -=(((colHi - colLow)/2)+1);
			else
				colLow +=(((colHi - colLow)/2)+1);
		}
		int seatId = rowLow*8 + colLow;
		seats[seatId] = true;
		if(seatId > hiId)
			hiId = seatId;
	}
	
	for (int i = 0; i < 839; i++)
	{
		if(!seats[i])
			std::cout << i << '\n';
	}
	

}
