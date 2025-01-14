//
// Created by grebrune on 1/14/25.
//

#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "Character.hpp"
# include "AMateria.hpp"

class Cure : public AMateria {
private :
public :
	// Constructors & destructor
	Cure();
	~Cure();
	// Overloaded operators
	Cure &operator=(const Cure &src);
	Cure(const Cure &copy);
	// Public methods
	AMateria* clone() const ; //duplicate the instance
	void	use(ICharacter&);
};

#endif //CURE_HPP