#include <iostream>
#include <string>
#include <fstream>
#include "Galaxy.h"
using namespace std;

    Galaxy :: Galaxy()
    {
        _name = "";
        _current_planets = 0;
    }
    
    Galaxy :: Galaxy(string named)
    {
        _name = named;
        _current_planets = 0;
    }

    Galaxy :: Galaxy(string named, int radii[], int planet_count)
    {
        _name = named;
        if (planet_count <= _max_size)
        {
        _current_planets = planet_count;
        for (int i = 0; i < planet_count; i++)
        {
            _radii[i] = radii[i];
        }
        for (int i = planet_count; i < _max_size; i++)
        {
            _radii[i] = 0;
        }
        }
        else 
        {
            _current_planets = _max_size;
            for (int i = 0; i < _max_size; i++)
            {
            _radii[i] = radii[i];
            }
        }
    }

    string const Galaxy :: getName()
    {
        return _name;
    }

    int const Galaxy :: getCurrentSize()
    {
        return _current_planets;
    }

    void Galaxy :: setName(string name)
    {
        _name = name;
    }

    int const Galaxy :: getRadius(int planet)
    {
        if (planet >= 0 && planet < _current_planets)
        {
        return _radii[planet];
        }
        else 
        {
            return -1;
        }
    }

    bool Galaxy :: addRadius(int radius)
    {
        if (radius > 0)
        {
            if (_current_planets < _max_size)
            {
                _radii[_current_planets] = radius;
                _current_planets = _current_planets + 1;
                return true;
            }
            else 
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }

    double Galaxy :: getAverageRadius()
    {
        double counter = 0;
        double sum = 0;
        for (int i = 0; i < _max_size; i++)
        {
            sum = sum + _radii[i];
            if (_radii[i] != 0)
            {
                counter = counter + 1;
            }
        }
        double average = (sum / counter);
        return average;
    }

