#include<iostream>
using namespace std;

#include "AlgorithmTermination.h"

class IterationNumberTermination : public AlgorithmTermination
{
private:
	int max_iteration_number;
	int iteration_number = 0;

public:

	IterationNumberTermination(int max_iteration) : max_iteration_number(max_iteration)
	{
	}

	virtual bool IsTerminated(double fitness) override
	{
		iteration_number++;

#if LOGGING
#if _DEBUG
		cout << "Iteration Number (" << max_iteration_number << ") - Current Iteration Number: " << iteration_number << endl;
#else
		cout << "Iteration: " << iteration_number << "/" << max_iteration_number << endl;
#endif
#endif

		return iteration_number >= max_iteration_number;
	}
};