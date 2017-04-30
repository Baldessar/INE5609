#include "pista.h"

Pista::Pista() {

}

Pista::Pista(int tamanho, int velocidade, Pista *frente, Pista *direita,
		Pista *esquerda, bool fonte, bool sumidouro, bool liberada) {
	this->tamanho = tamanho;
	this->velocidade = velocidade;
	this->frente = frente;
	this->direita = direita;
	this->esquerda = esquerda;
	this->fonte = fonte;
	this->sumidouro = sumidouro;
	this->fila = new LinkedQueue<Carro*> ();

}
Pista::~Pista() {
	delete fila;
}
//um carro é criado e adicionado a pista
void Pista::generateCar() {
	Carro *carro = new Carro();
	fila->enqueue(carro);
}
//adiciona o carro na fila
void Pista::insertCar(Carro *carro) {
	this->fila->enqueue(carro);
}

//o primeiro carro da fila é retirado da pista, se a pista for sumidoura, ele é excluido do programa,
//se não, ele é movido para outra pista, se ela nao estiver cheia
int Pista::excludeCar() {
	if (fila->empty()) {
		return 0;
	}
	if (sumidouro) {
		fila->dequeue();
		return 0;
	}
	Carro *carro = fila->back();
	int direction = carro->getRandom(3, 0);
	if (direction == 0 && frente->getTamanho() >= carro->getTamanho()) {
		this->frente->insertCar(carro);
	} else if (direction == 1 && direita->getTamanho() >= carro->getTamanho()) {
		this->direita->insertCar(carro);
	} else if (direction == 2 && esquerda->getTamanho() >= carro->getTamanho()) {
		this->esquerda->insertCar(carro);
	}
	return 0;

}

int Pista::getTamanho() {
	return tamanho;
}

void Pista::setTamanho(int tamanho) {
	this->tamanho = tamanho;
}

int Pista::getVelocidade() {
	return velocidade;
}

void Pista::setVelocidade(int velocidade) {
	this->velocidade = velocidade;
}

Pista* Pista::getFrente() {
	return frente;
}

void Pista::setFrente(Pista* frente) {
	this->frente = frente;
}

Pista* Pista::getDireita() {
	return direita;
}

void Pista::setDireita(Pista* direita) {
	this->direita = direita;

}

Pista* Pista::getEsquerda() {
	return esquerda;
}

void Pista::setEsquerda(Pista* esquerda) {
	this->esquerda = esquerda;
}

bool Pista::getFonte() {
	return fonte;
}

void Pista::setFonte(bool fonte) {
	this->fonte = fonte;
}

bool Pista::getSumidouro() {
	return sumidouro;
}

void Pista::setSumidouro(bool sumidouro) {
	this->sumidouro = sumidouro;
}

bool Pista::getLiberado(){
	return liberada;
}

void Pista::setLiberado(bool liberada) {
	this->liberada = liberada;
}

