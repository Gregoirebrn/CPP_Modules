//
// Created by grebrune on 1/14/25.
//

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
#include "IMateriaSource.hpp"

typedef struct s_lost_materia{
	AMateria				*save;
	struct s_lost_materia	*next;
} t_lost_materia;

class MateriaSource : public IMateriaSource {
private :
	AMateria*		_sources[4];
	t_lost_materia	*_lost;
public :
	// Constructors & destructor
	MateriaSource();
	~MateriaSource();
	// Overloaded operators
	MateriaSource &operator=(const MateriaSource &src);
	MateriaSource(const MateriaSource &copy);
	// Public methods
	void		AddLost(t_lost_materia *tmp);
	void		DelSources();
	void		learnMateria(AMateria*) ;
	AMateria*	createMateria(std::string const & type) ;
};

#endif //MATERIASOURCE_HPP