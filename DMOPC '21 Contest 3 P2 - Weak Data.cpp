#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1e6+2;
ll K; unordered_map<ll, ll> mp;
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> K;
    if(K==0) { cout << "1\n1\n";  return 0;}
    for(ll i=0; i<=1e6; i++){
        mp[i*(i+1)/2] = i;
    }
    for(ll i=1; i<=1e6; i++) {
        ll t = i*(i+1)/2;
        if(!mp.count(K-t)) continue;
        ll m = i, n = mp[K-t];
        if(n != 0){
            if(m+n+1 > 1e6) continue;
            cout << m + n + 1 << "\n";
            for(int k=1; k<=m; k++){
                cout << 0 << " ";
            }
            cout << 1 << " ";
            for(int k=1; k<=n; k++){
                cout << 0 << " \n"[k==n];
            }
        }else {
            cout << m << "\n";
            for(int k=1; k<=m; k++){
                cout << 0 << " \n"[k==m];
            }
        }
        return 0;
    }
    cout << -1 << endl;
}
