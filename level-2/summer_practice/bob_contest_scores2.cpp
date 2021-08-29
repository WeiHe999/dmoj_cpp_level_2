#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> scores;
	for (int x = 0; x < n; x++)
	{
	    int b;
	    cin >> b;
	    scores.emplace_back(b);
	}
	unordered_set <int>  set1 = {0, scores[0]};
	for (int a = 2; a <= n; a++)
	{
	    unordered_set <int>  set2;
        for (auto x : set1)
        {
            set2.insert(x);
            set2.insert(x + scores[a - 1]);
        }
        set1 = set2;
	}
	cout << set1.size() << endl;
}
