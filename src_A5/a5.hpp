/***
 *  File: a5.hpp
 *  Author: Aniruddha Nandi anandi
 */

#ifndef A5_HPP
#define A5_HPP

#include "token.hpp"
#include<stack>
#include<vector>
#include<iterator>
#include<stdexcept>

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT FUNCTION RPN BELOW
// YOU ARE NOT ALLOWED TO ALTER THE RPN FUNCTION INTERFACE
// INSIDE THE FUNCTION YOU CAN DO WHATEVER YOU LIKE

template <typename Iter> double RPN(Iter first, Iter last) {
  // IMPLEMENT ME!

std::stack<double> eval;

for(std::vector<token>::iterator it = first ; it != last ; ++it) {
	if(it->is_operator()) {
	if(eval.size() < 2) { throw std::runtime_error("too few operands"); }
	double t1 = eval.top();
	eval.pop();
	double t2 = eval.top();
	eval.pop();

	switch(it->as_operator()) {
		case '+': eval.push(t1 + t2); break;
		case '-': eval.push(t2 - t1); break;
		case '*': eval.push(t1 * t2); break;
		case '/': if(t1 != 0) { eval.push(t2 / t1); }
			  else { throw std::runtime_error("division by zero"); }
			  break;
	}
	}

	else if(it->is_operand()) {
	double num = it->as_operand();
	eval.push(num);
	}

}

	if(eval.size()!=1) {
	throw std::runtime_error("too many operands");
	}

	else {
	double res = eval.top();
	eval.pop();
	return res;
	}

} // RPN

#endif // A5_HPP
