//
// Created by Grisella Alaina on 3/28/23.
//

#ifndef S21_STACK_H
#define S21_STACK_H

#include "../s21_abstract_class.h"

namespace s21 {
template <typename T>
class s21_stack : public abstr_list<T> {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  s21_stack() : abstr_list<T>() {}
  s21_stack(std::initializer_list<value_type> const &items);
  s21_stack(const s21_stack &s);
  s21_stack(s21_stack &&s);
  s21_stack operator=(const s21_stack &&s);

  const_reference top();

  void push(value_type data_);
  void pop();
  void swap(s21_stack &other);
  size_type size();

  ~s21_stack();

 private:
  void clear();
  void push_back(T data_);
};

}  // namespace s21

#endif  // S21_STACK_H
