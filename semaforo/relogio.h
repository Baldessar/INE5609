/*
 * relogio.h
 *
 *  Created on: 29/04/2017
 *      Author: atalaia
 */

#ifndef RELOGIO_H_
#define RELOGIO_H_

class Relogio {
private:
	int tempoTotal;
	int tempoDeSimulacao;
	int tempoSemaforo;
public:

	Relogio(int tempoDeSimulacao, int tempoSemaforo);

	int getTempoTotal();

	void setTempoTotal(int tempoTotal);

	int getTempoDeSimulacao();

	void setTempoDeSimulacao(int tempoDeSimulacao);

	int getTempoSemaforo();

	void setTempoTotalSemaforo(int tempoSemaforo);

};
#endif /* RELOGIO_H_ */
