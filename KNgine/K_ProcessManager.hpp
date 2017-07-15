#ifndef __K_PROCESSMANAGER_HPP__
#define __K_PROCESSMANAGER_HPP__

#include "K_Process.hpp"

#include <vector>

class K_ProcessManager
{
public:
	K_ProcessManager();
	~K_ProcessManager();

	K_WeakProcessPtr addProcess(K_ProcessPtr process);
	void tick(double deltaT);

private:
	std::vector<K_ProcessPtr> _processes;
};


#endif // __K_PROCESSMANAGER_HPP__
