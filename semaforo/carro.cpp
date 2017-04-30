#include "carro.h"

//função que gera um numero aleatorio onde n é o menor numero e (n+m-1) é o maior numero
int Carro::getRandom(int m, int n) {
	srand(clock());
	int random = (rand() % m + n);
	return random;
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

