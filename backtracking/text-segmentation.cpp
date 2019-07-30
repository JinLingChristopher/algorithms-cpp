#include <set>
#include <string>
#include <iostream>

using namespace std;

bool isword(const string& str, const set<string>& words) {
    return words.find(str) != words.end();
}

set<string> build_words() {
    set<string> words;
    words.insert("BOTH");
    words.insert("EARTH");
    words.insert("AND");
    words.insert("HAND");
    words.insert("SATURN");
    words.insert("SPIN");
    words.insert("BOT");
    words.insert("HEART");
    words.insert("HANDS");
    words.insert("AT");
    words.insert("URNS");
    words.insert("PIN");

    return words;
}

bool splitable(const string& str, int i, const set<string>& words) {
    int n = str.size();
    if (i >= n) {
        return true;
    }
    for (int j = 0; j < n - i + 1; j++) {
        if (isword(str.substr(i, j), words)) {
            if (splitable(str, i + j, words)) {
                return true;
            }
        }
    }

    return false;
}


int main() {
    const string input("BOTHEARTHANDSATURNSPIN");
    const set<string> words = build_words();

    bool ret = splitable(input, 0, words);
    cout << "input is " << (ret ? "splitable" : "unsplitable") << endl;

    return 0;
}