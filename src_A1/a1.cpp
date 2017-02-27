//File: a1.cpp
//Author: Aniruddha Nandi anandi

#include<iostream>
#include<fstream>
#include<string>
#include<math.h>

	int main(int argc, char* argv[]) {

	if(argc<2) {
		std::cout << "error: no input file" << std::endl;
		return -1;
	}

	std::string fil_name = argv[1];

	std::ifstream f(fil_name);
	if (!f) {
		std::cout << "error: sorry but " << fil_name <<" does not exist" << std::endl;
		return -1;
	}

 	int k = 0;
	int n = 0;
	int num_of_lines = 0;
	std::string line = "";
	std::string ok = "";
	std::string dna = "";

	f >> k >> n;

	while(getline(f, line)) {
		f >> ok;
		if(num_of_lines < n) {
		dna += ok;
		}
        num_of_lines++;
    }

	f.close();

	//k<=n
	if (!(k>=3 && k<=10 && n>1 && num_of_lines>=n)) {
	std::cout << "error" << std::endl;
	return 0;
	}

	//int index = pow(4.0, k);

	//int* arr = new int[index];

	//for(int i=0; i<index; i++) {
	//arr[i] = 0;
	//}
	
	for(int j=1; j<=(signed)dna.length()-k+1; ++j) {
	std::string sub = dna.substr(j-1,k);
	if((signed)sub.length() == k && (sub.find('N') == std::string::npos)) {
			std::cout << sub << std::endl;
		}	
	}

	/*	for(int l=0; l<k; l++) {
		if(sub.at(l) == 'N') {
		continue;
		}
		else {
		count++;
		if(sub.at(l) == 'A') sub.at(l) = '0';
		if(sub.at(l) == 'C') sub.at(l) = '1';
		if(sub.at(l) == 'G') sub.at(l) = '2';
		if(sub.at(l) == 'T') sub.at(l) = '3';
		}

			if(count==k) {
			int i_quad = std::stoi (sub, nullptr, 4);
			arr[i_quad] = arr[i_quad] + 1;
			}
			else {
			continue;
			}
		}
	}

	char st[4];

	for(int b=0; b<index; b++) {
		std::string strng = itoa(b, st, 4);

		if((signed)strng.length() < k) {
		do {
		strng = "0" + strng;
		} while((signed)strng.length() == k-1);
		}

		for(int h=0; h<(signed)strng.length(); h++) {
		if(strng.at(h) == '0') strng.at(h) = 'A';
		if(strng.at(h) == '1') strng.at(h) = 'C';
		if(strng.at(h) == '2') strng.at(h) = 'G';
		if(strng.at(h) == '3') strng.at(h) = 'T';
		}

		if(arr[b] > 0) std::cout << strng << " " << arr[b] << std::endl;
	}

	//std::cout << index << std::endl; */

	//delete[] arr;

	return 0;

} //end of main
