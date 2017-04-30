#include <iostream>
#include "pista.h"
#include "carro.h"
#include "relogio.h"
#include "FilaEncadeada.h"
#include "semaforo.h"

using namespace std;
int main(int argc, char const *argv[]) {
	Relogio* relogio = new Relogio(20, 2);
	Semaforo* um = new Semaforo(relogio);
	Semaforo* dois = new Semaforo(relogio);
	Pista* pista1 = new Pista();
	Pista* pista2 = new Pista();

	um->setRelogio(relogio);
	//um->abrirSemaforo();
	um->setAberto(true);
	um->setNextSemaforo(dois);
	um->setPista1(pista1);
	um->setPista2(pista1);
	dois->setRelogio(relogio);
	dois->setAberto(false);
	dois->setNextSemaforo(um);
	dois->setPista1(pista2);
	dois->setPista2(pista2);

	int x;
	int aux = 0;

	while(relogio->getTempoTotal() < relogio->getTempoDeSimulacao()) {
		cout<<"tempo " << x << endl;
		um->liberaProximo(aux);
		dois->liberaProximo(aux);
		cout<<"pista 1 liberada: " << pista1->getLiberado()<<endl;
		cout<<"semaforo 1: " << um->getAberto()<<endl;
		cout<<"pista 2 liberada: " << pista2->getLiberado()<<endl;
		cout<<"semaforo 2: " << dois->getAberto()<<endl;
		aux = 0;
		++x;
		relogio->setTempoTotal(x);

	}
	return 0;
}
