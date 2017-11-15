#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const& a, type const& b) const {
        return a.second > b.second;
    }
};

void normalize(std::string &s){
    char c;
    for (int i = 0; i < s.length(); i++){
        c = s[i];
        if (isalpha(c) == 0){
            std::replace( s.begin(), s.end(), c, ' ');
        } else {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
    }
}

map<string,int> put_into_map(std::string &s){
    typedef string::size_type string_size;
    map<string,int> wordcount;
    string a;
    string_size i = 0;

    while (i < s.size()){
        while (i < s.size() && !isalpha(s[i])){
            ++i;
        }
        string_size j = i;
        a.clear();
        while (j < s.size() && isalpha(s[j])){
            a+=s[j];
            j++;
        }
        if (!wordcount[a]){
            wordcount[a] = 0;
        }
        wordcount[a] += 1;
        i = j;
    }
    return wordcount;
}




int main() {
    string a;
    getline (cin, a);
    normalize(a);
    map<string,int> wordcount = put_into_map(a);
    vector<pair<string, int> > mapcopy(wordcount.begin(), wordcount.end());
    sort(mapcopy.begin(), mapcopy.end(), less_second<string, int>());
    for (auto wordpair: mapcopy){
        cout << wordpair.first << ' '<< wordpair.second << '\n';
    }
}
