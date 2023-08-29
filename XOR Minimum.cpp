#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* child[2];
    bool end;
};

node* make_new_node()
{
    node* node1 = new node();
    node1->end = false;
    node1->child[0] = nullptr;
    node1->child[1] = nullptr;
    return node1;
}

void insert(node* root, int n)
{
    node* cur = root;
    for (int i = 30; i >= 0; i--)
    {
        bool bit = n & (1 << i);
        if (cur->child[bit] == nullptr) cur->child[bit] = make_new_node();
        cur = cur->child[bit];
    }
    cur->end = true;
}

int query(node* root, int k)
{
    node* cur = root;
    int s = 0;
    for (int i = 30; i >= 0; i--)
    {
        bool bit = k & (1 << i);
        if (cur->child[bit] != nullptr)
        {
            cur = cur->child[bit];
            if (bit) s += (1 << i);
        }
        else
        {
            cur = cur->child[1 - bit];
            if (!bit) s += (1 << i);
        }
    }
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b;
    cin >> n >> q;
    node* root = make_new_node();
    unordered_map <int, int> m1;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        insert(root, a);
        if (!m1.count(a)) m1[a] = i;
    }
    a = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> b;
        a ^= b;
        cout << m1[query(root, a)] << "\n";
    }
}
