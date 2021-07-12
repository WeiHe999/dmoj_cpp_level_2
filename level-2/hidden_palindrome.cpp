#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool is_palindrome(string n)
{
    vector<char> vec1;
    copy(n.begin(), n.end(), back_inserter(vec1));
    vector<char> vec2 (vec1.rbegin(), vec1.rend());
    if (vec1 == vec2) return true;
    else return false;
}

int main()
{
    string n;
    getline(cin, n);
    int maximum1 = 0;
    for (int x = 0; x < n.length() - 1; x++)
    {
        for (int a = x + 1; a < n.length() + 1; a++)
        {
            string substr1 = n.substr(x, a-x);
            bool b = is_palindrome(substr1);
            if (b == true and (a - x) > maximum1)
            {
                maximum1 = a - x;
            }
        }
    }
    cout << maximum1;
    return 0;
}
