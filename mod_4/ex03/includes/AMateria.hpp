//
// Created by grebrune on 1/14/25.
//

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter ;

class AMateria {
protected :
	std::string		_type;
public :
	// Constructors & destructor
	AMateria() {}
	AMateria(const std::string& type);
	virtual ~AMateria();
	// Public methods
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif //AMATERIA_HPP