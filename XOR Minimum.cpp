#include<bits/stdc++.h>
using namespace std;

#define INT_SIZE 32

struct TrieNode
{
	int value; // Only used in leaf nodes
	TrieNode *arr[2];
};

TrieNode *newNode()
{
	TrieNode *temp = new TrieNode;
	temp->value = 0;
	temp->arr[0] = temp->arr[1] = NULL;
	return temp;
}

void insert(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;

	for (int i=INT_SIZE-1; i>=0; i--)
	{
		bool val = pre_xor & (1<<i);

		if (temp->arr[val] == NULL)
			temp->arr[val] = newNode();

		temp = temp->arr[val];
	}

	temp->value = pre_xor;
}

int query(TrieNode *root, int pre_xor)
{
	TrieNode *temp = root;
	string str1 = "";
	for (int i=INT_SIZE-1; i>=0; i--)
	{
		bool val = pre_xor & (1<<i);

		if (temp->arr[val]!=NULL)
		{
			temp = temp->arr[val];
			str1 += to_string(val);
		}

		else if (temp->arr[1-val] != NULL)
		{
			temp = temp->arr[1-val];
			str1 += to_string(1-val);
		}
	}
    int num = stoi(str1, nullptr, 2);
    return num;
}


int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, x;
    cin >> n >> q;
    vector <int> vec1(n + 1);
    unordered_map<int, int> m1;
    TrieNode *root = newNode();
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        insert(root, vec1[i]);
        if (!m1.count(vec1[i])) m1[vec1[i]] = i-1;
    }
    int k = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> x;
        k = x ^ k;
        int ans = query(root, k);
        cout << m1[ans] << "\n";
    }
}
