//
// Created by Grisella Alaina on 3/28/23.
//

#include "s21_map.h"

using namespace s21;

template <typename T, typename S>
s21_map<T, S>::s21_map(std::initializer_list<value_type> const &items) {
  for (auto it = items.begin(); it != items.end(); it++) {
    insert(*it);
  }
}

template <typename T, typename S>
s21_map<T, S>::~s21_map() {
  this->destroy(this->root_);
}

template <typename T, typename S>
typename s21_map<T, S>::iterator s21_map<T, S>::begin() {
  iterator it;
  it.elem = this->minn_;
  return it;
}

template <typename T, typename S>
typename s21_map<T, S>::iterator s21_map<T, S>::next(iterator it) {
  return ++it;
}

template <typename T, typename S>
typename s21_map<T, S>::iterator s21_map<T, S>::end() {
  iterator it;
  it.elem = this->maxn_;
  return it;
}

template <typename T, typename S>
std::pair<typename s21_map<T, S>::iterator, bool> s21_map<T, S>::insert(
    const value_type &value) {
  return push(this->root_, value);
}

template <typename T, typename S>
std::pair<typename s21_map<T, S>::iterator, bool> s21_map<T, S>::insert(
    const T &key, const S &obj) {
  return insert(std::make_pair(key, obj));
}

template <typename T, typename S>
std::pair<typename s21_map<T, S>::iterator, bool>
s21_map<T, S>::insert_or_assign(const T &key, const S &obj) {
  return (insert_or_assign_(std::make_pair(key, obj), this->root_));
}

template <typename T, typename S>
s21_map<T, S>::s21_map(s21_map &m) {
  auto it = m.begin();
  for (size_t count = 0; count < m.size(); ++it, ++count) {
    insert(*it);
  }
}

template <typename T, typename S>
s21_map<T, S>::s21_map(s21_map &&m) {
  moveAssign(std::move(m));
}

template <typename T, typename S>
s21_map<T, S> &s21_map<T, S>::operator=(s21_map &m) {
  if (this != &m) {
    size_t count = 0;
    this->clear();
    for (auto it = m.begin(); count < m.size(); ++it, ++count) insert(*it);
  }
  return *this;
}

template <typename T, typename S>
s21_map<T, S> &s21_map<T, S>::operator=(s21_map &&m) {
  moveAssign(std::move(m));
  return *this;
}

template <typename T, typename S>
void s21_map<T, S>::moveAssign(s21_map &&m) {
  this->clear();
  this->root_ = m.root_;
  this->maxn_ = m.maxn_;
  this->minn_ = m.minn_;
  this->sz_ = m.sz_;
  m.root_ = nullptr;
  m.maxn_ = nullptr;
  m.minn_ = nullptr;
  m.sz_ = 0;
}

template <typename T, typename S>
S &s21_map<T, S>::at(const T &key) {
  iterator it(this->find_pair(this->root_, key));
  if (it.elem == nullptr) throw std::out_of_range("Map: at: out of range");
  return it.elem->pair.second;
}

template <typename T, typename S>
S &s21_map<T, S>::operator[](const T &key) {
  if (!this->find_pair(this->root_, key)) {
    insert(key, S());
  }
  iterator it(this->find_pair(this->root_, key));
  return it.elem->pair.second;
}

template <typename T, typename S>
std::pair<typename s21_map<T, S>::iterator, bool> s21_map<T, S>::push(
    Nodeb<T, S> *&nodePtr, std::pair<T, S> value) {
  std::pair<typename s21_map<T, S>::iterator, bool> res;
  if (nodePtr == nullptr) {
    nodePtr = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
    this->sz_ += 1;
    this->update_min_max(nodePtr);
    return std::pair<typename s21_map<T, S>::iterator, bool>{nodePtr, true};
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
    Nodeb<T, S> *tmp = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
    res = {tmp, false};
  }
  return res;
}

template <typename T, typename S>
std::pair<typename s21_map<T, S>::iterator, bool>
s21_map<T, S>::insert_or_assign_helper(std::pair<T, S> value,
                                       Nodeb<T, S> *&nodePtr) {
  std::pair<typename s21_map<T, S>::iterator, bool> res;

  if (nodePtr == nullptr) {
    nodePtr = new Nodeb<T, S>(value, nullptr, nullptr, nullptr);
    res = {nodePtr, true};
  } else if (value.first < nodePtr->pair.first) {
    if (nodePtr->left == nullptr) {
      Nodeb<T, S> *tmp = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
      nodePtr->left = tmp;
      res = {tmp, true};
    } else {
      res = insert_or_assign_helper(value, nodePtr->left);
    }
  } else if (value.first > nodePtr->pair.first) {
    if (nodePtr->right == nullptr) {
      Nodeb<T, S> *tmp = new Nodeb<T, S>(value, nodePtr, nullptr, nullptr);
      nodePtr->right = tmp;
      res = {tmp, true};
    } else {
      res = insert_or_assign_helper(value, nodePtr->right);
    }
  } else {
    nodePtr->pair = value;
    res = {nodePtr, false};
  }
  if (res.second) {
    this->sz_ += 1;
    this->update_min_max(res.first);
  }
  return res;
}

template <typename T, typename S>
void s21_map<T, S>::erase(iterator pos) {
  this->remove(this->root_, pos.elem->pair);
}

template <typename T, typename S>
bool s21_map<T, S>::contains(T value) {
  bool res = false;
  size_t count = 0;
  for (auto it = this->begin(); count < this->sz_; ++count, ++it) {
    if (it.elem->pair.first == value) {
      return res = true;
    }
  }
  return res;
}

template <typename T, typename T2>
void s21_map<T, T2>::swap(s21_map &other) {
  s21_map<T, T2> temp = *this;
  *this = std::move(other);
  other = std::move(temp);
}

template <typename T, typename T2>
void s21_map<T, T2>::merge(s21_map &other) {
  size_t count = 0;
  for (auto it = other.begin(); count < other.size(); ++it, ++count)
    insert(*it);
}
