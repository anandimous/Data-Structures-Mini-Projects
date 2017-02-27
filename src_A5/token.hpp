/***
 *  File: token.hpp
 *  Author: Jaroslaw Zola <jzola@buffalo.edu>
 */

// DO NOT EDIT THIS FILE !!!
// YOUR CODE MUST BE CONTAINED IN a5.hpp ONLY

#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <sstream>
#include <stdexcept>
#include <string>


class token {
public:
    /** Construct undefined token.
     */
    token() : tag(UNDEF) { }

    /** Construct operator token.
     */
    explicit token(char c) : tag(OPER), oper(c) { }

    /** Construct operand token.
     */
    explicit token(double d) : tag(ARG), arg(d) { }

    /** Return true if the token is operator.
     */
    bool is_operator() const { return (tag == OPER); }

    /** Return true if the token is operand.
     */
    bool is_operand() const { return (tag == ARG); }

    /** Return operator represented by the token.
     */
    char as_operator() const { return oper; }

    /** Return operand represented by the token.
     */
    double as_operand() const { return arg; }

private:
    enum { OPER, ARG, UNDEF} tag;

    union {
        char oper;
        double arg;
    };

}; // class token


/** Convert string to a token.
 */
inline token to_token(const std::string& s) {
    std::istringstream is(s);
    double x;
    if (!(is >> x)) {
        if (s.size() != 1) throw std::runtime_error("incorrect token");
        if ((s[0] != '+') && (s[0] != '-') && (s[0] != '*') && (s[0] != '/')) throw std::runtime_error("incorrect token");
        return token(s[0]);
    }
    return token(x);
} // to_token

#endif // TOKEN_HPP
