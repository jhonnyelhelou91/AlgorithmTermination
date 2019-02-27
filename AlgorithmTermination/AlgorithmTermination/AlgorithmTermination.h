#pragma once
#define LOGGING true;

class AlgorithmTermination
{
public :
	virtual bool IsTerminated(double fitness) = 0;
};