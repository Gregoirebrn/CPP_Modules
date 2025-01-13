
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T >
void	funk(T c)
{
	c = 9;
}

template < typename T , typename U , typename F>
void	iter(T array[], U len_array, F (*f)(T&)) {
	for (U i = 0;  i < len_array ; ++i) {
		f(array[i]);
	}
}

template < typename T , typename U , typename F>
void	iter(T array[], U len_array, F (*f)(const T&)) {
	for (U i = 0; i < len_array; ++i) {
		f(array[i]);
	}
}


#endif
