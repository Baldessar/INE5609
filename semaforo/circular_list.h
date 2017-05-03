#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>




template<typename T>
// !Lista Circulas Simples.
/*! vai que né
*/
class CircularList {
 public:
// !Lista Circulas Simples.
/*! vai que né
*/
    CircularList() {
        size_ = 0;
        head = new Node((T)0, head);
    }

    ~CircularList() {
        clear();
    }
// !Lista Circulas Simples.
/*! vai que né
*/
    void clear() {
        auto d = size_;
        for (int i = 0; i < d; ++i) {
            pop_back();
        }
    }  // limpar lista
// !Lista Circulas Simples.
/*! vai que né
*/
    void push_back(const T& data) {
        Node *novo, *anterior;
        if ( empty() ) {
            return push_front(data);
        }
        novo = new Node(data, head);
        anterior = head->next();
        for (int i = 0; i < size_-1; ++i) {
            anterior = anterior->next();
        }
        anterior->next(novo);
        size_++;
    }  // inserir no fim
// !Lista Circulas Simples.
/*! vai que né
*/
    void push_front(const T& data) {
        Node *anterior, *novo;
        anterior = head;
        novo = new Node(data);
        novo->next(anterior->next());
        anterior->next(novo);
        ++size_;
    }  // inserir no início
// !Lista Circulas Simples.
/*! vai que né
*/
    void insert(const T& data, std::size_t index) {
        Node *novo, *anterior;
        if (index > size_ || index < 0) {
            throw std::out_of_range("birl");
        }
        if (index == 0) {
           return push_front(data);
        }
        novo = new Node(data);
        anterior = head->next();
        for (int i = 0; i < index-1; ++i) {
            anterior = anterior->next();
        }
        novo->next(anterior->next());
        anterior->next(novo);
        ++size_;
    }  // inserir na posição
// !Lista Circulas Simples.
/*! vai que né
*/
    void insert_sorted(const T& data) {
        Node *atual = head->next();
        size_t posicao = 0;
        if ( empty() ) {
            push_front(data);
        }
        while ( posicao < size_-1 && data > atual->data() ) {
            atual = atual->next();
            ++posicao;
        }
        insert(data, posicao);
    }  // inserir em ordem
// !Lista Circulas Simples.
/*! vai que né
*/
    T& at(std::size_t index) {
        Node *atual = head;
       if (index > size_) {
           throw std::out_of_range("birl2");
       }
       if (empty()) {
            throw std::out_of_range("Empty");
       }
        for (size_t i = 0; i < index+1; ++i) {
            atual = atual->next();
        }
        return atual->data();
    }  // acessar em um indice (com checagem de limites)
// !Lista Circulas Simples.
/*! vai que né
*/
    const T& at(std::size_t index) const {
        Node *atual = head;
       if (index > size_) {
           throw std::out_of_range("birl2");
       }
       if (empty()) {
            throw std::out_of_range("Empty");
       }
        for (size_t i = 0; i < index; ++i) {
            atual = atual->next();
        }
        return atual->data();
    }  // versão const do acesso ao indice
// !Lista Circulas Simples.
/*! vai que né
*/
    T pop(std::size_t index) {
        Node *anterior, *retira;
        T volta;
        int i = 0;
        if ( empty() ) {
            throw std::out_of_range("birl");
        }
        if (index >= size_) {
            throw std::out_of_range("lasanha");
        }
        if (index == 0) {
            return pop_front();
        }
        anterior = head->next();
        while (i < index-1) {
            anterior = anterior->next();
            i++;
        }
        retira = anterior->next();
        anterior->next(retira->next());
        volta = retira->data();
        --size_;
        delete(retira);
        return volta;
    }  // retirar da posição
// !Lista Circulas Simples.
/*! vai que né
*/
    T pop_back() {
        if (size_ == 1) {
            return pop_front();
        }
        return pop(size_-1);
    }  // retirar do fim
// !Lista Circulas Simples.
/*! vai que né
*/
    T pop_front() {
       if ( empty() ) {
           throw std::out_of_range("empty");
       }
       Node *retira = head->next();
       T dado = head->next()->data();
       head->next(head->next()->next());
       --size_;
       delete retira;
       return dado;
    }  // retirar do início
// !Lista Circulas Simples.
/*! vai que né
*/
    void remove(const T& data) {
        pop(find(data));
    }  // remover dado específico
// !Lista Circulas Simples.
/*! vai que né
*/
    bool empty() const {
        return (size_ == 0);
    }  // lista vazia
// !Lista Circulas Simples.
/*! vai que né
*/
    bool contains(const T& data) const {
        Node *atual = head->next();
        size_t posicao = 0;
        while ( (posicao < size_) && (data != atual->data()) ) {
            atual = atual->next();
            ++posicao;
        }
        return(data == atual->data());
    }  // lista contém determinado dado?
// !Lista Circulas Simples.
/*! vai que né
*/
    std::size_t find(const T& data) const {
        Node *atual = head->next();
        size_t posicao = 0;
        while ( (posicao < size_) && (data != atual->data()) ) {
            atual = atual->next();
            ++posicao;
        }
        return posicao;
    }  // posição de um item na lista
// !Lista Circulas Simples.
/*! vai que né
*/
    std::size_t size() const {
        return size_;
    }  // tamanho da lista

 private:
    class Node {
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {
            return data_;
        }

        const T& data() const {
            return data_;
        }

        Node* next() {
            return next_;
        }

        const Node* next() const {
            return next_;
        }

        void next(Node* node) {
            next_ = node;
        }

     private:
           T data_;  // _info
           Node* next_{nullptr};  // _proximo
    };

       Node* end() {  // último nodo da lista
           auto it = head;
           for (auto i = 1u; i < size(); ++i) {
               it = it->next();
           }
           return it;
       }

    Node* head;  // nodo-topo
    std::size_t size_;  // tamanho
};

#endif
