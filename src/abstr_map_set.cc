#include "abstr_map_set.h"

template <typename T, typename S>
void abstr_map_set<T, S>::destroy(Nodeb<T, S> *&nodePtr) {
  if (nodePtr == nullptr) return;
  destroy(nodePtr->left);
  destroy(nodePtr->right);
  delete nodePtr;
  nodePtr = nullptr;
}

template <typename T, typename S>
iterator_tree<T, S>& iterator_tree<T, S>::operator++() {
  if (elem->right) {
    elem = elem->right;
    while (elem->left) {
      elem = elem->left;
    }
  } else {
    while (elem->parent) {
      Nodeb<T, S>* tmp = elem;
      elem = elem->parent;
      if (tmp->pair <= elem->pair) {
        break;
      }
    }
  }
  elem->flag = 1;
  return *this;
}

template <typename T, typename S>
iterator_tree<T, S> &iterator_tree<T, S>::operator--() {
  if (elem->left) {
    elem = elem->left;
    while (elem->right) {
      elem = elem->right;
    }
  } else {
    std::pair<T, S> tmp = elem->pair;
    while (elem->parent) {
      elem = elem->parent;
      if (tmp >= elem->pair) return *this;
    }
  }
  return *this;
}

template<typename T, typename S>
void abstr_map_set<T, S>::update_min_max(Nodeb<T, S> *&nodePtr) {
    if (this->minn_ == nullptr || nodePtr->pair.first < this->minn_->pair.first) {
        this->minn_ = nodePtr;
    }
    if (this->maxn_ == nullptr || this->maxn_->pair.first < nodePtr->pair.first) {
      this->maxn_ = nodePtr;
    }
}



template <typename T, typename S>
void abstr_map_set<T, S>::clear() {
  this->destroy(this->root_);
  this->maxn_ = nullptr;
  this->minn_ = nullptr;
  this->sz_ = 0;
}

template <typename T, typename S>
Nodeb<T, S> *abstr_map_set<T, S>::find_pair(Nodeb<T, S> *nodePtr, const T &key) {
  if (nodePtr == nullptr) return nullptr;
  if (key < nodePtr->pair.first) {
    return find_pair(nodePtr->left, key);
  } else if (key > nodePtr->pair.first) {
    return find_pair(nodePtr->right, key);
  } else {
    return nodePtr;
  }
}

template <typename T, typename S>
size_t abstr_map_set<T, S>::max_size() {
    return std::numeric_limits<size_t>::max();
    }

template<typename T, typename S>
void abstr_map_set<T, S>::update_mm_remove(Nodeb<T, S> *&nodePtr) {
  if (nodePtr->pair.first == this->minn_->pair.first || nodePtr->pair.first == this->maxn_->pair.first) {
  if (nodePtr->right == nullptr && nodePtr->left == nullptr) {
  if (nodePtr->pair.first == this->minn_->pair.first) {
    this->minn_ = nodePtr->parent;
  }
  if (nodePtr->pair.first == this->maxn_->pair.first) {
    this->maxn_ = nodePtr->parent;
  }
  }
   else if (nodePtr->left == nullptr) {
     this->minn_ = nodePtr->right;
   }
  }
}

template <typename T, typename S>
void abstr_map_set<T, S>::remove(Nodeb<T, S> *(&nodePtr), std::pair<T, S> value) {
  if (nodePtr == nullptr) return;
  if (value < nodePtr->pair) {
    remove(nodePtr->left, value);
  } else if (value > nodePtr->pair) {
    remove(nodePtr->right, value);
  } else {
    if (nodePtr->right == nullptr && nodePtr->left == nullptr) {
      this->update_mm_remove(nodePtr);
      delete nodePtr;
      nodePtr = nullptr;
      this->sz_ -= 1;
    } 
    else if (nodePtr->right == nullptr || nodePtr->left == nullptr) {
       Nodeb<T, S> *parent = nodePtr->parent;
       this->update_mm_remove(nodePtr);
      Nodeb<T, S> *tmp;
      if (nodePtr->left)
        {
          tmp =  nodePtr;
          nodePtr = nodePtr->left;
        }
      else 
              {
          tmp =  nodePtr;
          nodePtr = nodePtr->right;
        }
        delete tmp;
      nodePtr->parent = parent;
      this->sz_ -=1;
    } else {
      Nodeb<T, S> *smalest = find_smalest(nodePtr->right);
      nodePtr->pair = smalest->pair;
      remove(nodePtr->right, smalest->pair);
      this->sz_ -=1;
    }
  }
}

template <typename T, typename S>
Nodeb<T, S>* abstr_map_set<T, S>::find_smalest(Nodeb<T, S> *nodePtr) {
   if (nodePtr->left != nullptr){
     return find_smalest(nodePtr->left);
   }
   return nodePtr;
}


