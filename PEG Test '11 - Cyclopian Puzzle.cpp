#include <bits/stdc++.h>
using namespace std;
 
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << from_rod << to_rod << endl;
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}
 
int main()
{
    int n;
    cin >> n;
    tower_of_hanoi(n, 'A', 'C', 'B');
}
