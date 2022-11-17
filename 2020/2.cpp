#include <iostream>
#include <algorithm>

int main()
{
	std::string range, c, str;
	
	int qtd = 0;
	
	while(std::cin >> range >> c >> str)
	{
		std::string a1 = "",a2 = "";
		int flag = 0;
		for (int i = 0; i < (int) range.size(); i++)
		{
			if(range[i] == '-')
				flag = 1,i++;
			if(!flag)
				a1+=range[i];
			else
				a2+=range[i];
		}
		int low = stoi(a1);
		int hi = stoi(a2);
		int count = std::count(str.begin(),str.end(),c[0]);
		if(count >= low and count <= hi)
			qtd++;
	}
	
	std::cout << qtd << '\n';
}

