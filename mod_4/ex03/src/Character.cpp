//
// Created by grebrune on 1/14/25.
//

#include "Character.hpp"
#include "AMateria.hpp"

// Constructors & destructor
Character::Character() {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << "Character default constructor called!" << std::endl;
}

Character::Character(const std::string& name) {
	_name = new std::string(name);
	std::cout << "Character second constructor called!" << std::endl;
}

Character::~Character() {
	std::cout << "Character default destructor called!" << std::endl;
}

Character::Character(const Character &copy) {
	std::cout << "Character copy constructor called!" << std::endl;
	*this = Character(*copy._name);
}

// Overloaded operators
Character &Character::operator=(const Character &src) {
	if (this != &src) {
	}
	return (*this);
}

// Public methods
std::string const &	Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	_inventory[idx]->use(target);
}
