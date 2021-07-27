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



