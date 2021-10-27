#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, second_i;
    cin >> n;
    string name, partner;
    vector <string> students1;
    vector <string> students2;
    for (int a = 0; a < n; a++)
    {
        cin >> name;
        students1.emplace_back(name);
    }
    for (int a = 0; a < n; a++)
    {
        cin >> name;
        students2.emplace_back(name);
    }
    bool bad = false;
    for (int i = 0; i < n; i++)
    {
        if (students1[i] == students2[i])
        {
            bad = true;
            break;
        }
        second_i = find(students1.begin(), students1.end(), students2[i]) - students1.begin();
        if (students2[second_i] != students1[i])
        {
            bad = true;
            break;
        }
    }
    if (bad) cout << "bad" << endl;
    else cout << "good" << endl;
}
