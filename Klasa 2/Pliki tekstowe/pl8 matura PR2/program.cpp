#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print_v(vector<string>* v) {
    for(string x : *v) {
        cout << x << "_";
    }
}

int main() {
    ifstream f("anagram.txt");
    ofstream ofa("odp_4a.txt");
    ofstream ofb ("odp_4b.txt");

    string l;
    string ltemp;
    while(!f.eof()) {
        getline(f, l);
//        l = "klatka klatka klatka xsdfrt xsdh";
        ltemp = l;
        if(f.fail()) break;

        vector<string> slowa;
        for(int i = 0; i < l.size(); i++) {
            if(l[i] == ' ') {
                slowa.push_back(l.substr(0, i));
                l.erase(0, i+1);
                i = 0;
            }

            if(i == l.size()-1) {
                slowa.push_back(l);
                break;
            }
        }

        bool all_equal = true;
        int ss = slowa[0].size();
        for(string s : slowa) {
            if(ss != s.size()) {
                all_equal = false;
                break;
            }
        }


        if(all_equal) ofa << ltemp << endl;

        if(all_equal) {
            bool is_anagram = true;

            for(int i = 1; i < slowa.size(); i++) {
                for(int j = 0; j < slowa[i].size(); j++) {
                    if(slowa[0].find(slowa[i][j]) == -1) {
                        is_anagram = false;
                        break;
                    }
                }
                if(!is_anagram) break;
            }

            if(is_anagram) {
                ofb << ltemp << endl;
            }
        }
    }

    ofb.close();
    ofa.close();
    f.close();
}
