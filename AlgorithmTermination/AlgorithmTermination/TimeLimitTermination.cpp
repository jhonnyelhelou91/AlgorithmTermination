#include <ctime>
#include <string>
#include<iostream>
using namespace std;

#include "AlgorithmTermination.h"

class TimeLimitTermination : public AlgorithmTermination
{
private:
	clock_t start_time;
	double interval_ms;
	string interval_str;
	inline static const string Interval_str(double interval)
	{
		string res = "";
		if (interval >= 60000)
		{
			res += to_string((int)(interval / 60000));
			res += " minute(s) ";
		}

		if (interval >= 1000)
		{
			res += to_string((int)(interval / 1000) % 60);
			res += " second(s) ";
		}

		res += to_string((int)interval % 1000);
		res += " millisecond(s)";

		return res;
	}

public:

	TimeLimitTermination(double interval_ms) : interval_ms(interval_ms), interval_str(Interval_str(interval_ms))
	{
		start_time = clock();
	}

	virtual bool IsTerminated(double fitness) override
	{
		double diff = clock() - start_time;

#if LOGGING
#if _DEBUG
		cout << "Time Limit Generation (" << interval_str << " ) - Current Time: "
			<< Interval_str(diff) << endl;
#else
		cout << "Time: " << Interval_str(diff) << "/" << interval_str << endl;
#endif
#endif

		return diff >= interval_ms;
	}
};