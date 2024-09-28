
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
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator ite = vec.end();
	int	i = 0;
	for (it = vec.begin(); it != ite; ++it) {
		if (*it == to_find)
			return (std::cout << "Found " << to_find << " in " << i << " place." << std::endl, (void)0);
		i++;
	}
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
