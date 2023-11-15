#include "stateMachine.h"
stateMachine::stateMachine() : _add(0), _replace(0), _remove(0)
{
}
stateMachine::~stateMachine()
{
}
void stateMachine::addState(state *state, bool replace)
{
	_add = 1;
	_replace = replace;
	newState = state;
}
void stateMachine::removeState()
{
	_remove = 1;
}

void stateMachine::removeStateUntilOne()
{
	while (stackState.size() > 1)
	{
		state *top = stackState.top();
		delete top;
		stackState.pop();
	}
	stackState.top()->init();
}

int stateMachine::sizeState()
{
	return stackState.size();
}

void stateMachine::processStateChange()
{
	if (_remove && !stackState.empty())
	{
		state *top = stackState.top();
		delete top;
		stackState.pop();
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