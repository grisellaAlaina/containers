//
// Created by Grisella Alaina on 3/28/23.
//

#include "s21_set.h"

using namespace s21;

template <typename T, typename S>
s21_set<T, S>::s21_set(std::initializer_list<key_type> const &items) {
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <typename T, typename S>
typename s21_set<T, S>::iterator s21_set<T, S>::begin() {
  iterator it;
  it.elem = this->minn_;
  return it;
}

template <typename T, typename S>
typename s21_set<T, S>::iterator s21_set<T, S>::end() {
  iterator it;
  it.elem = this->maxn_;
  return it;
}

template <typename T, typename S>
std::pair<typename s21_set<T, S>::iterator, bool> s21_set<T, S>::insert(
    const key_type &key) {
  value_type pair = std::make_pair(key, key);
  return push(this->root_, pair);
}

template <typename T, typename S>
std::pair<typename s21_set<T, S>::iterator, bool> s21_set<T, S>::push(
    Nodeb<T, S> *&nodePtr, std::pair<T, S> value) {
  std::pair<typename s21_set<T, S>::iterator, bool> res;
  if (nodePtr == nullptr) {
    nodePtr = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
    this->sz_ += 1;
    this->update_min_max(nodePtr);
    return std::pair<typename s21_set<T, S>::iterator, bool>{nodePtr, true};
  } else if (value.first < nodePtr->pair.first) {
    if (nodePtr->left == nullptr) {
      Nodeb<T, S> *tmp = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
      nodePtr->left = tmp;
      res = {tmp, true};
      this->sz_ += 1;
      this->update_min_max(tmp);
    } else {
      res = push(nodePtr->left, value);
    }
  } else if (value.first > nodePtr->pair.first) {
    if (nodePtr->right == nullptr) {
      Nodeb<T, S> *tmp = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
      nodePtr->right = tmp;
      res = {tmp, true};
      this->sz_ += 1;
      this->update_min_max(tmp);
    } else {
      res = push(nodePtr->right, value);
    }
  } else {
    res = {nullptr, false};
  }
  return res;
}

template <typename T, typename S>
void s21_set<T, S>::erase(iterator pos) {
  this->remove(this->root_, pos.elem->pair);
}

template <typename T, typename S>
s21_set<T, S>::s21_set(s21_set &s) {
  auto it = s.begin();
  for (size_t count = 0; count < s.size(); ++it, ++count) {
    insert(*it);
  }
}

template <typename T, typename S>
s21_set<T, S> &s21_set<T, S>::operator=(s21_set &s) {
  size_t count = 0;
  this->clear();
  for (auto it = s.begin(); count < s.size(); ++it, ++count) insert(*it);
  return *this;
}

template <typename T, typename S>
s21_set<T, S>::s21_set(s21_set &&s) {
  moveAssign(std::move(s));
}

template <typename T, typename S>
s21_set<T, S> &s21_set<T, S>::operator=(s21_set &&s) {
  moveAssign(std::move(s));
  return *this;
}

template <typename T, typename S>
void s21_set<T, S>::moveAssign(s21_set &&s) {
  this->clear();
  this->root_ = s.root_;
  this->maxn_ = s.maxn_;
  this->minn_ = s.minn_;
  this->sz_ = s.sz_;
  s.root_ = nullptr;
  s.maxn_ = nullptr;
  s.minn_ = nullptr;
  s.sz_ = 0;
}

template <typename T, typename T2>
void s21_set<T, T2>::swap(s21_set &other) {
  s21_set<T, T2> temp_set = *this;
  *this = std::move(other);
  other = std::move(temp_set);
}

template <typename T, typename T2>
void s21_set<T, T2>::merge(s21_set &other) {
  size_t count = 0;
  for (auto it = other.begin(); count < other.size(); ++it, ++count)
    insert(*it);
}
