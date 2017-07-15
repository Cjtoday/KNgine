#ifndef __K_PROCESS_HPP__
#define __K_PROCESS_HPP__

#include <memory>

enum K_ProcessState {
	uninitilized,
	running,
	successful,
	aborted,
	failed
};


class K_Process
{
public:
	K_Process() :_state(uninitilized), _isStopped(false) {};
	virtual ~K_Process() {};

	virtual void update(double deltaT) = 0;
	virtual void initilize() = 0;

	const K_ProcessState getProcessState()
	{
		return _state;
	}

	const bool isStopped()
	{
		return _isStopped;
	}

protected:
	K_ProcessState _state;
	bool _isStopped;
};


typedef std::weak_ptr<K_Process> K_WeakProcessPtr;
typedef std::shared_ptr<K_Process> K_ProcessPtr;


#endif // __K_PROCESS_HPP__
