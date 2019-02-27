#pragma once
#include "AlgorithmState.h"
#include "..\AlgorithmTermination\AlgorithmTermination.h"

class Algorithm
{

private:
	AlgorithmTermination* _termination;
	
	AlgorithmState _state;

	double _fitness;
	double _best_fitness;

	int _current_iteration;

public:
	Algorithm();
	virtual ~Algorithm();

	inline const Algorithm& SetTermination(AlgorithmTermination* _termination) {
		(*this)._termination = _termination;

		return *this;
	}

	void Start();
	virtual double Process() = 0;
	void Stop();

	inline int GetCurrentIteration() const { return _current_iteration; }
	inline double GetBestFitness() const { return _best_fitness; }
	inline AlgorithmTermination* GetTermination() const { return _termination; }
	inline AlgorithmState GetState() const { return _state; }
};