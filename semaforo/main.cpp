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

	while (relogioGlobal->getTempoDeSimulacao() > relogioGlobal->getTempoTotal()) {
			cout << "tempo " << x << endl;
			for(int i = 0; i < listaPista->size(); i++) {

			}

			aux = 0;
			++x;
			relogioGlobal->setTempoTotal(x);

	}

	//(int tamanho, int velocidade, Pista *frente, Pista *direita,Pista *esquerda, bool fonte, bool sumidouro,bool liberada);
	return 0;
}

//teste maroto
//int main(int argc, char const *argv[]) {
//	Relogio* relogio = new Relogio(20, 2);
//	Semaforo* um = new Semaforo(relogio);
//	Semaforo* dois = new Semaforo(relogio);
//	Pista* pista1 = new Pista();
//	Pista* pista2 = new Pista();
//
//	um->setRelogio(relogio);
//	//um->abrirSemaforo();
//	um->setAberto(true);
//	um->setNextSemaforo(dois);
//	um->setPista1(pista1);
//	um->setPista2(pista1);
//	dois->setRelogio(relogio);
//	dois->setAberto(false);
//	dois->setNextSemaforo(um);
//	dois->setPista1(pista2);
//	dois->setPista2(pista2);
//
//	int x;
//	int aux = 0;
//
//	while(relogio->getTempoTotal() < relogio->getTempoDeSimulacao()) {
//		cout<<"tempo " << x << endl;
//		um->liberaProximo(aux);
//		dois->liberaProximo(aux);
//		cout<<"pista 1 liberada: " << pista1->getLiberado()<<endl;
//		cout<<"semaforo 1: " << um->getAberto()<<endl;
//		cout<<"pista 2 liberada: " << pista2->getLiberado()<<endl;
//		cout<<"semaforo 2: " << dois->getAberto()<<endl;
//		aux = 0;
//		++x;
//		relogio->setTempoTotal(x);
//
//	}
//	return 0;
//}
