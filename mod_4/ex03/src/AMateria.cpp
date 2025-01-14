//
// Created by grebrune on 1/14/25.
//

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors & destructor
AMateria::AMateria() {
	std::cout << "AMateria default constructor called!" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
	std::cout << "AMateria copy constructor called!" << std::endl;
	*this = copy;
}

AMateria::~AMateria() {
	std::cout << "AMateria default destructor called!" << std::endl;
}

// Overloaded operators
AMateria &AMateria::operator=(const AMateria &src) {
	if (this != &src) {
	}
	return (*this);
}

AMateria::AMateria(const std::string& type) {
	_type = type;
}

// Public methods
std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	std::cout << "AMateria use" << std::endl;
}

