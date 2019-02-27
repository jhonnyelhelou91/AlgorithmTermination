#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\AlgorithmTermination\AlgorithmTermination\AlgorithmTermination.h"
#include "..\AlgorithmTermination\Algorithm\Algorithm.h"
#include "..\AlgorithmTermination\Algorithm\CustomAlgorithm.cpp"
#include "..\AlgorithmTermination\AlgorithmTermination\AndTermination.cpp"
#include "..\AlgorithmTermination\AlgorithmTermination\FitnessStagnationTermination.cpp"
#include "..\AlgorithmTermination\AlgorithmTermination\FitnessThresholdTermination.cpp"
#include "..\AlgorithmTermination\AlgorithmTermination\IterationNumberTermination.cpp"
#include "..\AlgorithmTermination\AlgorithmTermination\OrTermination.cpp"
#include "..\AlgorithmTermination\AlgorithmTermination\TimeLimitTermination.cpp"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AlgorithmTerimnationUnitTest
{		
	TEST_CLASS(CustomAlgorithmTest)
	{
	public:
		
		TEST_METHOD(FitnessThresholdTermination_Process_ValidTermination)
		{
			double expected = 0.2;
			CustomAlgorithm algorithm;
			algorithm.SetTermination(new FitnessThresholdTermination(expected));
			algorithm.Start();

			Assert::IsTrue(algorithm.GetState() == AlgorithmState::CRITERIA_STOPPED, L"State is invalid");
			Assert::IsTrue(algorithm.GetBestFitness() >= expected, L"Fitness is invalid");
		}

		TEST_METHOD(IterationNumberTermination_Process_ValidTermination)
		{
			int expected = 1;
			CustomAlgorithm algorithm;
			algorithm.SetTermination(new IterationNumberTermination(expected));
			algorithm.Start();

			Assert::IsTrue(algorithm.GetState() == AlgorithmState::CRITERIA_STOPPED, L"State is invalid");
			Assert::AreEqual(algorithm.GetCurrentIteration(), expected, L"Current Iteration is invalid");
		}

		TEST_METHOD(TimeLimitTermination_Process_ValidTermination)
		{
			int expected = 1;
			CustomAlgorithm algorithm;
			algorithm.SetTermination(new TimeLimitTermination(expected * 1000.0));
			algorithm.Start();

			Assert::IsTrue(algorithm.GetState() == AlgorithmState::CRITERIA_STOPPED, L"State is invalid");
		}

		TEST_METHOD(FitnessStagnationTermination_Process_ValidTermination)
		{
			int expected = 3;
			CustomAlgorithm algorithm;
			algorithm.SetTermination(new FitnessStagnationTermination(expected));
			algorithm.Start();

			Assert::IsTrue(algorithm.GetState() == AlgorithmState::CRITERIA_STOPPED, L"State is invalid");
			Assert::AreEqual(algorithm.GetCurrentIteration(), expected, L"Current Iteration is invalid");
		}

		TEST_METHOD(OrTermination_Process_ValidTermination)
		{
			int expected = 3;
			CustomAlgorithm algorithm;
			algorithm.SetTermination(new OrTermination(
				new IterationNumberTermination(expected),
				new TimeLimitTermination(100)
				)
			);
			algorithm.Start();

			Assert::IsTrue(algorithm.GetState() == AlgorithmState::CRITERIA_STOPPED, L"State is invalid");
			Assert::AreEqual(algorithm.GetCurrentIteration(), expected, L"Current Iteration is invalid");
		}

		TEST_METHOD(AndTermination_Process_ValidTermination)
		{
			int expected = 3;
			CustomAlgorithm algorithm;
			algorithm.SetTermination(new AndTermination(
				new IterationNumberTermination(expected),
				new TimeLimitTermination(100)
			)
			);
			algorithm.Start();

			Assert::IsTrue(algorithm.GetState() == AlgorithmState::CRITERIA_STOPPED, L"State is invalid");
			Assert::AreNotEqual(algorithm.GetCurrentIteration(), expected, L"Current Iteration is invalid");
		}
	};
}
