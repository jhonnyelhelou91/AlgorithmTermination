#pragma once

#include <iostream>
#include "Algorithm.h"
#include "AlgorithmState.h"
using namespace std;

Algorithm::Algorithm() :
	_best_fitness(0),
	_fitness(0),
	_current_iteration(0)
{
	_state = AlgorithmState::STOPPED;
}

// Frees used resources
Algorithm::~Algorithm()
{
}

void Algorithm::Start()
{
	// do not run already running algorithm
	if (_state == AlgorithmState::RUNNING)
		return;

	_state = AlgorithmState::RUNNING;

	while (1)
	{
		_current_iteration++;

		if (_state != AlgorithmState::RUNNING)
		{
			break;
		}

		_fitness = Process();
		if (_fitness >= _best_fitness)
			_best_fitness = _fitness;

		//algorithm has reached preference
		if (_termination->IsTerminated(_best_fitness))
		{
			_state = AlgorithmState::CRITERIA_STOPPED;
			break;
		}
	}
}

// Stops execution of algoruthm
void Algorithm::Stop()
{
	if (_state == AlgorithmState::RUNNING)
		_state = AlgorithmState::STOPPED;
}