#include <iostream>
#include <string>
#include <cassert>
#include "queue.h"

using namespace std;

void test_empty_queue_has_zero_size() {
  Queue<string> q;
  assert(q.get_size() == 0);
}

void test_some_insertions_and_deletions() {
  Queue<string> q;
  q.enqueue("one");
  assert(q.get_size() == 1);
  q.enqueue("two");
  q.enqueue("three");
  assert(q.get_size() == 3);
  assert(q.dequeue() == "one");
  assert(q.get_size() == 2);
  assert(q.dequeue() == "two");
  assert(q.dequeue() == "three");
  q.enqueue("four");
  assert(q.get_size() == 1);
}

void test_no_copies() {
  Queue<int> p;
  Queue<int> q;
  // No way to test this at run time, but uncomment the following lines
  // and look for compile time errors.
  // p = q;
  // Queue<int> r(p);
}

Queue<int> one_two_three() {
  Queue<int> q = Queue<int>();
  for (int i = 1; i <= 3; i++) q.enqueue(i);
  return q;
}

void test_moves() {
  // Assignment of a temporary is a move
  Queue<int> p = Queue<int>();

  // Construction via a function return call is a move
  Queue<int> q = one_two_three();
  assert(q.get_size() == 3);
  assert(q.dequeue() == 1);
  cout << q.dequeue();

  // Test move assignment
  q = one_two_three();
  cout << q.dequeue();
  assert(q.get_size() == 3);
  assert(q.dequeue() == 1);
}

void test_dequeue_from_empty_queue_throws_underflow_error() {
  Queue<bool> q;
  try {
    q.dequeue();
    assert(false);
  } catch (const underflow_error& ue) {
    assert(true);
  } catch (...) {
    // Caught the wrong exception
    assert(false);
  }
}

int main() {
  test_empty_queue_has_zero_size();
  test_some_insertions_and_deletions();
  test_dequeue_from_empty_queue_throws_underflow_error();
  test_no_copies();
  test_moves();
  cout << "All tests passed\n";
}
