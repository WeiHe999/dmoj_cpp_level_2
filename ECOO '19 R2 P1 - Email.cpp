#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    for (int x = 0; x < 10; x++)
    {
        int n;
        cin >> n;
        cin.ignore();
        unordered_set <string> set1;
        for (int a = 0; a < n; a++)
        {
            string line;
            getline(cin, line);
            int index = line.find('@');
            string str1 = "";
            for (int b = 0; b < index; b++)
            {
                if (line[b] == '+')
                {
                    break;
                }
                if (line[b] != '.')
                {
                    str1 += tolower(line[b]);
                }
            }
            for (int c = index; c < line.length(); c++)
            {
                str1 += tolower(line[c]);
            }
            set1.insert(str1);
        }
        cout << set1.size() << endl;
    }
}
