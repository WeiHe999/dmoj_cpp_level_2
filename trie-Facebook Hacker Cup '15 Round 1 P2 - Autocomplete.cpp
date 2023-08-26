#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
struct node {
    unordered_map<char, node*> ch;
};

int T, N; node *root;
void clean(node *cur){
    if(cur==nullptr) return;
    for(auto p : cur->ch) clean(p.second);
    delete cur; cur = nullptr;
}
int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		ll ans = 0; root = new node();
		while (N--) {
			string st; cin >> st;
			int lvl = 0, flag = 0;
			node *cur = root;
			for (int i = 0; i < st.length(); i++) {
				if (!cur->ch.count(st[i])) {
					cur->ch[st[i]] = new node();
					if (flag == 0) flag = i+1;
					cur = cur->ch[st[i]];
				} else {
					cur = cur->ch[st[i]];
				}
			}
			if (flag) ans += flag;
			else ans += st.length();
//			printf("Curt: %lld\n", ans);
		}
		printf("Case #%d: %lld\n", t, ans);
		clean(root);
	}

	return 0;
}
