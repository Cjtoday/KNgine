#ifndef __K_VECTOR_HPP__
#define __K_VECTOR_HPP__



class K_Vector
{
public:
	K_Vector();
	K_Vector(float x, float y, float z);
	K_Vector(float x, float y, float z, float w);
	~K_Vector();


private:

	float _x;
	float _y;
	float _z;
	float _w;

};


#endif // __K_VECTOR_HPP__
