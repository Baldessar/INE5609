class Carro {
private:
	Pista pista;
	int tamanho;
public:
	Carro(Pista pista, int tamanho) {
		this->pista = pista;
		this->tamanho = tamanho + 3;
	}
	~Carro();

	int getTamanho() {
		return tamanho;
	}

	void setTamanho(int tamanho) {
		this->tamanho = tamanho;
	}

	Pista getPista() {
		return Pista;
	}

	void setTamanho(Pista pista) {
		this->pista = pista;
	}

};
