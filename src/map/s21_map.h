//
// Created by Grisella Alaina on 3/28/23.
//

#ifndef S21_MAP_H
#define S21_MAP_H

#include "../abstr_map_set.h"

namespace s21 {
template <typename T, typename S>
class s21_map : public abstr_map_set<T, S> {
 public:
  using key_type = T;
  using mapped_type = S;
  using value_type = std::pair<const key_type, mapped_type>;
  using refernce = value_type &;
  using const_reference = const value_type &;
  using iterator = iterator_map<T, S>;
  using size_type = size_t;

  s21_map(){};
  s21_map(std::initializer_list<value_type> const &items);
  s21_map(s21_map &m);
  s21_map(s21_map &&m);
  s21_map &operator=(s21_map &m);
  s21_map &operator=(s21_map &&m);
  ~s21_map();

  iterator begin();
  iterator end();
  iterator next(iterator it);
  std::pair<iterator, bool> insert(const value_type &value);
  std::pair<iterator, bool> insert(const T &key, const S &obj);
  std::pair<iterator, bool> push(Nodeb<T, S> *(&NodePtr),
                                 std::pair<T, S> value);
  std::pair<iterator, bool> insert_or_assign(const T &key, const S &obj);
  S &at(const T &key);
  S &operator[](const T &key);
  void erase(iterator pos);
  void swap(s21_map &other);
  void merge(s21_map &other);

  bool contains(T value);

 private:
  std::pair<iterator, bool> insert_or_assign_helper(const std::pair<T, S> value,
                                                    Nodeb<T, S> *(&nodePtr));
  void moveAssign(s21_map &&m);
};
};  // namespace s21

#endif  // S21_MAP_H
