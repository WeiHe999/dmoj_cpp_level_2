#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MM = 1e5 + 1;
int n, a, b, c, centroid, cnt=0, fixed_len1=1, fixed_len2=-1;
char ch;
unordered_map<int, vector<pair<int, int> > > graph;
vector<bool> is_removed(MM, false);
vector<int> subtree_size(MM), dist(MM);
unordered_map<int, int> m1; 


// DFS to calculate the size of the subtree rooted 
void dfs1(int node, int parent) {
	subtree_size[node] = 1;
	for (auto child : graph[node]) {
		if (child.first == parent || is_removed[child.first]) continue;
		dfs1(child.first, node);
		subtree_size[node] += subtree_size[child.first];
	}
}

// find centroid
void dfs2(int node, int parent, int tree_size) {
    bool flag = true;
	for (auto child : graph[node]) {
		if (child.first == parent || is_removed[child.first]) continue;
		if (subtree_size[child.first] * 2 > tree_size) {
		    flag = false;
		    dfs2(child.first, node, tree_size);
		}
	}
	if (flag) 
	{
	    centroid = node;
	    is_removed[node] = true;
	    return;
	}
}


// find distance from centroid to every node
void dfs3(int cur, int prev, vector<int> &vec1)
{
    cnt += m1[fixed_len1 - dist[cur]];
    cnt += m1[fixed_len2 - dist[cur]];
    vec1.push_back(dist[cur]);
    for (auto x: graph[cur])
    {
        if (x.first==prev || is_removed[x.first]) continue;
        dist[x.first] = dist[cur] + x.second;
        dfs3(x.first, cur, vec1);
    }
}


void dfs4(int node) {
    // update subtree_size
    dfs1(node, -1);
    // find centroid
    dfs2(node, -1, subtree_size[node]);
  
	m1 = {};
	m1[0] = 1;
	dist[centroid] = 0;
	for (auto x: graph[centroid])
	{
	    if (is_removed[x.first]) continue;
	    vector<int> vec1;
	    dist[x.first] = x.second;
	    dfs3(x.first, centroid, vec1);
	    for (auto y: vec1) m1[y]++;

    	
	}
	for (auto child : graph[centroid]) {
		if (is_removed[child.first]) continue;
		dfs4(child.first);
	}
}




int32_t main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i<n; i++)
    {
        cin >> a >> b >> ch;
        if (ch=='b') c = 1;
        else c = -1;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    dfs4(1);
    
    cout << cnt - (n-1) << endl;
    
    
    
}
