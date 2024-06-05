#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MM = 2e5+5, LOG = __lg(MM);
int N, dep[MM], anc[MM][LOG+1], dif[MM], c1[MM], c2[MM]; vector<array<int, 3>> adj[MM]; ll ans;
void dfs(int u, int par){
    dep[u] = dep[par] + 1 ; anc[u][0] = par;
    for(int k=1; k<=LOG; k++)
        anc[u][k] = anc[anc[u][k-1]][k-1];
    for(auto [v, a, b] : adj[u]){
        if(v == par) continue;
        c1[v] = a; c2[v] = b;
        dfs(v, u);
    }
}
int lca(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k=LOG; k>=0; k--)
        if(dep[anc[u][k]] >= dep[v]) u = anc[u][k];
    if(u == v) return u;
    for(int k=LOG; k>=0; k--)
        if(anc[u][k] != anc[v][k]) u = anc[u][k], v = anc[v][k];
    return anc[u][0];
}
void dfs2(int u, int par) {
    for(auto [v, a, b] : adj[u]){
        if(v == par) continue;
        dfs2(v, u);
        dif[u] += dif[v];
    }
    ans += min(1LL*dif[u] * c1[u], (ll)c2[u]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=1, u, v, a, b; i<N; i++) {
        cin >> u >> v >> a >> b;
        adj[u].push_back({v, a, b}); adj[v].push_back({u, a, b});
    }
    dfs(1, 0);
    for(int i=1; i+1<=N; i++) {
        dif[i]++; dif[i+1]++; dif[lca(i, i+1)]-=2;
    }
    dfs2(1, 0);  cout << ans << endl;
}
