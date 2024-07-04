#include <bits/stdc++.h>
using namespace std;
#define ll long long

random_device rd;
mt19937_64 mt(rd());

ll rnd(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(mt); }

const int LIMIT = 100;

void generate() {
    ofstream out("test.txt");
    if (!out) {
        cerr << "Error opening file for writing\n";
        exit(1);
    }

    int n = rnd(1, 10);
    out << n << '\n';
    for (int i = 0; i < n; ++i) {
        out << rnd(1, 10) << ' ';
    }
    out << '\n';
    out.close();
}

int32_t main() {
//    system("g++ -lm -O3 -std=c++17 -DLOCAL -pipe -o B.exe ../B.cpp"); // mycode
//    system("g++ -lm -O3 -std=c++17 -pipe -o C.exe ../C.cpp"); // brute
//    system("g++ -lm -O3 -std=c++17 -pipe -o gen.exe ../gen.cpp"); // run gen file ?

    if (system("g++ -lm -O3 -std=c++17 -DLOCAL -pipe -o B.exe ../B.cpp") != 0) {
        cerr << "Compilation of B.cpp failed\n";
        return 1;
    }
    if (system("g++ -lm -O3 -std=c++17 -pipe -o C.exe ../C.cpp") != 0) {
        cerr << "Compilation of C.cpp failed\n";
        return 1;
    }

    for (int tc = 1; tc <= LIMIT; ++tc) {
        cerr << "Case " << tc << '\n';

//        system("gen.exe >test.txt"); /// file
        generate(); /// function

        system("B.exe <test.txt >wa.txt");
        if (system("C.exe <test.txt >ac.txt"))break;
//        if (system("B.exe <test.txt >wa.txt") != 0) {
//            cerr << "Execution of B.exe failed\n";
//            return 1;
//        }
//        if (system("C.exe <test.txt >ac.txt") != 0) {
//            cerr << "Execution of C.exe failed\n";
//            return 1;
//        }

        ifstream acs("ac.txt");
        ifstream was("wa.txt");
        if (!acs || !was) {
            cerr << "Error opening output files for reading\n";
            return 1;
        }
        string ac, wa;
        getline(was, wa, (char) EOF);
        getline(acs, ac, (char) EOF);
        was.close();
        acs.close();
        if (ac != wa){
            cerr << "Mismatch found in case " << tc << '\n';
             cerr << "Test case input:\n";
            ifstream test_input("test.txt");
            string line;
            while (getline(test_input, line)) {
                cerr << line << '\n';
            }
            test_input.close();
            cerr << "Expected: " << ac << '\n';
            cerr << "Found: " << wa << '\n';
            return 1;
        };
    }
}
