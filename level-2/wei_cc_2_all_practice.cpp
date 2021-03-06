// Bob is playing blocks in his room. Bob's room can be modeled as a grid with 𝑁 rows and 𝑀 columns. Rows and columns are numbered from 1. The square at the 𝑖-th row from top and the 𝑗-th column from the left is denoted as the cell (𝑖,𝑗). Initially, Bob stacks 𝑎𝑖,𝑗 blocks at the cell (𝑖,𝑗).

// Now, Bob wants to add new blocks to some cells so that all cells have the same number of blocks. Can you help Bob to calculate the minimum number of new blocks Bob need to add?

// Input Specification
// The first line of input contains two integers 𝑁 and 𝑀 (1≤𝑁,𝑀≤100), the number of rows and the number of columns.

// Each of the following 𝑁 lines contains 𝑀 integers, 𝑎𝑖,𝑗 (0≤𝑎𝑖,𝑗≤100), the initial number of blocks at the cell (𝑖,𝑗).

// Output Specification
// Output one integer, the minimal number of blocks Bob needs to add so that all cells have the same number of blocks.

// Constraints
// Subtask	Points	Additional constraints
// 1	10	𝑁,𝑀≤10.
// 2	90	No additional constraints.
// Sample Input
// Copy
// 2 3
// 3 2 1
// 2 1 3
// Sample Output
// Copy
// 6
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n, m;
    cin >> n >> m;
    vector <int> vec1;
    int maximum = -1 * INT_MAX;
    for (int x = 0; x < n; x++)
    {
        for (int a = 0; a < m; a++)
        {
            int b;
            cin >> b;
            vec1.emplace_back(b);
            if (b > maximum) maximum = b;
        }
    }
    int s = 0;
    for (auto a : vec1)
    {
        s += (maximum - a);
    }
    cout << s << endl;
}


// Bob is writing a final quiz consisting of 𝑁 questions. Initially, Bob has 𝑀 points. If Bob answers one question correctly, he will get one point; otherwise, he will lose one point. One exception is that Bob will lose nothing if he only has 0 points.

// Given a string 𝑆 which represents Bob's answers, if the 𝑖-th character is o, it means Bob is correct for the 𝑖-th question; if the character is x, Bob is wrong for the question. Can you write a program to find out the number of points Bob will have in the end?

// Input Specification
// The first line of input contains two integers 𝑁, 𝑀 (1≤𝑁≤2×105, 0≤𝑀≤2×105), the number of questions and the number of initial points.

// The second line of input contains a string 𝑆, (|𝑆|=𝑁), consisting of o and x.

// Output Specification
// Output one integer, the final points Bob will have in the end.

// Constraints
// Subtask	Points	Additional constraints
// 1	20	𝑁≤20.
// 2	80	No additional constraints.
// Sample Input
// Copy
// 4 1
// xxoo
// Sample Output
// Copy
// 2
#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n, m;
    cin >> n >> m; cin.ignore();
    string line;
    getline(cin, line);
    for (auto a : line)
    {
        if (a == 'o') m++;
        if (a == 'x')
        {
            if (m != 0) m--;
        }
    }
    cout << m << endl;
}


// Given an integer 𝑥, the digit sum of 𝑥 is the sum of all digits in 𝑥. For example, if 𝑥=213, the digit sum is 2+1+3=6. Given 𝑛 integers, Bob wants to find out the max digit sum among all 𝑛 integers. Can you write a program to help Bob?

// Input Specification
// The first line of input contains one integer 𝑛 (2≤𝑛≤1000), the number of integers.

// Each of the following 𝑛 lines contains one integer 𝑥 (0≤𝑥≤101000).

// Output Specification
// Output one integer, the max digit sum among all 𝑛 integers.

// Constraints
// Subtask	Points	Additional constraints
// 1	10	𝑥≤2×109
// 2	20	𝑥≤9×1018
// 3	70	No additional constraints.
// Sample Input 1
// Copy
// 3
// 213
// 91
// 62
// Sample Output 1
// Copy
// 10
// Explanation
// The digit sum of the 3 integers are: 2+1+3=6, 9+1=10, and 6+2=8, where the max digit sum is 10.

// Sample Input 2
// Copy
// 2
// 101
// 999
// Sample Output 2
// Copy
// 27

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n; cin.ignore();
    int s;
    int maximum = -1 * INT_MAX;
    for (int x = 0; x < n; x++)
    {
        string a;
        getline(cin, a);
        s = 0;
        for (auto b : a)
        {
            s += b - '0';
        }
        if (s > maximum) maximum = s;
    }
    cout << maximum << endl;
}

// Given 𝑁 items, numbered from 1 to 𝑁, the 𝑖-th item has a value of 𝑣𝑖. Bob will put at most 𝐾 items (1≤𝐾≤𝑁) into his knapsack, and he wants to know what is the maximum possible sum of value he can get in the knapsack.

// Bob will ask you 𝑄 queries. For each query, he will give you an integer 𝐾, and you need to tell him the maximum possible sum of value.

// Input Specification
// The first line of input contains two integers 𝑁 and 𝑄 (1≤𝑁,𝑄≤105), the number of items and the number of questions Bob will ask.

// The second line of input contains 𝑁 integers, 𝑣𝑖 (−109≤𝑣𝑖≤109), the value of the 𝑖-th item.

// Each of the following 𝑄 lines contains one integer 𝐾 (1≤𝐾≤𝑁), the max number of items Bob can put into his knapsack.

// Output Specification
// For each query, output one integer, the maximum possible sum of value.

// Constraints
// Subtask	Points	Additional constraints
// 1	10	𝑁,𝑄≤10
// 2	20	𝑁,𝑄≤10000.
// 3	70	No additional constraints.
// Sample Input
// Copy
// 5 3
// 3 -2 5 4 -7
// 1
// 3
// 5
// Sample Output
// Copy
// 5
// 12
// 12

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    long long n, q, a;
    cin >> n >> q;
    vector <long long> values;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        if(a > 0) values.emplace_back(a);
    }
    sort(values.rbegin(), values.rend());
    vector <long long> vec1;
    for(long long i = 0; i < values.size(); i++)
    {
        if(i == 0) vec1.push_back(values[i]);
        else vec1.push_back(vec1[i - 1] + values[i]);
    }
    for (long long b = 0; b < q; b++)
    {
        cin >> a;
        if(a >= values.size()) cout << vec1.back() << endl;
        else cout << vec1[a - 1] << endl;
    }
}


// Bob is a teacher and he has 𝑁 students, where 𝑁 is an odd number. After marking the final quiz, Bob wants to find out the median student: half of the students get as much or higher marks than the median student; half of them get as much or lower marks. If multiple students get the same mark, Bob will sort these students by their name in lexicographical order. Can you write a program to help Bob find out the median student's name.

// Input Specification
// The first line of input contains one integer 𝑁 (1≤𝑁≤105), the number of students.

// Each of the following 𝑁 lines contains one string 𝑠𝑖 and one integer 𝑣𝑖 (1≤|𝑠𝑖|≤20, 1≤𝑣𝑖≤106), where 𝑠𝑖 is the 𝑖-th student's name consisting only of lowercase letters and 𝑣𝑖 is the mark the 𝑖-th student gets.

// In 30% cases, 𝑁≤500.

// In another 30% cases, 𝑁≤104.

// Output Specification
// Output one string, the median student's name.

// Sample Input 1
// Copy
// 5
// alice 2
// allen 4
// brian 1
// susan 3
// oscar 5
// Sample Output 1
// Copy
// susan
// Sample Input 2
// Copy
// 5
// alice 1
// brian 5
// allen 5
// susan 6
// oscar 8
// Sample Output 2
// Copy
// brian
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
    vector <pair <int, string> > vec1;
    string name;
    int score;
    for (int x = 0; x < n; x++)
    {
        cin >> name >> score;
        vec1.push_back({score, name});
    }
    sort(vec1.begin(), vec1.end());
    cout << vec1[n / 2].second << endl;
}


Bob is writing a programming contest. There are 𝑛 (1≤𝑛≤5) questions in the contest. The points of the 𝑛 questions are denoted as 𝑎1,𝑎2,…,𝑎𝑛. There is no partial point for each question. Thus, Bob either completely solves a question to get the full point, or gets 0 point. The final score is the sum of points Bob gets in each question. Bob wants to find out the number of distinct possible final scores he can have. Can you write a program to help him?

// Input Specification
// The first line of input contains one integer 𝑛 (1≤𝑛≤5), the number of questions in the contest.

// The second line of input contains 𝑛 integers, 𝑎𝑖 (1≤𝑎𝑖≤15), the point of the 𝑖-th question.

// Output Specification
// Output one integer, the number of distinct possible final scores Bob may have.

// Constraints
// Subtask	Points	Additional constraints
// 1	10	𝑛<=2.
// 2	10	𝑛=3.
// 3	10	𝑛=4.
// 4	70	No additional constraints.
// Sample Input 1
// Copy
// 2
// 1 2
// Sample Output 1
// Copy
// 4
// Explanation
// The final score can be 0, 1, 2, or 3. Thus, there are 4 distinct possible scores.

// Sample Input 2
// Copy
// 3
// 1 2 3
// Sample Output 2
// Copy
// 7
// Explanation
// The final score can be 0,1,2,3,4,5,6. Thus, there are 7 distinct possible scores.
#include <bits/stdc++.h>
using namespace std;

void getstrings(int n, vector <int> vec1, int i, vector <int> scores, unordered_set <int> &s1)
{
	if (i == n)
	{
		int s = 0;
    	for (int i = 0; i < n; i++)
    	{
    	    if (vec1[i] == 0) s += 0;
    	    else s += scores[i];
    	}
    	s1.insert(s);
	}
    else
    {
        vec1.emplace_back(0);
    	getstrings(n, vec1, i + 1, scores, s1);
    	vec1[i] = 1;
    	getstrings(n, vec1, i + 1, scores, s1);
    }
}

int main()
{
	int n;
	cin >> n;
	vector <int> scores;
	for (int x = 0; x < n; x++)
	{
	    int a;
	    cin >> a;
	    scores.emplace_back(a);
	}
    vector <int> vec1;
	unordered_set <int> s1; 
	getstrings(n, vec1, 0, scores, s1);
	cout << s1.size() << endl;
}

// Bob is writing a programming contest. There are 𝑛 (1≤𝑛≤1000) questions in the contest. The points of the 𝑛 questions are denoted as 𝑎1,𝑎2,…,𝑎𝑛. There is no partial point for each question. Thus, Bob either completely solves a question to get the full point, or gets 0 point. The final score is the sum of points Bob gets in each question. Bob wants to find out the number of distinct possible final scores he can have. Can you write a program to help him?

// Input Specification
// The first line of input contains one integer 𝑛 (1≤𝑛≤1000), the number of questions in the contest.

// The second line of input contains 𝑛 integers, 𝑎𝑖 (1≤𝑎𝑖≤15), the point of the 𝑖-th question.

// Output Specification
// Output one integer, the number of distinct possible final scores Bob may have.

// Constraints
// Subtask	Points	Additional constraints
// 1	15	𝑛≤5.
// 2	15	𝑛≤20.
// 3	70	No additional constraints.
// Sample Input 1
// Copy
// 2
// 1 2
// Sample Output 1
// Copy
// 4
// Explanation
// The final score can be 0, 1, 2, or 3. Thus, there are 4 distinct possible scores.

// Sample Input 2
// Copy
// 3
// 1 2 3
// Sample Output 2
// Copy
// 7
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> scores;
	for (int x = 0; x < n; x++)
	{
	    int b;
	    cin >> b;
	    scores.emplace_back(b);
	}
	unordered_set <int>  set1 = {0, scores[0]};
	for (int a = 2; a <= n; a++)
	{
	    unordered_set <int>  set2;
        for (auto x : set1)
        {
            set2.insert(x);
            set2.insert(x + scores[a - 1]);
        }
        set1 = set2;
	}
	cout << set1.size() << endl;
}


// Given an array 𝐴 with 𝑁 integers, denoted as 𝑎1,𝑎2,…,𝑎𝑁, Bob calculates the absolute difference |𝑎𝑖−𝑎𝑗| for all pairs of 𝑖 and 𝑗 (1≤𝑖<𝑗≤𝑁), and stores these differences into another array 𝐵. For example, if Bob's array 𝐴 is [3,2,5,1], the array 𝐵 will be [|3−2|,|3−5|,|3−1|,|2−5|,|2−1|,|5−1|], i.e. 𝐵=[1,2,2,3,1,4]. Bob wants to calculate the sum of the array 𝐵. Can you write a program to help Bob?

// Input Specification
// The first line of input contains one integer 𝑁 (2≤𝑁≤200000), the length of the array 𝐴.

// The second line of input contains 𝑁 integers, 𝑎𝑖, (−109≤𝑎𝑖≤109), the 𝑖-th element in the array 𝐴.

// Output Specification
// Output one integer, the sum of the array 𝐵.

// Constraints
// Subtask	Points	Additional constraints
// 1	20	𝑁≤1000
// 2	80	No additional constraints.
// Sample Input 1
// Copy
// 4
// 3 2 5 1
// Sample Output 1
// Copy
// 13
// Explanation
// The sample case is explained in the problem. The array 𝐵 is [1,2,2,3,1,4] and the sum is 13.

// Sample Input 2
// Copy
// 3
// 5 1 2
// Sample Output 2
// Copy
// 8
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    long long n;
    cin >> n;
    vector <int> vec1;
    long long s = 0;
    for (long long x = 0; x < n; x++)
    {
        int a;
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.rbegin(), vec1.rend());
    for (long long b = 0; b < n; b++)
    {
        s += (vec1[b] * (n - b - 1)) - b * vec1[b];
    }
    cout << s << endl;
}


// Given a string 𝑠, Bob defines the string power 𝑠𝑘 as the operation to repeat the string 𝑠 for 𝑘 times. For example, if 𝑠 is ab, then 𝑠3 is ababab.

// Bob has 𝑛 strings. For each string 𝑡, Bob wants to find out the largest 𝑘 such that 𝑡=𝑠𝑘 for some string 𝑠. For example, if 𝑡 is ababab, the largest 𝑘 is 3 and 𝑠 is ab. Can you write a program to help Bob?

// Input Specification
// The first line of input contains an integer 𝑛, (1≤𝑛≤2500), the number of strings.

// Each of the following 𝑛 lines contains a string 𝑡 (∑|𝑡|≤106). Note, the string 𝑡 may consist of lower case letters, upper case letters and digits.

// Output Specification
// For each string 𝑡, output the largest 𝑘 such that the string 𝑡 can be made by repeating some string 𝑠 for 𝑘 times.

// Constraints
// Subtask	Points	Additional constraints
// 1	20	𝑛≤5.
// 2	80	No additional constraints.
// Sample Input
// Copy
// 2
// aaaa
// ababab
// Sample Output
// Copy
// 4
// 3
// Explanation
// For aaaa, it can be made by repeating a for 4 times

// For ababab, it can be made by repeating ab for 3 times.
#include <bits/stdc++.h>
using namespace std;

bool check_pattern(string str2, int k)
{
    string first = str2.substr(0, k);
    for(int j=0; j<str2.size(); j+=k) 
    {
        //cout << "extracted="<<str2.substr(j, k) << ", first=" << first << endl;
        if(str2.substr(j, k)!=first) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >>n;
    for (int i=0; i<n; i++)
    {
        string str1;
        int flag=0;
        cin >> str1;
        int len = str1.size();
        for(int j=1; j<=str1.size()/2; j++)
        {
            if(len%j==0) 
            {
                if (check_pattern(str1, j))
                {
                    cout << len/j << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag==0) cout << 1 << endl;
    }
    
}



// You are given a spreadsheet with 𝐶 columns. The item in each cell is a string consisting of lower case letters. You are provided with an operation 𝑆𝑜𝑟𝑡(𝑘), where 𝑆𝑜𝑟𝑡(𝑘) sorts the rows of a table in the order of the values in column 𝑘 (while the order of the columns does not change). The sort is stable, that is, rows that have equal values in column 𝑘, remain in their original order.

// C1	C2	C3
// apple	red	sweet
// apple	green	sour
// pear	green	sweet
// banana	brown	rotten
// For example, given the above table, if you do 𝑆𝑜𝑟𝑡(2) operation to the table, you will get the following table.

// C1	C2	C3
// banana	brown	rotten
// apple	green	sour
// pear	green	sweet
// apple	red	sweet
// If you take a sequence of such sort operatoins, sometimes two sequences of sort opeartions are equivalent, if they have same effect for any table. For example a sequence { 𝑆𝑜𝑟𝑡(2), 𝑆𝑜𝑟𝑡(2), 𝑆𝑜𝑟𝑡(1) } is equivalent to {𝑆𝑜𝑟𝑡(2), 𝑆𝑜𝑟𝑡(1) }. However, it is not equivalent to {𝑆𝑜𝑟𝑡(1),𝑆𝑜𝑟𝑡(2)}, because the effect on the table is different.

// Given a sequence of sort operations, find out the shortest equivalent sequence.

// Input Specification
// The first line contains two integers, 𝐶 and 𝑁 (1≤𝐶≤106, 1≤𝑁≤3×106), the number of columns and the number of sort operations.

// The second line contains 𝑁 integers, 𝑘𝑖 (1≤𝑘𝑖≤𝐶), a sort operation on column 𝑘𝑖.

// In 15% test cases, 𝐶≤100,𝑁≤100.

// In another 15% test cases, 𝐶≤1000,𝑁≤1000.

// Output Specification
// The first line contains one integer, 𝑀, the length of the shortest sequence of sort operations equivalent to the input sequence.

// The second line contains exactly 𝑀 integers, representing a shortest sequence.

// Sample Input
// Copy
// 4 6
// 1 2 1 2 3 3
// Sample Output
// Copy
// 3
// 1 2 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
	int c, n;
	cin >> c >> n;
	vector <pair <int, int> > vec1;
	unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        int a;
        cin >> a;
        m1[a] = x;
    }
    for (auto b : m1) vec1.push_back({b.second, b.first});
    sort(vec1.begin(), vec1.end());
    cout << vec1.size() << endl;
    for (auto c : vec1) cout << c.second << " ";
    cout << endl;
}


// One bright morning, d's English teacher needed help marking some essays. Naturally, d went out of his way to help him. When d gets the papers, he notices that the essays are riddled with improper capitalization everywhere.

// Wanting to help his classmates (but not having enough time to properly fix their errors), d decides to convert the entire essay into either lowercase or uppercase text. He wants to do the least work possible, so he will convert an essay to lowercase if it already has more lowercase characters than uppercase, and vice-versa. If a tie occurs, he will leave the essay as it is.

// Having a lot of essays to fix, d asks you to write a program to help him!

// Input Specification
// The input will consist of one line, containing one essay. The essay will have spaces and alphanumeric characters only. It is guaranteed that there are no more than 1024 characters in the essay. The essay may contain leading whitespace.

// Output Specification
// Output the modified essay, according to the rules above.

// Sample Input
// Copy
// mITOCHONDRIA iS tHE pOWERHOUSE oF tHE cELL
// Sample Output
// Copy
// MITOCHONDRIA IS THE POWERHOUSE OF THE CELL

#include <iostream>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    int c1 = 0;
    int c2 = 0;
    for (auto a : line)
    {
        if (islower(a)) c1++;
        if (isupper(a)) c2++;
    }
    if (c1 > c2)
    {
        for (auto &b : line)
        {
            b = tolower(b);
        }
    }
    if (c1 < c2)
    {
        for (auto &b : line)
        {
            b = toupper(b);
        }
    }
    cout << line << endl;
}


// You were the Chosen One! You were supposed to destroy the Sith, not join them. You were supposed to bring balance to the Force, not leave it in darkness.

// The Force, represented by the characters ( and ) is now unbalanced! The Force is balanced if it is one of the following:

// ()
// AB, where 𝐴 and 𝐵 are balanced
// (A), where 𝐴 is balanced
// Kenobi can invert (i.e. turn a ( character to ), or vice versa) at most 1 character in the Force. Given the sequence which represents the Force, print YES if Kenobi can balance it, and NO otherwise.

// Input Specification
// The input will contain a single string, 𝑆, the sequence which represents the Force.

// Output Specification
// YES if it can be balanced, and NO otherwise.

// Constraints
// For all subtasks:

// 𝑆 will have an even number of characters.

// Subtask 1 [20%]
// 2≤|𝑆|≤1000

// Subtask 2 [80%]
// 2≤|𝑆|≤105

// Sample Input
// Copy
// ()()((()
// Sample Output
// Copy
// YES
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    string line;
    getline(cin, line);
    stack <char> s1;
    s1.push(line[0]);
    for (int a = 1; a < line.length(); a++)
    {
        if (!s1.empty() && line[a] == ')' && s1.top() == '(') s1.pop();
        else s1.push(line[a]);
    }
    if (s1.size() == 0 || s1.size() == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}


// School's back! You're up to no good again already… While your art teacher, Roger, was looking away, you grab his basket of Crayola™ markers and started connecting them together.

// This creates a colorful sword that you can use to hit people that you find annoying with. You want to be able to reach quite far with your sword though, so you keep on connecting.

// Although you want your crayon lightsaber to be as long as possible, you also care deeply about it being aesthetically pleasing. For that reason, you choose to never connect two crayons of the same color directly together.

// Given the colors of the markers in the basket, what is the longest Crayola™ marker sword you can construct?

// Input Specification
// The first line will contain an integer (1≤𝑁≤10000). This will then be followed by a line of 𝑁 strings that represent the colors of the markers. The colors can be: red, orange, yellow, green, blue, black.

// Output Specification
// The only output is an integer representing the maximum length possible for the marker sword.

// Sample Input 1
// Copy
// 4
// red blue green black
// Sample Output 1
// Copy
// 4
// Sample Input 2
// Copy
// 5
// yellow orange yellow yellow yellow
// Sample Output 2
// Copy
// 3
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

// Bessie the cow is working on an essay for her writing class. Since her handwriting is quite bad, she decides to type the essay using a word processor.

// The essay contains 𝑁 words (1≤𝑁≤100), separated by spaces. Each word is between 1 and 15 characters long, inclusive, and consists only of uppercase or lowercase letters. According to the instructions for the assignment, the essay has to be formatted in a very specific way: each line should contain no more than 𝐾 (1≤𝐾≤80) characters, not counting spaces. Fortunately, Bessie's word processor can handle this requirement, using the following strategy:

// If Bessie types a word, and that word can fit on the current line, put it on that line.

// Otherwise, put the word on the next line and continue adding to that line.

// Of course, consecutive words on the same line should still be separated by a single space. There should be no space at the end of any line.

// Unfortunately, Bessie's word processor just broke. Please help her format her essay properly!

// INPUT FORMAT:
// The first line of input contains two space-separated integers 𝑁 and 𝐾.

// The next line contains 𝑁 words separated by single spaces. No word will ever be larger than 𝐾 characters, the maximum number of characters on a line.

// OUTPUT FORMAT:
// Bessie's essay formatted correctly.

// SAMPLE INPUT:
// Copy
// 10 7
// hello my name is Bessie and this is my essay
// SAMPLE OUTPUT:
// Copy
// hello my
// name is
// Bessie
// and this
// is my
// essay
// Explanation
// Including "hello" and "my", the first line contains 7 non-space characters. Adding "name" would cause the first line to contain 11>7 non-space characters, so it is placed on a new line.
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n, k;
    cin >> n >> k; cin.ignore();
    string line;
    getline(cin, line);
    vector <string> words = split(line);
    int length = 0;
    for (int a = 0; a < words.size(); a++)
    {
        string word = words[a];
        if (a == 0)
        {
            cout << word;
            length = word.length();
        }
        else
        {
            if (length + word.length() > k)
            {
                cout << endl << word; length = word.length();
            }
            else
            {
                cout << " " << word;
                length += word.length();
            }
        }
    }
    cout << endl;
}


// Farmer John is lining up his 𝑁 cows (2≤𝑁≤103), numbered 1…𝑁, for a photoshoot. FJ initially planned for the 𝑖-th cow from the left to be the cow numbered 𝑎𝑖, and wrote down the permutation 𝑎1,𝑎2,…,𝑎𝑁 on a sheet of paper. Unfortunately, that paper was recently stolen by Farmer Nhoj!

// Luckily, it might still possible for FJ to recover the permutation that he originally wrote down. Before the sheet was stolen, Bessie recorded the sequence 𝑏1,𝑏2,…,𝑏𝑁−1 that satisfies 𝑏𝑖=𝑎𝑖+𝑎𝑖+1 for each 1≤𝑖<𝑁.

// Based on Bessie's information, help FJ restore the "lexicographically minimum" permutation 𝑎 that could have produced 𝑏. A permutation 𝑥 is lexicographically smaller than a permutation 𝑦 if for some 𝑗, 𝑥𝑖=𝑦𝑖 for all 𝑖<𝑗 and 𝑥𝑗<𝑦𝑗 (in other words, the two permutations are identical up to a certain point, at which 𝑥 is smaller than 𝑦). It is guaranteed that at least one such 𝑎 exists.

// INPUT FORMAT:
// The first line of input contains a single integer 𝑁.

// The second line contains 𝑁−1 space-separated integers 𝑏1,𝑏2,…,𝑏𝑁−1.

// OUTPUT FORMAT:
// A single line with 𝑁 space-separated integers 𝑎1,𝑎2,…,𝑎𝑁.

// SAMPLE INPUT:
// Copy
// 5
// 4 6 7 6
// SAMPLE OUTPUT:
// Copy
// 3 1 5 2 4
// Explanation
// 𝑎 produces 𝑏 because 3+1=4, 1+5=6, 5+2=7, and 2+4=6.
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n;
    cin >> n; cin.ignore();
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    vector <int> vec2;
    int current_cow;
    for (int x = 1; x < vec1[0]; x++)
    {
        vec2 = {};
        current_cow = x;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                vec2.emplace_back(current_cow);
                continue;
            }
            current_cow = vec1[i - 1] - current_cow;
            if (current_cow <= 0) break;
            if (find(vec2.begin(), vec2.end(), current_cow) != vec2.end()) break;
            vec2.emplace_back(current_cow);
            if (i == n - 1)
            {
                print(vec2);
                return 0;
            }
        }
    }
}



// We are familiar with infix notation for representing expressions, where the operator is placed infix between the operands, as in 5 * 5. Given an expression in postfix notation, such as 5 5 *, evaluate the expression and print it to standard output, rounded to one decimal place.

// Valid operands are * (multiplication), / (division), + (addition), - (subtraction), % (mod), and ^ (exponentiation).

// Input Format
// A valid postfix expression. The input will have no more than 50 characters, and the value of each number in the input and each intermediate result will be less than or equal to 1000.

// Output Format
// The result of the evaluation. The answer will be considered correct if its absolute or relative error does not exceed 10−1.

// Sample Input 1
// Copy
// 5 5 +
// Sample Output 1
// Copy
// 10.0
// Sample Input 2
// Copy
// 5 5 + 6 * 8 -
// Sample Output 2
// Copy
// 52.0
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stack>
#include <cmath>
using namespace std;

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    vector <string> vec1 = split(line);
    stack <double> s1;
    double tmp1;
    double tmp2;
    for (auto a : vec1)
    {
        if (a == "+")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(tmp2 + tmp1);
        }
        else if (a == "-")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(tmp2 - tmp1);
        }
        else if (a == "*")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(tmp2 * tmp1);
        }
        else if (a == "/")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push((tmp2 / 1.0) / tmp1);
        }
        else if (a == "%")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            double current = 0.0;
            while (current + tmp1 <= tmp2)
            {
                current += tmp1;
            }
            current = tmp2 - current;
            s1.push(current);
        }
        else if (a == "^")
        {
            tmp1 = s1.top();
            s1.pop();
            tmp2 = s1.top();
            s1.pop();
            s1.push(pow(tmp2, tmp1));
        }
        else
        {
            s1.push(stoi(a));
        }
    }
    double ans = (s1.top() / 1.0);
    cout << fixed << setprecision(1) << ans << endl;
}

// The CS Nerd is dreaming about giving Christmas presents to the girl. Unfortunately, he does not have enough courage to do this in real life.

// In the dream, there are 𝑁 presents that he could possibly give to the girl. The 𝑖𝑡ℎ present has a weight of 𝑤𝑖. The CS Nerd wants to impress the girl by building a large stack of presents – that is, presents stacked one on top of each other – and giving it to her.

// However, the CS Nerd needs to ensure that the sum of the weights of the presents above any present does not exceed that present's weight. What is the maximum number of presents that can be in the stack?

// Input Specification
// The first line of input will contain a single integer 𝑁 (1≤𝑁≤100000).

// 𝑁 lines of input follow. The 𝑖𝑡ℎ line will consist of a single integer, 𝑤𝑖 (1≤𝑤𝑖≤109).

// For 20% of the points, 𝑁≤10.

// For an additional 30% of the points, 𝑁≤1000.

// Output Specification
// Output a single integer, the maximum possible number of presents that can be in the stack.

// Sample Input
// Copy
// 5
// 7
// 8
// 2
// 5
// 10
// Sample Output
// Copy
// 3
// Explanation for Sample Output
// The CS Nerd can stack presents in the order 2, 4, and 3 from the bottom. The weights of these presents are 8, 5, and 2, respectively. Note that this is not the only possible solution.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n;
    cin >> n;
    vector <int> presents;
    for (int x = 0; x < n; x++)
    {
        int present;
        cin >> present;
        presents.emplace_back(present);
    }
    sort(presents.begin(), presents.end());
    int tmp = presents[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (presents[i] >= tmp)
        {
            tmp += presents[i];
            count++;
        }
    }
	cout << count << endl;
}


// There are 𝑁 chairs in a circle. Exactly 𝐾 of these chairs are empty and there are 𝐾+1 students numbered from 1 to 𝐾+1 standing at some of these chairs. Every second, each student moves forward by one chair. In particular, if they are currently standing by chair 𝑁, then they will move to chair 1 after. If a student reaches an empty chair, including at the very beginning, they will sit down for the remaining time. Who will be the last standing student?

// It is guaranteed that every student begins by a different chair.

// Edit: The test data has been fixed.

// Constraints
// For all subtasks:

// All the indices in the input will be between 1 and 𝑁 inclusive.

// Subtask 1 [30%]
// 1≤𝐾<𝑁≤5000

// Subtask 2 [50%]
// 1≤𝐾<𝑁≤200000

// Subtask 3 [20%]
// 1≤𝐾<𝑁≤1000000

// Input Specification
// The first line will have two space-separated integers, 𝑁 and 𝐾.
// The next line will have 𝐾 space-separated integers representing the indices of the empty chairs.
// The third line will have 𝐾+1 space-separated integers. The 𝑖th integer is the chair at which student 𝑖 begins at.

// Output Specification
// Output a single integer, the index of the last standing student.

// Sample Input
// Copy
// 7 2
// 2 1
// 6 5 4
// Sample Output
// Copy
// 3
#include <bits/stdc++.h>
using namespace std;


bool comp(pair <int, int> a, pair <int, int>  b) {
    if (a.first == b.first) {
        return a > b;
    } else {
        return b > a;
    }
}

int main()
{
    int n, k;
    vector <pair <int, int> > vec1;
    cin >> n >> k;
    int a;
    for (int i = 1; i <= k; i++) {
        cin >> a;
        vec1.push_back({a, 0});
    }
    for (int i = 1; i <= k + 1; i++) {
        cin >> a;
        vec1.push_back({a, i});
    }
    sort(vec1.begin(), vec1.end(), [](pair <int, int> a, pair <int, int> b)
    {if (a.first == b.first) {return a.second > b.second;} else {return a < b;}});

    stack <pair <int, int> > s1;
    for (pair <int, int> b : vec1) {
        if (!s1.empty())
        {
            if (s1.top().second == 0 || b.second != 0) 
            {
                s1.push(b);
            }
            else 
            {
                s1.pop();
            }
        }
        else 
        {
            s1.push(b);
        }
    }
    
    int c = 0;
    while (!s1.empty() && s1.top().second != 0)
    {
        c = s1.top().second;
        s1.pop();
    }
    cout << c << endl;
}



// Given two integers 𝐴 and 𝐵, 𝐴 modulo 𝐵 is the remainder when dividing 𝐴 by 𝐵. For example, the numbers 7, 14, 27 and 38 become 1, 2, 0 and 2, modulo 3. Write a program that accepts 10 numbers as input and outputs the number of distinct numbers in the input, if the numbers are considered modulo 42.

// Input Specification
// The input will contain 10 non-negative integers, each smaller than 1000, one per line.

// Output Specification
// Output the number of distinct values when considered modulo 42 on a single line.

// Sample Input 1
// Copy
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// Sample Output 1
// Copy
// 10
// Explanation for Sample Output 1
// The numbers modulo 42 are 1, 2, 3, 4, 5, 6, 7, 8, 9 and 10.
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


// Canadian Computing Competition: 2013 Stage 1, Junior #4
// You have been asked by a parental unit to do your chores.

// Each chore takes a certain amount of time, but you may not have enough time to do all of your chores, since you can only complete one chore at a time. You can do the chores in any order that you wish.

// What is the largest amount of chores you can complete in the given amount of time?

// Input Specification
// The first line of input consists of an integer 𝑇 (0≤𝑇≤100000), which is the total number of minutes you have available to complete your chores.

// The second line of input consists of an integer 𝐶 (0≤𝐶≤100), which is the total number of chores that you may choose from. The next 𝐶 lines contain the (positive integer) number of minutes required to do each of these chores. You can assume that each chore will take at most 100000 minutes.

// Output Specification
// The output will be the maximum number of chores that can be completed in time 𝑇.

// Sample Input 1
// Copy
// 6
// 3
// 3
// 6
// 3
// Output for Sample Input 1
// Copy
// 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int mins;
    cin >> mins;
    int c;
    cin >> c;
    vector <int> vec1;
    for (int x = 0; x < c; x++)
    {
        int a;
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    int ind = 0;
    while (mins >= vec1[ind])
    {
        mins -= vec1[ind];
        ind++;
    }
    cout << ind;
}


// KeenKen the monkey is going shopping! KeenKen currently has 𝐴 units of sugar, but he needs 𝐵 units of sugar. He has 𝐶 units of toothpaste, but he needs 𝐷 units of toothpaste.

// If he doesn't have enough sugar, he will have to go to the grocery store to get some. If he doesn't have enough toothpaste, he will have to go to the pharmacy. However, if he needs both, he can get them both at the department store, but that is farther away. Thus, he will only visit the department store if he needs to get both items.

// If he doesn't need to get either item, KeenKen will stay home.

// Please tell KeenKen what to do!

// Constraints
// 0≤𝐴,𝐵,𝐶,𝐷≤100

// Input Specification
// The first and only line will contain four space-separated integers, 𝐴,𝐵,𝐶,𝐷.

// Output Specification
// Output one line with the command KeenKen should complete. The output should correspond with one of the following:

// Go to the grocery store
// Go to the pharmacy
// Go to the department store
// Stay home
// Sample Input 1
// Copy
// 1 2 3 4
// Sample Output 1
// Copy
// Go to the department store
// Explanation for Sample 1
// KeenKen has 1 unit of sugar which is less than the 2 units required. He has 3 units of toothpaste which is less than the 4 units required. Since he needs more of both items, he should visit the department store.
#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b && c < d) cout << "Go to the department store" << endl;
    else if (a < b) cout << "Go to the grocery store" << endl;
    else if (c < d) cout << "Go to the pharmacy" << endl;
    else cout << "Stay home" << endl;
}

// Daniel the monkey was hanging off his favourite branch while watching his favourite anime, when all of a sudden, a potato fell from the sky! Upon examining the potato, he notices 𝐷 distinct digits carved on it.

// Daniel wants you to use some non-empty combination of digits from the potato to form a positive integer of length 𝐾, with no leading zeros. He also tells you that you can use the same digit more than once. Additionally, Daniel doesn't remember if he should read numbers from left to right or right to left, so he tells you to make him an integer that reads the same either way!

// In addition, Daniel doesn't like processing large integers, so he'll only accept the smallest possible answer. If it is impossible to satisfy this task, you'll have to tell him, and he will become a very sad monkey.

// Constraints
// 1≤𝐾≤2×103

// 1≤𝐷≤10

// 0≤𝑑𝑖≤9

// All 𝑑𝑖 are distinct.

// Subtask 1 [20%]
// 1≤𝑑𝑖≤9

// Subtask 2 [80%]
// No additional constraints.

// Input Specification
// The first line of input will contain 𝐾 and 𝐷 separated by a single space.

// The next line will contain 𝐷 space-separated integers, denoting the digits that you can use to construct the integer.

// Output Specification
// Output the minimum positive integer of length 𝐾 using some non-empty combination of the 𝐷 digits, or -1 if there is no valid answer.

// Sample Input 1
// Copy
// 5 6
// 3 1 2 5 4 9
// Sample Output 1
// Copy
// 11111
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int k, d;
    cin >> k >> d;
    cin.ignore();
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    sort(vec1.begin(), vec1.end());
    if (vec1.back() == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        int ind = 0;
        if (vec1[ind] == 0)
        {
            while (vec1[ind] < 1) ind++;
            if (k == 1) cout << vec1[ind] << endl;
            else
            {
                cout << vec1[ind];
                for (int a = 0; a < k - 2; a++) cout << 0;
                cout << vec1[ind] << endl;
            }
        }
        else
        {
            for (int a = 0; a < k; a++) cout << vec1[ind];
            cout << endl;
        }
    }
}

// Farmer John's cows have been holding a daily online gathering on the "mooZ" video meeting platform. For fun, they have invented a simple number game to play during the meeting to keep themselves entertained.

// Elsie has three positive integers 𝐴, 𝐵, and 𝐶 (𝐴≤𝐵≤𝐶). These integers are supposed to be secret, so she will not directly reveal them to her sister Bessie. Instead, she gives Bessie seven (not necessarily distinct) integers in the range 1…109, claiming that they are 𝐴, 𝐵, 𝐶, 𝐴+𝐵, 𝐵+𝐶, 𝐶+𝐴, and 𝐴+𝐵+𝐶 in some order.

// Given a list of these seven numbers, please help Bessie determine 𝐴, 𝐵, and 𝐶. It can be shown that the answer is unique.

// INPUT FORMAT:
// The only line of input consists of seven space-separated integers.

// OUTPUT FORMAT:
// Print 𝐴, 𝐵, and 𝐶 separated by spaces.

// SAMPLE INPUT:
// Copy
// 2 2 11 4 9 7 9
// SAMPLE OUTPUT:
// Copy
// 2 2 7
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    sort(vec1.begin(), vec1.end());
    cout << vec1[0] << " " << vec1[1] << " ";
    if (vec1[2] == vec1[0] + vec1[1]) cout << vec1[3] << endl;
    else cout << vec1[2] << endl;
}

// Every day, as part of her walk around the farm, Bessie the cow visits her favorite pasture, which has 𝑁 flowers (all colorful daisies) labeled 1…𝑁 lined up in a row (1≤𝑁≤100). Flower 𝑖 has 𝑝𝑖 petals (1≤𝑝𝑖≤1000).

// As a budding photographer, Bessie decides to take several photos of these flowers. In particular, for every pair of flowers (𝑖,𝑗) satisfying 1≤𝑖≤𝑗≤𝑁, Bessie takes a photo of all flowers from flower 𝑖 to flower 𝑗 (including 𝑖 and 𝑗).

// Bessie later looks at these photos and notices that some of these photos have an "average flower" -- a flower that has 𝑃 petals, where 𝑃 is the exact average number of petals among all flowers in the photo.

// How many of Bessie's photos have an average flower?

// INPUT FORMAT:
// The first line of input contains 𝑁. The second line contains 𝑁 space-separated integers 𝑝1…𝑝𝑁.

// OUTPUT FORMAT:
// Please print out the number of photos that have an average flower.

// SAMPLE INPUT:
// Copy
// 4
// 1 1 2 3
// SAMPLE OUTPUT:
// Copy
// 6
// EXPLANATION
// Every picture containing just a single flower contributes to the count (there are four of these in the example). Also, the (𝑖,𝑗) ranges (1,2) and (2,4) in this example correspond to pictures that have an average flower.
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    vector <int> vec1 = split(line);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int s = 0;
            for (int k = i; k <= j; k++) s += vec1[k];
            for (int a = i; a <= j; a++)
            {
                if (vec1[a] * (j - i + 1) == s) 
                {
                    count++;
                    break;
                }
            }
        }
    }
    cout << count << endl;
}

// DWITE Online Computer Programming Contest, November 2007, Problem 4
// Parenthesis are important characters in programming – they define order of operations and organize information. That is, as long as they are properly balanced. Parenthesis are balanced when opening and closing brackets are match with one another, and are themselves nested within balanced parenthesis.

// This is perhaps best illustrated in examples.

// () - balanced: opening is matched with a closing
// (() - not balanced: one of the opening brackets has no match
// ([)] - not balanced: the contents inside of ( ) are not balanced
// The input will contain 5 lines, each no more than 255 characters long. Valid characters are any of the three parenthesis types: (), [], {}, and any alphanumeric characters: a-z 0-9.

// The output will contain 5 lines, each stating either balanced or not balanced, for the supplied expressions.

// All of the characters but the parenthesis could effectively be ignored. Keep in mind the different types of parenthesis – an opening bracket needs to be matched with a closing bracket of the same type.

// Sample Input
// Copy
// abc
// ([{a}b]c)
// )(
// ([)]
// {abc]
// Sample Output
// Copy
// balanced
// balanced
// not balanced
// not balanced
// not balanced
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    stack <char> s1;
    int balanced;
    for (int x = 0; x < 5; x++)
    {
        balanced = 1;
        s1 = {};
        string line;
        getline(cin, line);
        for (auto a : line)
        {
            if (s1.empty())
            {
                if (a == ')')
                {
                    s1.push(0);
                    break;
                }
                if (a == '}')
                {
                    s1.push(0);
                    break;
                }
                if (a == ']')
                {
                    s1.push(0);
                    break;
                }
            }
            if (a == '(' || a == '{' || a == '[') s1.push(a);
            if (a == ')')
            {
                if (s1.top() == '(') s1.pop();
                else
                {
                    balanced = 0;
                    break;
                }
            }
            if (a == '}')
            {
                if (s1.top() == '{') s1.pop();
                else
                {
                    balanced = 0;
                    break;
                }
            }
            if (a == ']')
            {
                if (s1.top() == '[') s1.pop();
                else
                {
                    balanced = 0;
                    break;
                }
            }
        }
        if (s1.empty()) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
    }
}

// Canadian Computing Competition: 2010 Stage 1, Junior #4
// Your task is to help scientists predict the trend of the global warming. One of the hypotheses they are considering is that over long periods of time, the average temperature follows certain cycles, but each time the cycle starts from a higher temperature level. The temperatures are measured over five-year averages, and expressed in tenths of a degree.

// For example, if the following five-year averages are observed:

// 3,4,6,4,5,7,5

// then we can calculate that the temperature changes first 1 up, then 2 up, then 2 down, 1 up, 2 up, and 2 down. There is a cycle of changes of length three which covers all of the temperature differences: (+1,+2,−2). In other words, if we look at the differences starting at the first position, there is a cycle of length three of the form (+1,+2,−2) followed by another cycle of length three of exactly the same form. By way of another example, suppose the following average temperatures are observed:

// 3,4,6,7.

// In this case, there is a difference of one up, two up, then one up. We would consider the shortest cycle to be length two in this case: the cycle (+1,+2). Notice that this cycle occurs once, followed by one truncated occurrence of exactly the same cycle.

// Your task is to find the shortest such cycle from a given sequence of temperatures.

// Input Specification
// The input consists of a number of test cases. Each test case starts with the number 𝑛 (1≤𝑛≤20), representing the number of temperatures in a sequence, followed by the sequence of 𝑛 temperatures. You may assume that each temperature input is an integer in the range −1000…1000 inclusive. The numbers are separated by a single space. The last test case is indicated by a zero and should produce no output.

// Output Specification
// For each test case, produce the length of the shortest temperature cycle. The cycle always exists, since the whole sequence could be treated as one long cycle.

// Sample Input
// Copy
// 7 3 4 6 4 5 7 5
// 3 1 3 5
// 3 1 4 5
// 4 3 4 6 7
// 0
// Sample Output
// Copy
// 3
// 1
// 2
// 2

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    vector <int> vec1;
    vector <int> vec2;
    int ind;
    int count;
    while (line != "0")
    {
        vec2 = {};
        vec1 = split(line);
        vec1.assign(vec1.begin() + 1, vec1.end());
        for (int a = 1; a < vec1.size(); a++)
        {
            vec2.emplace_back(vec1[a] - vec1[a - 1]);
        }
        count = 0;
        for (int b = 0; b < vec2.size(); b++)
        {
            if (b != 0 && vec2[b] == vec2[0])
            {
                vector<int> v1;
                vector<int> v2;
                v1.assign(vec2.begin() + b, vec2.end());
                v2.assign(vec2.begin(), vec2.begin() + v1.size());
                if (v1 == v2) break;
            }
            count++;
        }
        cout << count << endl;
        getline(cin, line);
    }
}




// For Valentine's day, AQT wants to give a letter to his valentine. He currently has a string 𝑆 of 5 lowercase letters and wants to give one to his valentine that isn't present in the string. Help him find one!

// Constraints
// |𝑆|=5

// 𝑆 consists only of the letters abcdefghijklmnopqrstuvwxyz (lowercase English alphabet).

// Input Specification
// The first line contains the string 𝑆.

// Output Specification
// Output a letter that AQT does not have.
// Note: If there are multiple letters that meet this criteria, output the one with lowest alphabetical order. See sample explanation for more details.

// Sample Input
// Copy
// zdeac
// Sample Output
// Copy
// b
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string str1;
    getline(cin, str1);
    string alphabet = "abcedfghijklmnopqrstuvwxyz";
    for (auto a : alphabet)
    {
        if (find(str1.begin(), str1.end(), a) == str1.end())
        {
            cout << a << endl;
            break;
        }
    }
}



// Canadian Computing Competition: 2015 Stage 1, Senior #1
// Your boss has asked you to add up a sequence of positive numbers to determine how much money your company made last year.

// Unfortunately, your boss reads out numbers incorrectly from time to time.

// Fortunately, your boss realizes when an incorrect number is read and says "zero", meaning "ignore the current last number."

// Unfortunately, your boss can make repeated mistakes, and says "zero" for each mistake.

// For example, your boss can say "One, three, five, four, zero, zero, seven, zero, zero, six", which means the total is 7 as explained in the following chart.

// Boss statement(s)	Current numbers	Explanation
// "One, three, five, four"	1, 3, 5, 4	Record the first four numbers.
// "zero, zero"	1, 3	Ignore the last two numbers.
// "seven"	1, 3, 7	Record the number 7 at the end of our list.
// "zero, zero"	1	Ignore the last two numbers.
// "six"	1, 6	We have read all numbers, and the total is 7.
// At any point, your boss will have said at least as many positive numbers as "zero" statements. If all positive numbers have been ignored, the sum is zero.

// Write a program that reads the sequence of boss statements and computes the correct sum.

// Input Specification
// The first line of input contains the integer 𝐾 (1≤𝐾≤100000) which is the number of integers (including "zero") your boss will say. On each of the 𝐾 lines, there will either be one integer between 1 and 100 (inclusive) or the integer 0.

// Output Specification
// The output is one line, containing the integer which is the correct sum of the integers read, taking the "zero" statements into consideration. You can assume that the output will be an integer in the range 0 and 1000000 (inclusive).

// Sample Input 1
// Copy
// 4
// 3
// 0
// 4
// 0
// Sample Output 1
// Copy
// 0
// Sample Input 2
// Copy
// 10
// 1
// 3
// 5
// 4
// 0
// 0
// 7
// 0
// 0
// 6
// Sample Output 2
// Copy
// 7

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


// Canadian Computing Competition: 2016 Stage 1, Junior #5, Senior #2
// Since time immemorial, the citizens of Dmojistan and Pegland have been at war. Now, they have finally signed a truce. They have decided to participate in a tandem bicycle ride to celebrate the truce. There are 𝑁 citizens from each country. They must be assigned to pairs so that each pair contains one person from Dmojistan and one person from Pegland.

// Each citizen has a cycling speed. In a pair, the fastest person will always operate the tandem bicycle while the slower person simply enjoys the ride. In other words, if the members of a pair have speeds 𝑎 and 𝑏, then the bike speed of the pair is max(𝑎,𝑏). The total speed is the sum of the 𝑁 individual bike speeds.

// For this problem, in each test case, you will be asked to answer one of two questions:

// Question 1: what is the minimum total speed, out of all possible assignments into pairs?
// Question 2: what is the maximum total speed, out of all possible assignments into pairs?
// Input Specification
// The first line will contain the type of question you are to solve, which is either 1 or 2.

// The second line contains 𝑁 (1≤𝑁≤100).

// The third line contains 𝑁 space-separated integers: the speeds of the citizens of Dmojistan.

// The fourth line contains 𝑁 space-separated integers: the speeds of the citizens of Pegland.

// Each person's speed will be an integer between 1 and 1000000.

// For 8 of the 15 available marks, questions of type 1 will be asked. For 7 of the 15 available marks, questions of type 2 will be asked.

// Output Specification
// Output the maximum or minimum total speed that answers the question asked.

// Sample Input 1
// Copy
// 1
// 3
// 5 1 4
// 6 2 4
// Output for Sample Input 1
// Copy
// 12
// Explanation for Output for Sample Input 1
// There is a unique optimal solution:

// Pair the citizen from Dmojistan with speed 5 and the citizen from Pegland with speed 6.
// Pair the citizen from Dmojistan with speed 1 and the citizen from Pegland with speed 2.
// Pair the citizen from Dmojistan with speed 4 and the citizen from Pegland with speed 4.
// Sample Input 2
// Copy
// 2
// 3
// 5 1 4
// 6 2 4
// Output for Sample Input 2
// Copy
// 15
// Explanation for Output for Sample Input 2
// There are multiple possible optimal solutions. Here is one optimal solution:

// Pair the citizen from Dmojistan with speed 5 and the citizen from Pegland with speed 2.
// Pair the citizen from Dmojistan with speed 1 and the citizen from Pegland with speed 6.
// Pair the citizen from Dmojistan with speed 4 and the citizen from Pegland with speed 4.
// Sample Input 3
// Copy
// 2
// 5
// 202 177 189 589 102
// 17 78 1 496 540
// Output for Sample Input 3
// Copy
// 2016
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int q, n;
    cin >> q;
    cin >> n;
    cin.ignore();
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    vector <int> vec1 = split(str1);
    vector <int> vec2 = split(str2);
    int s = 0;
    if (q == 1)
    {
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());
        int min_e1;
        int min_e2;
        for (int x = 0; x < n; x++)
        {
            min_e1 = vec1[x];
            min_e2 = vec2[x];
            if (min_e1 < min_e2) s += min_e2;
            else s += min_e1;
        }
    }
    if (q == 2)
    {
        sort(vec1.rbegin(), vec1.rend());
        sort(vec2.begin(), vec2.end());
        int max_e1;
        int max_e2;
        for (int x = 0; x < n; x++)
        {
            max_e1 = vec1[x];
            max_e2 = vec2[x];
            if (max_e1 > max_e2) s += max_e1;
            else s += max_e2;
        }
    }
    cout << s << endl;
}


// Everyone knows that laughter comes in three types of pitches: up, down, and right. Kiara is especially interested in the laughing patterns of her friend, and wishes to graph it out to see what interesting shapes come out.

// Kiara wants you to generate the graph of a laugh that is 𝑁 pitches long. Each pitch will be given to you either as the character ^ (for up), v (for down), or > (for right).

// To generate the graph, imagine that you are working on a 2D grid of characters with infinite rows and 𝑁 columns. In the beginning, all characters in the grid are set to ., and your cursor is positioned in the first column. For every pitch given to you, perform the respective action:

// ^ pitch: replace the current character with /, and move the cursor one character to the right and one character up.
// v pitch: move the cursor one character down, replace the current character with \, and move the cursor one character to the right.
// > pitch: replace the current character with _, and move the cursor one character to the right.
// Although our hypothetical grid has infinite rows, for ease of comprehension, you should output only the rows which contain a character that is not . (i.e. print out all rows that contain one of /, \, or _).

// Constraints
// 1≤𝑁≤1000

// Input Specification
// The first line will contain a single integer 𝑁. The second line will contain a string of 𝑁 characters, each of which will be one of ^, v, or >.

// Output Specification
// Output the laugh graph, using the procedure described.

// Sample Input 1
// Copy
// 6
// vv>^^^
// Sample Output 1
// Copy
// ...../
// \.../.
// .\_/..
// Sample Input 2
// Copy
// 5
// vvvvv
// Sample Output 2
// Copy
// \....
// .\...
// ..\..
// ...\.
// ....\
// Explanation of Sample Output 2
// Note that only rows containing non-. characters should be included.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    vector <vector<char> > vec1;
    vector <char> tmp;
    for (int x = 0; x <= (2 * n); x++)
    {
        tmp.assign(n, '.');
        vec1.push_back(tmp);
    }
    int x = n;
    int y = 0;
    for (auto a : line)
    {
        if (a == '^')
        {
            vec1[x][y] = '/';
            x--;
            y++;
        }
        if (a == 'v')
        {
            x++;
            vec1[x][y] = '\\';
            y++;
        }
        if (a == '>')
        {
            vec1[x][y] = '_';
            y++;
        }
    }
    for (auto b : vec1)
    {
        if (b != tmp)
        {
            for (auto c : b)
            {
                cout << c;
            }
            cout << endl;
        }
    }
}


// AQT is studying fractions and he has encountered 𝑇 problems. In each problem, AQT is given a fraction with a numerator 𝐴 and a denominator 𝐵 (𝐴<𝐵). AQT wants to know after converting the fraction to a decimal and removing all terminating zeroes, how many digits there are to the right of the decimal. Can you help AQT answer all 𝑇 problems?

// Constraints
// In all subtasks,

// 1≤𝑇≤103

// 1≤𝐴<𝐵≤1018

// Subtask 1 [10%]
// 𝑇=1

// 1≤𝐴<𝐵≤5

// Subtask 2 [10%]
// 𝐵 is a multiple of 10

// Subtask 3 [30%]
// 1≤𝐴<𝐵≤109

// Subtask 4 [50%]
// No additional constraints.

// Input Specification
// The first line contains 𝑇, the number of problems you need to help AQT solve.

// The next 𝑇 lines contain 𝐴 and 𝐵, the numerator and the denominator of the fraction, respectively.

// Output Specification
// For each problem, output the answer to the problem if the answer is finite or −1, if the answer is infinite.

// Sample Input 1
// Copy
// 4
// 1 3
// 2 5
// 3 9
// 1 4
// Sample Output 1
// Copy
// -1
// 1
// -1
// 2
// Explanation for Sample 1
// For the first test case, 13=0.3⎯⎯⎯.

// For the second test case, 25=0.4.

// For the third test case, 39=0.3⎯⎯⎯.

// For the fourth test case, 14=0.25.

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int a;
    cin >> a;
    for (int x = 0; x < a; x++)
    {
        long long n, d;
        cin >> n >> d;
        long long b = __gcd(n, d);
        long long d1 = d / b;
        int s1 = 0;
        int s2 = 0;
        while (d1 % 2 == 0) 
        {
            d1 = d1 / 2;
            s1++;
        }
        while (d1 % 5 == 0) 
        {
            d1 = d1 / 5;
            s2++;
        }
        if (d1 != 1) cout << -1 << endl;
        else
        {
            if (s1 > s2) cout << s1 << endl;
            else cout << s2 << endl;
        }
    }
}


// In order to improve their physical fitness, the cows have taken up gymnastics! Farmer John designates his favorite cow Bessie to coach the 𝑁 other cows and to assess their progress as they learn various gymnastic skills.

// In each of 𝐾 practice sessions (1≤𝐾≤10), Bessie ranks the 𝑁 cows according to their performance (1≤𝑁≤20). Afterward, she is curious about the consistency in these rankings. A pair of two distinct cows is consistent if one cow did better than the other one in every practice session.

// Help Bessie compute the total number of consistent pairs.

// INPUT FORMAT:
// The first line of the input file contains two positive integers 𝐾 and 𝑁.

// The next 𝐾 lines will each contain the integers 1,…,𝑁 in some order, indicating the rankings of the cows (cows are identified by the numbers 1,…,𝑁). If 𝐴 appears before 𝐵 in one of these lines, that means cow 𝐴 did better than cow 𝐵.

// OUTPUT FORMAT:
// Output, on a single line, the number of consistent pairs.

// SAMPLE INPUT:
// Copy
// 3 4
// 4 1 2 3
// 4 1 3 2
// 4 2 1 3
// SAMPLE OUTPUT:
// Copy
// 4
// Explanation
// The consistent pairs of cows are (1,4), (2,4), (3,4), and (1,3).
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi(word));
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int k, n;
    cin >> k >> n;
    cin.ignore();
    vector <vector<int> > vec2;
    vector <int> vec1;
    for (int x = 0; x < k; x++)
    {
        string line;
        getline(cin, line);
        vec1 = split(line);
        vec2.push_back(vec1);
    }
    int s1 = 0;
    int s2;
    for (int a = 0; a < n - 1; a++)
    {
        for (int b = a + 1; b < n; b++)
        {
            int cow_1 = vec2[0][a];
            int cow_2 = vec2[0][b];
            s2 = 0;
            for (int c = 1; c < k; c++)
            {
                int index_cow_1 = find(vec2[c].begin(), vec2[c].end(), cow_1) - vec2[c].begin();
                int index_cow_2 = find(vec2[c].begin(), vec2[c].end(), cow_2) - vec2[c].begin();
                if (index_cow_1 < index_cow_2) s2++;
            }
            if (s2 == k-1) s1++;
        }
    }
    cout << s1 << endl;
}


// Farmer John has gone out for a walk down the road and thinks he may now be lost!

// Along the road there are 𝑁 farms (1≤𝑁≤100) in a row. Farms unfortunately do not have house numbers, making it hard for Farmer John to figure out his location along the road. However, each farm does have a colorful mailbox along the side of the road, so Farmer John hopes that if he looks at the colors of the mailboxes nearest to him, he can uniquely determine where he is.

// Each mailbox color is specified by a letter in the range 𝐴,…,𝑍, so the sequence of 𝑁 mailboxes down the road can be represented by a string of length 𝑁 containing letters in the range 𝐴,…,𝑍. Some mailboxes may have the same colors as other mailboxes. Farmer John wants to know what is the smallest value of 𝐾 such that if he looks at any sequence of 𝐾 consecutive mailboxes, he can uniquely determine the location of that sequence along the road.

// For example, suppose the sequence of mailboxes along the road is ABCDABC. Farmer John cannot set 𝐾=3, since if he sees ABC, there are two possible locations along the road where this consecutive set of colors might be. The smallest value of 𝐾 that works is 𝐾=4, since if he looks at any consecutive set of 4 mailboxes, this sequence of colors uniquely determines his position along the road.

// INPUT FORMAT:
// The first line of input contains 𝑁, and the second line contains a string of 𝑁 characters, each in the range 𝐴,…,𝑍.

// OUTPUT FORMAT:
// Print a line containing a single integer, specifying the smallest value of 𝐾 that solves Farmer John's problem.

// SAMPLE INPUT:
// Copy
// 7
// ABCDABC
// SAMPLE OUTPUT:
// Copy
// 4
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    string line;
    getline(cin, line);
    int s = 0;
    int test = 0;
    for (int k = 1; k <= n; k++)
    {
        bool repeated = false;
        for (int x = 0; x < n - k + 1; x++)
        {
            if (line.find(line.substr(x, k), x + 1) == -1)
            {
                s++;
            }
            else
            {
                repeated = true;
                break;
            }
        }
        if (!repeated) 
        {
            cout << k << endl;
            break;
        }
    }
}

// Canadian Computing Competition: 2014 Stage 1, Senior #3
// In order to ensure peace and prosperity for future generations, the United Nations is creating the world's largest candy. The ingredients must be taken in railway cars from the top of a mountain and poured into Lake Geneva. The railway system goes steeply from the mountaintop down to the lake, with a T-shaped branch in the middle as shown below.


// Right now, each of the 𝑁 ingredients is in its own railway car. Each railway car is assigned a positive integer from 1 to 𝑁. The ingredients must be poured into the lake in the order 1,2,3,…,𝑁 but the railway cars are lined up in some random order. The difficulty is that, because of the especially heavy gravity today, you can only move cars downhill to the lake, or sideways on the branch line. Is it still possible to pour the ingredients into the lake in the order 1,2,3,…,𝑁 ?

// For example, if the cars were in the order 2, 3, 1, 4, we can slide these into the lake in order as described below:


// Slide car 4 out to the branch
// Slide car 1 into the lake
// Slide car 3 out to the branch
// Slide car 2 into the lake
// Slide car 3 from the branch into the lake
// Slide car 4 from the branch into the lake
// Input Specification
// The first line will contain the number 𝑇 (1≤𝑇≤10) which is the number of different tests that will be run. Each test has the form of an integer 𝑁 (1≤𝑁≤100000) on the first line of the test, followed by a list of the 𝑁 cars listed from top to bottom. The cars will always use the numbers from 1 to 𝑁 in some order.

// Output Specification
// For each test, output one line which will contain either Y (for "yum") if the recipe can be completed, and N otherwise.

// Sample Input
// Copy
// 2
// 4
// 2
// 3
// 1
// 4
// 4
// 4
// 1
// 3
// 2
// Output for Sample Input
// Copy
// Y
// N
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        int k;
        cin >> k;
        stack <int> s1;
        stack <int> s2;
        for (int a = 0; a < k; a++)
        {
            int b;
            cin >> b;
            s1.push(b);
        }
        int current = 1;
        while (!s1.empty())
        {
            if (s2.size() >= 1 && s2.top() == current)
            {
                current++;
                s2.pop();
            }
            else if (s1.top() == current)
            {
                current++;
                s1.pop();
            }
            else
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        while(!s2.empty())
        {
            if (s2.top() == current)
            {
                current++;
                s2.pop();
            }
            else
            {
                cout << "N" << endl;
                break;
            }
        }
        if (s2.empty())
        {
            cout << "Y" << endl;
        }
    }
}


// Canadian Computing Competition: 2004 Stage 1, Junior #3
// A simile is a combination of an adjective and noun that produces a phrase such as "Easy as pie" or "Cold as ice".

// Write a program to input 𝑛 adjectives (1≤𝑛≤5) and 𝑚 nouns (1≤𝑚≤5), and print out all possible similes. The first two lines of input will provide the values of 𝑛 and 𝑚, in that order followed, one per line, by 𝑛 adjectives and 𝑚 nouns.

// Your program may output the similes in any order.

// Sample Input
// Copy
// 3
// 2
// Easy
// Smart
// Soft
// pie
// rock
// Sample Output
// Copy
// Easy as pie
// Easy as rock
// Smart as pie
// Smart as rock
// Soft as pie
// Soft as rock
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int x, y;
    cin >> x;
    cin >> y;
    cin.ignore();
    vector <string> vec1;
    vector <string> vec2;
    for (int a = 0; a < x; a++)
    {
        string line;
        getline(cin, line);
        vec1.emplace_back(line);
    }
    for (int b = 0; b < y; b++)
        {
            string line;
            getline(cin, line);
            vec2.emplace_back(line);
        }
    for (auto c : vec1)
        {
            for (auto d : vec2)
            {
                cout << c << " as " << d << endl;
            }
        }
}



// One day Derren decided he would do something remarkable with his life. Since Derren is very ambitious, he has decided he wants to memorize his own DNA genome sequence. The only problem is that the human genome is too long to be memorized letter-by-letter.

// In order to help him, you offered to write a program to divide his genome into the least number of words. He tells you that each of these words must be distinctly pronounceable. For a word to be considered distinctly pronounceable, the word must either be one letter in length or each pair of two adjacent letters in a word must contain a vowel and a consonant.

// Can you write a program to help Derren memorize his DNA genome?

// Input Specification
// A single line, the DNA sequence that Derren wants to memorize. The length of the line will contain at least 1 character and will not exceed 105 characters in length. The line will only consist of the characters A, C, T and G.

// For 70% of the points, the length of the line will not exceed 100 characters in length.

// Output Specification
// A single line, the input line with spaces inserted in the best positions to help Derren memorize his DNA Sequence.

// Sample Input 1
// Copy
// ACTGAGCA
// Sample Output 1
// Copy
// AC T GAG CA
// Sample Explanation 1
// AC is a two letter word containing a vowel and a consonant.

// T is a one letter word. It is separated because the pair CT and TG both would lack a vowel.

// GAG is one word because the GA and AG pairs both contain a vowel.

// There is a space between GAG and CA since the GC pair lacks a vowel.

// CA is a two letter word containing a vowel and a consonant.

// Sample Input 2
// Copy
// AAAAGCGCTA
// Sample Output 2
// Copy
// A A A AG C G C TA
#include <iostream>

using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    getline(cin, line);
    string str1;
    for (int i = 0; i < line.length(); i++)
    {
        if ((line[i] == 'A' && line[i + 1] != 'A') || (line[i] != 'A' && line[i + 1] == 'A'))
        {
            str1 += line[i];
        }
        else
        {
            str1 += line[i];
            str1 += " ";
        }
    }
    cout << str1 << endl;
}



// Canadian Computing Competition: 2004 Stage 1, Junior #4
// One of the simplest ways of coding a message is to do a letter shift.

// For example, if you shift the letters in the original message by 5 then A in your original message becomes F in the coded message. (B → G, C → H, …, T → Y, U → Z, V → A, …, Z → E). To decode the message, you simply need to shift back by the same number.

// A slightly trickier encryption uses a keyword to determine the amount of the shift. Suppose you were using a keyword ACT. To encode the message, you take the original message, remove everything but the alphabetic characters, and form the message into a block that has the same width as the keyword. Here is a sample message to encrypt:

// BANANA & PEEL

// The blocked version of the message is shown below with the keyword ACT as a header.

// A	C	T
 		
// B	A	N
// A	N	A
// P	E	E
// L		
// Now, the message is encoded using a letter shift. However, this time it is not a uniform shift, it will depend upon the keyword letter at the top of the column. If the letter at the top of the column is an A, then the letters in that column are not shifted. If the letter is a B, then the letter in that column shift by 1, and so on. In the example, the letters in the third column will shift by 19 since the T is the 20th letter of the alphabet.

// The encoded message is:

// A	C	T
 		
// B	C	G
// A	P	T
// P	G	X
// L		
// You will write a program that will accept a keyword and a string to be encoded. The keyword will never have more than 6 characters. The message will always be given in all upper case characters.

// Input Specification
// The first line of input consists of the keyword. The second line of the input is the message to be encoded. The keyword length will never exceed 6 characters. The total message length also will never exceed 60 characters.

// Output Specification
// Output the encoded message on a single line.

// Sample Input 1
// Copy
// ACT
// BANANA & PEEL
// Sample Output 1
// Copy
// BCGAPTPGXL
// Sample Input 2
// Copy
// TRICKY
// I LOVE PROGRAMMING!
// Sample Output 2
// Copy
// BCWXONKFOTKKFZVI

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    unordered_map <char, int> map1 = {{'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'J', 9}, {'K', 10},
    {'L', 11}, {'M', 12}, {'N', 13}, {'O', 14}, {'P', 15}, {'Q', 16}, {'R', 17}, {'S', 18}, {'T', 19}, {'U', 20}, {'V', 21}, {'W', 22}, {'X', 23},
    {'Y', 24}, {'Z', 25}};
    string key, line;
    getline(cin, key);
    getline(cin, line);
    string str1;
    for (int x = 0; x < line.length(); x++)
    {
        if (isalpha(line[x]))
        {
            str1 += line[x];
        }
    }
    int ind;
    for (int a = 0; a < key.length(); a++)
    {
        ind = a;
        while (ind < str1.length())
        {
            if (int(str1[ind]) + map1[key[a]] <= 90)
            {
                str1[ind] = char(int(str1[ind]) + map1[key[a]]);
            }
            else
            {
                str1[ind] = char(64 + (map1[key[a]] - (90 - int(str1[ind]))));
            }
            ind += key.length();
        }
    }
    cout << str1 << endl;
}


// As a 30 WPM typer, you are sitting in a computer lab playing a modified version of TypeRacer in hopes of increasing your typing speed. In this game, your goal is to transform a given string of lowercase characters 𝑆 into a new string of lowercase characters 𝑇. 𝑆 is the string you start with on your screen. In one keystroke, you can delete a character from the back of the current string on your screen, or you can add a new lowercase character to the back of the current string. Since you strive to be as fast as possible, please compute the minimum number of keystrokes needed to transform 𝑆 into 𝑇.

// Constraints
// 1≤|𝑆|,|𝑇|≤106, where |𝐴| denotes the number of characters in 𝐴.

// 𝑆 and 𝑇 only contain lowercase characters.

// Input Specification
// The first line contains the string 𝑆.

// The second line contains the string 𝑇.

// Output Specification
// Output one integer, the minimum number of keystrokes needed to transform 𝑆 into 𝑇.

// Sample Input 1
// Copy
// adachi
// shimamura
// Sample Output 1
// Copy
// 15
// Sample Input 2
// Copy
// shinomiya
// shirogane
// Sample Output 2
// Copy
// 12

#include <iostream>
using namespace std;

int main() 
{
    string str1, str2;
    long long int n;
	cin.tie();
	cin >> str1;
	cin >> str2;
	n = str1.length();
	if (str1 == str2){
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
		{
			n = i;
			break;
		}
	}
	if (str1.length() < str2.length())
	{
		cout << (str1.length() - n) + (str2.length() - n) << endl;
	}

	else
	{
		cout << (str1.length() - n) + (str2.length() - n) << endl;
	}
	return 0;
}



// You are learning how to count in math class today! To demonstrate this invaluable ability, your teacher wrote the first 𝑁 positive integers on the chalkboard. However, when he went for a quick bathroom break, Jennifer the delinquent took the chance to erase 2 of the numbers on the board! When your teacher returned, he summed up all the remaining numbers on the board and called it 𝑆. Naturally, since your teacher is a genius, he did not mess up his calculations when summing up the numbers and 𝑆 is computationally correct. However, 𝑆 wasn't exactly the number he expected to get! As the teacher's pet an exemplary student, please help your teacher find the number of possible unordered pairs of numbers Jennifer erased. To ensure the integrity of your solution, there may be up to 𝑇 test cases.

// Constraints
// 1≤𝑇≤100

// 2≤𝑁≤109

// 0≤𝑆≤1018

// Subtask 1 [10%]
// 2≤𝑁≤103

// Subtask 2 [20%]
// 2≤𝑁≤105

// Subtask 3 [70%]
// No additional constraints.

// Input Specification
// The first line contains an integer 𝑇, the number of test cases. The next 𝑇 lines describe the test cases.

// The first and only line of each test case contains 2 integers 𝑁 and 𝑆, as specified in the problem statement.

// Output Specification
// For each test case output one integer on its own line, the number of possible unordered pairs of numbers Jennifer erased.

// Sample Input
// Copy
// 2
// 5 9
// 2 0
// Sample Output
// Copy
// 2
// 1
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



// Canadian Computing Competition: 2004 Stage 1, Senior #1
// A collection of words is prefix-free if no word is a prefix of any other word. A collection of words is suffix-free if no word is a suffix of any other word. A collection of words is fix-free if it is both prefix-free and suffix-free.

// For this problem, a word is a sequence of lower-case letters of length between 1 and 25. A word 𝑋 is a prefix of word 𝑌 if 𝑋 consists of the first 𝑛 characters of 𝑌, in order, for some 𝑛. That is, the word cat has prefixes c, ca, and cat. Similarly, a word 𝑋 is a suffix of 𝑌 if 𝑋 consists of the last 𝑛 characters of 𝑌, in order, for some 𝑛.

// Your input will be 3𝑁+1 lines: the first line will be the number 𝑁, and the remaining 3𝑁 lines will be the 𝑁 collections of 3 words each. (That is, lines 2, 3, and 4 compose the first collection, lines 5, 6, and 7 compose the second collection, and so on). Your output will be 𝑁 lines, each line containing either Yes (if that collection of words is fix-free) or No (if that collection is not fix-free).

// Sample Input
// Copy
// 2
// abba
// aab
// bab
// a
// ab
// aa
// Sample Output
// Copy
// Yes
// No
#include <iostream>
#include <string>
using namespace std;
int check_fix(string str1, string str2)
{
    if (str2.length() < str1.length())
    {
        if (str1.substr(0, str2.length()) == str2 || str1.substr(str1.length() - str2.length()) == str2)
        {
            return 1;
        }
    }
    if (str1.length() < str2.length())
    {
        if (str2.substr(0, str1.length()) == str1 || str2.substr(str2.length() - str1.length()) == str1)
        {
            return 1;
        }
    }
    if (str1 == str2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    for (int x = 0; x < n; x++)
    {
        string str1, str2, str3;
        getline(cin, str1);
        getline(cin, str2);
        getline(cin, str3);
        if (check_fix(str1, str2) == 1) cout << "No" << endl;
        else if (check_fix(str1, str3) == 1) cout << "No" << endl;
        else if (check_fix(str2, str1) == 1) cout << "No" << endl;
        else if (check_fix(str2, str3) == 1) cout << "No" << endl;
        else if (check_fix(str3, str1) == 1) cout << "No" << endl;
        else if (check_fix(str3, str2) == 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}


// Canadian Computing Competition: 2003 Stage 1, Junior #4, Senior #2
// A simple poem consists of one or more four-line verses. Each line consists of one or more words consisting of upper or lower case letters, or a combination of both upper and lower case letters. Adjacent words on a line are separated by a single space.

// We define the last syllable of a word to be the sequence of letters from the last vowel (a, e, i, o or u, but not y) to the end of the word. If a word has no vowel, then the last syllable is the word itself. We say that two lines rhyme if their last syllables are the same, ignoring case.

// You are to classify the form of rhyme in each verse. The form of rhyme can be perfect, even, cross, shell, or free:

// perfect rhyme: the four lines in the verse all rhyme
// even rhyme: the first two lines rhyme and the last two lines rhyme
// cross rhyme: the first and third lines rhyme, as do the second and fourth
// shell rhyme: the first and fourth lines rhyme, as do the second and third
// free rhyme: any form that is not perfect, even, cross, or shell.
// The first line of the input file contains an integer 𝑁, the number of verses in the poem, 1≤𝑁≤5. The following 4𝑁 lines of the input file contain the lines of the poem. Each line contains at most 80 letters of the alphabet and spaces as described above.

// The output should have 𝑁 lines. For each verse of the poem there should be a single line containing one of the words perfect, even, cross, shell or free describing the form of rhyme in that verse.

// Sample Input 1
// Copy
// 1
// One plus one is small
// one hundred plus one is not
// you might be very tall
// but summer is not
// Output for Sample Input 1
// Copy
// cross
// Sample Input 2
// Copy
// 2
// I say to you boo
// You say boohoo
// I cry too
// It is too much foo
// Your teacher has to mark
// and mark and mark and teach
// To do well on this contest you have to reach
// for everything with a lark
// Output for Sample Input 2
// Copy
// perfect
// shell
// Sample Input 3
// Copy
// 2
// It seems though
// that without some dough
// creating such a bash
// is a weighty in terms of cash
// But how I see
// the problem so fair
// is to write subtle verse
// with hardly a rhyme
// Output for Sample Input 3
// Copy
// even
// free
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    for (int x = 0; x < n; x++)
    {
        vector <string> vec1 = {};
        for (int a = 0; a < 4; a++)
        {
            string line;
            getline(cin, line);
            string str1;
            int ind = line.length() - 1;
            while (line[ind] != 'a' && line[ind] != 'e' && line[ind] != 'i' && line[ind] != 'o' && line[ind] != 'u' && 
            line[ind] != 'A' && line[ind] != 'E' && line[ind] != 'I' && line[ind] != 'O' && line[ind] != 'U' && line[ind] != ' ')
            {
                str1 += tolower(line[ind]);
                ind--;
            }
            if (line[ind] != ' ') str1 += tolower(line[ind]);
            vec1.emplace_back(str1);
        }
        if (vec1[0] == vec1[1] &&  vec1[1] == vec1[2] && vec1[2] == vec1[3]) cout << "perfect" << endl;
        else if (vec1[0] == vec1[1] && vec1[2] == vec1[3]) cout << "even" << endl;
        else if (vec1[0] == vec1[2] && vec1[1] == vec1[3]) cout << "cross" << endl;
        else if (vec1[0] == vec1[3] && vec1[1] == vec1[2]) cout << "shell" << endl;
        else cout << "free" << endl;
    }
}


// DWITE Online Computer Programming Contest, December 2007, Problem 2
// There's an issue of plagiarism in every academic course, but it seems to be more common in Computer Science classes, possibly because it's not as apparent to spot as, for example, in an English essay. Though a typical program still contains enough English text in string literals and comments, to be an equivalent of a small essay. The task is to extract just such text from a block of code.

// The input will contain five lines of input. Valid ASCII text. String literals will be in either " or ' quotes. Comments will be C++ style: /* inline */ and // end of line. There will be no nested /* */ comments.

// The output will contain five lines, aggregating the text found on the matching lines of the input. The text is defined as any string literal and any comment. Blocks of text found in a line, should be joined together by spaces.

// Note: No nested /* */ comments means there will not be a line of input similar to /* /* */ */. Comments found inside a string are deemed to be a part of the string. Strings found inside a comment will be deemed to be a part of the comment. One type of a string literal can contain another. See sample input for clarifications.

// Sample Input
// Copy
// function my_badly_named_function(); //this is a comment
// puts "some string content" //and comments
// go_go("gadget" /* notice extra spaces */); //"for inline comment"
// "nested 'strings'"
// /*just some //comments*/
// Sample Output
// Copy
// this is a comment
// some string content and comments
// gadget  notice extra spaces  "for inline comment"
// nested 'strings'
// just some //comments
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    for(int x = 0; x < 5; x++)
    {
        string line;
        getline(cin, line);
        vector <string> vec1;
        int end;
        int tp = 0;
        string str1;
        for (int a = 0; a < line.length(); a++)
        {
            if(a < tp) continue;
            if (line[a]=='\"') 
            {
                end = line.find('\"', a + 1);
                str1 = line.substr(a + 1, end - a - 1);
                vec1.emplace_back(str1);
                tp = end + 1;
                continue;
            } 
            if (line[a]=='\'') 
            {
                end = line.find('\'', a + 1);
                str1 = line.substr(a + 1, end - a - 1);
                vec1.emplace_back(str1);
                tp = end + 1;
                continue;
            } 
            if (line[a]=='/') 
            {
                if (a + 1 < line.size() && line[a + 1] == '*')
                {
                    end = line.find("*/", a + 2);
                    str1 = line.substr(a + 2, end - a - 2);
                    vec1.emplace_back(str1);
                    tp = end + 2;
                    continue;
                }
                if (a + 1 < line.size() && line[a + 1]=='/')
                {
                    str1 = line.substr(a + 2);
                    vec1.emplace_back(str1);
                    break;
                }
    
            }        
            
        }
        string str2 = vec1[0];
        for (int i=1; i<vec1.size(); i++)
        {
            str2 = str2 + " " + vec1[i];
        }
        cout << str2 << endl;         
    }
}

// Flip the Switches
//  View as PDF
// Submit solution
// My submissions
// All submissions
// Best submissions
// Points:5
// Time limit:1.0s
// Memory limit:64M
// Author:
// 4fecta
// Problem type
// Megumin is trying to deactivate a security system! The security system is composed of 𝑁 different switches, and 
//is only fully deactivated when all of the switches are off. Let's define flipping a switch as changing it from on to off, or vice versa. Megumin has thought of the ingenious idea of exploding the whole thing flipping the switches with her staff to avoid detection! However, given her position, she can only use her staff to flip a prefix of the switches (switches 1 to 𝑘, 1≤𝑘≤𝑁) in one click. Can you help her figure out the minimum number of clicks needed to fully deactivate the system without using explosion?

// Input Specification
// The first line will contain an integer 𝑁 (1≤𝑁≤106).

// The next line will contain a string of 𝑁 characters 0 and 1, representing the states of the switches from 1 to 𝑁 (0 is off, 1 is on).

// Output Specification
// Output the minimum number of clicks required to fully deactivate the system.

// Sample Input
// Copy
// 4
// 1001
// Sample Output
// Copy
// 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
  cin.sync_with_stdio (0);
  cin.tie (0);
  int n;
  cin >> n;
  cin.ignore();
  string line;
  getline(cin, line);
  int ind = 1;
  int s = 0;
  while (ind != line.size())
  {
      if (line[ind] != line[ind - 1])
      {
          s++;
      }
      ind++;
  }
  if (line.back() == '1')
  {
      cout << s + 1;
  }
  else
  {
      cout << s;
  }
  return 0;
}

// There's a crisis in Hawaii! The great volcano "Mauna Loa" is about to erupt! The Mauna Loa is located in the middle of the largest island in Hawaii, with almost 200000 people living nearby.

// As a responsible dictator, Joey quickly pulled out a map containing the locations of all 𝑁 houses on the island. He came up with 𝑄 different scenarios on how the volcano might explode. Each scenario will describe the range of the volcano. Any house within the range of the volcano will be instantly destroyed. Please find how many houses will be destroyed in each of the scenarios.

// Input Specification
// The first line will contain 𝑁,𝑄, denoting the number of houses and the number of scenarios respectively.

// The next 𝑁 lines will contain 2 integers 𝑥,𝑦 denoting the position of the house relative to the volcano measured in meters.

// The next 𝑄 lines will contain a single integer 𝑟, denoting a scenario where all houses within 𝑟 meters of the volcano will get destroyed.

// Output Specification
// For each scenario, print a single integer on a line, denoting the number of houses that will be destroyed in that scenario.

// Constraints
// 𝑁≤186738

// 𝑄≤200000

// −1000000≤𝑥,𝑦≤1000000

// 0≤𝑟≤1414214

// At least 50% of the testcases will have 𝑁,𝑄≤1000.

// Sample Input 1
// Copy
// 4 3
// 2 2
// -4 0
// 0 -5
// -5 -5
// 2
// 4
// 6
// Sample Output 1
// Copy
// 0
// 2
// 3
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <stdio.h>

using namespace std;
template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi (word));
    }
  return vv;
}



int main()
{

  string line;
  getline(cin, line);
  vector <int> vec1 = split(line);
  int n = vec1[0];
  int q = vec1[1];
  vector <double> pos;
  for (int a = 0; a < n; a++)
  {
      getline(cin, line);
      vec1 = split(line);
      pos.push_back(sqrt(pow(vec1[0], 2) + pow(vec1[1], 2)));
  }
  sort(pos.begin(), pos.end());
  //print(pos);
  

  int arr[q];
  for(int i = 0; i < q; i++) scanf("%d", &arr[i]);
  
  for (int b = 0; b < q; b++)
  {
      int count = upper_bound (pos.begin(), pos.end(), double(arr[b])) - pos.begin();
      cout << count << "\n";
  }
  return 0;
}

// Having finished her homework, Molly decides to write the DMOPC. 
// However, as a kitten, she can't actually code, and decides to asks you to compete on her behalf. As you (probably) know, the DMOPC is systested, usually with batches. 
// Failing any test case in a batch results in a score of 0 for that batch.
// Being the great hacker programmer that you are, you know precisely which cases belong to which batch, and how your program will do on the cases. All that remains is to see how many points you can get…

// Input Specification
// Line 1: An integer, 𝐵, the number of batched cases that follow.
// Line 2…𝐵+1: 3 space separated integers, 𝑓𝑖, 𝑒𝑖, and 𝑝𝑖, indicating that the 𝑖𝑡ℎ batch starts on test case 𝑓𝑖, ends on case 𝑒𝑖, and is worth 𝑝𝑖 points.
// Line 𝐵+2: An integer, 𝐹, the number of test cases the program fails.
// Lines 𝐵+3…𝐵+𝐹+2: An integer, 𝑡𝑖, indicating the program fails the 𝑡𝑡ℎ𝑖 test case.

// Output Specification
// A single integer, the number of points the program can get.

// Constraints
// For all cases, 𝑝𝑖 (0≤𝑝𝑖≤104).

// Subtask	Points	𝐵	𝑓𝑖,𝑒𝑖	𝐹	𝑡𝑖
// 1	5	1≤𝐵≤103	1≤𝑓𝑖≤𝑒𝑖≤103	𝐹=0	DNE
// 2	5	1≤𝐵≤103	1≤𝑓𝑖≤𝑒𝑖≤103	1≤𝐹≤103	1≤𝑡𝑖≤103
// 3	30	1≤𝐵≤105	1≤𝑓𝑖≤𝑒𝑖≤105	1≤𝐹≤103	1≤𝑡𝑖≤105
// 4	60	1≤𝐵≤105	1≤𝑓𝑖≤𝑒𝑖≤109	1≤𝐹≤105	1≤𝑡𝑖≤109
// Sample Input
// Copy
// 3
// 1 5 100
// 20 21 10
// 1 18 1
// 2
// 2
// 5
// Sample Output
// Copy
// 10
// Explanation for Sample Output
// By failing test cases 2 and 5, the program fails batches 1 and 3, and only passes batch 2, giving it a total of 10 points.
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;


int main()
{
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1], arr2[n1], arr3[n1];
    int s = 0;
    for (int k = 0; k < n1; k++) {
        scanf("%d %d %d", &arr1[k], &arr2[k], &arr3[k]);
    }

    scanf("%d", &n2);
    int arr[n2];
    for(int i = 0; i < n2; i++) scanf("%d", &arr[i]);
    vector<int> vect_q(arr, arr+n2);
    sort(vect_q.begin(), vect_q.end());
    
    for (int m=0; m<n1; m++)
    {
        if (upper_bound (vect_q.begin(), vect_q.end(), arr2[m]) - 
        lower_bound (vect_q.begin(), vect_q.end(), arr1[m]) ==0)
        {
            s += arr3[m];
        }
        
    }

    printf("%d", s);
    return 0;
}

// Saki is walking around the school fields when she notices that something might be stalking her. 
// As such, she stops at 𝑄 locations on the field, with the 𝑖th being (𝑥𝑖,𝑦𝑖) and takes a look directly 
// in all 4 cardinal directions (north, south, east, and west) to see if she can locate these mysterious beings. 
// Saki's vision is quite good, so even if the being is far away, as long as she's looking in the right 
// direction, she is able to see it. (The top left corner is (1,1) and the bottom right corner is (𝐶,𝑅).) 
// Can you help Saki figure out if she's being stalked?

// Constraints
// For all subtasks:

// 1≤𝑥𝑖≤𝐶

// 1≤𝑦𝑖≤𝑅

// Subtask 1 [20%]
// 1≤𝑅,𝐶≤1000

// 1≤𝑄≤1000

// Subtask 2 [80%]
// 1≤𝑅,𝐶≤1000

// 1≤𝑄≤106

// Input Specification
// The first line will contain 2 space-separated integers, 𝑅 and 𝐶, the number of rows and columns her school field has.
// The next 𝑅 lines will each have 𝐶 characters, with a X representing a mysterious being, and an . representing flat land.
// The next line will have an integer, 𝑄.
// The next 𝑄 lines will have two integers, 𝑥𝑖 and 𝑦𝑖, her position on the field for the 𝑖th location.

// Output Specification
// The output should have 𝑄 lines, either Y if she can see one of the mysterious beings, or N otherwise.

// Note that fast input/output may be necessary.

// Sample Input
// Copy
// 4 4
// X...
// ....
// ....
// ..X.
// 3
// 2 3
// 4 4
// 1 1
// Sample Output
// Copy
// N
// Y
// Y
// Explanation for Sample Output
// Let S denote Saki's position. The first query looks like this:

// Copy
// X...
// ....
// .S..
// ..X.
// For the second query, the grid looks like the following:

// Copy
// X...
// ....
// ....
// ..XS
// For the third query, the grid looks like this:

// Copy
// S...
// ....
// ....
// ..X.
// Note that even though Saki is on the same square as a mysterious being, she can still see it.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T > void
print (T t)
{
for (const auto & e:t)
    cout << e << " ";
  cout << endl;
}

vector < int >
split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi (word));
    }
  return vv;
}

int
main ()
{
  cin.sync_with_stdio (0);
  cin.tie (0);
  string line;
  getline (cin, line);
  vector < int >rc;
  rc = split(line);
  int num_rows = rc[0];
  vector < int >v_x;
  vector < int >v_y;
  for (int n = 0; n < num_rows; n++)
    {
      getline (cin, line);
      int found = line.find ("X");

      if (found != std::string::npos)
	{
	  v_x.push_back(n + 1);
	  int cnt = 0;
	  for(char& c : line) {
            if (c=='X') v_y.push_back(cnt+1);
            cnt++;
            }
	}
    }
  int q;
  cin >> q;
  cin.ignore();
  for (int m = 0; m < q; m++)
    {
      getline(cin, line);
      rc = split(line);
      int x1 = rc[1];
      int y1 = rc[0];
      if ((find(v_x.begin(), v_x.end(), x1) != v_x.end()) |
	  (find(v_y.begin(), v_y.end(), y1) != v_y.end())) cout << "Y\n";
      else cout << "N\n";
    }
  return 0;
}



// CCC 01 J2 - Mod Inverse
// Canadian Computing Competition: 2001 Stage 1, Junior #2
// In many cryptographic applications the Modular Inverse is a key point. This question involves finding the modular
// inverse of a number.
// Given , where and are integers, the modular inverse of is the unique integer , , such
// that the remainder upon dividing by is .
// For example, , so the remainder when is divided by is , and thus is the inverse of
//  modulo .
// You are to write a program which accepts as input the two integers and , and outputs either the modular inverse ,
// or the statement No such integer exists. if there is no such integer .
// Constraints
// Sample Input 1
// 4
// 17
// Sample Output 1
// 13
// Sample Input 2
// 6
// 10
// Sample Output 2
// Time Limit: 2.0s Memory Limit: 64M
// 0 < x < m x m x n 0 < n < m
// x × n m 1
// 4 × 13 = 52 = 17 × 3 + 1 52 17 1 13
// 4 17
// x m n
// n
// m ≤ 100
// Page 2 of 2
// No such integer exists.
#include <iostream>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int x, m;
    cin >> x;
    cin >> m;
    int exists = 0;
    for (int s = 2; s < m; s++)
    {
        if ((x * s) % m == 1)
        {
            cout << s << endl;
            exists = 1;
            break;
        }
    }
    if (exists == 0)
    {
        cout << "No such integer exists." << endl;
    }
}


// Canadian Computing Competition: 2002 Stage 1, Junior #2
// Americans spell differently from Canadians. Americans write neighbor and color while Canadians write neighbour and colour. Write a program to help Americans translate to Canadian.

// Your program should interact with the user in the following way. The user should type a word (not to exceed 64 letters) and if the word appears to use American spelling, the program should echo the Canadian spelling for the same word. If the word does not appear to use American spelling, it should be output without change. When the user types quit! the program should terminate.

// The rules for detecting American spelling are quite naive: If the word has more than four letters and has a suffix consisting of a consonant followed by or, you may assume it is an American spelling, and that the equivalent Canadian spelling replaces the or by our. Note : you should treat the letter y as a vowel.

// Sample Input
// Copy
// color
// for
// taylor
// quit!
// Sample Output
// Copy
// colour
// for
// taylour
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string a;
    getline(cin, a);
    int b;
    while (a != "quit!")
    {
        if (a.length() > 4)
        {
            b = a.find("or");
            if (b == a.length() - 2)
            {
                if (a[b - 1] != 'a' && a[b - 1] != 'e' && a[b - 1] != 'i' && a[b - 1] != 'o' && a[b - 1] != 'u' && a[b - 1] != 'y')
                {
                    a.replace(a.find("or"), 3, "our");
                }
            }
        }
        cout << a << endl;
        getline(cin, a);
    }
}

// Canadian Computing Competition: 2007 Stage 1, Junior #4
// An anagram is a word or a phrase formed by rearranging the letters of another phrase such as ITEM and TIME. Anagrams may be several words long such as CS AT WATERLOO and COOL AS WET ART. Note that two phrases may be anagrams of each other even if each phrase has a different number of words (as in the previous example). Write a program to determine if two phrases are anagrams of each other.

// Input Specification
// The program should take two phrases, each on a separate line. You may assume that the input only contains upper case letters and spaces.

// Output Specification
// The program will print out one of two statements: Is an anagram. or Is not an anagram.

// Sample Input
// CS AT WATERLOO
// COOL AS WET ART
// Sample Output
// Is an anagram.
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    str1.erase(remove(str1.begin(), str1.end(), ' '), str1.end());
    str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());
    if (str1 == str2)
    {
        cout << "Is an anagram." << endl;
    }
    else
    {
        cout << "Is not an anagram." << endl;
    }
}

// Canadian Computing Competition: 2016 Stage 1, Senior #1
// An anagram of a string is formed by rearranging the letters in the string. For example, the anagrams of aab are aab, aba, and baa.

// A wildcard anagram of a string is an anagram of the string where some of the letters might have been replaced with an asterisk (*). For example, two possible wildcard anagrams of aab are *ab and *b*.

// Given two strings, determine whether the second string is a wildcard anagram of the first string.

// Input Specification
// The two lines of input will both consist of 𝑁 (1≤𝑁≤100) characters. Each character in the first line will be a lowercase letter. Each character in the second line will be either a lowercase letter or an asterisk.

// For 8 of the 15 available marks, the second line will not contain any asterisk characters.

// Output Specification
// Output the character A if the string on the second line is a wildcard anagram of the string on the first line. Otherwise, output the character N.

// Sample Input 1
// Copy
// abba
// baaa
// Output for Sample Input 1
// Copy
// N
// Sample Input 2
// Copy
// cccrocks
// socc*rk*
// Output for Sample Input 2
// Copy
// A
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int num;
    int length_b = b.length();
    if (a.length() != length_b)
    {
        cout << "N" << endl;
        return 0;
    }
    unordered_map <char, int> map1, map2;
    for (int x = 0; x < a.length(); x++)
    {
        if (map1.find(a[x]) == map1.end())
        {
            map1[a[x]] = 0;
        }
        map1[a[x]]++;
        if (map2.find(b[x]) == map2.end())
            {
                map2[b[x]] = 0;
            }
        map2[b[x]]++;
    }
    int difference = 0;
    for (auto a : map1)
    {
        if (map2.find(a.first) == map2.end())
        {
            difference += a.second;
        }
        else
        {
            difference += abs(a.second - map2[a.first]);
        }
    }
    if (map2.find('*') == map2.end())
    {
        if (difference == 0)
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
    else
    {
        if (difference == map2['*'])
        {
            cout << "A" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}

// Canadian Computing Competition: 2006 Stage 1, Senior #2
// Ruby is a code-breaker. She knows that the very bad people (Mr. X and Mr. Z) are sending secret messages about very bad things to each other.

// However, Ruby has managed to intercept a plaintext message and the corresponding ciphertext message. By plaintext, we mean the message before it was encrypted (i.e., readable English sentences), and by ciphertext, we mean the message after it was encrypted (i.e., gibberish). To encrypt a message, each letter is changed to a new letter, so that if you read the ciphertext message, it is not obvious what the plaintext message is.

// However, Ruby being the outstanding code-breaker she is, knows the algorithm that Mr. X and Mr. Z use. She knows they simply map one letter to another (possibly different) letter when they encrypt their messages. Of course, this map must be "one-to-one", meaning that each plaintext letter must correspond to exactly one ciphertext letter, as well as "onto", meaning that each ciphertext letter has exactly one corresponding plaintext letter.

// Your job is to automate Ruby's codebreaking and help save the world.

// Input Specification
// The input consists of 3 strings, with each string on a separate line. The first string is the plaintext message which Ruby knows about. The second string is the ciphertext message which corresponds to the plaintext message. The third string is another ciphertext message. You may assume that all strings have length of at least 1 character and at most 80 characters. You can also assume that there are only 27 valid characters: the uppercase letters (A through Z) as well as the space character ( ). That is, there will be no punctuation, lowercase letters, or special characters (like ! or @) in either the plaintext or ciphertext messages.

// Output Specification
// The output is a (plaintext) string which corresponds to the second ciphertext input. It may not be possible to determine each character of the second ciphertext string, however. If this is the case, the output should have a period (.) character for those letters which cannot be determined.

// Sample Input 1
// Copy
// THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
// UIFARVJDLACSPXOAGPYAKVNQTAPWFSAUIFAMB ZAEPH
// XFABSFAWFSZACBEAQFPQMFAEPJOHAWFSZACBEAUIJOHTAIBAIB
// Sample Output 1
// Copy
// WE ARE VERY BAD PEOPLE DOING VERY BAD THINGS HA HA
// Explanation for Sample Output 1
// Notice that every plaintext character is in the first message, and so, the entire mapping can be computed.
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string a, b, text;
    getline(cin, a);
    getline(cin, b);
    unordered_map <char, char> decoder;
    for (int x = 0; x < a.length(); x++)
    {
        decoder[b[x]] = a[x];
    }
    getline(cin, text);
    string str1 = "";
    for (auto c : text)
    {
        if (decoder.find(c) != decoder.end())
        {
            str1 += decoder[c];
        }
        else
        {
            str1 += '.';
        }
    }
    cout << str1;
}

// Canadian Computing Competition: 2010 Stage 1, Senior #2
// There is an ingenious text-compression algorithm called Huffman coding, designed by David Huffman in 1952.

// The basic idea is that each character is associated with a binary sequence (i.e., a sequence of 0s and 1s). These binary sequences satisfy the prefix-free property: a binary sequence for one character is never a prefix of another character's binary sequence.

// It is worth noting that to construct a prefix-free binary sequence, simply put the characters as the leaves of a binary tree, and label the "left" edge as 0 and the "right" edge as 1. The path from the root to a leaf node forms the code for the character at that leaf node. For example, the following binary tree constructs a prefix-free binary sequence for the characters {𝐴,𝐵,𝐶,𝐷,𝐸}:


// That is, A is encoded as 00, B is encoded as 01, C is encoded as 10, D is encoded as 110 and E is encoded as 111.

// The benefit of a set of codes having the prefix-free property is that any sequence of these codes can be uniquely decoded into the original characters.

// Your task is to read a Huffman code (i.e., a set of characters and associated binary sequences) along with a binary sequence, and decode the binary sequence to its character representation.

// Input Specification
// The first line of input will be an integer 𝑘 (1≤𝑘≤20), representing the number of characters and associated codes. The next 𝑘 lines each contain a single character, followed by a space, followed by the binary sequence (of length at most 20) representing the associated code of that character. You may assume that the character is an alphabet character (i.e., 𝑎…𝑧 and 𝐴…𝑍). You may assume that the sequence of binary codes has the prefix-free property. On the 𝑘+2nd line is the binary sequence which is to be decoded. You may assume the binary sequence contains codes associated with the given characters, and that the 𝑘+2nd line contains no more than 250 binary digits.

// Output Specification
// On one line, output the characters that correspond to the given binary sequence.

// Sample Input
// Copy
// 5
// A 00
// B 01
// C 10
// D 110
// E 111
// 00000101111
// Output for Sample Input
// Copy
// AABBE
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    vector <string> vec1;
    unordered_map <string, string> decoder;
    for (int x = 0; x < n; x++)
    {
        string line;
        getline(cin, line);
        vec1 = split(line);
        decoder[vec1[1]] = vec1[0];
    }
    string text;
    string str1 = "";
    getline(cin, text);
    while (text != "")
    {
        for (auto x : decoder)
        {
            if (text.find(x.first) == 0)
            {
                text = text.substr(x.first.length(), text.length() - x.first.length());
                str1 += x.second;
            }
        }
    }
    cout << str1;
}

// Brute Force Practice 2
// You have a string (indexed from 0) with no more than 50 lowercase characters. Find the lexicographically least substring with a length of at least 𝐾. A string 𝑆 is said to be lexicographically smaller than a string 𝑇 if |𝑆|<|𝑇| and 𝑆 is a prefix of 𝑇 or 𝑆𝑘<𝑇𝑘 and 𝑆𝑖=𝑇𝑖 (0≤𝑖<𝑘,0≤𝑘<min(|𝑆|,|𝑇|)). Here, |𝑋| denotes the length of the string.

// Input
// The first line will have the string.

// The second line will have 𝐾.

// Output
// Print the lexicographically least substring of length at least 𝐾.

// Sample Input
// Copy
// iloveprogramming
// 4
// Sample Output
// Copy
// ammi
#include <iostream>
#include <string>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string str1;
    getline(cin, str1);
    int s;
    cin >> s;
    string min_s = str1.substr(0, s);
    for (int x = 1; x < str1.length() - s; x++)
    {
        if (min_s.compare(str1.substr(x, s)) > 0)
        {
            min_s = str1.substr(x, s);
        }
    }
    cout << min_s;
}

// A seldom-known fact about email addresses is that you can format a given address in several different ways. In particular:

// The entire address is case-insensitive.
// Dots (.) before the at-sign (@) sign are ignored.
// A plus (+) followed by any string can be added before the at-sign (@). The plus and following string are ignored.
// For example, foo@bar.com and fO.o+baz123@bAR.com refer to the same email address.

// John runs a service where users sign up with their email address. He has noticed that some users have signed up multiple times using different representations of the same address. He has asked for your help to determine the number of unique email addresses that have signed up on his site.

// Input Specification
// The input will contain 10 datasets. Each dataset begins with a line containing an integer 𝑁 (1≤𝑁≤100000), the number of email addresses. The next 𝑁 lines each contain an email address 𝑆 (1≤|𝑆|≤30). The email address will be formatted as a non-empty user part consisting of letters, numbers, dots, and pluses followed by a single at-sign followed by a non-empty domain part consisting of letters, numbers, and dots.

// For the first 6 cases, 𝑁≤100.

// Output Specification
// For each dataset, output the number of unique email addresses in the dataset.

// Sample Input (Two Datasets Shown)
// Copy
// 3
// foo@bar.com
// fO.o+baz123@bAR.com
// foo@bar..com
// 3
// c++@foo.com
// c...@Foo.com
// .c+c@FOO.COM
// Sample Output
// Copy
// 2
// 1
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    for (int x = 0; x < 10; x++)
    {
        int n;
        cin >> n;
        cin.ignore();
        unordered_set <string> set1;
        for (int a = 0; a < n; a++)
        {
            string line;
            getline(cin, line);
            int index = line.find('@');
            string str1 = "";
            for (int b = 0; b < index; b++)
            {
                if (line[b] == '+')
                {
                    break;
                }
                if (line[b] != '.')
                {
                    str1 += tolower(line[b]);
                }
            }
            for (int c = index; c < line.length(); c++)
            {
                str1 += tolower(line[c]);
            }
            set1.insert(str1);
        }
        cout << set1.size() << endl;
    }
}


// Canadian Computing Competition: 2011 Stage 1, Senior #1
// You would like to do some experiments in natural language processing. Natural language processing (NLP) involves using machines to recognize human languages.

// Your first idea is to write a program that can distinguish English text from French text.

// After some analysis, you have concluded that a very reasonable way of distinguishing these two languages is to compare the occurrences of the letters t and T to the occurrences of the letters s and S. Specifically:

// if the given text has more t and T characters than s and S characters, we will say that it is (probably) English text;
// if the given text has more s and S characters than t and T characters, we will say that it is (probably) French text;
// if the number of t and T characters is the same as the number of s and S characters, we will say that it is (probably) French text.
// Input Specification
// The input will contain the number 𝑁 (0<𝑁<10000) followed by 𝑁 lines of text, where each line has at least one character and no more than 100 characters.

// Output Specification
// Your output will be one line. This line will either consist of the word English (indicating the text is probably English) or French (indicating the text is probably French).

// Sample Input 1
// Copy
// 3
// The red cat sat on the mat.
// Why are you so sad cat?
// Don't ask that.
// Output for Sample Input 1
// Copy
// English
// Sample Input 2
// Copy
// 3
// Lorsque j'avais six ans j'ai vu, une fois,
// une magnifique image,
// dans un livre
// Output for Sample Input 2
// Copy
// French
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    int count_t = 0;
    int count_s = 0;
    for (int x = 0; x < n; x++)
    {
        string line;
        getline(cin, line);
        for (int a = 0; a < line.length(); a++)
        {
            if (line[a] == 't' or line[a] == 'T')
            {
                count_t++;
            }
            if (line[a] == 's' or line[a] == 'S')
            {
                count_s++;
            }
        }
    }
    if (count_t > count_s)
    {
        cout << "English";
    }
    else
    {
        cout << "French";
    }
    return 0;
}


// Canadian Computing Competition: 2013 Stage 1, Junior #2
// An artist wants to construct a sign whose letters will rotate freely in the breeze. In order to do this, she must only use letters that are not changed by rotation of 180 degrees: I, O, S, H, Z, X, and N.

// Write a program that reads a word and determines whether the word can be used on the sign.

// Input Specification
// The input will consist of one word, all in uppercase letters, with no spaces. The maximum length of the word will be 30 letters, and the word will have at least one letter in it.

// Output Specification
// Output YES if the input word can be used on the sign; otherwise, output NO.

// Sample Input 1
// Copy
// SHINS
// Output for Sample Input 1
// Copy
// YES
// Sample Input 2
// Copy
// NOISE
// Output for Sample Input 2
// Copy
// NO
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string line;
    getline(cin, line);
    vector <char> vec1 = {'I', 'O', 'S', 'H', 'Z', 'X', 'N'};
    int s = 0;
    for (int x = 0; x < line.length(); x++)
    {
        if (find(vec1.begin(), vec1.end(), line[x]) == vec1.end())
        {
            s = 1;
        }
    }
    if (s == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}


// Canadian Computing Competition: 2015 Stage 1, Junior #2
// We often include emoticons in our text messages to indicate how we are feeling. The three consecutive characters :-) indicate a happy face and the three consecutive characters :-( indicate a sad face. Write a program to determine the overall mood of a message.

// Input Specification
// There will be one line of input that contains between 1 and 255 characters.

// Output Specification
// The output is determined by the following rules:

// If the input line does not contain any happy or sad emoticons, output none.
// Otherwise, if the input line contains an equal number of happy and sad emoticons, output unsure.
// Otherwise, if the input line contains more happy than sad emoticons, output happy.
// Otherwise, if the input line contains more sad than happy emoticons, output sad.
// Sample Input 1
// Copy
// How are you :-) doing :-( today :-)?
// Output for Sample Input 1
// Copy
// happy
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    getline(cin, line);
    int happy = 0;
    int sad = 0;
    for (int x = 0; x < line.length(); x++)
    {
        string substring = line.substr(x, 3);
        if (substring == ":-)")
        {
            happy++;
        }
        if (substring == ":-(")
        {
            sad++;
        }
    }
    if (happy == 0 && sad == 0)
    {
        cout << "none" << endl;
    }
    else if (happy == sad)
    {
        cout << "unsure" << endl;
    }
    else if (happy > sad)
    {
        cout << "happy" << endl;
    }
    else
    {
        cout << "sad" << endl;
    }
    return 0;
}

// Canadian Computing Competition: 2016 Stage 1, Junior #3
// A palindrome is a word which is the same when read forwards as it is when read backwards. For example, mom and anna are two palindromes.

// A word which has just one letter, such as a, is also a palindrome.

// Given a word, what is the longest palindrome that is contained in the word? That is, what is the longest palindrome that we can obtain, if we are allowed to delete characters from the beginning and/or the end of the string?

// Input Specification
// The input will consist of one line, containing a sequence of at least 1 and at most 40 lowercase letters.

// Output Specification
// Output the total number of letters of the longest palindrome contained in the input word.

// Sample Input 1
// Copy
// banana
// Output for Sample Input 1
// Copy
// 5
// Explanation for Output for Sample Input 1
// The palindrome anana has 5 letters.

// Sample Input 2
// Copy
// abracadabra
// Output for Sample Input 2
// Copy
// 3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool is_palindrome(string n)
{
    vector<char> vec1;
    copy(n.begin(), n.end(), back_inserter(vec1));
    vector<char> vec2 (vec1.rbegin(), vec1.rend());
    if (vec1 == vec2) return true;
    else return false;
}

int main()
{
    string n;
    getline(cin, n);
    int maximum1 = 0;
    for (int x = 0; x < n.length() - 1; x++)
    {
        for (int a = x + 1; a < n.length() + 1; a++)
        {
            string substr1 = n.substr(x, a-x);
            bool b = is_palindrome(substr1);
            if (b == true and (a - x) > maximum1)
            {
                maximum1 = a - x;
            }
        }
    }
    cout << maximum1;
    return 0;
}

// Canadian Computing Competition: 2005 Stage 1, Senior #1
// You've been snowed in at your summer residence. And without the Internet! Unfortunately, this means you're going to have rely on using the phone to get what you need to survive: pizza, pop, and the latest video games.

// Often times, companies replace the digits in their phone numbers with characters to make their phone numbers more memorable. Because apparently, it's easier to remember 416-BUY-MORE than it is to remember 416-289-6673. Some companies even add extra digits or characters (like 604-PIZZABOX) but any digits after the 10th are irrelevant.

// Since it's getting tedious to do the conversion by hand, write a program to help change all the phone numbers in your phone book to the form xxx-xxx-xxxx, using the below image to assist you.



// Input Specification
// Input consists of a series of test cases. The first line consists of an integer 𝑡, the number of test cases. Following this are 𝑡 lines consisting of alpha-numeric characters separated by hyphens, representing valid phone numbers. All letters will be in uppercase. No line is longer than 40 characters.

// Output Specification
// For each test case, output the phone number in the form xxx-xxx-xxxx to the screen.

// Sample Input
// Copy
// 5
// 88-SNOW-5555
// 519-888-4567
// BUY-MORE-POP
// 416-PIZZA-BOX
// 5059381123
// Sample Output
// Copy
// 887-669-5555
// 519-888-4567
// 289-667-3767
// 416-749-9226
// 505-938-1123
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	cin.ignore();
	string str1;
	for (int x = 0; x < n; x++)
	{
		string line;
		getline(cin, line);
		str1 = "";
		for (int a = 0; a < line.length(); a++)
		{
			if (isalpha(line[a]))
			{
				if (line[a] == 'A' || line[a] == 'B' || line[a] == 'C')
				{
					str1 += '2';
				}
				else if (line[a] == 'D' || line[a] == 'E' || line[a] == 'F')
				{
					str1 += '3';
				}
				else if (line[a] == 'G' || line[a] == 'H' || line[a] == 'I')
				{
					str1 += '4';
				}
				else if (line[a] == 'J' || line[a] == 'K' || line[a] == 'L')
				{
					str1 += '5';
				}
				else if (line[a] == 'M' || line[a] == 'N' || line[a] == 'O')
				{
					str1 += '6';
				}
				else if (line[a] == 'P' || line[a] == 'Q' || line[a] == 'R' || line[a] == 'S')
				{
					str1 += '7';
				}
				else if (line[a] == 'T' || line[a] == 'U' || line[a] == 'V')
				{
					str1 += '8';
				}
				else
				{
					str1 += '9';
				}
			}
			if (isdigit(line[a]))
			{
			    str1 += line[a];
			}
			
			if (str1.length() == 3 || str1.length() == 7)
			{
				str1 += '-';
			}
            if (str1.length() == 12)
            {
                break;
            }
		}
		cout << str1 << endl;
	}
	return 0;
}


// Tusk has been stranded on an island for some time now, and it's fair to say that he's grown terribly bored. As such, he's started to find ordinary things immensely fascinating.

// Today, he's interested in the waves he sees. He notes that certain times of the day, the water level either increases or decreases. Realizing this phenomenon is due to tides, he is now most fervent about determining the difference in water level between high tide and low tide.

// To this end, he's measured the water level 𝑁 times throughout the day using a high-precision measuring device such that each reading is a unique integer in the range 1…10000 inclusive.

// He knows that after measuring the absolute minimum reading at low tide, the transition to the absolute maximum reading representing the water level at high tide consists of a strictly increasing sequence of water level readings. He's interested in the difference between the absolute maximum and absolute minimum readings: the water level difference between tides.

// It's possible that he made a mistake in writing down these readings, however, in which case the sequence between the low tide reading and high tide reading will not be strictly increasing. If this is the case, it's likely that the data is useless — the water level difference cannot be accurately determined — and should be scrapped.

// Input Specification
// The first line will contain the single integer 𝑁 (3≤𝑁≤1000). The second line will contain 𝑁 space-separated positive integers: the water level readings in chronological order.

// Output Specification
// The integer difference in water level between high tide and low tide. If the difference cannot be accurately determined, output unknown.

// Sample Input 1
// Copy
// 5
// 2 1 3 5 10
// Sample Output 1
// Copy
// 9
// Sample Input 2
// Copy
// 5
// 1 2 5 4 9
// Sample Output 2
// Copy
// unknown
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < int > split (string str1)
{
  vector < int >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (stoi (word));
    }
  return vv;
}

int main()
{
  cin.sync_with_stdio (0);
  cin.tie (0);
  int n;
  cin >> n;
  cin.ignore();
  string line;
  getline(cin, line);
  vector <int> vec1 = split(line);
  int s = min_element(vec1.begin(), vec1.end()) - vec1.begin();
  int l = max_element(vec1.begin(), vec1.end()) - vec1.begin();
  int a = 0;
  if (l > s)
  {
      for (int x = s + 1; x <= l; x++)
      {
          if (vec1[x] < vec1[x - 1])
          {
              cout << "unknown" << endl;
              a = 1;
              break;
          }
      }
      if (a == 0)
      {
          cout << vec1[l] - vec1[s] << endl;
          a = 1;
      }
  }
  if (a == 0)
  {
      cout << "unknown" << endl;
  }
  return 0;
}


// Canadian Computing Competition: 2011 Stage 1, Junior #4
// Boring is a type of drilling, specifically, the drilling of a tunnel, well, or hole in the earth. With some recent events, such as the Deepwater Horizon oil spill and the rescue of Chilean miners, the public became aware of the sophistication of the current boring technology. Using the technique known as geosteering, drill operators can drill wells vertically, horizontally, or even on a slant angle.

// A well plan is prepared before drilling, which specifies a sequence of lines, representing a geometrical shape of the future well. However, as new information becomes available during drilling, the model can be updated and the well plan modified.

// Your task is to write a program that verifies validity of a well plan by verifying that the borehole will not intersect itself. A two-dimensional well plan is used to represent a vertical cross-section of the borehole, and this well plan includes some drilling that has occurred starting at (0,−1) and moving to (−1,−5). You will encode in your program the current well plan shown in the figure below:

// -3	-2	-1	0	1	2	3	4	5	6	7	8	9	10
// -1														
// -2														
// -3									
// -4														
// -5												
// -6														
// -7						
// -8														
// Input Specification
// The input consists of a sequence of drilling command pairs. A drilling command pair begins with one of four direction indicators (d for down, u for up, l for left, and r for right) followed by a positive length. There is an additional drilling command indicated by q (quit) followed by any integer, which indicates the program should stop execution. You can assume that the input is such that the drill point will not:

// rise above the ground, nor
// be more than 200 units below ground, nor
// be more than 200 units to the left of the original starting point, nor
// be more than 200 units to the right of the original starting point
// Output Specification
// The program should continue to monitor drilling assuming that the well shown in the figure has already been made. As we can see (−1,−5) is the starting position for your program. After each command, the program must output one line with the coordinates of the new position of the drill, and one of the two comments safe, if there has been no intersection with a previous position or DANGER if there has been an intersection with a previous borehole location. After detecting and reporting a self-intersection, your program must stop.

// Sample Input 1
// Copy
// l 2
// d 2
// r 1
// q 0
// Output for Sample Input 1
// Copy
// -3 -5 safe
// -3 -7 safe
// -2 -7 safe
// Sample Input 2
// Copy
// r 2
// d 10
// r 4
// Output for Sample Input 2
// Copy
// 1 -5 safe
// 1 -15 DANGER
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

template < typename T > void
print (T t)
{
 for (const auto & e:t) cout << e << " ";
  cout << endl;
}

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    vector <pair<int, int> > danger = {{0, -1}, {0, -2}, {0, -3}, {1, -3}, {2, -3}, {3, -3}, {3, -4}, {3, -5},
      {4, -5}, {5, -5}, {5, -4}, {5, -3}, {6, -3}, {7, -3}, {7, -4}, {7, -5}, {7, -6}, {7, -7},
      {6, -7}, {5, -7}, {4, -7}, {3, -7}, {2, -7}, {1, -7}, {0, -7}, {-1, -7}, {-1, -6}, {-1, -5}};
    string line;
    pair<int, int> pos = {-1, -5};
    int check;
    vector <string> vec1;
    while (true)
    {
      getline(cin, line);
      check = 0;
      vec1 = split(line);
      if (vec1[0] == "l")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.first -= 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "r")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.first += 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "u")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.second += 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "d")
      {
          for (int x = 0; x < stoi(vec1[1]); x++)
          {
              pos.second -= 1;
              if (find(danger.begin(), danger.end(), pos) != danger.end())
              {
                  check = 1;
              }
              danger.emplace_back(pos);
          }
          if (check == 1)
          {
              cout << pos.first << " " << pos.second << " DANGER" << endl;
              break;
          }
          cout << pos.first << " " << pos.second << " safe" << endl;
      }
      if (vec1[0] == "q")
      {
          break;
      }
   }
}

// DWITE Online Computer Programming Contest, December 2008, Problem 2
// There's an essay due in class, and your teacher demands at least a certain minimum length from your paper. Caring more about optimization than the subject of ancient history, a wordcount tool would come in handy; and save you from writing any more words than you need to.

// Knowing that your teacher counts only the words that are more than three letters long (having a similar software tool of her own), your program would need to do just that -- count the words that are at least 4 letters long.

// The input will contain 5 lines, each a line of English text, no more than 255 characters in length.

// The output will contain 5 integer values -- count of words over 3 letters long, in each line.

// Sample Input
// Copy
// DWITE question number two: Wordcount++
// Note how "two:" does not count.
// For simplicity - "don't" is two words, split by apostrophe.

// That was a blank line above.
// Sample Output
// Copy
// 4
// 3
// 4
// 0
// 4
#include <iostream>
#include <regex>
using namespace std;
int main()
{
    string subject;
    for (int x = 0; x < 5; x++)
    {
        getline(cin, subject);
        smatch match;
        int i = 0;
        while (regex_search(subject, match, regex("[a-zA-Z][a-zA-Z][a-zA-Z][a-zA-Z]+")))
        {
            i++;
            subject = match.suffix().str();
        }
        cout << i << endl;
    }
}

//alternative solution
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

vector < string > split (string str1)
{
  vector < string >vv;
  string word;
  istringstream ss (str1);
  while (getline (ss, word, ' '))
    {
      vv.push_back (word);
    }
  return vv;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    string line;
    vector <string> vec1;
    int s1;
    int s2;
    for (int x = 0; x < 5; x++)
    {
        getline(cin, line);
        vec1 = split(line);
        s2 = 0;
        for (auto w : vec1)
        {
            s1 = 0;
            for (int a = 0; a < w.length(); a++)
            {
                if (isalpha(w[a]))
                {
                    s1++;
                }
                else
                {
                    break;
                }
            }
            if (s1 > 3)
            {
                s2++;
            }
        }
        cout << s2 << endl;
    }
}



