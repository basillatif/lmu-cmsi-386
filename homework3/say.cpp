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
