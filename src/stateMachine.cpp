#include "stateMachine.h"
#include "MainMenu.hpp"
stateMachine::stateMachine() : _add(0), _replace(0), _remove(0)
{
}
stateMachine::~stateMachine()
{
	while (!stackState.empty())
	{
		state *top = stackState.top();
		delete top;
		top = nullptr;
		stackState.pop();
	}
}
void stateMachine::addState(state *state, bool replace)
{
	_add = 1;
	_replace = replace;
	newState = state;
}
void stateMachine::removeState(bool reinittheprevstate)
{
	_remove = 1;
	_reinit = reinittheprevstate;
}

void stateMachine::removeStateUntilOne()
{
	_removeUntilOne = true;
}

int stateMachine::sizeState()
{
	return stackState.size();
}

void stateMachine::processStateChange()
{
	if (_removeUntilOne)
	{
		_removeUntilOne = false;
		while (stackState.size() > 1)
		{
			state *top = stackState.top();
			delete top;
			stackState.pop();
		}
		stackState.top()->init();
		return;
	}
	if (_remove && !stackState.empty())
	{
		state *top = stackState.top();
		delete top;
		stackState.pop();
		// stackState.top()->init();
		if (_reinit)
			stackState.top()->init();

		_remove = 0;
	}
	if (_add)
	{
		if (!stackState.empty())
		{
			if (_replace)
			{
				state *top = stackState.top();
				delete top;
				stackState.pop();
			}
		}
		stackState.push(newState);
		stackState.top()->init();
		_add = 0;
	}
}
state *&stateMachine::getCurrentState()
{
	return stackState.top();
}

void stateMachine::removeAll()
{
	while (!stackState.empty())
	{
		state *top = stackState.top();
		delete top;
		top = nullptr;
		stackState.pop();
	}
}