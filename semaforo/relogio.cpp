/*
 * relogio.cpp
 *
 *  Created on: 28/04/2017
 *      Author: atalaia
 */
#include <time.h>
#include <stdlib.h>
using namespace std;

class Relogio {

public:

	//função que gera um numero aleatorio onde n é o menor numero e (n+m-1) é o maior numero
	int getRandom(int m, int n) {
		srand(clock());
		int random = (rand() % m + n);
		return random;
	}
};
