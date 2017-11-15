#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void normalize(std::string &s){
    char c;
    cout << s << '\n';
    for (int i = 0; i < s.length(); i++){
        c = s[i];
        if (isalpha(c) == 0 && isspace(c) == 0){
            cout << c << '\n';
            std::replace( s.begin(), s.end(), c, ' ');
        } else {
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        }
    }

    cout << s;
}

int main() {
    string a;
    getline (cin, a);
    normalize(a);
}
