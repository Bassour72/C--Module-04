#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _idx(0)
{
    for (int i = 0; i < 4; ++i)
        _materia[i] = NULL;

    std::cout << "[MateriaSource] Default constructor called, index initialized to " << _idx << "\n";
}

MateriaSource::MateriaSource(const MateriaSource& other) : _idx(other._idx)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._materia[i])
            _materia[i] = other._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
    std::cout << "[MateriaSource] Copy constructor called, index copied as " << _idx << "\n";
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "[MateriaSource] Copy assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
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
    for (int i = 0; i < 4; ++i)
    {
        if (_materia[i])
            delete _materia[i];
        _materia[i] = NULL;
    }

    std::cout << "[MateriaSource] Destructor called, all materia deleted\n";
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
