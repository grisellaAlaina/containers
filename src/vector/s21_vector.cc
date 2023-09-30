//
// Created by Grisella Alaina on 3/25/23.
//

#include "s21_vector.h"

template <typename T>
s21::s21_vector<T>::s21_vector(size_type n)
    : arr_(new value_type[n]()), sz_(n), cap_(n) {}

template <typename T>
s21::s21_vector<T>::s21_vector(std::initializer_list<value_type> const& items) {
  sz_ = cap_ = items.size();
  arr_ = new value_type[sz_]();
  std::copy(items.begin(), items.end(), arr_);
}

template <typename T>
bool s21::s21_vector<T>::empty() {
  return !(sz_ > 0);
}

template <typename T>
size_t s21::s21_vector<T>::size() {
  return sz_;
}

template <typename T>
size_t s21::s21_vector<T>::capacity() {
  return cap_;
}

template <typename T>
size_t s21::s21_vector<T>::max_size() {
  std::allocator<T> alloc;
  return alloc.max_size();
}

template <typename T>
void s21::s21_vector<T>::clear() {
  while (sz_) {
    this->pop_back();
  }
}

template <typename T>
void s21::s21_vector<T>::pop_back() {
  (arr_ + sz_ - 1)->~T();
  --sz_;
}

template <typename T>
T& s21::s21_vector<T>::operator[](size_type i) {
  return arr_[i];
}

template <typename T>
void s21::s21_vector<T>::reserve(size_type n) {
  if (n >= cap_) {
    value_type* tmp = new value_type[n]();
    for (size_t i = 0; i < n; ++i) tmp[i] = std::move(arr_[i]);
    if (arr_ != nullptr) delete[] arr_;
    arr_ = nullptr;
    arr_ = tmp;
    cap_ = n;
  }
}

template <typename T>
s21::s21_vector<T>::s21_vector(const s21_vector& v) {
  if (this->arr_ != v.arr_) {
    value_type tmp = v.sz_;
    sz_ = v.sz_;
    cap_ = v.cap_;
    arr_ = new value_type[sz_]();
    for (value_type i = 0; i < tmp; i++) {
      arr_[i] = v.arr_[i];
    }
  }
}

template <typename T>
s21::s21_vector<T>::s21_vector(s21_vector&& v) {
  this->arr_ = v.arr_;
  this->sz_ = v.sz_;
  this->cap_ = v.cap_;
  v.arr_ = nullptr;
}

template <typename T>
s21::s21_vector<T> s21::s21_vector<T>::operator=(s21_vector<T>& v) {
  if (this->arr_ != v.arr_) {
    value_type tmp = v.sz_;
    sz_ = v.sz_;
    cap_ = v.cap_;
    arr_ = new value_type[sz_]();
    for (value_type i = 0; i < tmp; i++) {
      arr_[i] = v.arr_[i];
    }
  }
  return *this;
}

template <typename T>
s21::s21_vector<T> s21::s21_vector<T>::operator=(s21_vector<T>&& v) {
  if (this->arr_ != v.arr_) {
    this->swap(v);
  }
  return *this;
}

template <typename T>
void s21::s21_vector<T>::push_back(const_reference value) {
  if (sz_ == cap_) {
    reserve(2 * cap_);
  }
  new (arr_ + sz_) T(value);
  ++sz_;
}

template <typename T>
T* s21::s21_vector<T>::insert(iterator pos, const_reference value) {
  bool flag = true;
  value_type* tmp = new value_type[cap_ + 1];
  for (size_t i = 0, x = 0; i < cap_; i++, x++) {
    if ((pos == (arr_ + i)) || (pos == (arr_ + sz_))) {
      if (pos != (arr_ + sz_))
        tmp[x++] = value;
      else
        tmp[sz_] = value;
      flag = false;
    }
    tmp[x] = arr_[i];
  }
  if (!flag) {
    if (arr_ != nullptr) delete[] arr_;
    sz_++;
    arr_ = tmp;
  } else {
    if (tmp != nullptr) delete[] tmp;
    this->push_back(this->front());
  }
  for (auto i = this->begin(); i != this->end(); ++i) {
    if (*i == value) return i;
  }
  return arr_;
}

template <typename T>
void s21::s21_vector<T>::erase(iterator pos) {
  value_type* tmp = new value_type[cap_ - 1];
  for (size_t i = 0, x = 0; i < cap_; i++, x++) {
    if (pos == (arr_ + i - 1)) x--;
    tmp[x] = arr_[i];
  }
  if (arr_ != nullptr) delete[] arr_;
  --sz_;
  arr_ = tmp;
}

template <typename T>
void s21::s21_vector<T>::swap(s21_vector<T>& other) {
  if (this->arr_ != other.arr_) {
    std::swap(arr_, other.arr_);
    std::swap(sz_, other.sz_);
    std::swap(cap_, other.cap_);
  }
}

template <typename T>
void s21::s21_vector<T>::shrink_to_fit() {
  T* curr = new value_type[sz_];
  for (size_type i = 0; i < sz_; i++) {
    curr[i] = arr_[i];
  }
  cap_ = sz_;
  std::swap(arr_, curr);
  if (curr != nullptr) delete[] curr;
}

template <typename T>
T& s21::s21_vector<T>::at(size_type pos) {
  if (pos >= sz_) throw std::out_of_range("out of arr");
  return arr_[pos];
}

template <typename T>
const T& s21::s21_vector<T>::front() {
  return arr_[0];
}

template <typename T>
const T& s21::s21_vector<T>::back() {
  return arr_[sz_ - 1];
}

template <typename T>
T* s21::s21_vector<T>::data() {
  return arr_;
}

template <typename T>
T* s21::s21_vector<T>::begin() {
  return arr_;
}

template <typename T>
T* s21::s21_vector<T>::end() {
  return arr_ + sz_;
}
