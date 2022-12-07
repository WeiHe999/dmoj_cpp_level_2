#include <bits/stdc++.h>
using namespace std;

int angle_from_direction(char a)
{
	if (a == 'E') return 0;
	if (a == 'N') return 90;
	if (a == 'W') return 180;
	if (a == 'S') return 270;
}

int angle_change(char a, char b)
{
	int a1 = angle_from_direction(a);
	int a2 = angle_from_direction(b);
	if(a2 == (a1 + 90) % 360) return 90;
	else if (a2 == a1) return 0;
	else if (a2 == (a1 + 270) % 360) return -90;
}

int main()
{
	int n;
	string s;
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		int total_change = 0;
    	for (int i = 0; i < s.size(); i++) total_change += angle_change(s[i],s[(i+1)%s.size()]);
    	if (total_change == 360) cout << "CCW" << endl;
    	else cout << "CW" << endl;
	}
}
