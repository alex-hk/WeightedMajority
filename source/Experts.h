#include <vector>
#include <stdio.h>
#include "Expert.h"

//using namespace std;

struct option {
	int key;
	int value;
};

class Experts {
private:
	float beta;
	std::vector<Expert> experts;
	std::vector<int> input;
	std::vector<option> counts;

public:
	Experts(float b, vector<int> in){beta = b; input = in;};
	void init(int exp);
	void printExperts();
	int getMajority();
	void updateExperts(int choice);
	void predictions();
};