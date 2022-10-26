#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map <int, unordered_set <int> > &graph, vector <int> &v1, vector <int> &dist, int start_node, unordered_map<int, vector<int> > &m_color)
{
    queue <int> q1;
    q1.push(start_node);
    dist[start_node] = 0;
    m_color[v1[start_node]].push_back(start_node);
    while (!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        for (auto x : graph[cur])
        {
            if (dist[x]<0)
            {
                dist[x] = dist[cur] + 1;
                if (m_color[v1[x]].size()<2) m_color[v1[x]].push_back(x);
                q1.push(x);
            }
        }
    }
}


int bfs2(unordered_map <int, unordered_set <int> > &graph, vector <int> &v1, vector <int> &dist, int start_node, 
    unordered_map<int, vector<int> > &m1_color, vector <int> &dist1)
{
    int min_dist = INT_MAX;
    queue <int> q1;
    q1.push(start_node);
    dist[start_node] = 0;
    if (m1_color.count(v1[start_node]))
    {
        for (auto x: m1_color[v1[start_node]])
        {
            if (x!=start_node)
            {
               min_dist = min(min_dist, dist[start_node]+dist1[x]);
               break;
            }
        }
        
    }
    while (!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        if (dist[cur]>= min_dist) return min_dist;
        for (auto x : graph[cur])
        {
            if (dist[x]<0)
            {
                dist[x] = dist[cur] + 1;
                if (m1_color.count(v1[x]))
                {
                    for (auto y: m1_color[v1[x]])
                    {
                        if (y!=x)
                        {
                           min_dist = min(min_dist, dist[x] + dist1[y]);
                           break;
                        }
                    }
                    
                }                
                q1.push(x);
            }
        }
    }
    return min_dist;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    vector <int> v1(n + 1);
    unordered_map <int, unordered_set <int> > graph;
    for (int x = 0; x < n; x++)
    {
        cin >> v1[x + 1];
    }
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector <int> dist1(n + 1, -1), dist2(n + 1, -1);
    unordered_map<int, vector<int> > m1_color, m2_color; //{color_no: {node-1, node-2}}
    bfs(graph, v1, dist1, 1, m1_color);
    int min_dist = bfs2(graph, v1, dist2, n, m1_color, dist1);
    if (min_dist==INT_MAX) cout << -1 << endl;
    else cout << min_dist << endl;
}
