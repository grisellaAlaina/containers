//
// Created by Grisella Alaina on 3/28/23.
//

#include "s21_stack.h"

template <typename T>
s21::s21_stack<T>::s21_stack(std::initializer_list<value_type> const &items)
    : s21_stack() {
  for (auto &i : items) this->push(i);
}

template <typename T>
s21::s21_stack<T>::s21_stack(const s21_stack &s) : s21_stack() {
  Node<value_type> *tmp = s.head_;
  while (tmp != nullptr) {
    this->push(tmp->data_);
    tmp = tmp->pNext_;
  }
}

template <typename T>
s21::s21_stack<T>::s21_stack(s21_stack &&s) : s21::s21_stack<T>(s) {
  this->clear();
}

template <typename T>
s21::s21_stack<T> s21::s21_stack<T>::operator=(const s21_stack &&s) {
  if (this->head_) {
    this->clear();
  }
  Node<value_type> *tmp = s.head_;
  while (tmp != nullptr) {
    this->push_back(tmp->data_);
    tmp = tmp->pNext_;
  }
  return *this;
}

template <typename T>
void s21::s21_stack<T>::push_back(value_type data_) {
  if (this->head_ == nullptr) {
    this->head_ = new Node<value_type>(data_);
  } else {
    Node<value_type> *tmp = this->head_;
    while (tmp->pNext_ != nullptr) {
      tmp = tmp->pNext_;
    }
    tmp->pNext_ = new Node<value_type>(data_);
    tmp->pNext_->pBack_ = tmp;
  }
  ++(this->sz_);
}

template <typename T>
s21::s21_stack<T>::~s21_stack<T>() {
  clear();
}

template <typename T>
const T &s21::s21_stack<T>::top() {
  return this->head_->data_;
}

template <typename T>
void s21::s21_stack<T>::push(value_type data_) {
  this->head_ = new Node<value_type>(data_, this->head_);
  (this->sz_)++;
}

template <typename T>
void s21::s21_stack<T>::pop() {
  Node<value_type> *tmp = this->head_;
  this->head_ = this->head_->pNext_;
  if (tmp != nullptr) delete tmp;
  (this->sz_)--;
}

template <typename T>
size_t s21::s21_stack<T>::size() {
  return this->get_size();
}

template <typename T>
void s21::s21_stack<T>::swap(s21_stack &other) {
  s21_stack<T> tmp_this(*this);
  s21_stack<T> tmp_other(other);
  this->clear();
  other.clear();
  for (size_t i = 0; i < tmp_this.size(); ++i) {
    other.push(tmp_this.top());
    tmp_this.pop();
  }
  for (size_t i = 0; i < tmp_other.size(); ++i) {
    this->push(tmp_other.top());
    tmp_other.pop();
  }
}

template <typename T>
void s21::s21_stack<T>::clear() {
  while (this->sz_) {
    this->pop();
  }
}
