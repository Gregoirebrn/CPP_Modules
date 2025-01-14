//
// Created by grebrune on 1/14/25.
//

#include "Ice.hpp"

// Constructors & destructor
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called!" << std::endl;
}

Ice::Ice(const Ice &copy) {
	std::cout << "Ice copy constructor called!" << std::endl;
	*this = copy;
}

Ice::~Ice() {
	std::cout << "Ice default destructor called!" << std::endl;
}

// Overloaded operators
Ice &Ice::operator=(const Ice &src) {
	AMateria::operator=(src);
	return (*this);
}

// Public methods
AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &origin) {
	std::cout << "* shoots an ice bolt at " << origin.getName() << " *" << std::endl;
}
