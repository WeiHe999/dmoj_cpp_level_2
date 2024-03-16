#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
const int MM = 5e5+3, mod = 1e9+7;
int N, M, a[MM], dfn[MM], low[MM], id[MM], sum[MM], tot, scc; vector<int> adj1[MM], adj2[MM]; stack<int> stk; bool vis[MM];
pl dp[MM][2];
void tarjan(int u){
    dfn[u] = low[u] = ++tot; stk.push(u); vis[u]=1;
    for(int v : adj1[u]){
        if(!dfn[v]) { tarjan(v);  low[u] = min(low[u], low[v]); }
        else if(vis[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) { //scc root
        scc++; int x = 0;
        do{
            x = stk.top(); stk.pop(); vis[x] = 0;
            id[x] = scc; sum[scc] += a[x];
        }while(x != u);
    }
}
void rebuild(){
    for(int u=1; u<=N; u++){
        for(int v : adj1[u]){
            if(id[u] == id[v]) continue;
            adj2[id[u]].push_back(id[v]);
        }
    }
}
void upd(pl &x, pl y) {
    if(x.first < y.first) x = y;
    else if(x.first == y.first) x.second = (x.second + y.second) % mod;
}
void dfs(int u) {
    if(dp[u][0].first != -1) return;
    if(u == id[N]) { dp[u][0] = {0, 1}; dp[u][1] = {sum[u], 1}; return; }
    for(int v : adj2[u]) {
        dfs(v);
        upd(dp[u][0], dp[v][0]); upd(dp[u][0], dp[v][1]);
        upd(dp[u][1], {sum[u] + dp[v][0].first, dp[v][0].second});
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> a[i];
    for(int i=1, u, v; i<=M; i++) {
        cin >> u >> v; adj1[u].push_back(v);
    }
    for(int i=1; i<=N; i++)
        if(!dfn[i]) tarjan(i);
    rebuild();  memset(dp, -1, sizeof(dp));  dfs(id[1]);
    upd(dp[id[1]][0], dp[id[1]][1]);
    cout << dp[id[1]][0].first << " " << dp[id[1]][0].second << "\n";
}
