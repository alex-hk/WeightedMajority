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
	Expert(){weight = 1.0f; prediction = 0; totalpred = 0; numwrong = 0;}
	float getWeight() { return weight; }
	int getPrediction() { return prediction; }
	int getTotal() { return totalpred; }
	int getWrong() { return numwrong; }
	void adjust(float beta, bool right) {
		totalpred++;
		if(!right){
			weight -= (beta*weight);
			numwrong++;
		}
	}
	void predict(std::vector<int> input) {
		srand(time(NULL));
		int randnum = rand() % (input.size());
		prediction = input[randnum];
	}
	
};
