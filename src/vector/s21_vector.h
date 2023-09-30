//
// Created by Grisella Alaina on 3/25/23.
//
#ifndef S21_VECTOR_H
#define S21_VECTOR_H

#include <algorithm>
#include <cstring>
#include <iostream>

namespace s21 {
template <typename T>
class s21_vector {
 public:
  using size_type = size_t;
  using value_type = T;
  using iterator = T *;
  using const_iterator = const T *;
  using reference = T &;
  using const_reference = const T &;

  s21_vector() {}
  s21_vector(size_type n);
  s21_vector(std::initializer_list<value_type> const &items);
  s21_vector(const s21_vector &v);
  s21_vector(s21_vector &&v);

  reference at(size_type pos);
  const_reference front();
  const_reference back();
  iterator data();

  iterator begin();
  iterator end();

  reference operator[](size_type i);
  s21_vector<T> operator=(s21_vector &&v);
  s21_vector<T> operator=(s21_vector &v);

  void reserve(size_type n);

  bool empty();
  size_type size();
  size_type capacity();
  size_type max_size();
  void shrink_to_fit();
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void pop_back();
  void swap(s21_vector &other);
  void push_back(const_reference value);

  ~s21_vector() {
    if (arr_ != nullptr) delete[] arr_;
  }

 private:
  iterator arr_ = nullptr;
  size_type sz_ = 0;
  size_type cap_ = 0;
};
}  // namespace s21

#endif  // S21_VECTOR_H
