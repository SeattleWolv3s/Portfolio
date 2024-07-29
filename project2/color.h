#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <ctype.h>
using namespace std;

#define RED "\033[41m"     /* Red */
#define GREEN "\033[42m"   /* Green */
#define BLUE "\033[44m"    /* Blue */
#define MAGENTA "\033[45m" /* Magenta */
#define CYAN "\033[46m"    /* Cyan */
#define RESET "\033[0m"

//useless file, planned to add more colors to add player color output to differentiate players, but ultimately just used provided colors only for the map