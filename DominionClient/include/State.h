#pragma once

class State
{
public:
	State();
	~State();
	
	virtual void runTextOnly();

	virtual void step();
	virtual void draw();
};
