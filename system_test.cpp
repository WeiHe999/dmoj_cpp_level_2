#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
vector<int>
split(string str1)
{
    vector<int> vv;
    string word;
    istringstream ss(str1);
    while (getline(ss, word, ' ')) {
        vv.push_back(stoi(word));
    }
    return vv;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int> > vec1;
    int s = 0;
    for (int x = 0; x < n; x++) {
        string line;
        getline(cin, line);
        vector<int> vec3 = split(line);
        vec3.push_back(1);
        vec1.push_back(vec3);
        s += vec3[2];
    }

    cin >> n;
    
    for (int a = 0; a < n; a++) {
        int b;
        cin >> b;
        for (int m=0; m<vec1.size(); m++) {
            if (b >= vec1[m][0] && b <= vec1[m][1]) {
                if (vec1[m][3] == 1)
                {
                    vec1[m][3] = 0;
                    s -= vec1[m][2];
                }
            }
        }
    }

    cout << s;
    return 0;
}
