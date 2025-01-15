//
// Created by grebrune on 1/14/25.
//

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

typedef struct s_cloned{
	AMateria			*save;
	struct s_cloned		*next;
} t_cloned;

class AMateria;

class Character : public ICharacter {
private :
	std::string		_name;
	AMateria*		_inventory[4];
	t_cloned		*_cloned;
public:
	// Constructors & destructor
	Character();
	Character(const std::string& name);
	virtual ~Character();
	// Overloaded operators
	Character &operator=(const Character &src);
	Character(const Character &copy);
	// Public methods
	void	AddCloned(AMateria *tmp);
	void	ClearInventory();
	std::string const &	getName() const ;
	void				equip(AMateria* m) ;
	void				unequip(int idx) ;
	void				use(int idx, ICharacter& target) ;
};

#endif //CHARACTER_HPP