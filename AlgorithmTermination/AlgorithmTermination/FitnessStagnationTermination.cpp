#include <ctime>
#include<iostream>
using namespace std;

#include "AlgorithmTermination.h"

class FitnessStagnationTermination : public AlgorithmTermination
{
private:
	int iteration_count = 0;
	double threshold;
	int max_iteration_count;

public:

	FitnessStagnationTermination(int max_iteration_count) : max_iteration_count(max_iteration_count)
	{
	}

	virtual bool IsTerminated(double fitness) override
	{
		if (threshold == fitness)
			iteration_count++;
		else
		{
			iteration_count = 1;
			threshold = fitness;
		}

#if LOGGING
#if _DEBUG
		cout << "Fitness Stagnation (" << max_iteration_count << ") - Current Stagnation Count: " << iteration_count << endl;
#else
		cout << "Stagnation: " << iteration_count << "/" << max_iteration_count << endl;
#endif
#endif

		return iteration_count >= max_iteration_count;
	}
};