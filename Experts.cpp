#include "Experts.h"
#include <vector>

using namespace std;

void Experts::init(int exp){
	for(int i = 0; i < exp; i++){
		experts.push_back(new Expert())
	}
}

void Experts::printExperts() {
	for (int i = 0; i < experts.size(); i++) {
		int total = experts[i].getTotal();
		int wrong = experts[i].getWrong();
		printf("Expert %d:: Prediction: %d\tTotal: %d\tWrong: %d\tCorrect:%d\tWeight:%f", i, total, wrong, total-wrong, experts[i].getWeight());
	}
}

int Experts::getMajority() {
	vector<int> totals(input.size(), 0);
	for (int i = 0; i < experts.size(); i++) {
		totals[experts[i].getPrediction()] += 1;
	}

	int max = -1;
	for (int j = 0; j < totals.size(); j++) {
		if (totals[j] > max) max = totals[j];
	}

	return max;
}

void Experts::updateExperts(int choice) {
	for (int i = 0; i < experts.size(); i++) {
		if (experts[i].getPrediction() != choice) experts[i].adjustWeight(beta);
	}
}
