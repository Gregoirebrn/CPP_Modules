
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include "NotFound.hpp"

template < typename T, typename U>
typename T::iterator easyfind(T &vec, T& to_find) {
	typename T::iterator find_or_not;
	std::find(vec.begin(), vec.end(), to_find);
	if (find_or_not != vec.end())
		std::cout << "Find Second Arguemnt" << std::endl;
	else
		throw NotFound();
}

#endif
