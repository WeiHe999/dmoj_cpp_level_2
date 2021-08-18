#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
	int n;
	cin >> n;
	vector <int> colours = {0, 0, 0, 0, 0, 0};
	string c;
	for(int x = 0; x < n; x++){
		cin >> c;
		if(c == "red") colours[0]++;
		if(c == "orange") colours[1]++;
		if(c == "yellow") colours[2]++;
		if(c == "green") colours[3]++;
		if(c == "blue") colours[4]++;
		if(c == "black") colours[5]++;
	}
	sort(colours.begin(), colours.end());
	int a = colours[5];
	int b = n - a;
	if (a < b + 1) cout << a + b << endl;
	else cout << 2 * b + 1 << endl;
}
