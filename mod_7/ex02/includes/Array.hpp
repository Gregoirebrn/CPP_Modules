
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename T> class Array {
private:
	T *_array;
	unsigned int _n;
public:
	Array() : _array(NULL), _n(0) {};

	Array(unsigned int n) : _array(new T[n]) , _n(n){};

	unsigned int size() const {return _n; };

	T & operator[](unsigned int n) const {
		if (_n < n)
			throw ;
		return (_array[n]);
	}

	Array & operator = (const Array &rhs) {
		if (this == &rhs)
			return *this;
		if (this->_n != rhs._n) {
			delete this->_array;
			this->_array = Array(rhs._n);
		}
		for (unsigned int i = 0; i < this->_n; ++i) {
			this->_array[i] = rhs._array[i];
		}
		return *this;
	}
	class OutBond : public std::exception {
	public:
		virtual const char* what() const throw() {
			return (this->_n);
		}
	};
};

#endif
