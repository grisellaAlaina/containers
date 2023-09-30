//
// Created by Grisella Alaina on 3/28/23.
//

#ifndef S21_LIST_H
#define S21_LIST_H

#include "../s21_abstract_class.h"

namespace s21 {
template <typename T>
class const_iterator_l : public abstract_iterator<T> {
 public:
  Node<T> *const_current;
  Node<T> *begin_current;
  const_iterator_l() : const_current() {}
  const_iterator_l(Node<T> *curr) : const_current(curr) {
    begin_current = const_current;
  }
  T &operator*() { return const_current->data_; }
  bool operator==(const const_iterator_l &right);
  bool operator!=(const const_iterator_l &right);
};

template <typename T>
class iterator_l : public const_iterator_l<T> {
 public:
  iterator_l() : const_iterator_l<T>() {}
  iterator_l(Node<T> *curr) : const_iterator_l<T>(curr) {}
  iterator_l &operator++();
  iterator_l &operator++(int);
  iterator_l &operator--();
  iterator_l &operator--(int);

  void set_current(Node<T> *other);
};

template <typename T>
class s21_list : public abstr_list<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = iterator_l<T>;
  using const_iterator = const_iterator_l<T>;
  using size_type = size_t;

  s21_list() : abstr_list<T>() {}
  s21_list(size_type n);
  s21_list(std::initializer_list<value_type> const &items);
  s21_list(const s21_list &l);
  s21_list(s21_list &&l);
  ~s21_list();

  s21_list<T> operator=(const s21_list &&l);
  s21_list<T> operator=(const s21_list &l);
  reference operator[](const int index);
  const_reference front();
  const_reference back();
  iterator begin() { return this->head_; }
  iterator end() { return this->tail_; }

  void clear();
  void push_back(value_type data_);
  void push_front(value_type data_);
  void erase(int index);
  void pop_back();
  void pop_front();
  void sort();
  void unique();
  void reverse();
  void swap(s21_list &other);
  void merge(const s21_list &other);
  void splice(const_iterator pos, s21_list other);

 private:
  iterator insert(iterator pos, const_reference value);
  void set_copy(Node<T> *other, Node<T> *end);
};
}  // namespace s21

#endif  // S21_LIST_H
