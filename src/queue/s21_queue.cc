//
// Created by Grisella Alaina on 3/28/23.
//

#include "s21_queue.h"

template <typename T>
s21::s21_queue<T>::s21_queue(std::initializer_list<value_type> const &items)
    : s21_queue() {
  for (auto &i : items) {
    push(i);
  }
}

template <typename T>
void s21::s21_queue<T>::push(value_type data_) {
  if (this->head_ == nullptr) {
    this->head_ = new Node<value_type>(data_);
  } else {
    Node<value_type> *current = this->head_;
    while (current->pNext_ != nullptr) {
      current = current->pNext_;
    }
    current->pNext_ = new Node<value_type>(data_);
  }
  (this->sz_)++;
}

template <typename T>
s21::s21_queue<T>::s21_queue(const s21_queue &q) : s21_queue() {
  Node<value_type> *current = q.head_;
  while (current != nullptr) {
    this->push(current->data_);
    current = current->pNext_;
  }
}

template <typename T>
s21::s21_queue<T>::s21_queue(s21_queue &&q) : s21::s21_queue<T>(q) {
  if (this->head_ == q.head_)
    throw std::invalid_argument("s21_queue argument too large.");
  q.clear();
}

template <typename T>
s21::s21_queue<T> &s21::s21_queue<T>::operator=(const s21_queue &q) {
  if (this->head_) {
    this->clear();
  }
  Node<value_type> *current = q.head_;
  while (current != nullptr) {
    this->push(current->data_);
    current = current->pNext_;
  }
  return *this;
}

template <typename T>
size_t s21::s21_queue<T>::size() {
  return this->sz_;
}

template <typename T>
const T &s21::s21_queue<T>::back() {
  if (this->head_ == nullptr) {
    return this->head_->data_;
  } else {
    Node<value_type> *current = this->head_;
    while (current->pNext_ != nullptr) {
      current = current->pNext_;
    }
    return current->data_;
  }
}

template <typename T>
const T &s21::s21_queue<T>::front() {
  return this->head_->data_;
}

template <typename T>
void s21::s21_queue<T>::pop() {
  Node<value_type> *current = this->head_;
  this->head_ = this->head_->pNext_;
  if (current != nullptr) delete current;
  (this->sz_)--;
}

template <typename T>
bool s21::s21_queue<T>::empty() {
  return !(this->sz_ != 0);
}

template <typename T>
void s21::s21_queue<T>::swap(s21_queue &other) {
  s21_queue<T> tmp_this(*this);
  s21_queue<T> tmp_other(other);
  this->clear();
  other.clear();
  for (size_t i = 0; i < tmp_this.size(); i++) {
    other.push(tmp_this.front());
    tmp_this.pop();
  }
  for (size_t i = 0; i < tmp_other.size(); i++) {
    this->push(tmp_other.front());
    tmp_other.pop();
  }
}

template <typename T>
void s21::s21_queue<T>::clear() {
  while (this->sz_) {
    this->pop();
  }
}

template <typename T>
s21::s21_queue<T>::~s21_queue() {
  clear();
}
