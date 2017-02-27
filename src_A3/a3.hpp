/***
 *  File: a3.hpp
 *  Author: Aniruddha Nandi anandi
 */

#ifndef A3_HPP
#define A3_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>

class key_value_sequences {
public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY

    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN -1
	
    int size(int key) const{
	for(int i=0; i<keys.size(); i++) {
		if(keys[i] == key) {
			return values[i].size();
		}
	}
	return -1;
	}

    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key) const{
	for(int i=0; i<keys.size(); i++) {
		if(keys[i] == key) {
			const int* p = values[i].data();
			return p;
		}
	}
	return nullptr;
    }
 
    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value){	
	
	int pos;
	bool found = false;
		
	for(int i=0; i<keys.size(); i++) {
		if(keys[i] == key) {
			pos = i;
			found = true;
			break;
		}
	}
	
	if(found){
		values[pos].push_back(value);
	}
	else{
		keys.push_back(key);
		std::vector<int> temp;
		temp.push_back(value);
		values.push_back(temp);
	}
	
    }
	
private:
	std::vector<int> keys;
    std::vector<std::vector<int>> values;

}; // class key_value_sequences

#endif // A3_HPP
