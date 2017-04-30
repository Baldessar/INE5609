/*
 * FilaEncadeada.h
 *
 *  Created on: 29/04/2017
 *      Author: atalaia
 */

#ifndef FILAENCADEADA_H_
#define FILAENCADEADA_H_

//  Copyright [2017] <Balde>

#include <cstdint>
#include <stdexcept>

template<typename T>
// !Lista Circulas Simples.
/*! vai que né
*/
class LinkedQueue {
 public:
    // !Lista Circulas Simples.
/*! vai que né
*/
    LinkedQueue() {
        head = nullptr;
        tail = nullptr;
        size_ = 0;
    }
// !Lista Circulas Simples.
/*! vai que né
*/
    ~LinkedQueue() {
       while ( !empty() ) {
            dequeue();
       }
    }
// !Lista Circulas Simples.
/*! vai que né
*/
// !Lista Circulas Simples.
/*! vai que né
*/
    void clear() {  // limpar
        while (size_ != 0) {
            dequeue();
        }
    }
// !Lista Circulas Simples.
/*! vai que né
*/
    void enqueue(const T& data) {
        Node *novo;
        novo = new Node(data, nullptr);
       if ( empty() ) {
           head = novo;
           // ++size_;
       } else {
            tail->next(novo);
       }
       tail = novo;
        ++size_;
    }  // enfilerar
// !Lista Circulas Simples.
/*! vai que né
*/
    T dequeue() {
        Node *retira;
        T volta;
        if ( empty() ) {
            throw std::out_of_range("vaziu");
        }
        retira = head;
        head = retira->next();
        volta = retira->data();
        if (size_ == 1) {
            tail = nullptr;
        }
        --size_;
        delete retira;
        return volta;
    }  // desenfilerar
// !Lista Circulas Simples.
/*! vai que né
*/
    T& front() const {
       if ( empty() ) {
           throw std::out_of_range("birl");
       }
    return head->data();
    }  // primeiro dado
//  !Lista Circulas Simples.
/*! vai que né
*/
    T& back() const {
        if ( empty() ) {
           throw std::out_of_range("birl");
       }
        return tail->data();
    }  // último dado
// !Lista Circulas Simples.
/*! vai que né
*/
    bool empty() const {  // fila vazia
        return (size_ == 0);
    }
// !Lista Circulas Simples.
/*! vai que né
*/
    std::size_t size() const {
        return size_;
    }  // tamanho

 private:
    class Node {
     public:
     explicit   Node(const T& data):
        data_{data}
        {}
        Node(const T& data, Node* next):
        data_{data}, next_{next}
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

        void next(Node* next) {
            next_ = next;
        }

     private:
        T data_;
        Node* next_;
    };
    Node* head;  // nodo-cabeça
    Node* tail;  // nodo-fim
    std::size_t size_;  // tamanho
};
// namespace structures


#endif /* FILAENCADEADA_H_ */
