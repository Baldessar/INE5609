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
	int posicao;
public:
	int randTamanho();

	int getPista();

	Carro(int tamanho);

	Carro();

	~Carro();

	int getTamanho();

	void setTamanho(int tamanho);

	int getPosicao();

	void setPosicao(int posicao);

};

#endif /* CARRO_H_ */
