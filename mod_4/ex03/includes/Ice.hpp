//
// Created by grebrune on 1/14/25.
//

#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "Character.hpp"
# include "AMateria.hpp"

class Ice : public AMateria {
private :
public :
	// Constructors & destructor
	Ice();

	Ice(const Ice &copy);

	~Ice();

	// Overloaded operators
	Ice &operator=(const Ice &src);

	// Public methods
	AMateria*	clone() const ; //duplicate the instance
	void		use(ICharacter&);
};

#endif //ICE_HPP