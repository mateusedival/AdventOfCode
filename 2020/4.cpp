#include <iostream>
#include <sstream>


int main()
{
	std::string str;
	
	bool cid = false;
	int fields = 0;
	
	int qtd = 0;
	while(std::getline(std::cin,str))
	{
		if(str == "")
		{
			if(fields == 8 || (fields == 7 && !cid))
				qtd++;

			fields = 0;
			cid = false;
			continue;
		}
		std::stringstream ss(str);
		std::string token;
		while(ss >> token)
		{
			fields++;
			std::cout << fields << "\n";
			if(token.substr(0,3) == "cid")
				cid = true;
		}
	}
	if(fields == 8 || (fields == 7 && !cid))
		qtd++;
	std::cout << qtd << '\n';

}
