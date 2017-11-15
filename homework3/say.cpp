<<<<<<< HEAD
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
=======
  #include <vector>
  #include <sstream>

int main {
  string say (string first_word) {
  vector <string> words;

  string say_more(string word) {
  if (word == null) {
    std::stringstream sayfct;
    for (i = 0; i < words.size(); i++)
    {
      if (i != 0)
      sayfct << ",";
      sayfct << words[i];
    }
    std::string s = sayfct.str();
    return words; //join replacement
  }
    words.pushback(word);
    return say_more;
  }
  return say_more first_word
  }
}

assert(say == "Hi there")
>>>>>>> c3e33706af670caf357ee6cf6b1546c94db3a5ad
