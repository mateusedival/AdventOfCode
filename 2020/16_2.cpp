#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <unordered_set>

typedef std::pair<int,int> ii;
#define p1 first
#define p2 second

class ticket
{
	public:
		std::string name;
		ii range1;
		ii range2;
		
		ticket(std::string n, ii r1, ii r2) : name(n), range1(r1), range2(r2) { }
	
};


int check(std::vector<ii> ranges, std::vector<int> values)
{
	bool checked = false;
	for(auto i : values)
	{
		checked = false;
		for(auto it : ranges)
		{
			if(i > it.p1 and i < it.p2)
				checked = true;
		}
		if(!checked)
			return i;
	}
	return -1;
}


int main()
{
	std::string line;
	std::vector<ii> ranges;
	
	std::vector<ticket> t;
	
	//tickets fields
	while(std::getline(std::cin, line), line != "")
	{
		std::string name =  line.substr(0,line.find(":"));
		line = line.substr(line.find(":")+1,line.size());
		std::string frange = line.substr(1,line.find("or")-1);
		std::string srange = line.substr(line.find("or")+2,line.size());
		int low,high;
		ii r1,r2;
		
		low = stoi(frange.substr(0,frange.find("-")));
		high = stoi(frange.substr(frange.find("-")+1,frange.size()));
		r1 = {low,high};
		ranges.push_back({low,high});
		
		
		low = stoi(srange.substr(0,srange.find("-")));
		high = stoi(srange.substr(srange.find("-")+1,srange.size()));
		ranges.push_back({low,high});
		r2 = {low,high};
		ticket aux(name,r1,r2);
		t.push_back(aux);
	}

	std::vector<int> my;
	//my ticket
	std::getline(std::cin, line);
	while(std::getline(std::cin, line), line != "")
	{
		
		while(line.find(",") != std::string::npos)
		{
			int value = stoi(line.substr(0,line.find(",")));
			my.push_back(value);
			line = line.substr(line.find(",")+1,std::string::npos);	
		}
		int value = stoi(line.substr(0,std::string::npos));
		my.push_back(value);
	}
	std::vector<std::vector<int>> values;

	//others tickets
	std::getline(std::cin, line);
	while(std::getline(std::cin, line), line != "")
	{
		std::vector<int> v;
		while(line.find(",") != std::string::npos)
		{
			int value = stoi(line.substr(0,line.find(",")));
			v.push_back(value);
			line = line.substr(line.find(",")+1,std::string::npos);	
		}
		int value = stoi(line.substr(0,std::string::npos));
		v.push_back(value);
		if(check(ranges,v) == -1)
			values.push_back(v);
		
	}
	std::unordered_map<int,int> fields;
	std::unordered_set<int> camp;
	int tam = values.size();
	while(true)
	{
		for(int z = 0; z < (int)t.size(); z++)
		{
			if(fields.count(z))
				continue;	
			int possibility = 0;
			std::vector<int> field;
			for (int i = 0; i < (int)values[0].size(); i++)
			{
				if(camp.count(i))
					continue;
				int count = 0;
				
				for (int j = 0; j < (int) values.size(); j++)
				{
					
					if(values[j][i] >= t[z].range1.p1 and values[j][i] <= t[z].range1.p2)
						count++;
					else if(values[j][i] >= t[z].range2.p1 and values[j][i] <= t[z].range2.p2)
						count++;
				}
				
				if(count == tam)
				{
					possibility++;
					field.push_back(i);
					
				}
			}	
			if(possibility == 1)
				fields[z] = field[0],camp.insert(field[0]);
			
				
		}
		
		if(camp.size() == 20)
			break;
	}
	long long  r = 1;
	for(int i = 0; i < 6; i++)
		r *= my[fields[i]];
	std::cout << r << '\n';
}
