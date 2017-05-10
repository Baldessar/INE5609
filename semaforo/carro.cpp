#include "carro.h"

//função que gera um numero aleatorio onde n é o menor numero e (n+m-1) é o maior numero
int Carro::randTamanho() {
	srand(clock());
	int random = (rand() % 4 + 2);
	return random;
}

int Carro::getPista(int pr,int pd,int pe) {
	srand(clock());
	int random = (rand() % 10 + 1);
	cout <<"AWE KRL " << random << endl;
	if (random <= 8) {
		return 1;
	} else if (random > pr && random <= pr+pd) {
		return 2;
	} else {
		return 3;
	}
}


Carro::Carro(int tamanho) {
	this->tamanho = tamanho + 3;
}

Carro::Carro() {

}

Carro::~Carro() {

}

int Carro::getTamanho() {
	return tamanho;
}

void Carro::setTamanho(int tamanho) {
	this->tamanho = tamanho;
}

int Carro::getPosicao() {
	return posicao;
}

void Carro::setPosicao(int posicao) {
	this->posicao = posicao;
}

