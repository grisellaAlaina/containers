//
// Created by Grisella Alaina on 3/28/23.
//

#include "s21_list.h"

template <typename T>
bool s21::const_iterator_l<T>::operator==(const const_iterator_l<T> &right) {
  return (this->const_current->data_ == right.const_current->data_);
}

template <typename T>
bool s21::const_iterator_l<T>::operator!=(const const_iterator_l &right) {
  return !(this->const_current->data_ == right.const_current->data_);
}

template <typename T>
s21::iterator_l<T> &s21::iterator_l<T>::operator++() {
  if (this->const_current->pNext_ != nullptr)
    this->const_current = this->const_current->pNext_;
  else
    this->const_current = this->begin_current;
  return *this;
}

template <typename T>
s21::iterator_l<T> &s21::iterator_l<T>::operator--() {
  if (this->const_current->pBack_ != nullptr)
    this->const_current = this->const_current->pBack_;
  return *this;
}

template <typename T>
s21::iterator_l<T> &s21::iterator_l<T>::operator++(int) {
  this->operator++();
  return *this;
}

template <typename T>
s21::iterator_l<T> &s21::iterator_l<T>::operator--(int) {
  this->operator--();
  return *this;
}

template <typename T>
T &s21::s21_list<T>::operator[](const int index) {
  int counter = 0;
  Node<value_type> *current = this->head_;
  while (current != nullptr) {
    if (counter == index) {
      return current->data_;
    }
    current = current->pNext_;
    counter++;
  }
  return this->head_->data_;
}

template <typename T>
void s21::iterator_l<T>::set_current(Node<T> *other) {
  this->const_current = other;
}

template <typename T>
s21::s21_list<T>::s21_list(std::initializer_list<value_type> const &items)
    : s21_list() {
  for (auto &i : items) {
    this->push_back(i);
  }
}

template <typename T>
s21::s21_list<T>::s21_list(size_type n) : s21_list() {
  while (n--) push_back(0);
}

template <typename T>
s21::s21_list<T>::s21_list(const s21_list &l) : s21_list() {
  Node<value_type> *current = l.head_;
  while (current != l.tail_) {
    this->push_back(current->data_);
    current = current->pNext_;
  }
}

template <typename T>
s21::s21_list<T>::s21_list(s21_list &&l) : s21_list<T>(l) {
  if (this->head_ == l.head_)
    throw std::invalid_argument("s21_list argument too large.");
  l.clear();
}

template <typename T>
s21::s21_list<T> s21::s21_list<T>::operator=(const s21_list &&l) {
  if (this->head_) {
    this->clear();
  }
  this->set_copy(l.head_, l.tail_);
  return *this;
}

template <typename T>
s21::s21_list<T> s21::s21_list<T>::operator=(const s21_list &l) {
  if (this == &l) {
    return *this;
  }
  this->set_copy(l.head_, l.tail_);
  return *this;
}

template <typename T>
void s21::s21_list<T>::push_back(value_type data_) {
  if (this->head_ == nullptr && this->tail_ == nullptr) {
    this->head_ = new Node<T>(data_);
    this->tail_ = new Node<T>;
    this->head_->pNext_ = this->tail_;
    this->tail_->pBack_ = this->head_;
    this->tail_->pNext_ = nullptr;
  } else {
    Node<T> *current = this->head_;
    while (current->pNext_ != this->tail_) {
      current = current->pNext_;
    }
    Node<T> *tmp = current;
    current->pNext_ = new Node<T>(data_);
    current->pNext_->pBack_ = tmp;
    current->pNext_->pNext_ = this->tail_;
    this->tail_->pBack_ = current->pNext_;
  }
  ++(this->sz_);
}

template <typename T>
void s21::s21_list<T>::push_front(value_type data_) {
  if (this->head_ == nullptr && this->tail_ == nullptr) {
    this->head_ = new Node<value_type>(data_, this->head_);
    this->head_->pNext_ = this->tail_;
    this->tail_->pBack_ = this->head_;
    this->tail_->pNext_ = nullptr;
  } else {
    this->head_ = new Node<value_type>(data_, this->head_);
  }
  (this->sz_)++;
}

template <typename T>
const T &s21::s21_list<T>::front() {
  return this->head_->data_;
}

template <typename T>
const T &s21::s21_list<T>::back() {
  if (this->head_ == nullptr) {
    return this->head_->data_;
  } else {
    Node<value_type> *current = this->head_;
    while (current->pNext_ != this->tail_) {
      current = current->pNext_;
    }
    return current->data_;
  }
}

template <typename T>
void s21::s21_list<T>::erase(int index) {
  if (index == 0) {
    pop_front();
  } else {
    Node<value_type> *current = this->head_;
    for (int i = 0; i < index - 1; i++) {
      current = current->pNext_;
    }
    Node<value_type> *to_delete = current->pNext_;
    current->pNext_ = to_delete->pNext_;
    if (to_delete != nullptr) delete to_delete;
    (this->sz_)--;
  }
}

template <typename T>
void s21::s21_list<T>::pop_back() {
  this->erase(this->sz_ - 1);
}

template <typename T>
void s21::s21_list<T>::pop_front() {
  Node<value_type> *current = this->head_;
  this->head_ = this->head_->pNext_;
  if (current != nullptr) delete current;
  (this->sz_)--;
}

template <typename T>
s21::s21_list<T>::~s21_list() {
  this->clear();
}

template <typename T>
void s21::s21_list<T>::clear() {
  while (this->sz_) {
    this->pop_front();
  }
  if (this->tail_ != nullptr) {
    if (this->tail_ != nullptr) delete this->tail_;
  }
  this->tail_ = nullptr;
  this->head_ = nullptr;
}

template <typename T>
void s21::s21_list<T>::set_copy(Node<T> *other, Node<T> *end) {
  while (other != end) {
    this->push_back(other->data_);
    other = other->pNext_;
  }
}

template <typename T>
void s21::s21_list<T>::sort() {
  s21_list<T> temp_this = *this;
  T temp;
  for (size_t i = 0; i < this->sz_ - 1; i++) {
    for (size_t j = 0; j < this->sz_ - i - 1; j++) {
      if (temp_this[j] > temp_this[j + 1]) {
        temp = temp_this[j];
        temp_this[j] = temp_this[j + 1];
        temp_this[j + 1] = temp;
      }
    }
  }
  *this = std::move(temp_this);
}

template <typename T>
void s21::s21_list<T>::unique() {
  Node<value_type> *current = this->head_;
  s21_list<T> temp;
  T temp_data;
  while (current != this->tail_) {
    if (temp_data != current->data_) {
      temp.push_back(current->data_);
      temp_data = current->data_;
    }
    current = current->pNext_;
  }
  *this = std::move(temp);
}

template <typename T>
void s21::s21_list<T>::swap(s21_list &other) {
  s21_list<T> temp(*this);
  *this = std::move(other);
  other = std::move(temp);
}

template <typename T>
void s21::s21_list<T>::reverse() {
  s21_list<T> temp(*this);
  size_t j = this->sz_;
  for (size_t i = 0; i < j; i++) {
    temp.push_back(this->back());
    this->pop_back();
  }
  *this = std::move(temp);
}

template <typename T>
void s21::s21_list<T>::merge(const s21_list &other) {
  this->set_copy(other.head_, other.tail_);
}

template <typename T>
void s21::s21_list<T>::splice(const_iterator pos, s21_list other) {
  iterator_l<T> tmp_it;
  tmp_it.set_current(pos.const_current);
  for (auto &&i : *this) {
    if (i == *pos) {
      for (auto &&j : other) {
        this->insert(tmp_it, j);
      }
      break;
    }
  }
}

template <typename T>
typename s21::s21_list<T>::iterator s21::s21_list<T>::insert(
    iterator pos, const_reference value) {
  size_t index = 0;
  Node<T> *current;
  for (auto i = this->begin(); i != this->end(); ++i, index++) {
    if (pos == i) break;
  }
  if (index == 0) {
    push_front(value);
  } else {
    current = this->head_;
    for (size_t y = 0; y < index - 1; y++) {
      current = current->pNext_;
    }
    current->pNext_ = new Node<T>(value, current->pNext_);
    (this->sz_)++;
  }
  iterator result;
  result.const_current = current->pNext_;
  return result;
}
