/*
 * carro.h
 *
 *  Created on: 29/04/2017
 *      Author: atalaia
 */

#ifndef CARRO_H_
#define CARRO_H_

#include "pista.h"

class Carro {
private:
	int tamanho;
public:
	int getRandom(int m, int n);

	Carro(int tamanho);

	Carro();

	~Carro();

	int getTamanho();

	void setTamanho(int tamanho);

};

#endif /* CARRO_H_ */
