c++ tips:
// c++ formatter
https://techiedelight.com/tools/clike
// reference with example
https://www.cplusplus.com/reference/queue/queue/pop/


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
b = regex_replace(b, regex(“*”, “”); //remove *

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
// construct a vector from an array
int arr[4] = {16,2,77,29};
vector<int> vec (arr, arr + 4 );

// define and initialize a vector to constants
 vector<vector<int> > a1(10, vector<int>(10, 4));    // 2D vector of 10*10 with all 4
 vector<int > a2(10, 999); // 1D vector containing 10 elements of 999

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
unordered_set<string> set1;
set1.insert(str1);
cout << set1.size() << ends;


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

//merge a local vector to a global vector
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

INT_MAX 2147483647 (10e9)
LONG_MAX 2147483647 (10e9)
LLONG_MAX 9,223,372,036,854,775,807 (10e18)
double max: 10e305 (less accurate)

int a = 1000000;
long long  b = a*a; // overflow, due to operation on int
long long b = 1ll*a*a; // correct, a is promoted to long long before operation

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

// map and unordered_map ****
unordered_map<string, float> dict1 = {{"b", 12.3}};
dict1["c"] = 14.6;
dict1.insert({"g", 167.8});
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

// class ***
https://www.youtube.com/watch?v=lrMaVM3eZOo
