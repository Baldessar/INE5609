/*
 * relogio.cpp
 *
 *  Created on: 28/04/2017
 *      Author: atalaia
 */

#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "relogio.h"

Relogio::Relogio(int tempoDeSimulacao, int tempoSemaforo) {
	this->tempoDeSimulacao = tempoDeSimulacao;
	this->tempoSemaforo = tempoSemaforo;
}

int Relogio::getTempoTotal() {
	return tempoTotal;
}

void Relogio::setTempoTotal(int tempoTotal) {
	this->tempoTotal = tempoTotal;
}

int Relogio::getTempoDeSimulacao() {
	return tempoDeSimulacao;
}

void Relogio::setTempoDeSimulacao(int tempoDeSimulacao) {
	this->tempoDeSimulacao = tempoDeSimulacao;
}

int Relogio::getTempoSemaforo() {
	return tempoSemaforo;
}

void Relogio::setTempoTotalSemaforo(int tempoSemaforo) {
	this->tempoSemaforo = tempoSemaforo;
}

