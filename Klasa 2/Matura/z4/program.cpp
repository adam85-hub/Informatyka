#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> p;

void init_pierwsze(int m) {
    for(int i = 2; i<=m; i++) {
        bool iP = true;
        for(int j = 2; j * j <= i; j++) {
            if(i%j==0 && i != j) {
                iP = false;
                break;
            }
        }
        if(iP) p.push_back(i);
    }
}

void cz_pierwsze(int x, vector<int>* czynniki) {
    int orginal = x;
    czynniki->clear();
    int pc = 0;
    while(true) {
        if(x%p[pc]==0){
            czynniki->push_back(p[pc]);
            x = x/p[pc];
        }
        else {
            pc++;
            if(p[pc] > x) {
                return;
            }
            if(p[pc] == orginal) {
                czynniki->push_back(1);
                czynniki->push_back(orginal);
                return;
            }
        }
    }
}

void printv(vector<int> v) {
    for(int x : v) {
        cout << x << " ";
    }
}

void printt(int* t, int s) {
    for(int i = 0; i < s; i++)
        cout << t[i] << " ";
}

void uniq(vector<int>* v) {
    for(int i = 0; i < v->size(); i++) {
        for(int j = i+1; j < v->size(); j++) {
            if((*v)[i]== (*v)[j]) {
                v->erase(v->begin()+j);
            }
        }
    }
}

bool contains(vector<int>* v, int value) {
    for(int i = 0; i < v->size(); i++) {
        if((*v)[i] == value) {
            return true;
        }
    }

    return false;
}

int main() {
    vector<int> t;

    ifstream ifile;
    ifile.open("liczby.txt");
    string x;
    for(int i = 0; i < 200; i++) {
        ifile >> x;
        t.push_back(stoi(x));
    }
    ifile.close();

    int m = 0; //najwieksza liczba
    for(int i = 0; i < 200; i++){
        if(m<t[i]) m = t[i];
    }
    m++;
    init_pierwsze(m);

    ofstream ofile;
    ofile.open("wyniki4.txt");
    // 4.1
    int cnt = 0;
    int first = -1;
    for(int i = 0; i < 200; i++) {
        x = to_string(t[i]);
        if(x[0] == x[x.size()-1]){
            cnt++;
            if(first == -1) first = t[i];
        }
    }
    ofile << "1 " << cnt << " " << first << endl;
    //4.2
    vector<int> cz_p;
    int suma1 = 0;
    int l1 = 0;
    int suma2 = 0;
    int l2 = 0;
    for(int i = 0; i < 200; i++) {
        cz_p.clear();
        cz_pierwsze(t[i], &cz_p);
        if(cz_p.size()>suma1) {
            suma1 = cz_p.size();
            l1 = t[i];
        }
        uniq(&cz_p);
        if(cz_p.size()>=suma2) {
            suma2 = cz_p.size();
            l2 = t[i];
        }
    }
    ofile << "2 " << l1 << " " << suma1 << " " << l2 << " " << suma2 << endl;
    // 4.3
    uniq(&t);

    ofstream trojkifile;
    trojkifile.open("trojki.txt");

    vector<int> tr;
    int good_count = 0;
    int good5_count = 0;
    bool good = true;
    for(int i = 0; i < t.size(); i++) {
        good = true;
        tr.clear();
        tr.push_back(t[i]);
        int k = 1;
        while(true){
            int j = 2;
            int next_n = 0;
            do {
                next_n = tr[k-1]*j;
                if(next_n > m) {
                    good = false;
                    break;
                }
                j++;
            } while(contains(&t, next_n) == false);
            if(good == false) break;
            tr.push_back(next_n);
            k++;
        }
        k--;
        if(tr.size()>=3) {
            for(int e = 2; e < tr.size(); e++) {
                for(int m = 1; m < e; m++) {
                    trojkifile << tr[0] << " " << tr[m] << " " << tr[e] << endl;
                    good_count++;
                }
            }

            if(tr.size() == 5) good5_count++;
        }
    }

    ofile << "3 " << good_count << " " << good5_count;

    ofile.close();
    trojkifile.close();

    return 0;
}
