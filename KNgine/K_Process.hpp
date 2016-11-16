#ifndef __K_PROCESS_HP__
#define __K_PROCESS_HP__

#include <memory>
#include "K_ProcessManager.hpp"

typedef std::shared_ptr<K_Process> StrongProcessPtr;
typedef std::weak_ptr<K_Process> WeakProcessPtr;


class K_Process
{
	friend class K_ProcessManager;
public:

	enum K_ProcessState
	{
		UNINITIALIZED = 0,
		REMOVED,
		RUNNING,
		PAUSED,
		SUCCEDDED,
		FAILED,
		ABORTED
	};


public:
	K_Process();
	virtual ~K_Process();

protected:
	virtual void onInit();
	virtual void onUpdate(unsigned long deltaMS) = 0;
	virtual void onSuccess(void);
	virtual void onFail();
	virtual void onAbort();


public:
	void succeed();
	void fail();

	void pause();
	void unpause();

	K_ProcessState getState() const;
	bool isAlive() const;
	bool isDead() const;
	bool isRemoved() const;
	bool isPaused() const;


	void attachChildProcess(StrongProcessPtr child);
	StrongProcessPtr removeChildProcess();
	StrongProcessPtr inspectChildProcess();

private:

	K_ProcessState		_state;
	StrongProcessPtr	_childProcess;


	void setState(K_ProcessState newState);



};


#endif // __K_PROCESS_HP__
