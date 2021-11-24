#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    int aa = to_string(a)[to_string(a).length() - 1] - '0', bb = to_string(b)[to_string(b).length() - 1] - '0';
	if(aa == bb) return a > b;
    return aa < bb;
}

int main()
{
	cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
	sort(vec1.begin(), vec1.end(), comp);
	for (auto b : vec1) cout << b << " ";
	cout << endl;
}
