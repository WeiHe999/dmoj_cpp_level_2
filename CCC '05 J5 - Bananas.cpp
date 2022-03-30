#include <bits/stdc++.h>
using namespace std;

bool monkey(string word)
{
    int a = word.find("ANA");
    int b = word.find("BAS");
    while (a != -1 || b != -1)
    {
        if (a != -1) word = regex_replace(word, regex("ANA"), "A");
        if (b != -1) word = regex_replace(word, regex("BAS"), "A");
        a = word.find("ANA");
        b = word.find("BAS");
    }
    if (word == "A") return true;
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    while (str1 != "X")
    {
        if (monkey(str1)) cout << "YES" << endl;
        else cout << "NO" << endl;
        cin >> str1;
    }
}
