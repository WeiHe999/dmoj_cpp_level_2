#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdio.h>

using namespace std;
template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

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
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int> > vec1;
    vector<string> v_s;
    int s = 0;
    for (int x = 0; x < n; x++) {
        string line;
        getline(cin, line);
        v_s.push_back(line);
    }

    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    vector<int> vect_q(arr, arr+n);
    sort(vect_q.begin(), vect_q.end());
    
    for (int m=0; m<v_s.size(); m++)
    {
        
        vector<int> vec3 = split(v_s[m]);
        if (upper_bound (vect_q.begin(), vect_q.end(), vec3[1]) - 
        lower_bound (vect_q.begin(), vect_q.end(), vec3[0]) ==0)
        {
            s += vec3[2];
        }
        
    }
 
    cout << s;
    return 0;
}
