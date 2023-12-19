#pragma once
#include "state.h"
#include <stack>
class stateMachine
{
private:
	std::stack<state *> stackState;
	state *newState;
	bool _replace;
	bool _add;
	bool _reinit = true;
	bool _remove;
	bool _removeUntilOne = false;

public:
	stateMachine();
	virtual ~stateMachine();
	void addState(state *state, bool replace = 0);
	void removeState(bool reinittheprevstate = 1);
	void processStateChange();
	state *&getCurrentState();

	void removeStateUntilOne();
	int sizeState();
	void removeAll();
};
