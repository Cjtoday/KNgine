#ifndef __K_KEYS_HPP__
#define __K_KEYS_HPP__

#include <map>

#define K_SUPPORTED_KEY_COUNT 52

#define K_KEY_UNSUPPORTED 0x00

#define K_KEY_0 0x01
#define K_KEY_1 0x02
#define K_KEY_2 0x03
#define K_KEY_3 0x04
#define K_KEY_4 0x05
#define K_KEY_5 0x06
#define K_KEY_6 0x07
#define K_KEY_7 0x08
#define K_KEY_8 0x09
#define K_KEY_9 0x0A

#define K_KEY_A  0x0B
#define K_KEY_B  0x0C
#define K_KEY_C  0x0D
#define K_KEY_D  0x0E
#define K_KEY_E  0x0F
#define K_KEY_F  0x10
#define K_KEY_G  0x11
#define K_KEY_H  0x12
#define K_KEY_I  0x13
#define K_KEY_J  0x14
#define K_KEY_K  0x15
#define K_KEY_L  0x16
#define K_KEY_M  0x17
#define K_KEY_N  0x18
#define K_KEY_O  0x19
#define K_KEY_P  0x1A
#define K_KEY_Q  0x1B
#define K_KEY_R  0x1C
#define K_KEY_S  0x1D
#define K_KEY_T  0x1E
#define K_KEY_U  0x1F
#define K_KEY_V  0x20
#define K_KEY_W  0x21
#define K_KEY_X  0x22
#define K_KEY_Y  0x23
#define	K_KEY_Z  0x24

#define K_KEY_TAB		0x25
#define K_KEY_CAPSLK	0x26
#define K_KEY_LSHIFT	0x27
#define K_KEY_LCTRL		0x28
#define K_KEY_LALT		0x29
#define K_KEY_SPACE		0x2A
#define K_KEY_RALT		0x2B
#define K_KEY_RCTRL		0x2C
#define K_KEY_RSHIFT	0x2D
#define K_KEY_ENTER		0x2E

#define K_KEY_LEFT		0x2F
#define K_KEY_RIGHT		0x30
#define K_KEY_UP		0x31
#define K_KEY_DOWN		0x32

#define K_KEY_ESCAPE	0x33

#define K_KEY_STATE_DOWN	0
#define K_KEY_STATE_UP	1

typedef unsigned int K_KeyCode;
typedef std::map<unsigned long, unsigned long> K_KeyMapping;

class K_Keys
{
public:
	K_Keys();
	~K_Keys();

	void updateKeyState(K_KeyCode keyCode, bool state);
	bool getKeyState(K_KeyCode keyCode);
	
private:

	bool _keyStates[K_SUPPORTED_KEY_COUNT];

};

#endif // __K_KEYS_HPP__
