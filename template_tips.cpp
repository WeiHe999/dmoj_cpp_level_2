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

Graph editor:
https://csacademy.com/app/graph_editor/


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

// competitive programming debug techniques
Time limit exceed (TLE)
#1) The number of operations in 1 second: 10^9, therefore
1. n=15, allow O(n!), we can do permutation/combinations, 12!=0.5 * 10^9
2. n=10^9, allow O(n)
3. n=10^4, allow O(n^2)
4. n=400, allow O(n^3)
5. n=100, allow O(n^4)
6. n=10^6, allow O(n*logn) or O(n*sqrt(n) )
7. n=10^18, allow O(logn) binary search or O(sqrt(n)) prime factors
#2) try to use binary search (lower_bound, upper_bound) to deal with the big arrays (length of array > 10^9)
#3) If a function is called millions times, try to put it into main program to reduce the time
#4) in recursive function, using global variables can reduce the execution time, for example: USACO 2022 US Open, Bronze Problem 3. Alchemy 
# if there are many lines of output, use “\n”, do not use cout << endl; because cout<< endl causing flushout leading to more time.

Segmentation error
#1) It may be caused by accessing out-of-bound index, for example, vector<int> a={1, 2, 3}; int b = a[10];
#2) It may caused by divided by 0

Memory error
#1) It may be caused by allocating a huge vector or 2D vector that consumes a huge memory

Debug
#1) If you see wrong answer with output “123”, you can get the input of the problem in your code:
If (ans==123) cout << input_int << Lendl;

// double and long double
Tips: 
1)# long long a=10; double b=a*1.0;//1.0 is a double
2)# long long a=10, long double b = a*1.0L; // 1.0L is a long double
3) when converting long long to decimal for decimal operation and then convert result back to long long, use: double long
    long long a=10000000000000001; //16 zeros
    double b = a * 1.0; //double has 15 precision, 1.0 is a double
    long long c = (long long) b;
    long double d = a*1.0L; // L means double long
    long long e = (long long) d;
    cout << a << endl; //10000000000000001 correct
    cout << c << endl; //1000000000000000 wrong
    cout << e << endl; //10000000000000001 correct
4)# round down and round up for long long, we can use: long int lroundl (long double x); DO NOT use: double floor (double x);
    long long f = lroundl(a*1.5L-0.5);
    cout << f << " is equal to: " << (long long) (a*1.5L) << endl; 
//15000000000000001 is equal to: 15000000000000001 correct
cout << (long long) floor(a*1.5) << endl; //15000000000000000 wrong

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

// digit string manipulations
// construct integer string: 100000
string str1(6, '0');
str1[0] = ‘1’;
// convert 23 to 5-digit palindrome
string p1 = ’234’
string p2 = p1;
reverse(p2.begin(), p2.end());
string palindrome = p1 + p2.substr(1); //“234” + “32” = “23432”
// convert string to long long or int
String a = “1234”
long long b = stol(a);
Int c = stoi(a);

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
cout << m.begin()->first << endl;

 
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

// tree and binary tree
# the difference between a complete binary tree and full binary tree:
A full binary tree: each node can have either aero children or 2 children
A complete binary tree: each node can have zero, one left, or two children.
# the properties of complete binary tree and full binary tree
1), nodes are labelled from1 1, 2, 3, … in horizontal order
2), node k’ s left child is: 2*k, right child is 2*k+1
3), node k’s parent is k//2
4), the depth of the tree if log2(n), n is the number of nodes
5), we can use an array to represent a complete/full binary tree

## level order traversal
In level order traversal of complete binary tree, the index of node m has left child at index 2*m, right child at 2*m+1 (index starting from 1)

** Find factor for an integer m
Loop k from 1 to sqrt(m), if m%k==0, k and m/k are factors, O(sqrt(m))

** find factors for all integers from 1 to m:
Use Sieve algorithm, O(m*logm)
Loop k from 1 to m step size=k, 
When k=1, v1[1]++, v1[2]++
When k=2, v1[2]++, v1[4]++…..


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

# function to count number of ways for letter arrangements, for example, AAB, there are 3!/2! Permutations
long long factorial(long long n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
long long letter_arrangements(string str1)
{
    unordered_map <char, long long> m1;
    for (long long x = 0; x < str1.size(); x++) m1[str1[x]]++;
    long long s = factorial(str1.size());
    for (auto a : m1) s /= factorial(a.second);
    return s;
}


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

# recursive function to search if a word is in a grid of letters without visiting a cell twice, refer to: ECOO '12 R1 P4 - Boggled
# argument: d is the starting point (x1, y1), table is the grid, word is the target word
bool check_existence(pair <int, int> d, vector <vector <char> > table, string word, int ind, 
set <pair <int, int> > &visited)
{
    if (ind == word.size())
    {
        return true;
    }
    vector <pair <int, int> > check = {{d.first - 1, d.second - 1}, {d.first - 1, d.second}, {d.first - 1, d.second + 1}, {d.first, d.second - 1},
    {d.first, d.second + 1}, {d.first + 1, d.second - 1}, {d.first + 1, d.second}, {d.first + 1, d.second + 1}};
    for (auto e : check)
    {
        if (e.first >= 0 && e.first < 4 && e.second >= 0 && e.second < 4)
        {
            if (table[e.first][e.second] == word[ind] && !visited.count(make_pair(e.first, e.second)))
            {
                set <pair <int, int> > visited1 = visited;
                visited1.insert({e.first, e.second});
                if (check_existence(e, table, word, ind + 1, visited1)) return true;
            }
        }
    }
    return false;
}
# main program to use check_existence, d is a pair representing the starting coordinates
set <pair <int, int> > visited1 = {{d.first, d.second}};
if (check_existence(d, table, word, 1, visited1))
{
    found = true;
    break;
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

// function to find all factors for an integer, complexity = O(sqrt(n))
unordered_set<int> find_factors(int num)
{
    unordered_set<int> s1;
    for (int i=1; i<=sqrt(num); i++)
    {
        if (num % i == 0)
        {
            //perfect square number
            if (num == i*i) s1.insert(i);
            else
            {
                int k = num/i;
                s1.insert(i);
                s1.insert(k);
            }
        }
    }
    return s1;
}

// function to construct palindrome numbers for a given length n
void construct_palindroms(int n, vector<long long> &vec1)
{
    //lower=1000, upper=9999
    string lower_str(n, '0'), upper_str(n, '9');
    lower_str[0] = '1';
    // extracy the first-half digits
    int half_len = ceil(n*1.0/2);
    long long start = stol(lower_str.substr(0, half_len));
    long long end = stol(upper_str.substr(0, half_len));
    //loop 
    for (long long i=start; i<=end; i++)
    {
        //odd
        string p1, p;
        p1 = to_string(i);
        reverse(p1.begin(), p1.end());
        if (n % 2 == 1) p = to_string(i) + p1.substr(1);
        //even digits
        else p = to_string(i) + p1; 
        if (p[0]!='0') vec1.push_back(stol(p));
    }
}

// function to enumerate all outcomes for N games
void permutation_outcomes(string prefix, int current, int len, vector<string> &result)
{
    if (prefix.size() == len)
    {
        result.push_back(prefix);
        return;
    }
    vector<char> r = {'W', 'L', 'T'};
    for (int i=0; i<3; i++)
    {
        string new_prefix = prefix;
        new_prefix += r[i];
        permutation(new_prefix, current+1, len, result);
    }
    
}


/***** Ideas and condition reacts *******/
# memoization with recursion to deal with TLE
When using recursion and got Time Limit Exception (TLE), try to use Memoization. Tips when using memoizations:
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

##### Complete search using permutation
For example (USACO 2019 December Bronze P3 - Livestock Lineup), 8 cows: Bessie, Buttercup, Belinda, Beatrice, Bella, Blue, Betsy, and Sue, find the alphabetically min order satisfying the given conditions, such as: 
Buttercup must be milked beside Bella
Blue must be milked beside Bella
Sue must be milked beside Beatrice
Idea: search all permutations using next_permutation, put all satisfied permutations into a vector, find the min from the result vector.
3Tips for next_permutation:
1. Sort the string or vector before using next_permuation()
2. Use do { } while (next_permuation(v1.begin(), v1.end());

Example-2: in CCC '13 S3 - Chances of Winning, for example, there are 3 games, each game can be W (win), L (loss), T (tie), there are 3*3=9 outcomes, such as: WWW, WLT, WTT, we can use permutation to list all outcomes, refer the function: permutation_outcomes

# complete search among all combinations 
For example: ingredients can be chosen from {A, B, C}, complete search all combinations: {}, {A}, {B}, {C}, {A, B}, {A, C}, {B, C}, {A, B, C}, to find the one maximize a metric
Another examples, we have 3 deals, each deal can be applied once, complete search all combinations: {}, {D1}, {D2}, {D3}, {D1, D2}, {D2, D3}, {D1, D3}, {D1, D2, D3}, to find the min cost.

##### Positions a sequence problems:
# example - 1: from original positions to the final positions
When dealing with order (or position) problem, make the final order to ascending sorted, and then change the original positions relative the final positions
For example (USACO 2022 February Bronze P2 - Photoshoot 2), originally we have 5 numbers: 5 1 3 2 4, we want to get the final sequence: 4 5 2 1 3, we are allowed to move number to left. How many moves do we need?
The final positions: 1 2 3 4 5 (make it to ascending order)
The original positions are mapped to: v1= {2 4 5 3 1}
Idea: loop v1, if seeing any element > current_max, ans++, In above example, 3 < current_max (5), ans=1; 1 < current_max (5), ans=2
Final answer: 2

# example - 2: position shift in cycles
In this type of problem, each digit in the sequence is moved to another position, and such operation is performed k times (k is very big), use a graph to represent the transition cycles.
For example (SAC '22 Code Challenge 4 Junior P4 - Obligatory Permutation Problem): the original permutation = {5 3 2 1 4}, and it will be performed 3 times (I.e., index-1 (5) is moved to index-5, index-2 (3) is moved to index-3). The idea to solve this type of the problems consists of 2 steps:
Step-1: find position-change cycles, cycle-1: 1—>5—>4—>1 len=3, cycle-2: 2—>3—>2 len=2
Step-2: move each digit in each cycle, for example in cycle 1: ind-1 is moved forward 100%3=1 steps to ind-5, in cycle 2: ind-2 is moved forward 100%2=0 steps to ind-2.
Another example (USACO 2020 February Bronze P3 - Swapity Swap) is to perform M digit reverse K times, for example, original sequence = {1, 2, 3, 4, 5, 6}, we perform 1000 times of digit reverse operation (reverse [1, 4], then reverse [2, 5]), reverse [1, 4] produces {4, 3, 2, 1, 5, 6}, then reverse [2, 5] produces {4, 3, 5, 1, 2, 6}
Step 1: find the position change cycles: first find the routing dict from mapping the original and final position: {4:1, 3:2, 5:3, 1:4, 2:5, 6:6}, then find the cycles: cycle-1: 1—>4—>1 len=2, cycle-2: 2—>5—>3—>2 len=3, cycle-3: 6—>6 len=1
Step-2: operations=1000, in cycle-1: ind-1 is moved forward 1000%2=0 steps to ind-1, in cycle-2: ind-5 is moved forward 1000%3=1 steps to ind-2 
Step-3: final sequence: {1, 2, 5, 4, 2, 6}, code is available at GitHub, data_structure/position_shift_in_a_sequence.cpp

# Method-3: keep track (pre_node, next_node) for each node
For example: in the problem DMOPC '21 Contest 7 P2 - Knitting Scarves, there are a sequence {1, 2, 3, 4, 5, 6} we move elements from 3 to 5 to the right of 1, we use unordered_map <int, pair<int, int> > m1 to track the pre_node and next_node, such as {0: (-1, 1), 1: (1, 2), 2: (1, 3)…}, when we move a segment of elements, we just need to change the pre_node/next_node for the boundary nodes, for example, if we move segment from 4 to 5 to the right of 1, we need to change the pre_node or next_node for the 6 boundary nodes (1, 2, 3, 4, 5, 6)

##### partial sum array in a sequence
When the problem says keeping combining two adjacent numbers, it is a partial sum problem.
For example (USACO 2022 February Bronze P1 - Sleeping in Class)
Original sequence: 1 2 3 1 1 1
Keep combining two adjacent numbers until all elements are equal in the sequence. It essential groups the sequence into 3 groups such that each group sums to 3, e.g., (1, 2) (3) (1, 1, 1)
PSA for the original sequence: 0 1 3 6 7 8 9, 
Idea: loop PSA, find the first element (3) which is a factor of total sum (9), and then check if 1*3, 2*3, 3*3 are all in PSA, if yes, return {3, 3, 3}

Example-2: Multiple of K
Tip: for multiple of k problems, we shall use remainders
Problem: given an array {3 5 1 6 2 14}, find the max length of subarray with sum of multiple of 7
Idea: step-1: find PSA: {0, 3, 8, 9, 15, 17, 31}, step-2: find remainder of 7 of PSA: {0, 3, 1, 2, 1, 3, 3}, step-3: created frequency map: {0: [0], 1: [2, 4], 2: [3], 3: [1, 5, 6]}
Based on the frequency map, we can find the max length subarray, which is 6-1=5; we can also find the number of subarrays divisible by 7: for remainder 1, we 2-choose-2 = 1, for remainder 3, we have 3-choose-2=3, total number = 4

###### partial update in a sequence using difference array, to address Time Limit Error (TLE)
For example, original array = {0, 0, 0, 0, 0}, first add 1 in [2, 4], then add 1 in [1, 3],
difference_array = {0, 0, 0, 0, 0} 
Add 1 in [2, 4] —> difference_array = {0, 0, 1, 0, 0, -1} (ind-2 add 1, ind-5 subtract 1)
Add 1 in [1, 3] —> difference_array = {0, 1, 1, 0, -1, -1} (ind-1 add 1, ind-4 subtract 1)
Find PSA: spa = {0, 0, 1, 2, 2, 1, 0} ==> final increments for all the 5 elements = {0, 1, 2, 2, 1}

###### embedded string processing using string replacement
This method is an alternative way to the recursive method. For example (CCC '05 J5 - Bananas), a valid A-word is defined as: 1# “A” is a A-word, 2#, “ANA” is a A-word, 3# “A”+”N”+another-A-word is also a A-word. A, ANA, ANANA are all valid A-words. How to write a program to check if an input word is a A-word?
Idea: replace “ANA” with “A” repeatedly, if the final string==“A”, then it is a valid A-word.
            while (true)
            { if(word.find("ANA")!=-1) word = regex_replace(word, regex("ANA"), "A");
		else break;}

###### Reconstruction problem - to reconstruct a sequence
For example (An Animal Contest 6 P1 - Workout Routine), given a N and a K, reconstruct an array of N such that each element is between 0 and 10**9 and the sum is divisible by K.
Idea: convert the problem of finding N integers to finding one integer
construct the first N-1 integers to be 1, 2, 3, … K-1, then find the K-th number to satisfy both conditions (<10**9 and sum % K==0)

Second example (DMOPC '21 Contest 3 P2 - Weak Data): given an input N, generate an array with N even subarrays. 
Idea: 1) the array can be: 1, 2, 1, 2, 2, 2, 1,…, 2) convert the problem to find x  (the number of 2 in the array), 3) using prefix sum array to find the judge_function(), which is the function used to verify if the generated array is correct or not.

###### digit construction problems
P-1: construct the search space by digit construction
For example (Good Number), a good number of d digits is defined as the number with at least (d-1) identical digits, for example (700, 717, 777 are all good numbers), find the min good number starting from a specified number such as 1234, the answer is 1311.
Idea: do complete search on the solution space which is formed by digit construction. Let’s set the first digit to be 0, 1, 2, 3, …. Or 9, and the remaining 3 digits are set to identical from (000, 111, 222, 333, 444, 555, …, 999), and then do the same to set the second digit to be 0, 1, 2, …9, and the remaining (1st, 3rd, 4th digits) to be 000, 111, 222,….. The solution space: 0000, 0111, 0222, …., 1000, 1111, 1222, 1333, …, 9000, 9111,…, 9999, 0000, 1011, 2022, 3033, …, 0100, 1111, 2122, … (we can remove those which starts with 0)

P-2: palindrome number construction
For example (Palindromic Numbers), if we want to construct all palindrome numbers in the range [123, 989], we can extract the first half digits and then loop them, the second half digits are reversed from the first half digits. Loop from 12 to 98, we can construct palindromes: 121, 131, 141, 151, ……, 979, 989, but we need to check the first and the last palindrome if they are in the range. (Refer to function: construct_palindroms(int n)

If we just want to count how many palindromes in the range [123, 989], 
Simple method: loop from 1 to 98, for each number, construct 2 palindromes, for example, 8—> 88 and 8; 124—> 12421 and 124421, for each constructed palindrome, if it is in the specified range, cnt ++;

###### Multiple/factors problems in an array (some elements are multiple of other element)
Method-1: Sieve algorithms O(N log (log N)) ~= O(N) 
For example (pair of multiples: given an array: 16 11 6 1 9 11, find how many pairs of multiples, there are 7 pairs (indicated by index (I, j): (1, 4), (2, 4), (3, 4), (5, 4), (6, 4), (2, 6), (6, 2)
Idea of Sieve algorithms:
Step-1: create frequency vector of size 17 vec1: {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 2, 0, 0, 0, 1}
Step-2: loop from 0 to 17: if vec1[k]>0, cnt += vec1[k]*(vec1[k]-1) // pairs with the elements of the same value
Step-3: Sieve algorithm, for k, check multiple of k: 2*k, 3*k, 4*k, 5*k, if vec1[m*k]>0, cnt += vec1[k]*(vec1[m*k]) //pair with elements of different value
Method-2: factorization O(sqrt(N))
For example (pair of multiples: given an array: 16 11 6 1 9 11, find how many pairs of multiples, there are 7 pairs (indicated by index (I, j): (1, 4), (2, 4), (3, 4), (5, 4), (6, 4), (2, 6), (6, 2)
Idea:
Step 1: find the unordered_map<int, int> freq={1: 1, 6: 1, 9: 1, 11:2, 16: 1}
Step 2: for each element, find factors (O(sqrt(n)) for example, 11 has factors {1, 11}, 
Step 3: for each factor {1, 11}, 1 has occurrence of 1, we can make a pair {1, 11}, 11 have occurrence of 2, we can make {11, 11}, {11, 11}, but we need to subtract the second {11, 11} since it a pair with itself.

###### Grid problem
#1: Method-1: using unordered_map <int, int> to records the points horizontally, vertically, or left-diagonally, or right-diagonally
Availability for N*N grid (queen attack on chess board)
row_availability = vector<int> row_availability(N, 0);
col_availability = vector<int> col_availability(N, 0);
left_diagonal_availability = vector<int> col_availability(2*N-1, 0);
// check if a point (r, c) is available at left diagonal or not where r>=0, c>=0, for example (0, 2)
if (left_diagonal_availability(r+c)==0) count << “available” << endl;
right_diagonal_availability = vector<int> col_availability(2*N-1, 0);
// check if a point (r, c) is available at right diagonal or not where r>=0, c>=0, for example (0, 2)
if (left_diagonal_availability(r+n-1-c)==0) count << “available” << endl;
Better way using unordered_map <int, int> row, col, dia_left, dia_right; example COCI '14 Contest 5 #3 Traktor 

#2 Method-2: bottom-up dynamic programming
Define states (x, y, state), fill up all states in the grid. 
Example-1: DMOPC '21 Contest 7 P1 - Chika Grids
Fill up each cell based on top-left cells and/or bottom right cells.
Example-2: CCC '22 J5 - Square Pool
Fill up each cell (the max square) based on the max square ended at the top cell and the max square ended at the left cell.

In some cases, the state can be 5-D such as (x, y, p, s, t) Github: dynamic_programming/bottom_up_4d_states_grid_travel.cpp
Example: 
find the number of ways to travel from (0,0) to (N, N) with obstacles (e.g., haybales) in some cells with constraint on max number of turns
input format:
	1 # test case
	4 3 # grid 4*4, max number of turns = 3
	...H
	.H..
	....
	H...
Define state matrix: dp[r][c][k][f] represent the number of ways ending at (r, c) with k turns and facing f, facing 0 means toward-east, facing 1 means toward-south

#3 Method-3: embedded loop on all internal points (if the number of points is less than 2000)
Example-2: CCC '22 J5 - Square Pool
Idea: loop through every 2 points, use the two points as the left vertical boundary and right vertical boundary, sort all the points inside the boundary, then find the gap between two consecutive inside points, get the max gap

#4 search for a word from the grid
For example: ECOO '12 R1 P4 - Boggled,
For example, search ENGLISH from the 4*4 letter grid
Idea: 1) use unordered_map to record the coordinates of each letter in the grid, 2) loop for all cells with letter E, 3) use recursive method to search all possible path starting from E, 4) there are maybe more than one N in the grid, need to try every path, 5) not allowed to visit the same cell twice, need to use a set to record all visited cells, refer to function: check_existence

#5 Grid travel path
CCC '05 J4 - Cross Spiral
Idea: You have two directions: UP and DOWN, start from DOWN, when you go DOWN, your priority is (right—>down—> left), which means if you can go right, do it, else if you can go down, do it, else if you can go left, do it. If you cannot go any of right/down/left, change you direction to UP, when UP, your priority is (left—>up—>right), If you cannot go any of left/up/right, change your direction to DOWN.

###### Number theory
Example-1 DMOPC '20 Contest 4 P1 - Missing Numbers: Given 2 integers a and b, find the number of pairs of integers (x, y) where 0<x<y<=b) that satisfies x+y=a. For example, a=6, b=5, we can have pairs (2, 4), (1, 5). 
Idea: 
x+y=a and x<y —> a/2 < y < a and y<=b —> a/2 < y <= min(a-1, b), so the number of pairs is: min(a-1, b) - a/2. For example a=6, b=5, the number of pairs = min(6-1, 5) - 6/2 = 5-3=2 (1, 5) and (2, 4)

Example-2: Diophantine linear equations DMOPC '21 Contest 9 P1 - Board Numbers
This kind of problem can be formulated into n-1 linear equations, aiming to find n variables, the problem asks you how many solutions available. For example you have 4 positive integers satisfying x1+x2=5, x2+x3=4, x3+x4=3, find how many solutions available. 
Idea: find the number of possible solutions for x1, the idea is to narrow down the range for x1,
1. x1+x2=5 —> x2=5-x1 —> 1<= x1 <=4
2. x2+x3=4—>x3=4-x2=4-(5-x1)=x1-1 —> 2<=x1 < inf
3. x3+x4=3 —> x4 = 3-x3 = 3-(4-5+x1)=5-4+3 - x1 ==> 1<=x1 <=3 
Put together, we have 2<=x1<=3, so x1 has 2 solutions

Example-3: GCD problems: Max GCD
Given an array [12 15 18], what is the max GCD of all numbers if one of them is replaced to any number.
Key point 1: gcd(a, b, c) = gcd(a, gcd(b, c))
Key point 2: given [a, b, c], max gcd after replacing c is equivalent to max gcd after removing c
Key point 3: prefix gcd and postfix gcd help to reduce time, [a1, a2, a3, a4], we can calculate prefix gcd = [a1, gcd(a1, a2), gcd(a1, a2, a3), gcd(a1, a2, a3, a4)], and postfix gcd = [gcd(a1, a2, a3, a4), gcd(a2, a3, a4), gcd(a3, a4), a4], with prefix and postfix GCDs, we can quickly calculate gcd of [a1, a2, a4] (removing a3) as: gcd( gcd(a1, a2), gcd(a4) ) where gcd(a1, a2) can be obtained from prefix GCDs and gcd(a4) can be obtained from postfix GCDs.

###### binary flapping problems
# Example-1: a=“10001000001111000001”, you can flip any substring from the front, what is min number of flips you need to make the string to be all 1’s. 
Idea: 1) simply the string to 1010101, since flip 00000 is equivalent to flip 0, 2) drop the last 1’s since we do not need to change them, then the string is changed to 101010, 3) we need 6 flips (=len(str)) to get all 1’s: flip-1: 001010, flip-2: 111010, flip-3: 000010, flip-4: 111110, flip-5: 000000, flip-6: 1111111
# example-2 USACO 2022 US Open, Bronze Problem 1. Photoshoot: 
given string: GHHGHHGHGGGHHG, you can reverse the even-length substring starting from the front, what is the min number of reverses to get max number of G in the even positions.
Idea: represent GH to F(false), HG to T (true), GG or HH to ., the new string: FT.F.FT, then simplify it to: FTFT, drop the last T, get: FTF, you need 3 reverses: R-1: TTF, R-2: FFF, R-3: TTT
# Example - 3: you have 26 lights which are originally ON, starting from 1, you toggle every light, and then start from 2, you toggle the even-number lights, and then from 3, you toggle the lights which is multiple of 3, and so on, finally how many lights are ON?
Idea: for the 8-th light, 8 has factors of 1, 2, 4, 8, so it will be toggled 4 times, finally OFF, for the 9-th light, 9 has factors of 1, 3, 9 (odd number of factors), finally ON. So, only the number with odd number of factors will be ON finally. Only perfect square numbers have odd number of factors. From 1 to 26, there are 5 square numbers: 1, 4, 9, 16, 25. So the answer is: int( sqrt(26)).

###### String problems
Example-1: recursively remove a substring in O(n) COCI '13 Contest 5 #3 Eksplozjia
For example (using stack technique), str1=“kababcc”, bomb_str=“abc”, 
Idea: let str2=“”, loop str1,  append char to str2, if str2.substr(str1.size()-bomb_str.size())==bomb_str, pop_back bomb_str from str2 (do not update str2 by: str2 = str2.substr(0, str1.size()-bomb_str.size()), because str2 is much longer than bomb_str)

Example-2: USACO 2022 US Open, Silver Problem 3. COW Operations
The string contains only three chars, C, O, W, for example COWOCWCO, you can simplify the string using 2 rules: 1) double chars can be eliminated, 2) any char can be replaced with the other two chars in either other, for example, O can be replaced with CW or WC. So, COWOCWCO can be simplify to be: W. Actually, COWOCWCO is equivalent to: CCCOOOWW—>CO—>W,. In other words, it is only dependent on the counts for each char: {C: 3, O: 3, W: 2}, any event counts can be eliminated to 0, any odd counts can be reduced to 1. Therefore: after simplification, we will have  {C: 1: O: 1, W: 0}, CO can be further simplified to W.

Example-2: string processing using stack Bob's Expression Evaluation
For example, evaluate prefix expression: * / 5 2 + 2 3
Idea: reverse it to postfix expression: 3 2 + 2 5 / *, scan the string, if it is an digit, push it into a stack, if it is an operator, pop two numbers from stack, do the computation and then push the result back to the stack (pay attention to: which one the first operand and which is the second operand, in this example, the fist pop is the first operand, the second pop is the second operand)

Example-2a: string processing using stack DMOPC '21 Contest 9 P2 - String Puzzle
Problem: find is stringA (caabdfgg) can be convert to string B (efh) by merging two consecutive chars into a higher char (for example, ‘aa’==> ‘b’, but cannot convert ‘ZZ’
Idea: use stack and two pointers, ‘c’ < ‘e’, push ‘c’ into stack, ‘a’ is not equal to ‘c’, push it into stack, ‘a’ is equal to stack.top(), pop stack and push in ‘b’, ‘b’ is equal to stack.top(), pop ‘b’, convert to ‘c’, repeat until  str_a[I]==str_b[j] && stack.isempty(), i++, j++ 

###### Binary search to find the answer (if the question asks an integer as the output)
Example-1: fins the squared root of 100 by not using sqrt function with precision 1e-3.
Idea: set left=0, right=100, so mid=50, 50^2>100, so we set left=0, right=50, mid=25, 25^2>100, set left=0, right=25,… until right-left < 1e-3
Example-2: USACO 2022 US Open, Bronze Problem 3. Alchemy
Idea: we can set left=0, right=10e6, k=(left+right)/2, check if we can make k metal N, we need to have a function: bool check() to check if we can maker k metal N. We keep guessing until right==left.
Example-3: Largest Minimum Distance
Idea: there are 5 seats, numbered as {1, 2, 4, 8, 9}, 3 students sit 3 of 5 seats, what is the max min distance between any two students? The idea is to guess the answer in [1, 9], we first guess 5 if it does not work, we then guess (1+4)/2=2, until left>right.
Example-4: WC '15 Finals S2 - Hydration
Problem: 4 cows with ordered heights: [10, 13, 13, 24], a cow of height 10 can drink water in troughs of height int he range [10-5, 10], 4 troughs with ordered heights: [8, 14, 20, 22], each cow drinks water for 1 min, what is the min time for all cow to drink water? Output -1 if impossible.
Idea: each trough is a serving counter with a queue, we want to find the min of max-queue-length . Use binary search, lo=1, hi=4, mid=2, then use two-pointer to check if 2 works or not, when trough height is 8, cow 1 and 2 can be served, cow 3 cannot be served because the service capacity is 2; when tough is 14, cow 3 cannot be served, failed. We set lo=3, hi=4, mid=3, it works. The answer is 3.
Example-5: to solve double number problem TLE '17 Contest 7 P3 - Countless Calculator Computations
Problem: given x^(x^(x^(x…))) = 2, find x with an absolute error of 10^(-5)
Idea: binary search x, with the step size set to 10^(-6), initially set low=1, high=2, try mid=1.5, if  abs(x^(x^(x^(x…))) - 2) < 10^(-6), break, else if 1.5 is too high, change high = 1.5 - 10^(-6)

###### Tree problems:
Example-1: DWITE '12 R1 #4 - Trick or Tree'ing
Ideas: 1) Binary tree with n nodes have n-1 edges, 2) string from root, you need to travel 2*number_edges to visit all nodes and then return back to the root, 3) starting from the root, the min number of edges that he need to travel to visit all the nodes is that he finally stay at the farthest leaf, then the number of edges to travel is: 2*number_of_edges - depth, 4) from a string (((1, 2) (3, 4)), 5), how do we find the number of nodes and the height of the binary tree, the number of nodes = number_of_( + number_of_digits, (e.g., 4 + 5=9), the depth is the highest level of (e.g., 3), so the number of edges to travel starting from root to visit all nodes = 2*(9-1) - 3 = 13

##### Interval problems
This category gives a series of intervals: [(1, 3), (4, 7), (6, 9), (12, 15)], and ask you to find: 1) combine overlapped intervals, 2) search a query interval in which given interval, for example, interval [5, 7] is in interval (4, 7), need to use lower_bound
Example-1: SAC '22 Code Challenge 5 P4 - Querying Intervals
Problem: given a series of intervals [(-5, 4), (7, 9), (10, 14), (16, 19)], determine if all integers in the interval [8, 10] fall within at least one of the given intervals.
Idea: step-1) combine overlapped intervals into a big interval, [(-5, 4), (7, 14), (16, 19)], since we may combine 2 or more consecutive intervals into a big interval, we use stack to do it, always try to combine the current interval with the stack top interval. Step-2): search is interval [8, 10] falls within one big interval, the method is to first construct vector_upper_bounds = {4, 9, 19}, and then lower_bound search 10, locate interval (7, 14), and then verify if interval [8, 10] is within (7, 14)

##### sliding window problem
This category usually need to find the sum of the numbers in the sliding window, we just need to get the sum for the first window, denoted as s1, when the sliding window move forward by one unit, s2=s1 + new_number - dropped_number
Example-1: ICPC PACNW 2016 C - Cameras
Problem: given a sequence; {0, 0, 1, 0, 0, 1, 0, 0, 0, 1}, how many numbers need to be changed from 0 to 1, such that every consecutive 3 numbers has num >= 2.
Idea: step-1, deal with the first window [0, 0, 1], we need to fill the second to make it to: [0, 1, 1], and then we move forward one unit at a time, for the 2rd window, we drop v[0]=0 and add v[3]=0, the sum is unchanged, for the third window, we drop v[1]=1 and add v[4]=0, the sum is reduced by 1 to 1, so we need to fill v[4] to 1.
