#include <iostream>
#include <stack>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    int a;
    stack <int> s1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        if (a == 0) s1.pop();
        else s1.push(a);
    }
    int s = 0;
    while (!s1.empty())
    {
        s += s1.top();
        s1.pop();
    }
    cout << s << endl;
}
