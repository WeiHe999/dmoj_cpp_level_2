#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    int s = 0;
    int test = 0;
    for (int k = 1; k <= n; k++)
    {
        bool repeated = false;
        for (int x = 0; x < n - k + 1; x++)
        {
            if (line.find(line.substr(x, k), x + 1) == -1)
            {
                s++;
            }
            else
            {
                repeated = true;
                break;
            }
        }
        if (!repeated) 
        {
            cout << k << endl;
            break;
        }
    }
}
