#include <bits/stdc++.h>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector <int> split (string str1)
{
    vector <int> vec1;
    string word;
    istringstream ss (str1);
    while (getline (ss, word, ' ')) vec1.push_back(stoi(word));
    return vec1;
}

void count(vector <vector <int> > vec1, unordered_map <string, int> &m_count)
{
    for (int row = 0; row < vec1.size(); row++) m_count["R" + to_string(row + 1)] = accumulate(vec1[row].begin(), vec1[row].end(), 0);
    for (int col = 0; col < vec1[0].size(); col++)
    {
        int s = 0;
        for (auto a : vec1) s += a[col];
        m_count["C" + to_string(col + 1)] = s;
    }
}

void flip(vector <vector <int> > &vec1, unordered_map <string, int> &m_count, string op)
{
    if (op[0] == 'R')
    {
        int row = stoi(op.substr(1))-1;
        for (int col=0; col<vec1[0].size(); col++)
        {
            if(vec1[row][col]==0)
            {
                vec1[row][col] = 1;
                m_count[op]++;
                m_count["C"+to_string(col+1)]++;
                
            }
            else
            {
                vec1[row][col] = 0;
                m_count[op]--;
                m_count["C"+to_string(col+1)]--;                
                
            }
        }
    }
    else
    {
        int col = stoi(op.substr(1))-1;
        for (int row=0; row<vec1.size(); row++)
        {
            if(vec1[row][col]==0)
            {
                vec1[row][col] = 1;
                m_count[op]++;
                m_count["R"+to_string(row+1)]++;
                
            }
            else
            {
                vec1[row][col] = 0;
                m_count[op]--;
                m_count["R"+to_string(row+1)]--;                
                
            }
        }        

    }
}

string find_max_row_col(unordered_map <string, int> &m_count, int n)
{
    int max_value = -1;
    string max_str;
    for(auto x: m_count)
    {
        if (m_count[x.first]>max_value)
        {
            max_value = m_count[x.first];
            max_str = x.first;
        }
    }
    if(max_value==0) return "done";
    else if (max_value<=int(n/2)) return "na";
    else return max_str;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n;
    int max_limit = 4000;
    cin >> n; cin.ignore();
    string line;
    vector <vector <int> > vec1;
    vector <int> tmp;
    vector <string> operations;
    unordered_map <string, int> m_count;
    for (int x = 0; x < n; x++)
    {
        getline(cin, line);
        tmp = split(line);
        vec1.push_back(tmp);
    }
    count(vec1, m_count);
    

    // find the row or col with max 1s
    int num=0;
    while (num<max_limit)
    {
        string v = find_max_row_col(m_count, vec1.size());

        if (v=="done")
        {
            cout << operations.size() << endl;
            for (auto a : operations) cout << a.substr(0, 1) << " " << a.substr(1) << endl;
            break;
        }
        else if (v=="na")
        {
            cout << "-1" << endl;
            break;
        }
        else
        {
            operations.push_back(v);
            flip(vec1, m_count, v);
            num++;
        }        
    }

    
}
