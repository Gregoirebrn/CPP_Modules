//
// Created by grebrune on 1/14/25.
//

#include "Character.hpp"
#include "AMateria.hpp"

// Constructors & destructor
Character::Character() : _name("default") {
	_cloned = NULL;
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << "Character default constructor called!" << std::endl;
}

Character::Character(const std::string& name) : _name(name){
	_cloned = NULL;
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
	std::cout << "Character second constructor called!" << std::endl;
}

Character::~Character() {
	ClearInventory();
	while (_cloned) {
		AMateria *tmp = _cloned->save;
		t_cloned *pmt = _cloned;
		_cloned = _cloned->next;
		delete pmt;
		delete tmp;
	}
	std::cout << "Character default destructor called!" << std::endl;
}

Character::Character(const Character &copy) : _name(copy._name) {
	for (int i = 0; i < 4; ++i) {
		if (copy._inventory[i] != NULL)
			_inventory[i] = copy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character copy constructor called!" << std::endl;
}

// Overloaded operators
Character &Character::operator=(const Character &src) {
	if (this != &src) {
		ClearInventory();
		for (int i = 0; i < 4; ++i) {
			if (src._inventory[i] != NULL)
				_inventory[i] = src._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

// Public methods
void	Character::ClearInventory() {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
		_inventory[i] = NULL;
	}
}

std::string const &	Character::getName() const {
	return _name;
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m->clone();
			break;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3) {
		if (_inventory[idx])
			AddCloned(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

void	Character::AddCloned(AMateria *clone) {
	t_cloned	*tmp = new t_cloned;
	tmp->save = clone;
	tmp->next = NULL;
	if (!_cloned) {
		_cloned = tmp;
		return ;
	}
	tmp->next = _cloned;
	_cloned = tmp;
}
