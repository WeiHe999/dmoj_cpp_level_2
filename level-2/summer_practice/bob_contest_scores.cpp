#include <bits/stdc++.h>
using namespace std;

void getstrings(int n, vector <int> vec1, int i, vector <int> scores, unordered_set <int> &s1)
{
	if (i == n)
	{
		int s = 0;
    	for (int i = 0; i < n; i++)
    	{
    	    if (vec1[i] == 0) s += 0;
    	    else s += scores[i];
    	}
    	s1.insert(s);
	}
    else
    {
        vec1.emplace_back(0);
    	getstrings(n, vec1, i + 1, scores, s1);
    	vec1[i] = 1;
    	getstrings(n, vec1, i + 1, scores, s1);
    }
}

int main()
{
	int n;
	cin >> n;
	vector <int> scores;
	for (int x = 0; x < n; x++)
	{
	    int a;
	    cin >> a;
	    scores.emplace_back(a);
	}
    vector <int> vec1;
	unordered_set <int> s1; 
	getstrings(n, vec1, 0, scores, s1);
	cout << s1.size() << endl;
}
