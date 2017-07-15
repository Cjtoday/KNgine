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

struct K_Normal
{
	float _x;
	float _y;
	float _z;
};


struct K_Vertex
{
	K_Position	_position;
	K_Color		_color;
	K_UV		_uv;
	K_Normal    _normal;

	void setUV(float u, float v)
	{
		_uv._u = u;
		_uv._v = v;
	}
};


#endif // __K_VERTEX_HPP__
