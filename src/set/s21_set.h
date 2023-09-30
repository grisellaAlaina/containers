//
// Created by Grisella Alaina on 3/28/23.
//

#ifndef S21_SET_H
#define S21_SET_H

#include "../abstr_map_set.h"

namespace s21 {

template <typename T, typename S = T>
class s21_set : public abstr_map_set<T, S> {
 public:
  using key_type = T;
  using value_type = std::pair<const T, T>;
  using refernce = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_set<T, S>;
  using const_iterator = const iterator_set<T, S>;
  using size_type = size_t;

  s21_set(){};
  s21_set(std::initializer_list<key_type> const &items);
  s21_set(s21_set &s);
  s21_set(s21_set &&s);
  ~s21_set() { this->destroy(this->root_); };
  s21_set &operator=(s21_set &s);
  s21_set &operator=(s21_set &&s);

  iterator begin();
  iterator end();
  std::pair<iterator, bool> insert(const key_type &key);
  void erase(iterator pos);
  void swap(s21_set &other);
  void merge(s21_set &other);

 protected:
  std::pair<iterator, bool> push(Nodeb<T, S> *(&NodePtr),
                                 std::pair<T, S> value);
  void moveAssign(s21_set &&s);
};

}  // namespace s21

#endif  // S21_SET_H
