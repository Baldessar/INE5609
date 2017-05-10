#include <iostream>
#include "pista.h"
#include "carro.h"
#include "relogio.h"
#include "FilaEncadeada.h"
#include "semaforo.h"
#include "circular_list.h"

using namespace std;

int main(int argc, char const *argv[]) {
	Relogio *relogioGlobal = new Relogio(10, 1);
	CircularList<Semaforo*>* listaSemaforo = new CircularList<Semaforo*> ();
	//Semaforo firstSem = new Semaforo(relogioGlobal,);
	CircularList<Pista*>* listaPista = new CircularList<Pista*> ();

	//sumidouros//
	Pista *o1oeste = new Pista(2000, 80, nullptr, nullptr, nullptr, false,
			true, true);
	Pista *s1sul = new Pista(500, 60, nullptr, nullptr, nullptr, false, true,
			true);
	Pista *s2sul = new Pista(500, 40, nullptr, nullptr, nullptr, false, true,
			true);
	Pista *l1leste = new Pista(400, 30, nullptr, nullptr, nullptr, false, true,
			true);
	Pista *n2norte = new Pista(500, 40, nullptr, nullptr, nullptr, false, true,
			true);
	Pista *n1norte = new Pista(500, 60, nullptr, nullptr, nullptr, false, true,
			true);

	//intermediarias//
	Pista *c1oeste = new Pista(300, 60, nullptr, nullptr, nullptr, false,
			false, false);
	Pista *c1leste = new Pista(300, 60, nullptr, nullptr, nullptr, false,
			false, false);

	//fontes//
	Pista *o1leste = new Pista(2000, 80, c1leste, s1sul, n1norte, true,
			false, false);
	Pista *s1norte = new Pista(500, 60, n1norte, c1leste, o1oeste, true,
			false, false);
	Pista *s2norte = new Pista(500, 40, n2norte, l1leste, c1oeste, true,
			false, false);
	Pista *l1oeste = new Pista(400, 30, c1oeste, n2norte, s2sul, true,
			false, false);
	Pista *n2sul = new Pista(500, 40, s2sul, c1oeste,l1leste , true,
			false, false);
	Pista *n1sul = new Pista(500, 60, s1sul, o1oeste,c1leste , true,
			false, false);

	c1oeste->setPistas(o1oeste, n1norte, s1sul);
	c1leste->setPistas(l1leste, s2sul, n2norte);

	listaPista->push_front(o1oeste);
	listaPista->push_front(s1sul);
	listaPista->push_front(s2sul);
	listaPista->push_front(l1leste);
	listaPista->push_front(n2norte);
	listaPista->push_front(n1norte);
	listaPista->push_front(c1oeste);
	listaPista->push_front(c1leste);
	listaPista->push_front(o1leste);
	listaPista->push_front(s1norte);
	listaPista->push_front(s2norte);
	listaPista->push_front(l1oeste);
	listaPista->push_front(n2sul);
	listaPista->push_front(n1sul);

	Semaforo *sem1 = new Semaforo(relogioGlobal, o1leste, c1leste, nullptr,
			true);
	Semaforo *sem2 = new Semaforo(relogioGlobal, s1norte, s2norte, nullptr,
			true);
	Semaforo *sem3 = new Semaforo(relogioGlobal, c1oeste, l1oeste, nullptr,
			true);
	Semaforo *sem4 = new Semaforo(relogioGlobal, n1sul, n2sul, nullptr,
			true);
	sem1->setNextSemaforo(sem2);
	sem2->setNextSemaforo(sem3);
	sem3->setNextSemaforo(sem4);
	sem4->setNextSemaforo(sem1);
	listaSemaforo->push_front(sem1);
	listaSemaforo->push_front(sem2);
	listaSemaforo->push_front(sem3);
	listaSemaforo->push_front(sem4);

	int x = 0;
	int aux = 0;
	Carro *carro = new Carro();
	while (relogioGlobal->getTempoDeSimulacao() > relogioGlobal->getTempoTotal()) {
			cout << "tentando " << carro->getPista(8,1,1) << endl;
			for(int i = 0; i < listaPista->size(); i++) {

			}

			aux = 0;
			++x;
			relogioGlobal->setTempoTotal(x);

	}

	return 0;
}

