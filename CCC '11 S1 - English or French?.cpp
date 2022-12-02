#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int count_t = 0;
    int count_s = 0;
    for (int x = 0; x < n; x++)
    {
        string line;
        getline(cin, line);
        for (int a = 0; a < line.length(); a++)
        {
            if (line[a] == 't' or line[a] == 'T')
            {
                count_t++;
            }
            if (line[a] == 's' or line[a] == 'S')
            {
                count_s++;
            }
        }
    }
    if (count_t > count_s)
    {
        cout << "English";
    }
    else
    {
        cout << "French";
    }
    return 0;
}
