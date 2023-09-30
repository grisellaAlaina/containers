//
// Created by Grisella Alaina on 3/28/23.
//

#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <initializer_list>
#include <iostream>

#include "../s21_abstract_class.h"

namespace s21 {
template <typename T>
class s21_queue : public abstr_list<T> {
 public:
  using size_type = size_t;
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;

  s21_queue() : abstr_list<T>() {}
  s21_queue(std::initializer_list<value_type> const &items);
  s21_queue(const s21_queue &q);
  s21_queue(s21_queue &&q);

  s21_queue<T> &operator=(const s21_queue &s);

  size_type size();
  bool empty();
  void push(value_type data_);
  void pop();
  void swap(s21_queue &other);

  const_reference front();
  const_reference back();

  ~s21_queue();

 private:
  void clear();
};
}  // namespace s21

#endif  // S21_QUEUE_H
