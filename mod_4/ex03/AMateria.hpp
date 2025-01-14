//
// Created by grebrune on 1/14/25.
//

#ifndef CPP_MODULES_AMATERIA_HPP
# define CPP_MODULES_AMATERIA_HPP

# include <iostream>

class AMateria {
private :
public :
	// Constructors & destructor
	AMateria();

	AMateria(const AMateria &copy);

	~AMateria();

	// Overloaded operators
	AMateria &operator=(const AMateria &src);

	// Public methods
};

#endif //CPP_MODULES_AMATERIA_HPP