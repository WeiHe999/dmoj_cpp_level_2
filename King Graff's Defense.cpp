#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int MM = 1e6+1;

int dfn[MM], low[MM], head[MM], v[2*MM], nxt[2*MM];


stack <int> s1;
int i = 0;
long long f = 0;
int e_id = 0;

void tarjan(int cur, int prev)
{
    i++;
    dfn[cur] = low[cur] = i;
    s1.push(cur);
   for (int i = head[cur]; i!=-1; i=nxt[i])
    {
        int x = v[i];
        if (x == prev) continue;
        if (dfn[x] == 0)
        {
            tarjan(x, cur);
            low[cur] = min(low[cur], low[x]);
        }
        else low[cur] = min(low[cur], dfn[x]);
    }
    if (dfn[cur] == low[cur])
    {
        vector <int> vec1;
        while (s1.top() != cur)
        {
            vec1.emplace_back(s1.top());
            s1.pop();
        }
        vec1.emplace_back(s1.top());
        long long ss = vec1.size();
        f += (ss * (ss -1ll))/2ll;
        
        s1.pop();
    }
}




int32_t main() {
   
    int n, m, a, b;
    cin >> n >> m;
    memset(head, -1, sizeof(head));
   for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        v[e_id] = b;
        nxt[e_id] = head[a];
        head[a] = e_id;
        e_id++;
        
        v[e_id] = a;
        nxt[e_id] = head[b];
        head[b] = e_id;
        e_id++;

    }
    tarjan(1, -1);
    
    
    long long m1 = 1ll*(long long) n * ((long long) n - 1ll);
    cout << fixed << setprecision(5) << (1.0 - 1.0 * f / (m1 / 2ll));    
}
