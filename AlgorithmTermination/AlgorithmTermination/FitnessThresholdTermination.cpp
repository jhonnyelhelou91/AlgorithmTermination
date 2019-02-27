#include <iostream>
#include <ctime>
using namespace std;

#include "AlgorithmTermination.h"

class FitnessThresholdTermination : public AlgorithmTermination
{
private:
	double threshold;

public:

	FitnessThresholdTermination(double threshold) : threshold(threshold)
	{
	}

	virtual bool IsTerminated(double fitness) override
	{
#if LOGGING
#if _DEBUG
		cout << "Fitness Threshold (" << threshold << ") - Current Fitness: " << fitness << endl;
#else
		cout << "Threshold: " << fitness << "/" << threshold << endl;
#endif
#endif

		return fitness >= threshold;
	}
};