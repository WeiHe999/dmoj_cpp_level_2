#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    for (int x = 0; x < n; x++)
    {
        vector <string> vec1 = {};
        for (int a = 0; a < 4; a++)
        {
            string line;
            getline(cin, line);
            string str1;
            int ind = line.length() - 1;
            while (line[ind] != 'a' && line[ind] != 'e' && line[ind] != 'i' && line[ind] != 'o' && line[ind] != 'u' && 
            line[ind] != 'A' && line[ind] != 'E' && line[ind] != 'I' && line[ind] != 'O' && line[ind] != 'U' && line[ind] != ' ')
            {
                str1 += tolower(line[ind]);
                ind--;
            }
            if (line[ind] != ' ') str1 += tolower(line[ind]);
            vec1.emplace_back(str1);
        }
        if (vec1[0] == vec1[1] &&  vec1[1] == vec1[2] && vec1[2] == vec1[3]) cout << "perfect" << endl;
        else if (vec1[0] == vec1[1] && vec1[2] == vec1[3]) cout << "even" << endl;
        else if (vec1[0] == vec1[2] && vec1[1] == vec1[3]) cout << "cross" << endl;
        else if (vec1[0] == vec1[3] && vec1[1] == vec1[2]) cout << "shell" << endl;
        else cout << "free" << endl;
    }
}
