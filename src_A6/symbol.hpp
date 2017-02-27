/***
 *  $Id$
 **
 *  File: symbol.hpp
 *  Created: Apr 17, 2015
 *
 *  Author: Jaroslaw Zola <jzola@buffalo.edu>
 *  Copyright (c) 2015 Jaroslaw Zola
 */

#ifndef SYMBOL_HPP
#define SYMBOL_HPP

struct symbol {
    explicit symbol(char av = 0, int ac = 0) : value(av), count(ac) { }
    char value; // actual symbol, by default 0 (empty)
    int count;  // count of the symbol, by default 0
}; // symbol

// compare two symbols
// symbol with a lower count is "less than" symbol with a higher count
// symbols with equal count are compare lexicographically
inline bool operator<(const symbol& lhs, const symbol& rhs) {
    return ((lhs.count < rhs.count) || (!(rhs.count < lhs.count) && (lhs.value < rhs.value)));
} // operator<

template <typename T> struct bnode {
    explicit bnode(const T& t = T(), bnode* l = nullptr, bnode* r = nullptr)
        : value(t), left(l), right(r) { }

    T value;      // payload

    bnode* left;  // left child
    bnode* right; // right child
}; // struct bnode

#endif // SYMBOL_HPP
