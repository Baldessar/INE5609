// Copyright 2017 Marcelo Muller Vieira Filho

#ifndef EVENTO_H
#define EVENTO_H


/*! \brief Eventos possíveis do simulador
 *
 */
enum Tipo { mudaSemaforo = 1, //  Evento de mudança de semáforo
             mudaPista = 2, //  Evento de mudança de pista
             entraCarro = 3, //  Evento de entrada de carro no sistema
			 chegadaFim = 4 //  Evento de chegada de carro no fim da pista
           };

class Evento {
 public:
    Evento();

	/**
     * @brief      Construtor
     *
     * @param  tempo    Tempo em que o evento irá ocorrer (em segundos)
     * @param  tipo    Tipo do evento
     * @param  fonte  Ponteiro para o objeto em que o evento atuará
     */
    Evento(int tempo, Tipo tipo, void* fonte);

	/**
     * @brief      Tempo em que o evento acontecerá
     *
     * @return     Tempo em segundos
     */
    int tempo() const;

	/**
     * @brief      O tipo do evento
     *
     * @return     Tipo do evento
     */
    Tipo tipo() const;

	/**
     * @brief      Retorna o ponteiro para o objeto alvo do evento
     *
     * @return     Ponteiro para o objeto alvo
     */
    void* fonte() const;

	/**
     * @brief      Compara dois eventos utilizando os tempos de ocorrência
     *
     *
     * @return     True se o tempo de ocorrência deste evento é menor que o
     *             evento passado como parâmetro, falso caso contrário
     */
    bool operator<(const Evento& e) const;

	/**
     * @brief      Compara dois eventos utilizando os tempos de ocorrência
     *
     * @return     True se o tempo de ocorrência deste evento é menor ou igual
     *             que o evento passado como parâmetro, falso caso contrário
     */


 private:
    int tempo_;
	Tipo tipo_;
	void* fonte_;
};

#endif
