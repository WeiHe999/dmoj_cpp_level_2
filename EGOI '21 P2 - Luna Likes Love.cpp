#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MM = 1e6 + 10;
vector<int> bit(MM);

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}



void update (int pos, int val) { //going upward
	for(int i=pos; i<MM; i += i&-i) 
		bit[i] += val;
}

long long  query(int pos ) { //going downward
	long sum = 0;
	for(int i=pos; i>0; i -= i &-i) 
		sum += bit[i];
	return sum;
}



int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, cur, top, ans = 0;
    cin >> n;

    vector<int> v1(2*n+1);
    unordered_map<int, pair<int, int> > m1; // value: {first_index, second_index}
    for (int i=1; i<=2*n; i++)
    {
        cin >> a;
        v1[i] = a; 
        if (!m1.count(a)) m1[a].first = i;
        else m1[a].second = i;
    }
    
    //print(v1);
    
    unordered_set<int> s1;
    for (int i=1; i<=2*n; i++)
    {
        //cout << v1[i] << endl;
        if (!s1.count(v1[i]))
        {
            s1.insert(v1[i]);
            update (i, 1); // set to active
        }
        else // second appearance
        {
            int ind_first = m1[v1[i]].first;
            update (ind_first, -1);
            ans += (query(i-1) - query(ind_first));
            //cout << v1[i] << " : " << query(i-1) - query(ind_first) << endl;
            
        }
  
    }
    cout << ans + n << endl;
    
    
}
