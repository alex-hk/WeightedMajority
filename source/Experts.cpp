#include "Experts.h"
#include <vector>

using namespace std;

void Experts::init(int exp){
	for(int i = 0; i < exp; i++){
		experts.push_back(Expert());
	}
	
	for(int j = 0; j < input.size(); j++){
		option * op = new option();
		op->key = input[j];
		op->value = 0;
		counts.push_back(op);
	}	
}

void Experts::printExperts() {
	int total, wrong;
	for (int i = 0; i < experts.size(); i++) {
		total = experts[i].getTotal();
		wrong = experts[i].getWrong();
		printf("Expert %d:: Prediction: %d  Total: %d  Wrong: %d  Correct:%d  Weight:%f\n", i, experts[i].getPrediction(), total, wrong, (total-wrong), experts[i].getWeight());
	}
	printf("===================================\n\n");
}

void Experts::resetCounts(){
	for(int i = 0; i < counts.size(); i++){
		counts[i]->tweight = 0;
		counts[i]->value = 0;
	}
}

int Experts::getMajority() {
	for (int i = 0; i < experts.size(); i++) {
		int value = experts[i].getPrediction();
		float expweight = experts[i].getWeight();
		for(int j = 0; j < counts.size(); j++){
			if(counts[j]->key == value) { counts[j]->value++; counts[j]->tweight+=expweight;}
		}		
	}

	float max = -1.0f;
	int maxkey = -1;
	for (int j = 0; j < counts.size(); j++) {
		if (counts[j]->tweight > max) { max = counts[j]->tweight; maxkey = counts[j]->key; }
	}

	return maxkey;
}

void Experts::updateExperts(int correct) {
	for (int i = 0; i < experts.size(); i++) {
		if (experts[i].getPrediction() != correct){
			experts[i].adjust(beta,0);
		}
		else experts[i].adjust(beta,1);
	}
}

void Experts::predictions(){
	for(int i = 0; i < experts.size(); i++){
		experts[i].predict(input);
	}
}
