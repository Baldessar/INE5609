/*
 * pista.h
 *
 *  Created on: 29/04/2017
 *      Author: atalaia
 */

#ifndef PISTA_H_
#define PISTA_H_

#include "carro.h"
#include "FilaEncadeada.h"
#include "relogio.h"
#include <iostream>
#include <time.h>

class Carro;

using namespace std;
class Pista {

private:
	LinkedQueue<Carro*> *fila;
	int tamanho;
	int velocidade;
	Pista *frente;
	Pista *direita;
	Pista *esquerda;
	bool fonte;
	bool sumidouro;
	bool liberada;

public:
	Pista();

	Pista(int tamanho, int velocidade, Pista *frente, Pista *direita,Pista *esquerda, bool fonte, bool sumidouro,bool liberada);

	~Pista();

	//um carro é criado e adicionado a pista
	void generateCar();

	//adiciona o carro na fila
	void insertCar(Carro *carro);

	//o primeiro carro da fila é retirado da pista, se a pista for sumidoura, ele é excluido do programa,
	//se não, ele é movido para outra pista, se ela nao estiver cheia
	int excludeCar();

	int getTamanho();

	void setTamanho(int tamanho);

	int getVelocidade();

	void setVelocidade(int velocidade);

	Pista* getFrente();

	void setFrente(Pista* frente);

	Pista* getDireita();

	void setDireita(Pista* direita);

	Pista* getEsquerda();

	void setEsquerda(Pista* esquerda);

	void setPistas(Pista* frente, Pista* direita, Pista* esquerda);

	bool getFonte();

	void setFonte(bool fonte);

	bool getSumidouro();

	void setSumidouro(bool sumidouro);

	bool getLiberado();

	void setLiberado(bool liberada);
};

#endif /* PISTA_H_ */


