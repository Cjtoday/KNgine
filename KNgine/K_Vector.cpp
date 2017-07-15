#include "K_Vector.hpp"

K_Vector::K_Vector() : _x(0), _y(0), _z(0), _w(1)
{
}

K_Vector::K_Vector(float x, float y, float z) : _x(x), _y(y), _z(z), _w(1)
{
}

K_Vector::K_Vector(float x, float y, float z, float w): _x(x), _y(y), _z(z), _w(w)
{
}


K_Vector::~K_Vector()
{
}
