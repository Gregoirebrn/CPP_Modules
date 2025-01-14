//
// Created by grebrune on 1/14/25.
//

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
private :
	std::string*	_name;
	AMateria*		_inventory[4];
public:
	// Constructors & destructor
	Character();
	Character(const std::string& name);
	~Character();
	// Overloaded operators
	Character &operator=(const Character &src);
	Character(const Character &copy);
	// Public methods
	std::string const &	getName() const ;
	void				equip(AMateria* m) ;
	void				unequip(int idx) ;
	void				use(int idx, ICharacter& target) ;
};

#endif //CHARACTER_HPP