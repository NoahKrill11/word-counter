#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Song
{
public:
	std::string name;
	int count;
};
int main()
{
	std::string line;
	std::vector<Song> v; 
	bool found = false;
	std::ifstream myfile ("ex.txt");
	Song title;
	if (myfile.is_open())
	{
		while(myfile >> line)
		{
		title.name=line;
		if(v.size() ==0)
		{
			title.count =1;
			v.push_back(title);
		}
		else
		{
			for(int i=0; i<v.size();++i)
			{
				if(line==v[i].name)
				{
					found=true;
					v[i].count = v[i].count+1;
					break;
				}
			}
			if(found == true)
			{
				found = false;
			}
			else 
			{
				title.count=1;
				v.push_back(title);
				found = false;
			}
		}
	}
	for(int i=0; i<v.size();++i)
	{
		std::cout << v[i].name << " " << v[i].count<< " ";
	}
	std::cout << std::endl;
	std::cout << "The total number of orig words is : " << v.size()+1 << std::endl;
	}
	
	else 
		std::cout << "Unable to open file"; 

	return 0;
}
