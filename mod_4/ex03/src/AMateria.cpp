//
// Created by grebrune on 1/14/25.
//

#include "AMateria.hpp"
#include "ICharacter.hpp"

// Constructors & destructor
AMateria::~AMateria() {
	std::cout << "AMateria default destructor called!" << std::endl;
}

AMateria::AMateria(const std::string& type) {
	_type = type;
}

// Public methods
std::string const &AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "AMateria Should Not Print" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src) {
	if (this != &src)
		_type = src._type;
	return (*this);
}

