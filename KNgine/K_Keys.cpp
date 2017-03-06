#include "K_Keys.hpp"
#include "K_Error.hpp"

K_Keys::K_Keys() 
{
	for (int i = 0; i < K_SUPPORTED_KEY_COUNT; ++i)
	{
		_keyStates[i] = false;
	}
}

K_Keys::~K_Keys()
{
}

void K_Keys::updateKeyState(K_KeyCode keyCode, bool state)
{
	if (keyCode > K_SUPPORTED_KEY_COUNT)
	{
		K_Error unsupportedKeyError("Unsupported Key Error", std::to_string(keyCode));
		K_Error::dump();
	}
	_keyStates[keyCode] = state;
}

bool K_Keys::getKeyState(K_KeyCode keyCode)
{
	if (keyCode > K_SUPPORTED_KEY_COUNT)
	{
		K_Error unsupportedKeyError("Unsupported Key Error", std::to_string(keyCode));
		K_Error::dump();
	}
	return _keyStates[keyCode];
}
