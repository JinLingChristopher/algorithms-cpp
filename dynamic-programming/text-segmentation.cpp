#include <set>
#include <string>
#include <iostream>

using namespace std;

bool isword(const string& str, const set<string>& words) {
    return words.find(str) != words.end();
}

const set<string> build_words() {
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

bool fast_splitable(const string& str, int i, const set<string>& words) {
    int n = str.size();
    bool table[n + 1];
    table[n] = true;
    
    int right = n;
    for (int i = n - 1; i >= 0; i--) {
        table[i] = false;
        for (int j = i + 1; j <= right; j++) {
            if (isword(str.substr(i, j - i), words)) {
                if (table[j]) {
                    table[i] = true;
                    right = i;
                }
            }
        }
    }

    return table[0];
}

int main() {
    const string input("BOTHEARTHANDSATURNSPIN");
    const set<string> words = build_words();

    bool ret = fast_splitable(input, 0, words);
    cout << "input is " << (ret ? "splitable" : "unsplitable") << endl;

    return 0;
}