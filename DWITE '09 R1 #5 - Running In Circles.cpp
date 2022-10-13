#include <bits/stdc++.h>
using namespace std;



int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int a = 0; a < 5; a++)
    {
        int n, b, c;
        cin >> n;
        unordered_map <int, vector <int> > graph;
        vector<vector<int> > reachable(101, vector<int>(101, 99999));
        for (int x = 0; x < n; x++)
        {
            cin >> b >> c;
            graph[b].emplace_back(c);
            reachable[b][c] = 1;
        }
        //floyd
        for (int i=1; i<=100; i++)
        {
            for (int start=1; start<=100; start++)
            {
                for (int end=1; end<=100; end++)
                {
                    reachable[start][end] = min(reachable[start][end], reachable[start][i]+reachable[i][end]);
                }
            }
        }
        
        for (int i=1; i<=100; i++)
        {
            if(reachable[1][i] <101 && reachable[i][i] < 101)
            {
                cout << reachable[i][i] << endl;
                break;
            }
        }

 
        

    }
}
