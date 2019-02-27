# Algorithm Termination

This library exposes termination operations that you can use to customize when to stop a long running process/algorithm.

## Getting Started

* Copy the files <br />`git clone 'https://github.com/jhonnyelhelou91/AlgorithmTermination.git' 'C:\git\C++\AlgorithmTermination'`
* Open the solution <br />`C:\git\C++\AlgorithmTermination\AlgorithmTermination.sln`
* Build solution <br />`Ctrl + Shift + B`

### Prerequisites

* Visual Studio
* Microsoft C++ Redistributable

## Running the tests

For the tests, you will find a simple algorithm that returns the current seconds divided by 60 as the fitness of the algorithm. The tests should cover most of the termination algorithms
as well as provide some examples on how it works.
<br />
To run the tests, you need the following:
* Build solution <br />`Ctrl + Shift + B`
* Open Test Explorer from Visual Studio `Ctrl + Q` then type `Test Explorer` and hit `Enter`
* Run All tests

## Definitions
Below are the details regarding all the classes and headers defined within the code.

### AlgorithmState.h
Enum to list the state of an algorithm `STOPPED`, `CRITERIA_STOPPED`, `RUNNING`. Later on, you can add the states that you think are useful to you (PAUSED, USER_STOPPED...)

### AlgorithmTermination.h
Defines the abstract class of a termination.
Currently, the following terminations are implemented but you can add any custom terminations:
* _FitnessStagnationTermination_ <br />
Terminates when the fitness stagnates (does not change) for the specified consecutive iterations.
* _FitnessThresholdTermination_ <br />
Terminates when the desired threshold is met.
* _IterationNumberTermination_ <br />
Terminates after the desired number of iterations.
* _TimeLimitTermination_ <br />
Terminates after the specified time limit is met.
* _AndTermination_ <br />
Terminates when both terminations are met. Allows chaining of any of the terminations implemented (AndTermination, OrTermination included).
* _OrTermination_ <br />
Terminates when any of the terminations are met. Allows chaining of any of the terminations implemented (AndTermination, OrTermination included).
Helpful but unimplemented examples of algorithm termination might be:
* _RAMLimitTermination_ <br />
Terminates when the specified RAM is met.
* _ThreadLimitTermination_ <br />
Terminates when the specified thread count is met.

### Algorithm.h
Defines the abstract class of an algorithm as well as the base methods that check whether the termination criteria is met. When implementing your custom algorithm, the process method
has to be implemented where it returns the fitness of the current iteration. In case the algorithm does not have a fitness method, you can return a constant value 0 or -1 or...
However, note that this won't work when using FitnessStagnationTermination or FitnessThresholdTermination.

- - - -

## Useful Examples
* Time limit reached or stagnates 1000 iterations after 70%
`new OrTermination(<br />
	//Stop after 1 hour <br />
	new TimeLimitTermination(3600), <br />
	//Or <br />
	new AndTermination( <br />
		// fitness is above 70% <br />
		new FitnessThresholdTermination(0.7), <br />
		// And <br />
		//Fitness remains the same for consecutive 1000 iterations <br />
		new FitnessStagnationTermination(1000) <br />
	)<br />
)`

* Threshold at 100% or stagnates 100 times after 1500 iterations
`new OrTermination( <br />
	//Threshold at 100% <br />
	new FitnessThresholdTermination(1), <br />
	//Or <br />
	new AndTermination( <br />
		// Terminate after 1500 iterations <br />
		new IterationNumberTermination(1500), <br />
		// And <br />
		//Fitness remains the same for consecutive 100 iterations <br />
		new FitnessStagnationTermination(100) <br />
	) <br />
)`

## Additional Work
You can also include a json/csv/xml or any other parser to separate the termination configuration from your algorithm logic.
