//
// Created by grebrune on 1/14/25.
//

#include "AMateria.hpp"

// Constructors & destructor
AMateria::AMateria(void)
{
	std::cout << "AMateria default constructor called!" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "AMateria copy constructor called!" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria default destructor called!" << std::endl;
}

// Overloaded operators
AMateria &AMateria::operator=(const AMateria &src)
{
	if (this != &src) {
	}
	return (*this);
}

// Public methods