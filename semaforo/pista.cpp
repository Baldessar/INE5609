#include "FilaEncadeada.cpp"
#include "carro.cpp"
#include <iostream>
#include "relogio.cpp"
#include <time.h>

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
	Relogio relogio;

public:
	Pista() {
		tamanho = 200;
	}
	Pista(int tamanho, int velocidade, Pista *frente, Pista *direita,
			Pista *esquerda, bool fonte, bool sumidouro) {
		this->tamanho = tamanho;
		this->velocidade = velocidade;
		this->frente = frente;
		this->direita = direita;
		this->esquerda = esquerda;
		this->fonte = fonte;
		this->sumidouro = sumidouro;
		this->fila = new LinkedQueue<Carro*> ();

	}
	~Pista() {
		delete fila;
	}
	//um carro é criado e adicionado a pista
	void generateCar() {
		Carro *carro = new Carro();
		fila->enqueue(carro);
	}
	//adiciona o carro na fila
	void insertCar(Carro *carro) {
		this->fila->enqueue(carro);
	}

	//o primeiro carro da fila é retirado da pista, se a pista for sumidoura, ele é excluido do programa,
	//se não, ele é movido para outra pista, se ela nao estiver cheia
	int excludeCar() {
		if (fila->empty()) {
			return 0;
		}
		if (sumidouro) {
			fila->dequeue();
			return 0;
		}
		Carro *carro = fila->back();
		int direction = relogio.getRandom(3, 0);
		if (direction == 0 && frente->getTamanho() >= carro->getTamanho()) {
			this->frente->insertCar(carro);
		} else if (direction == 1 && direita->getTamanho() >= carro->getTamanho()) {
			this->direita->insertCar(carro);
		} else if (direction == 2 && esquerda->getTamanho() >= carro->getTamanho()) {
			this->esquerda->insertCar(carro);
		}
		return 0;

	}

	int getTamanho() {
		return tamanho;
	}

	void setTamanho(int tamanho) {
		this->tamanho = tamanho;
	}

	int getVelocidade() {
		return velocidade;
	}

	void setVelocidade(int velocidade) {
		this->velocidade = velocidade;
	}

	Pista* getFrente() {
		return frente;
	}

	void setFrente(Pista* frente) {
		this->frente = frente;
	}

	Pista* getDireita() {
		return direita;
	}

	void setDireita(Pista* direita) {
		this->direita = direita;

	}

	Pista* getEsquerda() {
		return esquerda;
	}

	void setEsquerda(Pista* esquerda) {
		this->esquerda = esquerda;
	}

	bool getFonte() {
		return fonte;
	}

	void setFonte(bool fonte) {
		this->fonte = fonte;
	}

	bool getSumidouro() {
		return sumidouro;
	}

	void setSumidouro(bool sumidouro) {
		this->sumidouro = sumidouro;
	}

};

int main(int argc, char const *argv[]) {
	Relogio *relogio = new Relogio();
	int x = relogio->getRandom(3, 0);

	cout << x << endl;
	return 0;
}
