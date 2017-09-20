#include "Experts.h"
#include <vector>

using namespace std;

void Experts::init(int exp){
	for(int i = 0; i < exp; i++){
		experts.push_back(new Expert());
	}
	
	for(int j = 0; j < input.size(); j++){
		option * op = new option();
		op->key = input[j];
		op->value = 0;
		counts.push_back(op);
	}	
}

void Experts::printExperts() {
	for (int i = 0; i < experts.size(); i++) {
		int total = experts[i]->getTotal();
		int wrong = experts[i]->getWrong();
		printf("Expert %d:: Prediction: %d  Total: %d  Wrong: %d  Correct:%d  Weight:%f\n", i, total, wrong, total-wrong, experts[i]->getWeight());
	}
}

int Experts::getMajority() {
	for (int i = 0; i < experts.size(); i++) {
		int value = experts[i]->getPrediction();
		for(int j = 0; j < counts.size(); j++){
			if(counts[j]->key == value) counts[j]->value++;
		}		
	}

	int max = -1;
	for (int j = 0; j < counts.size(); j++) {
		if (counts[j]->value > max) max = counts[j]->value;
	}

	return max;
}

void Experts::updateExperts(int choice) {
	for (int i = 0; i < experts.size(); i++) {
		if (experts[i]->getPrediction() != choice) experts[i]->adjustWeight(beta);
	}
}

void Experts::predictions(){
	for(int i = 0; i < experts.size(); i++){
		experts[i]->predict(input);
	}
	printf("=============================\n\n");
}
