#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    unordered_set <int> set1;
    for (int x = 0; x < 10; x++)
    {
        int n;
        cin >> n;
        set1.insert(n % 42);
    }
    cout << set1.size();
}
