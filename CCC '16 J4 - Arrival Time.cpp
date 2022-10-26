#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    string line;
    getline(cin, line);
    int min = stoi(line.substr(3, 2)) + stoi(line.substr(0, 2)) * 60;
    int arrival = min;
    for (int x = 0; x < 120; x++)
    {
        if (arrival >= 420 && arrival < 600) arrival += 2;
        else if (arrival >= 900 and arrival < 1140) arrival += 2;
        else arrival++;
        if (arrival == 1440) arrival = 0;
    }
    int s = 0;
    while (arrival >= 60)
    {
        arrival -= 60;
        s++;
    }
    if (s < 10) cout << '0' << s << ":";
    else cout << s << ":";
    if (arrival < 10) cout << '0' << arrival << endl;
    else cout << arrival << endl;
}
