//
// Created by grebrune on 1/14/25.
//

#include "MateriaSource.hpp"

// Constructors & destructor
MateriaSource::MateriaSource() {
	_lost = NULL;
	for (int i = 0; i < 4; ++i) {
		_sources[i] = NULL;
	}
	std::cout << "MateriaSource default constructor called!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	_lost = NULL;
	for (int i = 0; i < 4; ++i) {
		if (copy._sources[i] != NULL)
			_sources[i] = copy._sources[i]->clone();
		else
			_sources[i] = NULL;
	}
	std::cout << "MateriaSource copy constructor called!" << std::endl;
}

MateriaSource::~MateriaSource() {
	DelSources();
	while (_lost) {
		AMateria *tmp = _lost->save;
		t_lost_materia *pmt = _lost;
		_lost = _lost->next;
		delete pmt;
		delete tmp;
	}
	std::cout << "MateriaSource default destructor called!" << std::endl;
}

// Overloaded operators
MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
	if (this != &src) {
		DelSources();
		for (int i = 0; i < 4; ++i) {
			if (src._sources[i] != NULL) {
				_sources[i] = src._sources[i]->clone();
			}
		}
	}
	return (*this);
}

// Public methods
void MateriaSource::learnMateria(AMateria *src) {
	for (int i = 0; i < 4; ++i) {
		if (_sources[i] == NULL) {
			_sources[i] = src;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; ++i) {
		if (_sources[i] != NULL && _sources[i]->getType() == type) {
			t_lost_materia *tmp = new t_lost_materia;
			tmp->save = _sources[i]->clone();
			tmp->next = NULL;
			AddLost(tmp);
			return tmp->save;
		}
	}
	return NULL;
}

void MateriaSource::DelSources() {
	for (int i = 0; i < 4; ++i) {
		if (_sources[i] != NULL) {
			delete _sources[i] ;
			_sources[i] = NULL;
		}
	}
}

void	MateriaSource::AddLost(t_lost_materia *tmp) {
	if (!_lost) {
		_lost = tmp;
		return ;
	}
	tmp->next = _lost;
	_lost = tmp;
}

