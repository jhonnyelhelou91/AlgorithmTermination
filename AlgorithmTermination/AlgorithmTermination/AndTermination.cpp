#include "AlgorithmTermination.h"
#include <iostream>
using namespace std;

class AndTermination : public AlgorithmTermination
{
private:
	AlgorithmTermination* first;
	AlgorithmTermination* second;

public:
	AndTermination(AlgorithmTermination* _first, AlgorithmTermination* _second)
	{
		first = _first;
		second = _second;
	}
	~AndTermination()
	{
		delete first;
		delete second;
	}

	bool AddTermination(AlgorithmTermination* termination)
	{
		if (first && second)
			return false;

		if (!first)
			first = termination;
		else
			second = termination;

		return true;
	}

	virtual bool IsTerminated(double fitness) override
	{
#if _DEBUG
#if LOGGING
		cout << "And Termination:" << endl << "(" << endl;
#endif
#endif

		bool is_terminated = first->IsTerminated(fitness);

#if _DEBUG
#if LOGGING
		cout << " AND " << endl;
#endif
#endif

		if (second)
			is_terminated = is_terminated && second->IsTerminated(fitness);

#if _DEBUG
#if LOGGING
		cout << ")" << endl;
#endif
#endif

		return is_terminated;
	}
};