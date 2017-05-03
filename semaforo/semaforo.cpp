#include "semaforo.h"

Semaforo::Semaforo(Relogio* relogio) {
	this->relogio = relogio;
}

Semaforo::Semaforo(Relogio* relogio, Pista* pista1, Pista* pista2,
		Semaforo* nextSemaforo, bool aberto) {
	this->relogio = relogio;
	this->pista1 = pista1;
	this->pista2 = pista2;
	this->nextSemaforo = nextSemaforo;
	this->aberto = aberto;
}

void Semaforo::liberaProximo(int &aux) {
	if (aux == 0) {
		if (aberto && (relogio->getTempoTotal() % relogio->getTempoSemaforo())
				== 0) {
			this->aberto = false;
			this->pista1->setLiberado(false);
			this->pista2->setLiberado(false);
			nextSemaforo->setAberto(true);
			nextSemaforo->getPista1()->setLiberado(true);
			nextSemaforo->getPista2()->setLiberado(true);
			aux++;
		}
	}
}
//ESSA MERDA NAO FUNCIONA E EU N TENHO IDEIA DE O POR QUE!!
//void Semaforo::abrirSemaforo() {
//	nextSemaforo->setAberto(true);
//	nextSemaforo->getPista1()->setLiberado(true);
//	nextSemaforo->getPista2()->setLiberado(true);
//}

Relogio* Semaforo::getRelogio() {
	return relogio;
}

void Semaforo::setRelogio(Relogio* relogio) {
	this->relogio = relogio;
}

Pista* Semaforo::getPista1() {
	return pista1;
}

void Semaforo::setPista1(Pista* pista1) {
	this->pista1 = pista1;
}

Pista* Semaforo::getPista2() {
	return pista2;
}

void Semaforo::setPista2(Pista* pista2) {
	this->pista2 = pista2;
}

Semaforo* Semaforo::getNextSemaforo() {
	return nextSemaforo;
}

void Semaforo::setNextSemaforo(Semaforo* nextSemaforo) {
	this->nextSemaforo = nextSemaforo;
}

bool Semaforo::getAberto() {
	return aberto;
}

void Semaforo::setAberto(bool aberto) {
	this->aberto = aberto;
}
