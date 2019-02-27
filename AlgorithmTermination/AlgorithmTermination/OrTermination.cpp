#include "AlgorithmTermination.h"
#include <iostream>
using namespace std;

class OrTermination : public AlgorithmTermination
{
private:
	AlgorithmTermination* first;
	AlgorithmTermination* second;

public:
	OrTermination(AlgorithmTermination* _first, AlgorithmTermination* _second)
	{
		first = _first;
		second = _second;
	}
	~OrTermination()
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

#if LOGGING
#if _DEBUG
		cout << "Or Termination:" << endl << "(" << endl;
#endif
#endif

		bool is_terminated = first->IsTerminated(fitness);

#if _DEBUG
#if LOGGING
		cout << " Or " << endl;
#endif
#endif

		if (second)
			is_terminated = is_terminated || second->IsTerminated(fitness);

#if _DEBUG
#if LOGGING
		cout << ")" << endl;
#endif
#endif

		return is_terminated;
	}
};