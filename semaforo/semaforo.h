/*
 * semaforo.h
 *
 *  Created on: 30/04/2017
 *      Author: atalaia
 */

#ifndef SEMAFORO_H_
#define SEMAFORO_H_

#include "pista.h"
class Semaforo {
private:
	Relogio* relogio;
	Pista* pista1;
	Pista* pista2;
	Semaforo* nextSemaforo;
	bool aberto;

public:
	Semaforo(Relogio* relogio);

	Semaforo(Relogio* relogio, Pista* pista1, Pista* pista2,
			Semaforo* nextSemaforo, bool aberto);

	void liberaProximo(int &aux);

	void abrirSemaforo();

	Relogio* getRelogio();

	void setRelogio(Relogio* relogio);

	Pista* getPista1();

	void setPista1(Pista* pista1);

	Pista* getPista2();

	void setPista2(Pista* pista2);

	Semaforo* getNextSemaforo();

	void setNextSemaforo(Semaforo* nextSemaforo);

	bool getAberto();

	void setAberto(bool aberto);

};

#endif /* SEMAFORO_H_ */
