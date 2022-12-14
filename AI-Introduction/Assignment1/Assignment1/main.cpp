#include <ctime>
#include <iostream>
#include <vector>
#include <functional>
#include "Problem.h"
#include "Search.h"
#include "Action.h"

typedef std::vector<Action> (*searchFunc)(Problem& problem);

void printStats(std::vector<std::pair<int, float>>& statistics)
{
	std::cout << "length, seconds" << '\n';
	for (auto& pair : statistics)
	{
		std::cout << pair.first << ", " << pair.second << '\n';
	}
}

void doExperiment(int iteration, int problemSize, int suffleSteps, searchFunc searchFunc)
{
	std::cout << "Start to do experiment" << std::endl;
	std::vector<std::pair<int, float>> statistics;

	for (int i = 0; i < iteration; i++)
	{
		Problem problem(problemSize, suffleSteps);
		problem.printState(problem.initState);

		clock_t t = clock();
		std::vector<Action> solution = searchFunc(problem);
		t = clock() - t;

		std::pair<int, float> stats(solution.size(), ((float)t) / CLOCKS_PER_SEC);
		statistics.push_back(stats);

		printf("Searching tooks %f seconds.\n", stats.second);
		problem.printSolution(solution);

		problem.updateInitState();
	}

	printStats(statistics);
}

void testSearchFunction(searchFunc searchFunc)
{
	std::cout << "Start to test search function" << std::endl;
	int iteration = 50;
	int size = 3;
	int suffleSteps = 30;

	for (int i = 1; i <= iteration; i++)
	{
		Problem problem(size, suffleSteps);
		std::vector<Action> solution = searchFunc(problem);
		if (solution == std::vector<Action>({ Action::CUTOFF }))
		{
			std::cout << "Iteration " << i << ": CUTOFF\n";
		}
		else
		{
			std::cout << "Iteration " << i << ": ";
			std::cout << problem.isSolution(solution, problem.initState) << std::endl;
		}
		problem.updateInitState();
	}
}


int main()
{
	std::srand((unsigned int) std::time(NULL)); // Generate a random seed
	std::cout << "haihai" << std::endl;
	//doExperiment(50, 3, 50, (searchFunc)search::bfs);
	//doExperiment(50, 3, 50, (searchFunc)search::dlsWrapper);
	//doExperiment(50, 3, 50, (searchFunc)search::aStarMisplace);
	doExperiment(50, 3, 50, (searchFunc)search::aStarManhattan);

	 //???º??????ڲ???????????????????ȷ??
	 //testSearchFunction((searchFunc)search::bfs);
	 //testSearchFunction((searchFunc)search::dlsWrapper);
	//testSearchFunction((searchFunc)search::aStarMisplace);
	 //testSearchFunction((searchFunc)search::aStarManhattan);

	system("pause");
}