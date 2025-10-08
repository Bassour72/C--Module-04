#include "MateriaSource.hpp"


MateriaSource::MateriaSource() : _idx(0)
{
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _idx(other._idx)
{
    for (int i = 0; i < 4; i++)
    {
        if (other._materia[i])
            _materia[i] = other._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (_materia[i])
            {
                delete _materia[i];
                _materia[i] = NULL;
            }
            if (other._materia[i])
                _materia[i] = other._materia[i]->clone();
            else
                _materia[i] = NULL;
        }
        _idx = other._idx;
    }
    return *this;
}


MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (_materia[i])
            delete _materia[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m || _idx >= 4)
        return;

    _materia[_idx] = m;
    _idx++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    return NULL;
}
