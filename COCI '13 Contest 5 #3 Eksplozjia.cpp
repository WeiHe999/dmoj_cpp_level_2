#include <deque>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    size_t blen = b.size();

    // make a = b$a
    a = b + "$" + a;

    vector<size_t> n(a.size()); // array for knuth-morris-pratt
    vector<bool> removals(a.size()); // positions of right ends at which we remove `b`s

    deque<size_t> lastN;
    n[0] = 0;

    // For the first blen + 1 iterations just do vanilla knuth-morris-pratt
    for (size_t i = 1; i < blen + 1; ++ i) {
        size_t z = n[i - 1];
        while (z && a[i] != a[z]) {
            z = n[z - 1];
        }
        if (a[i] != a[z]) n[i] = 0;
        else n[i] = z + 1;

        lastN.push_back(n[i]);
    }

    // For the remaining iterations some characters could have been logically
    //     removed from `a`, so use lastN to get last value of n instaed
    //     of actually getting it from `n[i - 1]`
    for (size_t i = blen + 1; i < a.size(); ++ i) {
        size_t z = lastN.back();
        while (z && a[i] != a[z]) {
            z = n[z - 1];
        }
        if (a[i] != a[z]) n[i] = 0;
        else n[i] = z + 1;

        if (n[i] == blen) // found a match
        {
            removals[i] = true;

            // kill last |b| - 1 `n_i`s
            for (size_t j = 0; j < blen - 1; ++ j) {
                lastN.pop_back();
            }
        }
        else {
            lastN.push_back(n[i]);
        }
    }

    string ret;
    size_t toRemove = 0;
    for (size_t pos = a.size() - 1; a[pos] != '$'; -- pos) {
        if (removals[pos]) toRemove += blen;
        if (toRemove) -- toRemove;
        else ret.push_back(a[pos]);
    }
    reverse(ret.begin(), ret.end());

    if (ret.size()>0) cout << ret << endl;
    else cout << "FRULA" << endl;

    return 0;
}
