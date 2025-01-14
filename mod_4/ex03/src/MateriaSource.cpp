//
// Created by grebrune on 1/14/25.
//

#include "MateriaSource.hpp"

// Constructors & destructor
MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << "MateriaSource copy constructor called!" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource default destructor called!" << std::endl;
}

// Overloaded operators
MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
	}
	return (*this);
}

// Public methods
void MateriaSource::learnMateria(AMateria *) {

}

AMateria *MateriaSource::createMateria(const std::string &type) {
	return NULL;
}

