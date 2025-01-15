//
// Created by grebrune on 1/14/25.
//

#include "Cure.hpp"

// Constructors & destructor
Cure::Cure() : AMateria("cure"){
	std::cout << "Cure default constructor called!" << std::endl;
}

Cure::Cure(const Cure &copy) {
	std::cout << "Cure copy constructor called!" << std::endl;
	*this = copy;
}

Cure::~Cure() {
	std::cout << "Cure default destructor called!" << std::endl;
}

// Overloaded operators
Cure &Cure::operator=(const Cure &src) {
	AMateria::operator=(src);
	return (*this);
}

// Public methods
void Cure::use(ICharacter &origin) {
	std::cout << "* heals " << origin.getName() << "'s wounds *" << std::endl;
}

AMateria *Cure::clone() const {
	return new Cure(*this);
}
