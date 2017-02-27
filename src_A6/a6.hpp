/***
 *  File: a6.hpp
 *  Author: Aniruddha Nandi anandi
 */

#ifndef A6_HPP
#define A6_HPP

#include <iostream>
#include "symbol.hpp"
#include <queue>
#include <vector>
typedef bnode<symbol> ht_node;

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT ALL REQUIRED FUNCTIONS BELOW
// YOU ARE NOT ALLOWED TO ALTER ANY INTERFACE
// INSIDE A FUNCTION YOU CAN DO WHATEVER YOU LIKE

// IMPLEMENT YOUR FUNCTION huffman_tree

struct CompareKeys {
    bool operator() (ht_node* lhs, ht_node* rhs) {
        return rhs->value < lhs->value;
    }
};

template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last) {
	
	std::priority_queue<ht_node*, std::vector<ht_node*>, CompareKeys> pq;
    for (; first != last; ++first) { pq.push(new ht_node(*first)); }
 
    while (pq.size() > 1)
    {
        ht_node* left = pq.top();
        pq.pop();
 
        ht_node* right = pq.top();
        pq.pop();
 
		char val;
		if(left->value.value < right->value.value) { val = left->value.value; }
		else { val = right->value.value; }
        symbol* sym = new symbol(val, left->value.count + right->value.count);
		
		ht_node* res = new ht_node(*sym, left, right);
		pq.push(res);
		delete sym;
    }
 
    return pq.top();	
}

// IMPLEMENT YOUR FUNCTION print_dictionary
void print_dictionary(std::ostream& os, bnode<symbol>* root, std::string s = "") {
	
	if(!root) {return;}
	
	if(root->left == NULL && root->right==NULL) { os << root->value.value << " " << s << "\n"; }
	
	print_dictionary(os, root->left, s + "0");
    print_dictionary(os, root->right, s + "1");
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root) {
	if (root == NULL) return;

	release_tree(root->left);
	release_tree(root->right);
   
	delete root;
}

#endif // A5_HPP
