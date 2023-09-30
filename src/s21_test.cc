//
// Created by Grisella Alaina on 3/25/23.
//

#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <list>

#include "vector/s21_vector.cc"
#include "queue/s21_queue.cc"
#include "list/s21_list.cc"
#include "stack/s21_stack.cc"
#include "map/s21_map.cc"
#include "set/s21_set.cc"
#include "abstr_map_set.cc"



TEST(s21_vector, cap) {
   s21::s21_vector<int> s21_vector_1(3);
   std::vector<int> std_vector_1(3);
   ASSERT_EQ(std_vector_1.capacity(), s21_vector_1.capacity());
}

TEST(s21_vector, el_access) {
   s21::s21_vector<int> s21_vector_1(3);
   std::vector<int> std_vector_1(3);
   ASSERT_EQ(std_vector_1[2], s21_vector_1[2]);
}

TEST(s21_vector, initializer_list) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   std::vector<int> std_vector_1{1, 2, 3};
   ASSERT_EQ(std_vector_1[2], s21_vector_1[2]);
}

TEST(s21_vector, empty) {
   s21::s21_vector<int> s21_vector_1;
   std::vector<int> std_vector_1;
   ASSERT_EQ(std_vector_1.empty(), s21_vector_1.empty());
}

TEST(s21_vector, max) {
   s21::s21_vector<int> s21_vector_1;
   std::vector<int> std_vector_1;
   ASSERT_EQ(std_vector_1.max_size(), s21_vector_1.max_size());
}

TEST(s21_vector, pop) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1.pop_back();
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.pop_back();
   ASSERT_EQ(std_vector_1.size(), s21_vector_1.size());
}

TEST(s21_vector, clear_sz) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1.clear();
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.clear();
   ASSERT_EQ(std_vector_1.size(), s21_vector_1.size());
}

TEST(s21_vector, push_back) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1.push_back(4);
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.push_back(4);
   ASSERT_EQ(std_vector_1[3], s21_vector_1[3]);
}

TEST(s21_vector, cap2) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1.push_back(4);
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.push_back(4);
   ASSERT_EQ(std_vector_1.capacity(), s21_vector_1.capacity());
}

TEST(s21_vector, shrink_to_fit) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1.push_back(4);
   s21_vector_1.shrink_to_fit();
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.push_back(4);
   std_vector_1.shrink_to_fit();
   ASSERT_EQ(std_vector_1.capacity(), s21_vector_1.capacity());
}

TEST(s21_vector, erase_begin) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1.push_back(4);
   s21_vector_1.erase(s21_vector_1.begin());
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.erase(std_vector_1.begin());
   ASSERT_EQ(std_vector_1[0], s21_vector_1[0]);
}

TEST(s21_vector, ens) {
   s21::s21_vector<int> s21_vector{10, 2};
   std::vector<int> std_vector{10, 2};
   auto itstd = std_vector.begin();
   auto its = s21_vector.begin();
   for (; its != s21_vector.end(); ++itstd, ++its) {
       ASSERT_EQ(*its, *itstd);
   }
}

TEST(s21_vector, swap) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21::s21_vector<int> s21_vector_2{4};
   s21_vector_1.swap(s21_vector_2);
   std::vector<int> std_vector_1{1, 2, 3};
   std::vector<int> std_vector_2{4};
   swap(std_vector_1,std_vector_2);
   ASSERT_EQ(std_vector_1[0], s21_vector_1[0]);
}

TEST(s21_vector, at) {
   s21::s21_vector<int> s21_vector_1(3);
   std::vector<int> std_vector_1(3);
   ASSERT_EQ(std_vector_1.at(2), s21_vector_1.at(2));
}

TEST(s21_vector, front) {
   s21::s21_vector<int> s21_vector_1(3);
   std::vector<int> std_vector_1(3);
   ASSERT_EQ(std_vector_1.front(), s21_vector_1.front());
}

TEST(s21_vector, back) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   std::vector<int> std_vector_1{1, 2, 3};
   ASSERT_EQ(std_vector_1.back(), s21_vector_1.back());
}

TEST(s21_vector, insert) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1.insert(std_vector_1.begin(), 8);
   s21_vector_1.insert(s21_vector_1.begin(), 8);
   ASSERT_EQ(std_vector_1[0], s21_vector_1[0]);
}

TEST(s21_vector, copy) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21::s21_vector<int> s21_vector_2 = s21_vector_1;
   std::vector<int> std_vector_1{1, 2, 3};
   std::vector<int> std_vector_2 = std_vector_1;
   ASSERT_EQ(std_vector_2[2], s21_vector_2[2]);
}

TEST(s21_vector, copy2) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21::s21_vector<int> s21_vector_2(s21_vector_1);
   std::vector<int> std_vector_1{1, 2, 3};
   std::vector<int> std_vector_2(std_vector_1);
   ASSERT_EQ(std_vector_2[2], s21_vector_2[2]);
}

TEST(s21_vector, copy_self) {
   s21::s21_vector<int> s21_vector_1{1, 2, 3};
   s21_vector_1 = s21_vector_1;
   std::vector<int> std_vector_1{1, 2, 3};
   std_vector_1 = std_vector_1;
   ASSERT_EQ(std_vector_1[2], s21_vector_1[2]);
}



TEST(s21_vector, move) {
   s21::s21_vector<int> s21_vector_1{10, 2, 3};
   std::vector<int> std_vector_1{10, 2, 3};
   s21::s21_vector<int> s21_vector_2{5, 5};
   std::vector<int> std_vector_2{5, 5};
   s21_vector_1 = std::move(s21_vector_2);
   std_vector_1 = std::move(std_vector_2);
   ASSERT_EQ(std_vector_1[0], s21_vector_1[0]);
}

TEST(s21_vector, move_sec) {
   s21::s21_vector<int> s21_vector_1{10, 2};
   std::vector<int> std_vector_1{10, 2};
   s21::s21_vector<int> s21_vector_2(std::move(s21_vector_1));
   std::vector<int> std_vector_2(std::move(std_vector_1));
   ASSERT_EQ(std_vector_2[0], s21_vector_2[0]);
}

TEST(s21_vector, data) {
   s21::s21_vector<int> s21_vector_1{10, 2, 3};
   std::vector<int> std_vector_1{10, 2, 3};
   ASSERT_EQ( *s21_vector_1.data(),  *std_vector_1.data());
}

// QUEUE ___________________________________________________

TEST(s21_queue, 1) {
   s21::s21_queue<int> s21_queue;
   s21_queue.push(3);
   std::queue<int> std_queue;
   std_queue.push(3);
   ASSERT_EQ(std_queue.front(), s21_queue.front());
}

TEST(s21_queue, 2) {
   s21::s21_queue<int> s21_queue_1{5, 4, 3, 2, 1};
   for (size_t i = 5; !s21_queue_1.empty(); i--) {
       ASSERT_EQ(i, s21_queue_1.front());
       s21_queue_1.pop();
   }
}

TEST(s21_queue, 3) {
   s21::s21_queue<int> s21_queue;
   s21_queue.push(3);
   s21_queue.pop();
   std::queue<int> std_queue;
   std_queue.push(3);
   std_queue.pop();
   ASSERT_EQ(std_queue.size(), s21_queue.size());
}

TEST(queue, 4) {
   s21::s21_queue<int> s21_queue;
   s21_queue.push(3);
   s21_queue.pop();
   std::queue<int> std_queue;
   std_queue.push(3);
   std_queue.pop();
   ASSERT_EQ(std_queue.empty(), s21_queue.empty());
}

TEST(queue, 5) {
   s21::s21_queue<int> s21_queue_1{1, 2, 3};
   std::queue<int> std_queue;
   for (size_t i = 0; i < 4 ; i++) {
       std_queue.push(i);
   }
   ASSERT_EQ(std_queue.back(), s21_queue_1.back());
}

TEST(s21_queue, 6) {
   s21::s21_queue<int> s21_queue;
   s21_queue.push(3);
   s21::s21_queue<int> s21_queue2(s21_queue);
   std::queue<int> std_queue;
   std_queue.push(3);
   std::queue<int> std_queue2 = std_queue;
   ASSERT_EQ(std_queue2.front(), s21_queue2.front());
}

TEST(queue, swap) {
   s21::s21_queue<int> s21_queue1;
   s21::s21_queue<int> s21_queue2;
   s21_queue1.push(3);
   s21_queue2.push(1);
   std::queue<int> std_queue1;
   std::queue<int> std_queue2;
   std_queue1.push(3);
   std_queue2.push(1);
   std_queue1.swap(std_queue2);
   s21_queue1.swap(s21_queue2);
   ASSERT_EQ(std_queue1.front(), s21_queue1.front());
}

TEST(queue, move) {
   s21::s21_queue<int> s21_queue1;
   s21::s21_queue<int> s21_queue2;
   s21_queue1.push(3);
   s21_queue2.push(1);
   std::queue<int> std_queue1;
   std::queue<int> std_queue2;
   std_queue1.push(3);
   std_queue2.push(1);
   std_queue1 = std::move(std_queue2);
   s21_queue1 = std::move(s21_queue2);
   ASSERT_EQ(std_queue1.front(), s21_queue1.front());
}

// STACK ___________________________________________________

TEST(s21_stack, top) {
   s21::s21_stack<int> s21_stack{1, 2, 3};
   std::stack<int> std_stack;
   for (size_t i = 1; i < 4 ; i++) {
       std_stack.push(i);
   }
   ASSERT_EQ(std_stack.top(), s21_stack.top());
}

TEST(s21_stack, pop) {
   s21::s21_stack<int> s21_stack{1, 2, 3};
   s21_stack.pop();
   std::stack<int> std_stack;
   for (size_t i = 1; i < 4 ; i++) {
       std_stack.push(i);
   }
   std_stack.pop();
   ASSERT_EQ(std_stack.top(), s21_stack.top());
}

TEST(s21_stack, empty) {
   s21::s21_stack<int> s21_stack{1, 2, 3};
   std::stack<int> std_stack;
   for (size_t i = 1; i < 4 ; i++) {
       std_stack.push(i);
   }
   ASSERT_EQ(std_stack.empty(), s21_stack.empty());
}

TEST(s21_stack, sz) {
   s21::s21_stack<int> s21_stack{1, 2, 3};
   std::stack<int> std_stack;
   for (size_t i = 1; i < 4 ; i++) {
       std_stack.push(i);
   }
   ASSERT_EQ(std_stack.size(), s21_stack.size());
}

TEST(s21_stack, copy) {
   s21::s21_stack<int> s21_stack{1, 2, 3};
   s21::s21_stack<int> s21_stack2 = s21_stack;
   std::stack<int> std_stack;
   for (size_t i = 1; i < 4 ; i++) {
       std_stack.push(i);
   }
   std::stack<int> std_stack2 = std_stack;
   ASSERT_EQ(std_stack2.size(), s21_stack2.size());
}

TEST(s21_stack, swap) {
   s21::s21_stack<int> s21_stack{1, 2, 3};
   s21::s21_stack<int> s21_stack2{4};
   std::stack<int> std_stack, std_stack2;
   for (size_t i = 1; i < 4 ; i++) {
       std_stack.push(i);
   }
   std_stack2.push(4);
   s21_stack.swap(s21_stack2);
   std_stack.swap(std_stack2);

   ASSERT_EQ(std_stack.size(), s21_stack.size());
}

TEST(s21_stack, move) {
   s21::s21_stack<int> s21_stack, s21_stack2;
   for (size_t i = 1; i < 7 ; i++) {
       s21_stack.push(i);
   }
   s21_stack2.push(4);
   s21_stack2 = (std::move(s21_stack));
   std::stack<int> std_stack, std_stack2;
   for (size_t i = 1; i < 7 ; i++) {
       std_stack.push(i);
   }
   std_stack2.push(4);
   std_stack2 = (std::move(std_stack));
   for (size_t i = 0; !std_stack2.empty(); i++) {
       ASSERT_EQ(std_stack2.top(), s21_stack2.top());
       std_stack2.pop();
       s21_stack2.pop();
   }
}

// LIST _________________________________________________

TEST(s21_list, push_back) {
    s21::s21_list<int> s21_list;
    s21_list.push_back(3);
    std::list<int> std_list;
    std_list.push_back(3);
    ASSERT_EQ(std_list.back(), s21_list.back());
}

TEST(s21_list, pfront_back_condata) {
    s21::s21_list<int> s21_list(2);
    s21_list.push_front(3);
    std::list<int> std_list(2);
    std_list.push_front(3);
    ASSERT_EQ(std_list.back(), s21_list.back());
}

TEST(s21_list, ini_list) {
    s21::s21_list<int> s21_list{1, 2, 3};
    std::list<int> std_list{1, 2, 3};
    ASSERT_EQ(std_list.back(), s21_list.back());
}

TEST(s21_list, cpy) {
    s21::s21_list<int> s21_list{1, 2, 3};
    s21::s21_list<int> s21_list2 = s21_list;
    std::list<int> std_list{1, 2, 3};
    std::list<int> std_list2 = std_list;
    ASSERT_EQ(std_list2.back(), s21_list2.back());
}

TEST(s21_list, cpy_self) {
    s21::s21_list<int> s21_list{1, 2, 3};
    s21_list = s21_list;
    std::list<int> std_list{1, 2, 3};
    std_list = std_list;
    ASSERT_EQ(std_list.back(), s21_list.back());
}

TEST(s21_list, move) {
    s21::s21_list<int> s21_list{1};
    s21::s21_list<int> s21_list2{4};
    std::list<int> std_list{1};
    std::list<int> std_list2{4};
    s21_list = std::move(s21_list2);
    std_list = std::move(std_list2);
    int j = std_list.size();
    for (int i = 0; i < j; ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
}

TEST(s21_list, move_self) {
    s21::s21_list<int> s21_list{1};
    std::list<int> std_list{1};
    s21_list = std::move(s21_list);
    std_list = std::move(std_list);
    int j = std_list.size();
    for (int i = 0; i < j; ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
}


TEST(s21_list, move_sec) {
    s21::s21_list<int> s21_list{1, 2, 3};
    s21::s21_list<int> s21_list2(std::move(s21_list));
    std::list<int> std_list{1, 2, 3};
    std::list<int> std_list2(std::move(std_list));
    int j = std_list2.size();
    for (int i = 0; i < j; ++i) {
        ASSERT_EQ(std_list2.back(), s21_list2.back());
        std_list2.pop_back();
        s21_list2.pop_back();
    }
}

TEST(s21_list, sort) {
    s21::s21_list<int> s21_list{3, 2, 4, 1};
    std::list<int> std_list{3, 2, 4, 1};
    s21_list.sort();
    std_list.sort();
    for (int i = 0; i < 4; ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
    }

TEST(s21_list, unique) {
    s21::s21_list<int> s21_list{3, 2, 4, 4, 1, 5, 5};
    std::list<int> std_list{3, 2, 4, 4, 1, 5, 5};
    s21_list.unique();
    std_list.unique();
    for (int i = 0; i < 5; ++i) {
        ASSERT_EQ(std_list.front(), s21_list.front());
        std_list.pop_front();
        s21_list.pop_front();
    }
}

TEST(s21_list, reverse) {
    s21::s21_list<int> s21_list{3, 2, 4, 1};
    std::list<int> std_list{3, 2, 4, 1};
    s21_list.reverse();
    std_list.reverse();
    for (size_t i = 0; i < 4; ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
}

TEST(s21_list, swap) {
    s21::s21_list<int> s21_list{3, 2, 4, 1};
    s21::s21_list<int> s21_list_2{5, 6, 7, 8};
    std::list<int> std_list{3, 2, 4, 1};
    std::list<int> std_list_2{5, 6, 7, 8};
    s21_list.swap(s21_list_2);
    std_list.swap(std_list_2);
    for (size_t i = 0; i < std_list.size(); ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
}

TEST(s21_list, merge) {
    s21::s21_list<int> s21_list{3, 2, 4, 1};
    s21::s21_list<int> s21_list_2{5, 6, 7, 8};
    std::list<int> std_list{3, 2, 4, 1};
    std::list<int> std_list_2{5, 6, 7, 8};
    s21_list.merge(s21_list_2);
    std_list.merge(std_list_2);
    size_t j = std_list.size();
    for (size_t i = 0; i < j; ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
}

TEST(s21_list, splice) {
    s21::s21_list<int> s21_list{3, 2, 4, 1};
    s21::s21_list<int> s21_list_2{5, 6, 7, 8};
    std::list<int> std_list{3, 2, 4, 1};
    std::list<int> std_list_2{5, 6, 7, 8};
    s21_list.splice(s21_list.begin(), s21_list_2);
    std_list.splice(std_list.begin(), std_list_2);
    size_t j = std_list.size();
    for (size_t i = 0; i < j; ++i) {
        ASSERT_EQ(std_list.back(), s21_list.back());
        std_list.pop_back();
        s21_list.pop_back();
    }
}

// MAP_________________________________________

TEST(s21_map, create) {
    s21::s21_map<int, int> s21_map;
    std::map<int, int> std_map;
    
    ASSERT_EQ(s21_map.size(), std_map.size());
    
    }

TEST(s21_map, initializer_list) {
    s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
    std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

    size_t count = 0;
    auto it = s21_map.begin();
    auto std_it = std_map.begin(); 
    
    for (; count < s21_map.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
    }

    TEST(s21_map, end) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

  std::map<int, int>::iterator s_it(std::prev(std_map.end()));
  s21::s21_map<int, int>::iterator s21_it(s21_map.end());

  ASSERT_EQ(s21_it.elem->pair.first, s_it->first);
}

TEST(s21_map, begin) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

  std::map<int, int>::iterator s_it(std_map.begin());
  s21::s21_map<int, int>::iterator s21_it(s21_map.begin());

  ASSERT_EQ(s21_it.elem->pair.first, s_it->first);
}

TEST(s21_map, size) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};


  ASSERT_EQ(s21_map.size(), std_map.size());
}

TEST(s21_map, empty) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};


  ASSERT_EQ(s21_map.empty(), std_map.empty());
}

TEST(s21_map, contains) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

  ASSERT_EQ(s21_map.contains(7098), false);
}

TEST(s21_map, clear) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  s21_map.clear();

  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std_map.clear();

  ASSERT_EQ(s21_map.empty(), std_map.empty());   
}

TEST(s21_map, at) {
  s21::s21_map<int, int> s21_map{{7, 5}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map{{7, 5}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

  ASSERT_EQ(s21_map.at(7), std_map.at(7));   
}

TEST(s21_map, operator) {
  s21::s21_map<int, int> s21_map{{7, 5}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map{{7, 5}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

  ASSERT_EQ(s21_map[7], std_map[7]);   
}

TEST(s21_map, char) {
  s21::s21_map<char, int> s21_map{{'d', 5}};
  std::map<char, int> std_map{{'d', 5}};

  ASSERT_EQ(s21_map[7], std_map[7]);   
}

TEST(s21_map, erase) {
    s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
    std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

    auto s21_it = s21_map.begin();
    auto stder_it = std_map.begin();

    s21_map.erase(s21_it);
    std_map.erase(stder_it);

    size_t count = 0;
    auto it = s21_map.begin();
    auto std_it = std_map.begin();     
    for (; count < s21_map.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
    }

  TEST(s21_map, copy) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  s21::s21_map<int, int> s21_map_sec(s21_map);

  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map_sec(std_map);

    size_t count = 0;
    auto it = s21_map_sec.begin();
    auto std_it = std_map_sec.begin(); 
    
    for (; count < s21_map.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
}



TEST(s21_map, copy_operator) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  s21::s21_map<int, int> s21_map_sec{{44, 1}, {234, 1}};
  s21_map_sec = s21_map;

  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map_sec{{44, 1}, {234, 1}};
  std_map_sec = std_map;

    size_t count = 0;
    auto it = s21_map_sec.begin();
    auto std_it = std_map_sec.begin(); 
    
    for (; count < std_map_sec.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
}

TEST(s21_map, copy_operator_self) {

  s21::s21_map<int, int> s21_map_sec{{44, 1}, {234, 1}};
  s21_map_sec = s21_map_sec;

  std::map<int, int> std_map_sec{{44, 1}, {234, 1}};
  std_map_sec = std_map_sec;
  for (const auto& pair : std_map_sec) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    size_t count = 0;
    auto it = s21_map_sec.begin();
    auto std_it = std_map_sec.begin(); 
    for (; count < std_map_sec.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
}

TEST(s21_map, move) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  s21::s21_map<int, int> s21_map_sec{{44, 1}, {234, 1}};
  s21_map_sec = std::move(s21_map);

  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map_sec{{44, 1}, {234, 1}};
  std_map_sec = std::move(std_map);

    size_t count = 0;
    auto it = s21_map_sec.begin();
    auto std_it = std_map_sec.begin(); 
    for (; count < s21_map_sec.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
  ASSERT_EQ(s21_map.empty(), std_map.empty());   
}

TEST(s21_map, move_sec) {
  s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  s21::s21_map<int, int> s21_map_sec(std::move(s21_map));

  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map_sec(std::move(std_map));

    size_t count = 0;
    auto it = s21_map_sec.begin();
    auto std_it = std_map_sec.begin(); 
    for (; count < s21_map_sec.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
  ASSERT_EQ(s21_map.empty(), std_map.empty());   
}

TEST(s21_map, move_sec_self) {
 s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  s21::s21_map<int, int> s21_map_sec{{44, 1}, {234, 1}};
  s21_map_sec = std::move(s21_map_sec);

  std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
  std::map<int, int> std_map_sec{{44, 1}, {234, 1}};
  std_map_sec = std::move(std_map_sec);

    size_t count = 0;
    auto it = s21_map_sec.begin();
    auto std_it = std_map_sec.begin(); 
    for (; count < s21_map_sec.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
  ASSERT_EQ(s21_map.empty(), std_map.empty());   
}

    TEST(s21_map, swap) {
    s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
    s21::s21_map<int, int> s21_map2{{50, 1}, {55, 1}};
    std::map<int, int> std_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
    std::map<int, int> std_map2{{50, 1}, {55, 1}};

    std_map2.swap(std_map);
    s21_map2.swap(s21_map);

    size_t count = 0;
    auto it = s21_map2.begin();
    auto std_it = std_map2.begin(); 
    
    ASSERT_EQ(std_map2.size(), s21_map2.size());
    for (; count < s21_map2.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
    }

TEST(s21_map, merge) {
    s21::s21_map<int, int> s21_map{{7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};
    s21::s21_map<int, int> s21_map2{{50, 1}, {55, 1}};
    std::map<int, int> std_map2{{50, 1}, {55, 1}, {7, 1}, {33, 1}, {12, 1}, {2, 1}, {333, 1}};

    s21_map2.merge(s21_map);

    size_t count = 0;
    auto it = s21_map2.begin();
    auto std_it = std_map2.begin(); 
    
    ASSERT_EQ(std_map2.size(), s21_map2.size());
    for (; count < s21_map2.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, std_it->first);
    }
    }

// SET __________________________________________

TEST(s21_set, create) {

    s21::s21_set<int> s21_set;
    std::set<int> std_set;

   ASSERT_EQ(s21_set.size(), std_set.size());
    }

TEST(s21_set, initializer_list) {
    s21::s21_set<int> s21_set{7, 5, 8, 8};
    std::set<int> std_set{7, 5, 7, 8};

    size_t count = 0;
    auto it = s21_set.begin();
    auto std_it = std_set.begin(); 
    
    for (; count < s21_set.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
    }

    TEST(s21_set, end) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  std::set<int> std_set{3, 4, 5, 6, 4};

  std::set<int>::iterator s_it(std::prev(std_set.end()));
  s21::s21_set<int>::iterator s21_it(s21_set.end());

  ASSERT_EQ(s21_it.elem->pair.first, *s_it);
}

TEST(s21_set, begin) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  std::set<int> std_set{3, 4, 5, 6, 4};

  std::set<int>::iterator s_it(std_set.begin());
  s21::s21_set<int>::iterator s21_it(s21_set.begin());

  ASSERT_EQ(s21_it.elem->pair.first, *s_it);
}

TEST(s21_set, size) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  std::set<int> std_set{3, 4, 5, 6, 4};


  ASSERT_EQ(s21_set.size(), std_set.size());
}

TEST(s21_set, empty) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  std::set<int> std_set{3, 4, 5, 6, 4};


  ASSERT_EQ(s21_set.empty(), std_set.empty());
}

TEST(s21_set, clear) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  s21_set.clear();

  std::set<int> std_set{3, 4, 5, 6, 4};
  std_set.clear();

  ASSERT_EQ(s21_set.empty(), std_set.empty());   
}

TEST(s21_set, erase) {
    s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
    std::set<int> std_set{3, 4, 5, 6, 4};

    auto s21_it = s21_set.begin();
    auto stder_it = std_set.begin();

    s21_set.erase(s21_it);
    std_set.erase(stder_it);

    size_t count = 0;
    auto it = s21_set.begin();
    auto std_it = std_set.begin();     
    for (; count < s21_set.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
    }

    TEST(s21_set, copy) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  s21::s21_set<int> s21_set_sec(s21_set);

  std::set<int> std_set{3, 4, 5, 6, 4};
  std::set<int> std_set_sec(std_set);

    size_t count = 0;
    auto it = s21_set_sec.begin();
    auto std_it = std_set_sec.begin(); 
    
    for (; count < s21_set.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
}

TEST(s21_set, copy_operator) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  s21::s21_set<int> s21_set_sec{44, 234};
  s21_set_sec = s21_set;

  std::set<int> std_set{3, 4, 5, 6, 4};
  std::set<int> std_set_sec{44, 234};
  std_set_sec = std_set;

    size_t count = 0;
    auto it = s21_set_sec.begin();
    auto std_it = std_set_sec.begin(); 
    
    for (; count < std_set.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
}

TEST(s21_set, move) {
  s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
  s21::s21_set<int> s21_set_sec{44, 234};
  s21_set_sec = std::move(s21_set);

  std::set<int> std_set{3, 4, 5, 6, 4};
  std::set<int> std_set_sec{44, 234};
  std_set_sec = std::move(std_set);

    size_t count = 0;
    auto it = s21_set_sec.begin();
    auto std_it = std_set_sec.begin(); 
    for (; count < s21_set_sec.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
  ASSERT_EQ(s21_set.empty(), std_set.empty());   
}


    TEST(s21_set, swap) {
    s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
    s21::s21_set<int> s21_set2{50, 55};
    std::set<int> std_set{3, 4, 5, 6, 4};
    std::set<int> std_set2{50, 55};


    std_set2.swap(std_set);
    s21_set2.swap(s21_set);

    size_t count = 0;
    auto it = s21_set2.begin();
    auto std_it = std_set2.begin(); 
    
    ASSERT_EQ(std_set2.size(), s21_set2.size());
    for (; count < s21_set2.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
    }

TEST(s21_set, merge) {
    s21::s21_set<int> s21_set{3, 4, 5, 6, 4};
    s21::s21_set<int> s21_set2{50, 55};
    std::set<int> std_set2{50, 55, 3, 4, 5, 6, 4};


    s21_set2.merge(s21_set);

    size_t count = 0;
    auto it = s21_set2.begin();
    auto std_it = std_set2.begin(); 
    
    ASSERT_EQ(std_set2.size(), s21_set2.size());
    for (; count < s21_set2.size(); ++it, ++std_it, ++count) {
        ASSERT_EQ(it.elem->pair.first, *std_it);
    }
    }

    int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



