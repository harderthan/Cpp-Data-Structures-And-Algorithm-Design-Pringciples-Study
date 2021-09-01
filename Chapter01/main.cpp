#include <algorithm>
#include <iostream>
#include <list>

struct CircularllNode {
  std::string data;
  CircularllNode *next;
};
using node = CircularllNode;
using node_ptr = node *;
struct CircularllIterator {
private:
  node_ptr ptr;

public:
  CircularllIterator(node_ptr p) : ptr(p) {}
  std::string &operator*() { return ptr->data; }
  node_ptr get() { return ptr; }
  CircularllIterator &operator++() {
    ptr = ptr->next;
    return *this;
  }
  CircularllIterator operator++(int) {
    CircularllIterator result = *this;
    ++(*this);
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

public:
  Circularll() = default;
  Circularll(const Circularll &other) : head(NULL) {
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
  Circularll(const std::initializer_list<std::string> &ilist) : head(NULL) {
    for (auto it = std::rbegin(ilist); it != std::rend(ilist); it++)
      push_front(*it);
  }
  void push_front(std::string val) {
    auto new_node = new node{val, NULL};
    if (head != NULL)
      new_node->next = head;
    head = new_node;
  }
  void pop_front() {
    auto first = head;
    if (head) {
      head = head->next;
      delete first;
    }
  }
  
  CircularllIterator begin() { return CircularllIterator(head); }
  CircularllIterator end() { return CircularllIterator(NULL); }
  CircularllIterator begin() const { return CircularllIterator(head); }
  CircularllIterator end() const { return CircularllIterator(NULL); }
};

int main(int argc, char **argv) { return 0; }