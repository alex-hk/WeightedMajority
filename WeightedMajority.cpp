// WeightedMajority.cpp : Defines the entry point for the console application.
//

#include <collection.h>
#include <stdio.h>
#include "Experts.h"
#include <vector>

const unsigned int trials = 20;
const unsigned int experts = 10;
const float beta = .05f;
const vector<int> input = {0,1};

int main(int argc, char* argv[])
{
	Experts ex();
	ex.init(beta);

	for(int i = 0; i < trials; i++){

	}

    return 0;
}

