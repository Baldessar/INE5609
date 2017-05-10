#include "evento.h"


Evento::Evento()
	: tempo_{0},
	  tipo_{(Tipo) 0},
	  fonte_{nullptr}
{}

Evento::Evento(int tempo, Tipo tipo, void* fonte)
    : tempo_{tempo},
      tipo_{tipo},
      fonte_{fonte}
{}

int Evento::tempo() const {
    return tempo_;
}

Tipo Evento::tipo() const {
    return tipo_;
}

void* Evento::fonte() const {
    return fonte_;
}


bool Evento::operator<(const Evento& e) const {
    return tempo() < e.tempo();
}
