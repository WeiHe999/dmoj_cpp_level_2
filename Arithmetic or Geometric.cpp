#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
long long power_mod(long long x, long long y, long long p)
{
	long long res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	if (x == 0) return 0; // In case x is divisible by p;

	while (y > 0)
	{
		// If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}


// This code is contributed by shubhamsingh10


// long long power_mod(long long a, long long b, long long c)
// {
//     if (b == 1) return a % c;
//     if (b % 2 == 0) return (power_mod(a, b / 2, c) * power_mod(a, b / 2, c)) % c;
//     else return (power_mod(a, b / 2, c) * power_mod(a, b / 2, c) * power_mod(a, 1, c)) % c;
// }

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, a, b, c, k;
    cin >> t;
    const long long e = 1e9+7;
    for (long long x = 0; x < t; x++)
    {
        cin >> a >> b >> c >> k;
        if (c - b == b - a)
        {
            cout << (c % e + ((c - b) % e) * ((k - 3) % e)) % e << endl;
        }
        else if (c / b == b / a)
        {
            cout << ((a % e) * power_mod((c / b), k - 1, e)) % e << endl;
        }
    }
}
