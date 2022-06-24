#include <bits/stdc++.h>
using namespace std;

void lexicographical_smallest_string(string &s, int n)
{
	set <string> collection;
	for (int i = 0; i < n; i++)
	{
		string cur;
		for (int j = i; j < n; j++)
		{
			cur.push_back(s[j]);
			collection.insert(cur);
		}
	}
	queue <string> q;
	for (int i = 0; i < 26; i++)
	{
		q.push(string(1, i + 'a'));
	}
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		if (collection.find(cur) == collection.end())
		{
			cout << cur << endl;
			return;
		}
		for (int i = 0; i < 26; i++)
		{
			cur.push_back(i + 'a');
			q.push(cur);
			cur.pop_back();
		}
	}
}

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	lexicographical_smallest_string(s, n);
}
