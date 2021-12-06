#include <iostream>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    long long num;
    for (int x = 0; x < n; x++)
    {
        long long s1, s2;
        cin >> s1 >> s2;
        num = ((s1 * (s1 + 1)) / 2) - s2;
        long long l;
        long long r;
        if(num<=s1)
        {
            l=1;
            r=num-1;
        }
        else
        {
            r = s1;
            l = num - s1;
        }
        cout << (r-l+1)/2 << endl;
    }
}
