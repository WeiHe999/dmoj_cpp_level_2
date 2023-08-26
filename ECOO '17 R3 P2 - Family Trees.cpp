#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    	long long size = 0;
    	unordered_map<long long, node*> ch;
};

const long long MM = 100001, mod = 1000000007;
long long n;
string strings[100001];
node *rt = 0;

void insert(node* cur, long long ind, vector <long long> &path, long long path_size)
{
	if (ind == path_size) return;
	cur->size = max(cur->size, path[ind]);
	auto tmp = cur->ch.find(path[ind]);
	if (tmp != cur->ch.end()) insert(tmp->second, ind + 1, path, path_size);
	else
	{
		cur->ch[path[ind]] = new node;
		insert(cur->ch[path[ind]], ind + 1, path, path_size);
	}
}

long long rec1(node* cur)
{
	long long tot = 0;
	for (pair<long long, node*> ch : cur->ch)
		tot = (tot + rec1(ch.second)) % mod;
	return (tot + cur->size) % mod;
}

void rec2(node* &cur)
{
	for (pair<long long, node*> ch : cur->ch) rec2(ch.second);
	cur->ch.clear();
	delete cur;
}

int main() {
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t = 10;
	for (long long x = 1; x <= t; x++)
	{
		cin >> n;
		for (long long i = 0; i < n; i++) cin >> strings[i];
		rt = new node;
		for (long long i = 0; i < n; i++)
		{
    		vector <long long> vec1;
    		string str1 = strings[i], cur = "";
    		for (long long j = 0, len = str1.length(); j < len; j++)
    		{
    			if (str1[j] == '.') {
    				vec1.push_back(stoi(cur));
    				cur = "";
    			}
    			else
    				cur += str1[j];
    		}
    		vec1.push_back(stoi(cur));
    		insert(rt, 1, vec1, vec1.size());
	    }
	    cout << rec1(rt) + 1 << "\n";
		rec2(rt);
	}
}
