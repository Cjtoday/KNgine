#ifndef __K_VERTEX_HPP__
#define __K_VERTEX_HPP__



struct K_Position
{
	float _x;
	float _y;
	float _z;
};


struct K_Color
{
	unsigned char _r;
	unsigned char _g;
	unsigned char _b;
	unsigned char _a;
};


struct K_UV
{
	float _u;
	float _v;
};


struct K_Vertex
{
	K_Position	_position;
	K_Color		_color;
	K_UV		_uv;
};


#endif // __K_VERTEX_HPP__
