#include <bits/stdc++.h>

using namespace std;

int main()
{  
    cin.sync_with_stdio (0);
    cin.tie(0);
    string line;
    getline(cin, line); 
    int c = count(line.begin(), line.end(), 'L');
    int d = count(line.begin(), line.end(), 'M');
    int s = 0, a = 0, b = 0;
    for (int x = 0; x < c; x++) if (line[x] != 'L') s++;
    for (int x = c; x < c + d; x++) if (line[x] != 'M') s++;
    
    for (int x = 0; x < c; x++)  if (line[x] == 'M') a++;
    for (int x = c; x < c + d; x++) if (line[x] == 'L') b++;
    cout << s - min(a, b) << endl;
}
