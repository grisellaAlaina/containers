#ifndef ABSTR_MAP_SET_H
#define ABSTR_MAP_SET_H

#include <initializer_list>
#include <iostream>
#include <utility>
#include <vector>

namespace s21 {

  template <typename T, typename S>
struct Nodeb {
  std::pair<T, S> pair;
  Nodeb<T, S> *parent = nullptr;
  Nodeb<T, S> *left = nullptr;
  Nodeb<T, S> *right = nullptr;
  int flag = 0;
  
  Nodeb(std::pair<T, S> two, Nodeb *p, Nodeb *l, Nodeb *r)
      : pair(two), parent(p), left(l), right(r){};

  Nodeb() : parent(nullptr), left(nullptr), right(nullptr){};
};

template <typename T, typename S>
class iterator_tree {
 public:
  Nodeb<T, S> *elem;
  iterator_tree<T, S> &operator++();
  iterator_tree<T, S> &operator--();
  bool operator!=(const iterator_tree<T, S> &it) { return elem != it.elem; }
  bool operator==(const iterator_tree<T, S> &it) { return elem == it.elem; }
};

template <typename T, typename S>
class iterator_map : public iterator_tree<T, S> {
 public:
  iterator_map() { this->elem = nullptr; }
  iterator_map(Nodeb<T, S> *ref) { this->elem = ref; }
  std::pair<T, S> &operator*() { return this->elem->pair; }
};

template <typename T, typename S>
class iterator_set : public iterator_tree<T, S> {
 public:
  iterator_set() { this->elem = nullptr; }
  iterator_set(Nodeb<T, S> *ref) { this->elem = ref; }
  T &operator*() { return this->elem->pair.first; }
};

  template <typename T, typename S>
  class abstr_map_set {

    public:
    size_t size() { return sz_; }
    bool empty() {return (sz_ == 0) ? true : false; }
    void clear();
    size_t max_size();
    
    protected:
    Nodeb<T, S> *root_ = nullptr;
    Nodeb<T, S> *maxn_ = nullptr;
    Nodeb<T, S> *minn_ = nullptr;
    size_t sz_ = 0;
    void destroy(Nodeb<T, S> *&nodePtr);
    void update_min_max(Nodeb<T, S> *&nodePtr);
    void update_mm_remove(Nodeb<T, S> *&nodePtr);
    void remove(Nodeb<T, S> *&nodePtr, std::pair<T, S> value);
    Nodeb<T, S> *find_smalest(Nodeb<T, S> *nodePtr);
    Nodeb<T, S> *find_pair(Nodeb<T, S> *nodePtr, const T &key);
  };
}

#endif