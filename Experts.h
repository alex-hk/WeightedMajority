#include <vector>
#include <stdio.h>
#include "Expert.h"

//using namespace std;

class Experts {
private:
	float beta;
	std::vector<Expert> experts;
public:
	void printExperts();
	int getMajority();
	void updateExperts(int choice);
};
