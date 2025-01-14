//
// Created by grebrune on 1/14/25.
//

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private :
public :
	// Constructors & destructor
	MateriaSource();
	~MateriaSource();
	// Overloaded operators
	MateriaSource &operator=(const MateriaSource &src);
	MateriaSource(const MateriaSource &copy);
	// Public methods
	virtual void learnMateria(AMateria*) ;
	virtual AMateria* createMateria(std::string const & type) ;
};

#endif //MATERIASOURCE_HPP