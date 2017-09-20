#include <vector>
#include <time.h>
#include <stdlib.h>

class Expert {
private:
	float weight;
	int prediction;
	int totalpred;
	int numwrong;
	
public:
	Expert(){weight = 1f;}
	float getWeight() { return weight; }
	int getPrediction() { return prediction; }
	int getTotal() { return totalpred; }
	int getWrong() { return numwrong; }
	void adjustWeight(float beta) { weight -= (beta*weight); }
	void predict(std::vector<int> input) {
		srand(time(NULL));
		int randnum = rand() % (input.size()) - 1;
		prediction = input[randnum];
	}
	
};
