#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

vector <string> split (string str1)
{
    vector <string> vv;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vv.emplace_back(word);
    return vv;
}

int debug = 0;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    // n: number of elements, k: thresold for psa, q: number of queries, e: each element
    int n, k, q, e;
    cin >> n >> k >> q;
    vector<int> psa(n+1, 0);
    unordered_map<int, vector<int> > m1; //value, vector of indices
    for (int i=1; i<=n; i++)
    {
        cin >> e; 
        psa[i] = psa[i-1] + e;
        m1[e].push_back(i);
    }
    if (debug)
    {
        cout << "psa:" << endl;
        print(psa);
        cout << "map: " << endl;
        for (auto x: m1)
        {
            cout << x.first << ":" << endl;
            print(x.second);
        }
        
    }
    
    // step 2:
    for (int i=0; i<q; i++)
    {
        int a, b, left, right;
        cin >> a >> b >> left >> right;
        if (psa[right] - psa[left-1] <= k)
        {
            cout << "No" << endl;
        }
        else
        {
            bool first = false, second = false;
            int pa = lower_bound(m1[a].begin(), m1[a].end(), left) - m1[a].begin();
            if (pa < m1[a].size())
            {
                if (m1[a][pa] <= right) 
                {
                    first = true;
                }
            }
            int pb = lower_bound(m1[b].begin(), m1[b].end(), left) - m1[b].begin();
            if (pb < m1[b].size())
            {
                if (m1[b][pb] <= right) 
                {
                    second = true;
                }
            }  
            if (debug)
            {
                cout << "lower bound:" << endl;
                cout << "checking " << a << ", " << b << "with left=" << left << ", right=" << right << endl;
                cout << "vector of index:" << endl;
                print(m1[a]);
                print(m1[b]);
                cout << "lower bound index:" << endl;
                cout << "for a=" << a << ", index=" << pa << endl;
                cout << "for b=" << b << ", index=" << pb << endl;
            }
            if (first && second) cout << "Yes" << endl;
            else cout << "No" << endl;
            
        }
    }
    
    
}
