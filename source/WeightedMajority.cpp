// WeightedMajority.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "Experts.h"
#include <vector>

const unsigned int trials = 20;
const unsigned int experts = 10;
const float beta = .05f;
const std::vector<int> input = {0,1};
const std::vector<int> output = {1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0,1,0,1,1};

int main(int argc, char* argv[])
{
	Experts ex(beta, input);
	ex.init(experts);
	ex.printExperts();
	int correct;
	for(int i = 0; i < trials; i++){
		correct = output[i];
		ex.predictions();
		int majority = ex.getMajority();
		ex.updateExperts(correct);
		printf("Trial #%d\nMajority predicted: %d\nCorrect answer: %d\n", i,majority, correct);
		ex.printExperts();
	}

    return 0;
}

