#include "stateMachine.h"
#include <iostream>

stateMachine::stateMachine() : _add(0), _replace(0), _remove(0)
{
}
stateMachine::~stateMachine()
{
	removeAllState();
}
void stateMachine::addState(state *state, bool replace)
{
	_add = 1;
	_replace = replace;
	newState = state;

	std::cerr << "in addState\n";
}
void stateMachine::removeState(bool reinittheprevstate)
{
	_remove = 1;
	_reinit = reinittheprevstate;
}

void stateMachine::removeAllState()
{
	while (!stackState.empty())
	{
		state *top = stackState.top();
		delete top;
		// top = nullptr;
		stackState.pop();
	}
}

void stateMachine::removeStateUntilOne()
{
	while (stackState.size() > 1)
	{
		state *top = stackState.top();
		delete top;
		stackState.pop();
	}
	// stackState.top()->init();

	std::cerr << "in removeStateUntilOne\n";
}

int stateMachine::sizeState()
{
	return stackState.size();
}

void stateMachine::processStateChange()
{
	std::cerr << "in processStateChange\n";

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
		std::cerr << "in processStateChange add\n";
		if (!stackState.empty())
		{
			if (_replace)
			{
				std::cerr << "in processStateChange replace\n";
				state *top = stackState.top();
				delete top;
				stackState.pop();
			}
		}
		_add = 0;
		stackState.push(newState);

		std::cerr << "in processStateChange push newstate\n";
		stackState.top()->init();
		std::cerr << "in processStateChange init newstate\n";
	}
}
state *&stateMachine::getCurrentState()
{
	return stackState.top();
}