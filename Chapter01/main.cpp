#include <algorithm>
#include <iostream>
#include <list>

struct CircularllNode {
  std::string data;
  CircularllNode *prev;
  CircularllNode *next;
};
using node = CircularllNode;
using node_ptr = node *;
struct CircularllIterator {
private:
  node_ptr ptr;

public:
  CircularllIterator() = default;
  CircularllIterator(node_ptr p) : ptr(p) {}
  std::string &operator*() { return ptr->data; }
  node_ptr get() { return ptr; }
  CircularllIterator &operator++() {
    if (ptr->next == nullptr) {
      while (ptr->prev != nullptr) {
        ptr = ptr->prev;
      }
    } else {
      ptr = ptr->next;
    }
    return *this;
  }
  CircularllIterator operator++(int) {
    CircularllIterator result = *this;
    ++(*this);
    return result;
  }
  CircularllIterator &operator--() {
    if (ptr->prev == nullptr) {
      while (ptr->next != nullptr) {
        ptr = ptr->next;
      }
    } else {
      ptr = ptr->prev;
    }
    return *this;
  }
  CircularllIterator operator--(int) {
    CircularllIterator result = *this;
    --(*this);
    return result;
  }
  friend bool operator==(const CircularllIterator &left,
                         const CircularllIterator &right) {
    return left.ptr == right.ptr;
  }
  friend bool operator!=(const CircularllIterator &left,
                         const CircularllIterator &right) {
    return left.ptr != right.ptr;
  }
};
class Circularll {
private:
  node_ptr head;
  node_ptr tail;

public:
  Circularll() = default;
  Circularll(const Circularll &other) : head(NULL), tail(NULL) {
    if (other.head) {
      head = new node{0, NULL};
      auto cur = head;
      auto it = other.begin();
      while (true) {
        cur->data = *it;
        auto tmp = it;
        ++tmp;
        if (tmp == other.end())
          break;

        cur->next = new node{0, NULL};
        cur = cur->next;
        it = tmp;
      }
    }
  }

  Circularll(const std::initializer_list<std::string> &ilist)
      : head(NULL), tail(NULL) {
    for (auto it = std::rbegin(ilist); it != std::rend(ilist); it++)
      push_front(*it);
  }

  void push_front(std::string val) {
    auto new_node = new node{val, NULL, NULL};
    if (head != NULL) {
      new_node->next = head;
      head->prev = new_node;
    }
    head = new_node;
    if(tail == NULL)
      tail = head;
  }
  void pop_front() {
    auto first = head;
    if (head) {
      head = head->next;
      delete first;
    }
  }

  CircularllIterator begin() { return CircularllIterator(head); }
  CircularllIterator end() { return CircularllIterator(tail); }
  CircularllIterator begin() const { return CircularllIterator(head); }
  CircularllIterator end() const { return CircularllIterator(tail); }
};

class MusicContainer {
private:
  Circularll circular_ll_;
  CircularllIterator head_;

public:
  MusicContainer() { head_ = circular_ll_.begin(); }
  MusicContainer(const std::initializer_list<std::string> &ilist)
      : circular_ll_(ilist){};
  void printAll(){
    for(auto n: circular_ll_){
      // std::cout << n.da << std::endl;
    }
  }
  std::string next() {
    ++head_;
    return *head_;
  }
  std::string previouse();
  void insert(std::string music);
  void remove(std::string music);
};

int main(int argc, char **argv) {
  std::cout << "Chapter 01" << std::endl;
  std::initializer_list<std::string> ilist = {"a", "b", "c", "d", "e"};
  Circularll circular_ll(ilist);

  std::cout << "오름차순 케이스" << std::endl;
  CircularllIterator iter = circular_ll.begin(); // "a"
  for (int idx = 0; idx < 10; ++idx) {
    std::cout << *iter << std::endl;
    ++iter;
  }

  std::cout << "내림차순 케이스" << std::endl;
  iter = circular_ll.end(); // "e"
  for (int idx = 0; idx < 10; ++idx) {
    std::cout << *iter << std::endl;
    --iter;
  }
  std::cout << *iter << std::endl;

  std::cout << "뮤직 컨테이너" << std::endl;
  MusicContainer container(ilist);
  // container.printAll();
  
  return 0;
}