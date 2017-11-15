#include <iostream>
#include <cassert>

using namespace std;


struct say_or {
  string words = "";
  say_or(string initial = ""): words(initial) {}

  say_or operator()(string input){
    return say_or(words + (words == "" ? "" : " ") + input);
  }

  string operator()(){
    return words;
  }

};

say_or say (string test) {
  return say_or(test);
}

int main () {
 say("hi");
 assert(say("hello")("there")("buddy")() == "hello there buddy");
 cout << "All tests pass" <<endl;
}
