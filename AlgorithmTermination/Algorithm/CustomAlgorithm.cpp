#pragma once

#include <ctime>
#include "Algorithm.h"
#include "AlgorithmState.h"
using namespace std;

#define MAX_MILLISECOND 60.0

class CustomAlgorithm : public Algorithm {
	virtual double Process() {
		time_t now_time = time(NULL);
		struct tm now;
		localtime_s(&now, &now_time);

		// seconds is between 0 and 60
		double fitness = now.tm_sec / MAX_MILLISECOND;
		return fitness;
	}
};