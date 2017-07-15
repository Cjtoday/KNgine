#include "K_ProcessManager.hpp"

K_ProcessManager::K_ProcessManager() : _processes()
{
}

K_ProcessManager::~K_ProcessManager()
{
}

K_WeakProcessPtr K_ProcessManager::addProcess(K_ProcessPtr process)
{
	// Add a process to our process list and return a weak_ptr
	_processes.push_back(process);
	return K_WeakProcessPtr(process);
}

void K_ProcessManager::tick(double deltaT)
{
	for (const auto& process : _processes)
	{
		switch (process->getProcessState())
		{
		case uninitilized:
			process->initilize();
			break;
		case  running:
			process->update(deltaT);
			break;
		}
		if (process->isStopped())
		{
			switch (process->getProcessState())
			{
			case successful:
				break;
			case aborted:
				break;
			case failed:
				break;
			}
		}
	}
}