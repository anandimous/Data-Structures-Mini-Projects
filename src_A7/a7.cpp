/***
*  File: a7.cpp
*  Author: Aniruddha Nandi anandi
*/

#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

bool checkEditDistance(std::string s1, std::string s2)
{
    int l1 = s1.length(); 
	int l2 = s2.length();
	
	if ((l1 - l2) > 1 || (l2 - l1) > 1) { return false; }
	
	int edit = 0;

	int i = 0, j = 0;

	while (i < l1 && j < l2) {
		if (s1[i] != s2[j])
		{
			if (edit == 1)
			return false;
			
			if (l1 > l2)
			i++;
			else if (l1 < l2)
			j++;
			else
			{
				i++;
				j++;
			}

			edit++;
		}

		else
		{
			i++;
			j++;
		}
	}

	if (i < l1 || j < l2) { edit++; }

	return edit == 1;
}

bool compare(std::pair<std::string, int> p1, std::pair<std::string, int> p2)
{
return p1.second < p2.second;
}

int main(int argc, char* argv[]) {

std::string s_in;
std::vector<std::string> candidates;

if(argc<2) {
	std::cout << "error: no input file" << std::endl;
	return -1;
}

std::string fil_name = argv[1];

std::fstream f(fil_name);
if (!f) {
	std::cout << "error: " << fil_name <<" does not exist" << std::endl;
	return -1;
}

std::string word;
int count;
std::map<std::string, int> dict;
std::map<std::string, int> output;

//File scannning
while(!f.eof()) {
	f >> word >> count;
	dict[word] = count;
}

f.close();

std::map<std::string,int>::iterator it;

while(std::cin >> s_in) {
	bool exact = false;
	bool found = false;
	it = dict.find(s_in);

	if (it != dict.end()) { 
		std::cout << it->first << " " << it->second << std::endl;
		it->second += 1;
		exact = true;
	}
	
	if(exact != true) {
		for(it = dict.begin(); it != dict.end(); it++) {
			if(checkEditDistance(s_in, it->first) == true) {
				output[it->first] = it->second;
				found = true;
			}
		}
		
		if(found == true) {
			it = std::max_element(output.begin(), output.end(), compare);
			std::cout << it->first << " " << it->second << std::endl;
			output.clear();
		}
		
		else {
			std::cout << "-" << std::endl;
			dict[s_in] = 1;
		}
	}
}

return 0;

}