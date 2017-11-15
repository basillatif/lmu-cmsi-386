#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {

  struct Node {
    T data;
    Node* next;
  };

  int size = 0;
  Node* front = nullptr;
  Node* top = nullptr;


  Node* copy(Node* n) {
    return new Node {n->data, n->next ? copy(n->next) : nullptr};
  }

public:

  ~Queue() {
    while (front != nullptr) {
      dequeue();
    }
  }

  Queue() = default;

  Queue(const Queue& s) = delete;
  Queue& operator=(const Queue& s) = delete;

  Queue(Queue&& s): size(s.size), top(s.top), front(s.front) {
    s.top = nullptr;
    s.front = nullptr;
    s.size = 0;
  }

  Queue& operator=(Queue&& s) {
    if (&s != this) {
      size = s.size;
      top = s.front;
      s.front = nullptr;
      s.size = 0;
    }
    return *this;
  }

  int get_size() {
    return size;
  }

  T get_top() {
    return top->data;
  }

  T get_front() {
    return front->data;
  }

  void enqueue(T x) {
    if (size == 0) {
      front = new Node{x, nullptr};
      top = front;
      size++;
    }
    else {
    Node *temp = new Node{x, nullptr};
    top->next = temp;
    top = temp;
    size++;
  }
  }

  T dequeue() {
    if (size == 0) {
      throw underflow_error("The queue is empty");
      }
    else if (size == 1) {
      // Node* nodeToDelete = front;
      T valueToReturn = front->data;
      //front = front->next;
      size--;
      delete front;
      front = nullptr;
      return valueToReturn;

    }
    else {
    Node* nodeToDelete = front;
    T valueToReturn = front->data;
    front = front->next;
    size--;
    delete nodeToDelete;
    return valueToReturn;
  }
  }
};
