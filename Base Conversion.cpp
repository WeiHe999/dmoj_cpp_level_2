#include <bits/stdc++.h>
using namespace std;

vector <string> get_all(string s, vector <string> &vec1)
{
    for (int x = 1; x < s.size(); x++)
    {
        string str1;
        if (s[x] == '1') str1 = s.substr(0, x) + "0" + s.substr(x + 1);
        else str1 = s.substr(0, x) + "1" + s.substr(x + 1);
        vec1.emplace_back(str1);
    }
    return vec1;
}

string convertToBase3(int N){
 string result = "";
 while(N>0){
     int rem = N%3;
     N = N/3;
     result = to_string(rem) + result;
 }
 return result;
 }
 
bool check(string str1, string str2)
{
    if (str1.size()!=str2.size()) return false;
    int cnt = 0;
    for (int i=0; i<str1.size(); i++)
    {
     if (str1[i] != str2[i]) cnt++;
     if (cnt>1) return false;
    }
    return true;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string b2, b3;
    cin >> b2 >> b3;
    vector <string> vec1;
    get_all(b2, vec1);
    for (int x = 0; x < vec1.size(); x++)
    {
        int n = stol(vec1[x], 0, 2);
        string base3 = convertToBase3(n);
        if (check(base3, b3))
        {
            cout << n << "\n";
            return 0;
        }
    }
}
