// WeightedMajority.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include "Experts.h"
#include <vector>

const unsigned int trials = 50;
const unsigned int experts = 20;
const float beta = .05f;
const std::vector<int> input = {0,1};
std::vector<int> output;

void randomOutput(){
	printf("Output: {");
	for(int i = 0; i < trials; i++){
		int randnum = rand()%(input.size());
		printf("%d, ",randnum);
		output.push_back(randnum);
	}
	printf("}\n");
}

int main(int argc, char* argv[])
{

	srand(time(NULL));
	randomOutput();
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
		ex.resetCounts();
	}

    return 0;
}

