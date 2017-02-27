/***
 *  File: a2.hpp
 *  Author: Aniruddha Nandi anandi
 */

#ifndef A2_HPP
#define A2_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF sorted_sc_array IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS EXCEPT OF <algorithm>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION AS PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>


class sorted_sc_array {
public:
    sorted_sc_array() : size_(0), ptr_(nullptr), arr_len(4294967295) { 
	ptr_ = new signed char[arr_len];
	}

    ~sorted_sc_array() { delete[] ptr_; }

    // IMPLEMENT ME (DONE!!!!)
    sorted_sc_array(const sorted_sc_array& A) : size_(A.size_), arr_len(4294967295) {
          if (size_ == 0) ptr_ = nullptr;
          else {
              ptr_ = new signed char[size_];
              std::copy(A.ptr_, A.ptr_ + size_, ptr_);
          }
	}

    // IMPLEMENT  ME (DONE!!!!)
    sorted_sc_array& operator=(const sorted_sc_array& A) {
        if (this == &A) return *this;
        delete[] ptr_;
        size_ = A.size_;
        if (size_ == 0) ptr_ = nullptr;
        else {
            ptr_ = new signed char[size_];
            std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        }
        return *this;
	}

    // RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
    int size() const { return size_; }

    // RETURNS RAW POINTER TO THE ACTUAL DATA, CAN BE INVOKED AT ANY TIME
    const signed char* data() const { 
	std::sort(ptr_, ptr_ + size_);
	return ptr_; 
	}
 
    // IMPLEMENT ME: AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER (TBD!!!)
    void insert(signed char c) { 
		if (size_ < arr_len) {
			ptr_[size_++] = c;
		}

		else {
			signed char *ptr_new = new signed char[arr_len = arr_len*2];
			std::copy(ptr_, ptr_ + size_, ptr_new);
			delete[] ptr_;
			ptr_ = ptr_new;
			ptr_[size_++] = c; 
		}
		
		// maybe use std::sort (myvector.begin(), myvector.end());
		// if inefficient, use binary insertion
	}


private:
    int size_;         // size of the array
    signed char* ptr_; // pointer to the array
	unsigned int arr_len; // dynamic mem alloc for array
	
}; // class sorted_sc_array

#endif // A2_HPP
