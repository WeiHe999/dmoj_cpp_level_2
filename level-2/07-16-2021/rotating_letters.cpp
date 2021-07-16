#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string line;
    getline(cin, line);
    vector <char> vec1 = {'I', 'O', 'S', 'H', 'Z', 'X', 'N'};
    int s = 0;
    for (int x = 0; x < line.length(); x++)
    {
        if (find(vec1.begin(), vec1.end(), line[x]) == vec1.end())
        {
            s = 1;
        }
    }
    if (s == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
