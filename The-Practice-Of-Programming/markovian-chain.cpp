//
// Created by king on 2019/8/5.
//

#include <map>
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <string>

using namespace std;

typedef deque<string> Prefix;
static map<Prefix, vector<string>> statetab;
static const int NPREF = 2;
static const string NONWORD = "\n";
static const int MAXGEN = 10000;

void add(Prefix& prefix, const string& s) {
    if (prefix.size() == NPREF) {
        statetab[prefix].push_back(s);
        prefix.pop_front();
    }
    prefix.push_back(s);
}

void build(Prefix& prefix, istream& in) {
    string buf;
    while (in >> buf) {
        add(prefix, buf);
    }
}

void generate(int nwords) {
    Prefix prefix;
    int i;

    cout << "please enter prefix: " << endl;
    for (i = 0; i < NPREF; ++i) {
        string w;
        cin >> w;
        add(prefix, w);
    }

    cout << "start generation of the program" << endl;

    for (i = 0; i < nwords; ++i) {
        vector<string>& suf = statetab[prefix];
        const string& w = suf[rand() % suf.size()];
        if (w == NONWORD) {
            break;
        }
        cout << w << "\n";
        prefix.pop_front();
        prefix.push_back(w);
    }
}


int main() {
    int nwords = MAXGEN;
    Prefix prefix;

    for (int i = 0; i < NPREF; ++i) {
        add(prefix, NONWORD);
    }

    ifstream infile;
    infile.open("psalms.txt");

    build(prefix, infile);
    add(prefix, NONWORD);
    generate(nwords);

    return 0;
}