/*
Having finished her homework, Molly decides to write the DMOPC. However, as a kitten, she can't actually code, and decides to asks you to compete on her behalf. As you (probably) know, the DMOPC is systested, usually with batches. Failing any test case in a batch results in a score of 0 for that batch.

Being the great hacker programmer that you are, you know precisely which cases belong to which batch, and 
how your program will do on the cases. All that remains is to see how many points you can get…

Input Specification
Line 1: An integer, 𝐵, the number of batched cases that follow.
Line 2…𝐵+1: 3 space separated integers, 𝑓𝑖, 𝑒𝑖, and 𝑝𝑖, indicating that the 𝑖𝑡ℎ batch starts on test case 𝑓𝑖, ends on case 𝑒𝑖, and is worth 𝑝𝑖 points.
Line 𝐵+2: An integer, 𝐹, the number of test cases the program fails.
Lines 𝐵+3…𝐵+𝐹+2: An integer, 𝑡𝑖, indicating the program fails the 𝑡𝑡ℎ𝑖 test case.

Output Specification
A single integer, the number of points the program can get.
*/

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
