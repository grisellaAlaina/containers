//
// Created by Grisella Alaina on 3/28/23.
//

#ifndef UNTITLED2_S21_ABSTRACT_CLASS_H
#define UNTITLED2_S21_ABSTRACT_CLASS_H

#include <iostream>

namespace s21 {

    template <typename T>
    class abstract_iterator {
    public:
        virtual T &operator*() = 0;
    };

    template<typename T>
    class Node {
    public:
        Node *pNext_;
        Node *pBack_;
        T data_;

        Node(T data = T(), Node *Next = nullptr, Node *Back = nullptr) {
            data_ = data;
            pNext_ = Next;
            pBack_ = Back;
        }
    };

    template<typename T>
    class abstract_containters {
    
    public:
        abstract_containters() : sz_(0) {}
        size_t virtual max_size() {
            std::allocator<T> alloc;
            return alloc.max_size();
        }
        bool empty() { return !(sz_ > 0); }
        size_t get_size() { return sz_; }

    protected:
        size_t sz_;
    };

    template<typename T>
    class abstr_list : public abstract_containters<T> {
    
    public:
        abstr_list() : abstract_containters<T>(), head_(nullptr), tail_(nullptr) {}
    
    protected:
        Node<T> *head_;
        Node<T> *tail_;
        
    };
}


#endif //UNTITLED2_S21_ABSTRACT_CLASS_H
