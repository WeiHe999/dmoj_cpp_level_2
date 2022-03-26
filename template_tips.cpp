c++ tips:
// c++ formatter
https://techiedelight.com/tools/clike
// reference with example
https://www.cplusplus.com/reference/queue/queue/pop/

CP algorithms:
https://cp-algorithms.com/

Zoom meeting: https://zoom.us/j/92941888492 (Passcode: 6464415960)
Ccc-winter-2022: Zoom Link: https://zoom.us/j/97017497850
Password: 9192023039 
CCC-2-winter assignment contest password: 937a0fa19719
CCC-2-Winter 2022 course notes:
https://docs.google.com/document/d/1kbIzuCQ76Dl150K8dWJ8ruFMUMVQAs2sP3z93bHHnsw/edit


// include
#include <bits/stdc++.h> // everything included


// template ******

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
  
//measure time
cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;

  return 0;
}

// input *****
// single integer input from stdin
int a;
cin >> a;
cin.ignore();

//multiple inputs per line
int a, b;
cin >> a >>b; //input: 5 7, then a=5, b=7

//line input from stdin
string line;
getline(cin, line);

//input as: A 123
char c;
int a;
cin >> c >> a; //c=‘A’, a = 123

//input: Tom 234
string str1;
int a;
cin >> str1 >> a; //str1=“Tom”, a=123

//batch input into array
#include <stdio.h>
int main()
{
    int N; //number of integers to be input
    scanf("%d", &N);
    int arr[N];
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
}

// fast input/output using c
#include <stdio.h>
 int n;
 scanf("%d", &n);
 int arr1[n], arr2[n];
 for (int k=0; k<n; k++) scanf("%d %d", &arr1[k], &arr2[k]);
 printf("%d\n", n);
 for (int m=0; m<n; m++) printf("%d ", arr1[m]);
 printf("\n");
 float f1 = 12.468;
 printf("The final score is %.2f.\n", f1);
string str1= "Mike";
printf("This is %s", str1.c_str());
 
// input output from files
ifstream fin("template.in"); 
ofstream fout("template.out"); }

// output ****
// output decimal number rounded to 2 points after decimal point
# include <iomanip>
Float a=3.267;
Cout << fixed << setprecision(2) << a << endl; //output 3.27

// print integer in fixed format (such as: 02:08)
int a=2, b=8;
cout << setw(2) << setfill('0') << a << setw(2) << setfill('0') << b << endl;

//round, ceil, floor (remember to *1.0 to make it float first)
int a = round(28/10); // a=2 because 28/10=2 
int b = ceil(22/10); // b=2
Int a= round(1.0*28/10); // a=3
Int c = floor(1.0*28/10); //c=2

//output double, need to set precision
int a1=123456783;
int a2=7689254;
double d = (a1+a2)/2.0;
cout << d << endl;// 6.5573e+07 which is approximated value, wrong
cout << fixed << setprecision(6) << d << endl; //65573018.500000, correct answer

// for interactive program, need to flush the output before get input from online judge
cout << "? " << 2 << " " << 1 << endl << flush;
cin >> ans;


// string ****
// loop over a string or vector
for (long n=0; n<str1.size(); n++) cout << str1[n]
for(auto x: str1) cout << x;

// find an element from a string
int pos = line.find ("X");
if (pos != -1) count << line[pos];

//find a substring from the end
  std::string str ("The sixth sick sheik's sixth sheep's sick.");
  std::string key ("sixth");
  std::size_t found = str.rfind(key);  //index of the last ‘sixth’


# sort a string
string sortedWord = "yifeng";
sort(sortedWord.begin(), sortedWord.end()); //ascending order
sort(sortedWord.rbegin(), sortedWord.rend()); //descending order

# substring
string str1 = "yifeng";
string substr1 = str1.substr(1, 3); //“ife”
String substr2 = str1.substr(3); //remaining: eng

//string concat
String str3 = str1 + "@" + str2

# digit or alphabet for a char
   char val1 = ‘3’;
   char val2 = ‘a’;
if(isdigit(val1)) cout << val1;
if(isalpha(val2)) cout << val2;

# convert string to lower or upper
std::string data = "Abc";
std::transform(data.begin(), data.end(), data.begin(),
    [](char c){ return std::tolower(c); }); //abc
std::transform(data.begin(), data.end(), data.begin(),
    [](char c){ return std::toupper(c); }); //ABC

// find number of vowels
    string line = "aBeU i09yqED";
    string v = "aeiou";
    for(int i = 0; i < line.length(); ++i)
      {if (v.find(tolower(line[i]))!=string::npos) vowels++; }

// regular expression ***
https://www.youtube.com/watch?v=_BaG3qw_zLE

char regex_filename[] = “[a-zA-Z_] [a-zA-Z_0-9]*\\.[a-zA-Z0-9]+”;
// ^ excluding
//* repeat the previous digit or group 0 or more times
//+ repeat one or more times
//? repeat zero or one time
//. matches any single character

//replace a substring
#include <regex>
string str1("hello $name");
str1 = regex_replace(str1, regex("\\$name"), "Somename"); //hello Somename

//find matches
string subject = “My GeeksforGeeks is my GeeksforGeeksdfg none of your GeeksforGeek";
smatch match;
regex r("GeeksforGeek[s]?");
int i = 0;
while (regex_search(subject, match, r)) {
cout << match.str(0) << match.position(0) << endl;
i++;
subject = match.suffix().str();}

// remove a char from a string
b.erase(remove(b.begin(), b.end(), '*'), b.end());
b = regex_replace(b, regex(“*”), “”); //remove *

// compare two strings
string str1="abbc";
string str2 = "abba";
if (str1.compare(str2)>0) cout << "str1 is greater than str2" << endl; //str1 is greater than str2
if (str1>str2) cout << "str1 is greater than str2" << endl; //also works
//compare
0D < AAB < AABA < Z < aab < c

// find multiple appearances of a substring
string str1 = "I love java and java love me";
int start = 0;
int pos = str1.find("love", start);
int cnt = 0;
while(pos!=-1){
      pos = str1.find("love", pos+1);
      cout << pos << endl;
      cnt ++;}

// int/float to string
int a = 10;
string str1 = to_string(a);
// string to int or double or float
string str2 = "123”;
int b = stoi(str2);
float c = stof(str2);
double d = stod(str2);

//reference or deep copy
string s="1345";
string t = s;//deep copy
string &t=s; //the same mem

// find number of occurrences for each char
vector<int> freq;
freq.reserve(128);//128 ASCII code
string str1="abca";
for (int k=0; k<str1.size(); k++) freq[str1[k]]++;
//count small letter
vector<int> freqs(26);
for(char c: s){
    if(c != ' ') freqs[c-'A']++;}



// vector ***

Tips:
1. Do not do erase or insert on a vector because it is O(n) complexity, except erasing the last element which is O(1)
2. If you need to do frequent operations (remove or add) to the ends of a sequence, using deque
3. Use unordered_map if the key is hashable, for example, key is int, string, char
4. Example: https://github.com/WeiHe999/data_structure/blob/main/deque_and_map.cpp

// construct a vector from an array
int arr[4] = {16,2,77,29};
vector<int> vec (arr, arr + 4 );

// define and initialize a vector to constants
 vector<vector<int> > a1(10, vector<int>(10, 4));    // 2D vector of 10*10 with all 4
 vector<int > a2(10, 999); // 1D vector containing 10 elements of 999

//4d array
        int dp[50][50][tot_turns+1][2];
        memset(dp, 0, sizeof dp); // initialize to 0
        //initialization
        dp[0][0][0][0] = 1; //facing east
        dp[0][0][0][1] = 1; // facing south


//assign
vector<int> vec1;
vec1.assign(3, 0); //[0, 0, 0]

//slicing
vector<int> v2(vec1.begin() + 1, vec1.end());
vector<int> v3;
v3.assign(vec1.begin() + 1, vec1.end());

// find an element from a vector
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end()) int index = it - v.begin();

// sort a vector in ascending or descending order
vector<int> v1={1, 3, 4, 2};
sort(v1.begin(), v1.end()); //ascending order
sort(v1.rbegin(), v1.rend()); //descending order

Sort a vector of pairs {(2, “aaa”), (3, “mike”), (2, “zzz”)), ascending on the first element and then descending on the second element
vector<pair<int, string> > a = {{2, "aaa"}, {3, "bbb"}, {2, "zzz"}};
sort(a.begin(), a.end(), [](pair<int, string> a, pair<int, string> b){if(a.first==b.first) return a.second>b.second; else return a<b;});

//std::stable_sort preserves the order of equivalent elements, while std::sort doesn’t, but sort O(N·log(N)) performs faster than stable_sort
stable_sort(v1.begin(), v1.end()); //ascending order

//sort vector of vectors based on second element
vector<vector<int>> vec = {{1,4}, {9, 2}};
//sort in ascending order based on the second element
std::sort(vec.rbegin(), vec.rend(),
          [](vector<int> a, vector<int> b) {return a[1] < b[1];});

//access elements
v1[1]=200;
v1.push_back(99);
v1.emplace_back(98);

//max/min 
vector<int>  vec1 = {3, 0, 5, 2};
int min_ind = min_element(vec1.begin(), vec1.end()) - vec1.begin(); //1
int min_value = *min_element(vec1.begin(), vec1.end()); //0

//vector of pairs
vector<pair<int, int> > v1 = {{1,-3}, {-2, 1}, {2, 4}};
int a1=1, b1=-3;
if(find(v1.begin(), v1.end(), make_pair(a1, b1))!=v1.end()) //check if a pair in the vector
pair<int, int> p1 = {a1, b1};  // a pair
cout << p1.first << ", " << p1.second << endl; //access elements in a pair

//unique vector
#include <unordered_set>
void unique_vector(vector<int> &vec)
{
    unordered_set<int> s; //set is ordered
    for (auto i : vec)
        s.insert(i);
    vec.assign( s.begin(), s.end() );   //random order in the vector
}

//use set to count items
String str1 = “yyyyhe”;
unordered_set<string> set1;
set1.insert(str1);
cout << set1.size() << ends;
//erase: O(1)
set1.erase(str1);
// check if an element exists
if (set1.count(str1)) count << “exist” << ends;


//rotate 2D vector
  vector<vector<int> > myvector={{1,2,3}, {4,5,6}, {7,8,9}};
	  // step-1: reverse the vector
	  reverse(myvector.begin(), myvector.end());
	  // step-2: flip elements along diagonal
	  int size = myvector.size();
	  for (int i = 0; i < size; ++i) {
	    for (int j = 0; j < i; ++j) {
	      swap(myvector[i][j], myvector[j][i]);
	    }
	  }

//difference in for-each loop 
for(auto x: vect1) x=3; //copy element, do not change original vector
for (auto x &: vect1) x=3; //reference, changed original vector

//insert
 vector<int>::iterator it=v1.begin();
 v1.insert(it+2, 100);
//pop (remove the last element)
 v1.pop_back();
// remove an element based on index
auto it1=v1.begin()+1;
v1.erase(it1); //erase the second element

//erase all elements with a given value
vector<int> v2={1, 3, 4, 2, 1};
for (int k=0; k<v2.size(); k++)
{
    if (v2[k]==1) v2.erase(v2.begin()+k);
}

//lower_boound and upper_bound
//lower_bound (3): point to the first iterator that is larger than or equal to 3
//upper_bound(3): point to the first iterator that is larger than 3
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
  std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
  std::vector<int>::iterator low, up;
  low=std::lower_bound (v.begin(), v.end(), 20); //  index=3, the first position >=20
  up= std::upper_bound (v.begin(), v.end(), 20); // index=6, the first position >20

//binary_search, return true or false
vector<int> arr = {10, 15, 20, 25, 30, 35};
if (binary_search(arr.begin(), arr.end(), 67))
    cout << “Element exists in vector";
else
     cout << “Element does not exist";

//count the number of elements in vector that is less or equal to a threshold
//upper_bound (pos.begin(), pos.end(), threshold) return the iterator pointing to the first element larger than the threshold
int count = upper_bound (pos.begin(), pos.end(), threshold) - pos.begin();

//binary search on a vector
std::sort (v.begin(), v.end());
  if (std::binary_search (v.begin(), v.end(), 3)) // return True or False
    std::cout << "found!\n"; else std::cout << "not found.\n";

// count the number of occurrences for an element
vector<int> v = {3, 7, 3, 11, 3, 3, 2};
int num_occurance1 = count(v.begin(), v.end(), 3); //4, search on unsorted vector, O(n)

sort(v.begin(), v.end()); //O(nlogn)
auto range1 = equal_range(v.begin(), v.end(), 3); //log(n)
int num_occurence = range1.second - range1.first; //4
range1 = equal_range(v.begin(), v.end(), 5);
num_occurence = range1.second - range1.first; //0
//range1.first ==> std::lower_bound (v.begin(), v.end(), 3);
//range1.second ==> std::upper_bound (v.begin(), v.end(), 3);

// find the difference and intersection between two vectors
vector<int> first = {5,10,15,20,25};
vector<int> second = {50,40,30,20,10};
std::vector<int> v1, v2;               
std::sort (first.begin(),first.end());     //  5 10 15 20 25
std::sort (second.begin(), second.end());   // 10 20 30 40 50
auto it1=set_intersection (first.begin(), first.end(), second.begin(), second.end(), back_inserter(v1));
auto it2=set_difference (first.begin(), first.end(), second.begin(), second.end(), back_inserter(v2));
std::cout << "The intersection has " << (v1.size()) << " elements:\n"; //2
std::cout << "The difference has " << (v2.size()) << " elements:\n"; //3

//merge a local vector to a global vector (don’t use insert for vector)
global_visited.insert(global_visited.end(), local_visited.begin(), local_visited.end() );

// math calculation ***
#include <cmath>
float a = sqrt(pow(2, 3) + pow(9,2));

// always use double instead of float
int a = 10;
float b=float(a);
double c = double(a);

//infinity
#include <cmath>
double b=INFINITY;
float c=INFINITY;

#include <climits>
int int_max = INT_MAX;
int int_min = INT_MIN;
long long ll_max = LLONG_MAX;
Long long ll_min = LLONG_MIN;

# power
power(2, n) may cause TLE, because it is O(n). 
For example :
long long s = 0;
Int p = 1;
for (int i=0; i<n; i++) s+=power(2, i);
Should be changed to:
long long s = 0, p=1;
for (int i=0; i<n; i++) 
{
    s = s + p;
    P = p*2;
}

INT_MAX 2147483647 (10e9)
LONG_MAX 2147483647 (10e9)
LLONG_MAX 9,223,372,036,854,775,807 (10e18)
double max: 10e305 (less accurate)

int a = 1000000;
long long  b = a*a; // overflow, due to operation on int
long long b = 1ll*a*a; // correct, a is promoted to long long before operation

// GCD (built-in function: __gcd(a, b) and LCM
long long lcm(long long a, long long b)
{
    return (a * b) / __gcd(a, b);
}

# find angle from coordinates (0-360 degree)
double angle = atan2(y*1.0, x) * 180 / p;
if (angle < 0) angle += 360.0;

// function calls ****
// use reference in function call
float dijkstra(
    unordered_map<int, unordered_map<int, float>> &graph,
    unordered_map<int, float> &costs,
    unordered_map<int, int> &parents,
    int start_node,
    int end_node
    ) //The above function makes changes to: graph, costs, parents, so that they can be used in main function.


 // stack ****
stack<int> st;
st.push(10);
st.push(20);
cout << st.size() << endl;
while (!st.empty()) {
    int a = st.top(); // get the top element
    cout << a << endl;
     st.pop();  }

// unordered_set *** (fast in search if an element in the set)
unordered_set<string> set1;
set1.insert(str1);
cout << set1.size() << ends;

unordered_set<string> s;
s.insert("C++");
s.insert("C++");
s.insert("java");
// search if an element in the set, O(1) operation
if(s.count(“java”)) cout << "yes\n";
for(string x : s) cout << x << endl;

// set (ordered) ***
// set uses a binary search tree, delete or insert O(log(n)), no index for set
set<int> s;
s.insert(1);
s.insert(3);
s.insert(4);
s.insert(5);
auto it = s.lower_bound(4); //point to the first element >= 4
if(it!=s.end()) cout << *it << endl; 
it = s.upper_bound(4); // point to the first element > 4
if(it!=s.end()) cout << *it << endl; 

// we can get the first (smallest) and the last (largest) element from set
// we can also apply lower_bound and upper_bound on set
set<int> s;
s.insert(1); // [1]
s.insert(14); // [1, 14]
s.insert(9); // [1, 9, 14]
s.insert(2); // [1, 2, 9, 14]
cout << *s.upper_bound(7) << '\n'; // 9
cout << *s.upper_bound(9) << '\n'; // 14
cout << *s.lower_bound(5) << '\n'; // 9
cout << *s.lower_bound(9) << '\n'; // 9
cout << *s.begin() << '\n'; // 1
auto it = s.end();
cout << *(--it) << '\n'; // 14
s.erase(s.upper_bound(6)); // [1, 2, 14]

// multiset: 
1. essentially a sorted set that allows multiple copies of the same element.
2. The begin(), end(), lower_bound(), and upper_bound() operations work the same way they do in the normal sorted set.
multiset<int> ms;
ms.insert(1); // [1]
ms.insert(14); // [1, 14]
ms.insert(9); // [1, 9, 14]
ms.insert(2); // [1, 2, 9, 14]
ms.insert(9); // [1, 2, 9, 9, 14]
ms.insert(9); // [1, 2, 9, 9, 9, 14]
cout << ms.count(4) << '\n'; // 0
cout << ms.count(9) << '\n'; // 3
cout << ms.count(14) << '\n'; // 1

// map and unordered_map ****
unordered_map<string, float> dict1 = {{"b", 12.3}};
dict1["c"] = 14.6;
dict1.insert({"g", 167.8});
//erase: O(1)
dict1.erase(“g”);
// check if an element in the dict
if dict1.count(“g”) count << “exist” << ends;
// access elements
for (auto x: dict1) cout << x.first << x.second << endl;

//find if a key exist
unordered_map < string, int> m1;
unordered_map < string, vector<int> > m2;
if(m1.count(“java”)) count << “The key exists” << ends;
// by default, a new key is always set with values 0, or an empty vector, we can do below even we do not know if key1 exists
m1[“c++’]++;
m2[“c++”].append(12);

// embedded dict
unordered_map < string, unordered_map<string, float> > graph;
// load elements into embedded dict
if (graph.find(vec1[0])==graph.end()) graph[vec1[0]] = unordered_map<string, float> { {vec1[1], stof(vec1[2]) } };
// insert element, there is no push_back function
else graph[vec1[0]].insert( {vec1[1], stof(vec1[2]) } );

// dict with value of a list
unordered_map<int, vector<int> > graph;

//sort unordered_map, first put it into a vector
Vector<pair<int, int> > vect1;
for(auto x: graph) vect1.push_back({x.first, x.second});
sort(vect1.begin(), vect1.end());

// difference between map and unordered_map
map: use binary-search tree to store data, it is ordered, search complexity O(log(n))
unordered_map: use hash function and array to store data, it is unordered, search complexity O(1)

// The ordered map supports all of the operations that an unordered map supports, and additionally supports lower_bound and upper_bound
map<int, int> m;
m[3] = 5; // [(3, 5)]
m[11] = 4; // [(3, 5); (11, 4)]
m[10] = 491; // [(3, 5); (10, 491); (11, 4)]
cout << m.lower_bound(10)->first << " " << m.lower_bound(10)->second << '\n'; //10 491
cout << m.upper_bound(10)->first << " " << m.upper_bound(10)->second << '\n'; //11  4
m.erase(11); // [(3, 5); (10, 491)], O(log(n))
 
// tuple ****
vector<tuple<string, int, int> > a;
a = {{"apple”, 12, 13}, {"pear", 12, 2}};
a[0] = {"cherry", 12, 1};
sort(a.begin(), a.end(), [](tuple<string, int, int> p1, tuple<string, int, int> p2){if(get<1>(p1)<get<1>(p2)) return true; else return get<2>(p1)<get<2>(p2); });
for(int i=0; i<a.size(); i++) cout <<get<0>(a[i]) << ", " << get<1>(a[i])<< ", " << get<2>(a[i])<< endl;

// queue ****
 std::queue<int> myqueue;
 myqueue.push (3);
 while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
//double ended queue (sequence)
    deque <int> gquiz; //{15, 20, 10, 30}
    gquiz.push_back(10);
    gquiz.push_front(20);
    gquiz.push_back(30);
    gquiz.push_front(15);
    for(auto x: gquiz) cout << x << endl;
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.at(1) : " << gquiz[1];
    cout << "\ngquiz.front() : " << gquiz.front();
    cout << "\ngquiz.back() : " << gquiz.back();
    cout << endl;
    gquiz.pop_front();
    gquiz.pop_back();
    for(auto x: gquiz) cout << x << endl;

// STL array ***
//array
https://www.youtube.com/watch?v=eN_uT1xgIlM
std::array<int, 3> a2 = {1, 2, 3};
sort(a1.begin(), a1.end());
for(const auto& s: a3) std::cout << s << Lendl;

When using C++, arrays should be declared globally if at all possible. This avoids the common issue of initialization to garbage values.
# when defining an array inside main(), we need to set it elements to all 0
int dp[50];
memset(dp, 0, sizeof dp); // initialize to 0

// list *** (double link-list)
#include <list>
std::list<int> l = { 7, 5, 16, 8 };
l.push_front(25);
l.push_back(13);
 // Insert an integer before 16 by searching
auto it = std::find(l.begin(), l.end(), 16);
if (it != l.end()) l.insert(it, 42); //25, 7, 5, 42, 16, 8, 13

//heap
//min heap
vector<pair <int, int> > v1 {{12, 18}, {15, 90}, {21, 18}, {40, 9}, {5, 100}};
make_heap(v1.begin(), v1.end(), [](pair <int, int> a, pair <int, int> b) {return a > b;});
pop_heap(v1.begin(), v1.end(), [](pair <int, int> a, pair <int, int> b) {return a > b;});
cout << v1.back().first << ", " << v1.back().second << endl;
v1.pop_back();

// priority queue (fast to get the max-value element)
Insert: O(log(n))
Delete an element: O(log(n))
Retrieve the max-value element: O(log(n))

priority_queue<int> pq;
pq.push(4); // [4]
pq.push(2); // [2, 4]
pq.push(1); // [1, 2, 4]
pq.push(3); // [1, 2, 3, 4]
cout << pq.top() << endl; // 4
pq.pop(); // [1, 2, 3]
pq.pop(); // [1, 2]
pq.push(5); // [1, 2, 5]
cout << pq.top() << endl; // 5

// date time ****

//string datetime to struct tm
struct tm tm;
std::string s="2013/12/04 15:03:12";
if (strptime(s.c_str(), "%Y/%m/%d %H:%M:%S", &tm)) {
    int d = tm.tm_mday,
        m = tm.tm_mon + 1,
        y = tm.tm_year + 1900;
    std::cout << y << "-" << m << "-" << d << " "
              << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << endl;
}  

//struct tm to epoch time (seconds since 1970)
long long timeSinceEpoch = mktime(&tm);
cout << timeSinceEpoch << endl;

// time delta
int delta_hrs = 72001;
time_t delta_seconds = delta_hrs * 60*60;
time_t timeSinceEpoch_new = timeSinceEpoch - delta_seconds;

// get struct tm from epoch time
struct tm tm2;
memcpy(&tm2, localtime(&timeSinceEpoch_new), sizeof (struct tm));

//print date time in right format
std::cout << tm2.tm_year+1900 << "-" << setw(2) << setfill('0') << tm2.tm_mon+1 << "-" << setw(2) << setfill('0') << tm2.tm_mday << " " << setw(2) << setfill('0') << tm2.tm_hour << ":" << setw(2) << setfill('0')<< tm2.tm_min << ":" << setw(2) << setfill('0')<< tm2.tm_sec << endl;   

// permutation
#1. Permutation on a vector using built-in function, is used to permeate a vector from the starting order.
    vector<int> a={1, 3, 2};
    sort(a.begin(), a.end()); // must sort in ascending order, otherwise some permutations will be missing
    do {
        for (auto x: a) cout << x << ", ";
        cout << endl; //1,2,3;  1,3,2;  2,1,3; 2,3,1; 3,1,2; 3,2,1
    }
    while (next_permutation(a.begin(), a.end())); //next permutation larger than the previous one
    cout << "after permutation: " << endl;
    for (auto x: a) cout << x << ", "; //1, 2, 3 (back to original order)
    cout << endl;    

#2. Permutation using recursion: generate 4-digit permutations using [‘a’, ‘b’]
void permute(vector<char> a, string prefix, int tot_len)
{
    if (prefix.size()==tot_len)
    {
        cout << prefix << endl;
        return;
    }
    for (auto x: a)
    {
        string new_prefix = prefix + x;
        permute(a, new_prefix, tot_len);
    }
}
int main() {
    vector<char> a={'a', 'b'};
    permute(a, "", 3);  
}
Output: aaa, aab, aba, abb, baa, bab, bba, bbb

#3, using loop to generate permutation: generate 4-digit permutations using [‘a’, ‘b’]
# use a vector to append temporary result: {“”, “a”, “b”, “aa”, “ab”, “ba”, “bb”}
# best solution, can generate all of the 1-digit, 2 digit, 3 digit permutations
vector<char> a={'a', 'b'};
vector<string> v1;
int tot_len = 3;
v1.push_back("");
vector<string> result;
for (int i=0; i<v1.size(); i++)
{
    for (auto x: a)
    {
        string new_str = v1[i] + x;
        if (new_str.size()==tot_len) result.push_back(new_str);
        else v1.push_back(new_str);
    }
}
for (auto x: result) cout << x << endl;
Output: aaa, aab, aba, abb, baa, bab, bba, bbb


// class ***
https://www.youtube.com/watch?v=lrMaVM3eZOo

// left right two pointer strategy, O(2n)
1. Shift right pointer forward
2. If condition is satisfied, fix the right pointer, move left pointer
3. If condition is not satisfied, fixed the left pointer, move the right pointer
4. Repeat until both pointers reach the end

// prefix sum array for partial sum or partial counting
vector<int> v1 = {1, 3, 4, 2, 5};
vector<int> psa = {1, 4, 8, 10, 15};
// use pas to find partial sum
Int s1_3 = psa[2]; # sum from the 1st element to the 3rd element
Int s2_4 = psa[3]-psa[0]; # sum from from the 2rd element to the 4th element

// difference array for partial constant update
For example, original state = [1, 4, 2, 3], 
Update 1: from element 1 to 2, add 1, 
update 2: from element 3 to 4: add -1
Solution: v=[0, 0, 0, 0], 
after update 1: v1=[1, 1, 0, 0], its difference array vd1=[1, 0, -1, 0, 0]
After update 2: v2=[1, 1, -1, -1], difference array vd2=[1, 0, -2, 0, 1]
Do prefix sum on vd2, we get: v2_p = [1, 1, -1, -1, 0], trim to original length [1, 1, -1, -1]
Add v2_p to original state, v_final = [2, 5, 1, 2]
Coding solution: 1) for update 1: vd1=[1, 0, -1, 0, 0], (+1 to start-element, -1 to the one after the end-element)
2. For update 2: vd2=[1, 0, -2, 0, 1] ((-1 to start-element, +1 to the one after the end-element)
3. Prefix sum: spa = [1, 1, -1, -1, 0], trim to the length of original vector==> spa=[1, 1, -1, -1]
4. Add prefix sum to original vector: v_final = [2, 5, 1, 2]

// difference array to find how many updates applied (reverse application)
For example, original state = [1, 4, 2, 3], desired state = [2, 5, 4, 4]
How many partial update (each partial update increase 1) need to convert original state to desired state?
Solution:
delta = desired_state - original_state = [1, 1, 2, 1] (this is the array after we perform partial updates, corresponding to v2 in above example)
Difference array = [1, 0, 1, -1, -1]
positive_sum = 2, negative_sum = 2, 
num_updates = max(positive_sum, negative_sum) = 2

//difference array is used in partial update (the update is a arithmetic sequence, such as add 2, 4, 6 to 2rd, 3rd and 4th elements)
Given vector v1={1, 3, 4, 2, 5}, do update (1, 4, 2), update 1st element to 4th element by adding 2, 4, 6…., find the vector after a series of such updates.
Solution:
Assume v2={0, 0, 0, 0, 0, 0}, do update (1, 3, 2), we get v3={2, 4, 6, 8, 0, 0}, 
1. Do 1st order difference on v3, we get d1={2, 2, 2, 2, -8, 0}, 
2. Do 2rd order difference on d1, we get: d2={2, 0, 0, 0, -10, 8}
3. Do 1st Prefix Sum on d2: {2, 2, 2, 2, -8, 0}
4. Do 2rd Prefix Sum, {2, 4, 6, 8, 0, 0}
Steps 2-4 is program solution for a large size vector.

// prime related algorithms
1) how to test if a number is prime
loop to sqrt(n)
2) how to find all prime numbers up to 100?
Sieve algorithm: start from prime number, 2, 3, 5, exclude 2*2, 2*3, 2*4, 2*5 …. For prime 2, exclude 3*3, 3*4, 3*5… for prime 3, exclude 5*5, 5*6, 5*7… for prime 5
n*log(log(n))
3) how to do prime factorization?
Case 1: n = 60, loop from 2 to sqrt(n)=7
60/2=30, 30/2=15, 15/3=5, 5/5=1,
prime factors = [2, 2, 3, 5]
Cas2 2: n = 42, loop from 2 to sqrt(n)=6 (for (int i=2; i<=6; i++)
42/2=21, 21/3=7, exit until 7 is not divisible by any of [2, 3, 4, 5, 6], if 7 !=1, put 7 into prime_factors
prime factors=[2, 3, 7]

// modulo
(a + b) mod m = (a mod m + b mod m) mod m 
(a − b) mod m = (a mod m − b mod m) mod m 
(a·b) (modm)=((a mod m)·(b mod m)) mod m 
a^b mod m=(a mod m) ^b mod m 


##### Functions ###############################

// calculate: a**b % c, for example, 2**121 % 100000007
long long power_mod(long long a, long long b, long long c)
{
    if (b == 1) return a % c;
    a = a % c;
    if (b % 2 == 0)  
    {
        return (power_mod(a, b / 2, c) * power_mod(a, b / 2, c)) % c;
    }
    else 
    {
        return (power_mod(a, b / 2, c) * power_mod(a, b / 2, c) * power_mod(a, 1, c)) % c;
    }
}
// Mr. Nan’s version
long long power( long x, long n, long mod ) {   // calculate x ^ n % mod 
	if ( n == 0 ) return 1 ;      // base case
	long t = power ( x , n/2 , mod );     //calculate  x^(n/2) % mod 
	t = t * t % mod ; 
	if(n % 2 != 0)   t = t * x % mod ;
	return t;
}

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, unsigned int y, int p)
{
	int res = 1;	 // Initialize result

	x = x % p; // Update x if it is more than or
				// equal to p

	if (x == 0) return 0; // In case x is divisible by p;

	while (y > 0)
	{
	    //cout << "x=" << x << ", y=" << y << ", res=" << res << endl; 
		// If y is odd, multiply x with result
		if (y%2!=0)
			res = (res*x) % p;

		// y must be even now
		y = y>>1; // y = y/2
		x = (x*x) % p;
	}
	return res;
}


# counter-clockwise rotate a square matrix
# x: the input row id, y: input col id, a: the origin row id, b: the origin col id, n: the length of the square matrix)
# for example, clockwise rotate the element at (4, 5) along origin (1, 1) for a square matrix of size 5
pair <long long, long long> ccw_rotate(long long x, long long y, long long a, long long b, long long n)
	{
	    x = x - a;
	    y = y - b;
	    long long x2 = n - y - 1;
	    long long y2 = x; 
            x2 += a;
            y2 += b
	    return make_pair(x2, y2);
	}

# clockwise rotate a square matrix
pair <long long, long long> cw_rotate(long long x, long long y, long long a, long long b, long long n)
	{
	    x = x - a;
	    y = y - b;
	    long long x2 = y; # based on y2=x, —> x2 = y
	    long long y2 = n-1-x; 
            x2 += a;
            y2 += b
	    return make_pair(x2, y2);
	}

# find the rank, for example {2, 2, 5, 5, 4} —> ranks = {4, 4, 1, 1, 3}
vector<int> find_rank(vector<int> scores)
{
    int n = scores.size();
    vector<int> ranks(n, 0);
    vector<pair<int, int> > vec1; //{score, index}
    for (int i=0; i<scores.size(); i++)
    {
        vec1.push_back({scores[i], i+1});
    }
    sort(vec1.rbegin(), vec1.rend());
    int rank = 1;
    int prev = vec1[0].first;
    ranks[vec1[0].second-1] = rank;
        
    for (int z = 1; z < vec1.size(); z++)
    {
        if (vec1[z].first != prev) rank = z + 1;
        ranks[vec1[z].second-1] = rank;
        prev = vec1[z].first;
    }
    return ranks;
}

// count the number of subarrays with even sum
/* 
For example v1 = {4, 5, 7, 8, 9, 3}
             4   5.  7.  8.   9.   3
s=0.      1.   0.  2.  3.   1.   4.  (sum=11)
t:           0.   2. 1.   1.   4.   2
s: the number even-sum subarrays ended at i 
t: the number odd-sum subarrays ended at i 
*/
long long count_even_sum(vector<int> v1)
{
    long long tot=0, s=0;//s: the number of even-sum subarrays ended at index i
    for (long long i=0; i<v1.size(); i++)
    {
        if(v1[i]%2==0)
        {
            s = s + 1; // s+1 is the number even-sum subarrays ended at i
        }
        else
        {
            s = i-s; // i-s is the number of odd-sum subarrays ended at i
        }
        tot += s;
    }
    return tot;
}

// convert integer from other base to base 10 (base-2 number needs to be represented in string, otherwise overflow)
long long to_base10(long long b1, string num)
{
    long long b10_num = 0;
    long long p = 1;
    for (long long a = num.size() - 1; a >= 0; a--)
    {
        b10_num += (num[a] - '0') * p;
        p = p*b1;
    }
    return b10_num;
}

// convert integer from base 10 to other base
string from_base10(long long b2, long long n)
{
    string str1 = "";
    while (n != 0)
    {
        str1 += to_string(n % b2);
        n /= b2;
    }
    reverse(str1.begin(), str1.end());
    return str1;
}

// find combinations from a n-element vector
#include <bits/stdc++.h>
using namespace std;

// find all k-element combinations from n-element vector
void combinations(int ind, int k, vector <int> vec1, vector <int> &vec2)
{
    if (vec2.size() == k)
    {
        for (int a = 0; a < vec2.size() - 1; a++) cout << vec2[a] << ", ";
        cout << vec2.back() << endl;
        return;
    }
    for (int x = ind + 1; x < vec1.size(); x++)
    {
        vector <int> vec3 = vec2;
        vec3.emplace_back(vec1[x]);
        combinations(x, k, vec1, vec3);
    }
}

// find all combinations with lengths from 1 to n from n-element vector
void combinations_all(int ind, vector <int> vec1, vector <int> vec2)
{
    if (vec2.size() >0 &&  vec2.size() <= vec1.size())
    {
        for (int a = 0; a < vec2.size() - 1; a++) cout << vec2[a] << ", ";
        cout << vec2.back() << endl;
    }
    if (vec2.size() > vec1.size()) return;
    for (int x = ind + 1; x < vec1.size(); x++)
    {
        vector <int> vec3 = vec2;
        vec3.emplace_back(vec1[x]);
        combinations_all(x, vec1, vec3);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec1 = {1, 2, 3, 4}, vec2;
    int k = 3;
    //k-length combinations
    combinations(-1, k, vec1, vec2);
    // all combinations
    vec2 = {};
    combinations_all(-1, vec1, vec2);
}


/***** Ideas and condition reacts *******/
# When using recursion and got Time Limit Exception (TLE), try to use Memoization. Tips when using memoizations:
1. Get value from memo each time when you call recursion function
2. Save value to memo each time when you return
3. The recursion function must return something, cannot be void
4. The memo can be a vector or an unorded_map, and must use reference, such as unordered_map <int, int> & map1
Example: Palindromic Integer Partition, for example, input=7, output: 8 (8 ways of palindromic partitions, such as; 7=7, 7=1+5+1…)
long long find_num_palindromes(long long n, unordered_map <long long, long long> &memo)
{
    if (n == 1 || n == 0)
    {
        memo[n] = 1;
        return 1;
    }
    long long s = 0;
    for (long long x = 1; x * 2 <= n; x++)
    {
        if (memo.count(n - (x * 2))) s += memo[n - (x * 2)];
        else s += find_num_palindromes(n - (x * 2), memo);
    }
    memo[n] = s + 1;
    return s + 1;
}

# Complete search using next_permutation
For example (USACO 2019 December Bronze P3 - Livestock Lineup), 8 cows: Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, and Sue, find the alphabetically min order satisfying the given conditions, such as: 
Buttercup must be milked beside Bella
Blue must be milked beside Bella
Sue must be milked beside Beatrice
Idea: search all permutations using next_permutation, put all satisfied permutations into a vector, find the min from the result vector.
3Tips for next_permutation:
1. Sort the string or vector before using next_permuation()
2. Use do { } while (next_permuation(v1.begin(), v1.end());

# complete search among all combinations 
For example: ingredients can be chosen from {A, B, C}, complete search all combinations: {}, {A}, {B}, {C}, {A, B}, {A, C}, {B, C}, {A, B, C}, to find the one maximize a metric
Another examples, we have 3 deals, each deal can be applied once, complete search all combinations: {}, {D1}, {D2}, {D3}, {D1, D2}, {D2, D3}, {D1, D3}, {D1, D2, D3}, to find the min cost.

# When dealing with order (or position) problem, make the final order to ascending sorted, and then change the original positions relative the final positions
For example (USACO 2022 February Bronze P2 - Photoshoot 2), originally we have 5 numbers: 5 1 3 2 4, we want to get the final sequence: 4 5 2 1 3, we are allowed to move number to left. How many moves do we need?
The final positions: 1 2 3 4 5 (make it to ascending order)
The original positions are mapped to: v1= {2 4 5 3 1}
Idea: loop v1, if seeing any element > current_max, ans++, In above example, 3 < current_max (5), ans=1; 1 < current_max (5), ans=2
Final answer: 2

# partial sum array in a sequence
When the problem says keeping combining two adjacent numbers, it is a partial sum problem.
For example (USACO 2022 February Bronze P1 - Sleeping in Class)
Original sequence: 1 2 3 1 1 1
Keep combining two adjacent numbers until all elements are equal in the sequence. It essential groups the sequence into 3 groups such that each group sums to 3, e.g., (1, 2) (3) (1, 1, 1)
PSA for the original sequence: 0 1 3 6 7 8 9, 
Idea: loop PSA, find the first element (3) which is a factor of total sum (9), and then check if 1*3, 2*3, 3*3 are all in PSA, if yes, return {3, 3, 3}

# partial update in a sequence using difference array, to address Time Limit Error (TLE)
For example, original array = {0, 0, 0, 0, 0}, first add 1 in [2, 4], then add 1 in [1, 3],
difference_array = {0, 0, 0, 0, 0} 
Add 1 in [2, 4] —> difference_array = {0, 0, 1, 0, 0, -1} (ind-2 add 1, ind-5 subtract 1)
Add 1 in [1, 3] —> difference_array = {0, 1, 1, 0, -1, -1} (ind-1 add 1, ind-4 subtract 1)
Find PSA: spa = {0, 0, 1, 2, 2, 1, 0} ==> final increments for all the 5 elements = {0, 1, 2, 2, 1}







