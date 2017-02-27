/***
 *  File: encode.hpp
 *  Author: Aniruddha Nandi anandi
 */

#ifndef ENCODE_HPP
#define ENCODE_HPP

#include "a6.hpp"
#include "symbol.hpp"
#include <string>
#include <map>

// IMPLEMENT FUNCTION ENCODE BELOW
// THIS FUNCTION IS USED BY EXTRA CHALLENGE PROGRAM a6e
// ONLY IF YOU GET 100 FOR a6 YOU WILL BE TESTED ON a6e

std::map<char, std::string> m;

void print_dictionary(bnode<symbol>* root, std::string s = "") {
	if(!root) {return;}
	
	if(root->left == NULL && root->right==NULL) { m[root->value.value] = s; }
	
	print_dictionary(root->left, s + "0");
    print_dictionary(root->right, s + "1");
}

std::string encode(const std::string& M, bnode<symbol>* root) {
	std::string str="";
	
	print_dictionary(root);
	
	for(int i=0; i<M.length(); ++i) {
		 str += m[M.at(i)];
	}
	
	return str;
}

#endif // ENCODE_HPP
