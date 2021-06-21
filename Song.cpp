#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
int main()
{
	std::string line;//word by word variable
	std::vector<std::string> v; // holds all orig words 
	bool found = false;// vaiable to not allow for duplicate words to be pushed onto the vector
	std::ifstream myfile ("Candy.txt");
	if (myfile.is_open())
	{
		while(myfile >> line)
		{
		if(v.size() ==0)
		{
			v.push_back(line);
		}
		else
		{
			for(int i=0; i<v.size();++i)
			{
				if(line==v[i])
				{
					found=true;
					break;
				}
			}
			if(found == true)
			{
				found = false;
			}
			else 
			{
				v.push_back(line);
				found = false;
			}
		}
	}
	for(int i=0; i<v.size();++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "The total number of orig words is : " << v.size()+1 << std::endl;
	}
	
	else 
		std::cout << "Unable to open file"; 

	return 0;
}
