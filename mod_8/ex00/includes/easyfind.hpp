
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NotFound : public std::exception {
public:
	virtual const char* what() const throw() {
		return ("No occurrence found!");
	}
};

template < typename T>
void find_or_not(const std::vector<T> &vec, const T& to_find) {
	typename std::vector<T>::const_iterator value_found = std::find(vec.begin(), vec.end(), to_find);

	if (value_found != vec.end())
		return (std::cout << "Value found " << to_find << std::endl, (void)0);
	throw NotFound();
}

#endif
//
//	T & operator[](unsigned int n) const {
//		if (_n < n)
//			throw ;
//		return (_array[n]);
//	}
//
//	EasyFind & operator = (const EasyFind &rhs) {
//		if (this == &rhs)
//			return *this;
//		if (this->_n != rhs._n) {
//			delete this->_array;
//			this->_array = EasyFind(rhs._n);
//		}
//		for (unsigned int i = 0; i < this->_n; ++i) {
//			this->_array[i] = rhs._array[i];
//		}
//		return *this;
//	}
