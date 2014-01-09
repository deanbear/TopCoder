#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

class MiddleCode
{
public: 
    string encode(string s) {
    	string t = "";
    	while(s.size() > 0) {
    		string tmp;
    		if(s.size() % 2) {
    			for(int i = 0;i < s.size();i ++) {
    				if(i != s.size() / 2)
    					tmp += s[i];
    				else
    					t += s[i];
    			}
    		} else {
    			int c = s[s.size()/2] < s[s.size()/2 -1] ? s.size()/2 : (s.size()/2 -1);
    			for(int i = 0;i < s.size();i ++) {
					if(i != c)
						tmp += s[i];
					else
						t += s[i];
				}
    		}
    		s = tmp;
    	}
    	return t;
    }
    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "word"; string Arg1 = "ordw"; verify_case(0, Arg1, encode(Arg0)); }
	void test_case_1() { string Arg0 = "aaaaa"; string Arg1 = "aaaaa"; verify_case(1, Arg1, encode(Arg0)); }
	void test_case_2() { string Arg0 = "abacaba"; string Arg1 = "caabbaa"; verify_case(2, Arg1, encode(Arg0)); }
	void test_case_3() { string Arg0 = "shjegr"; string Arg1 = "ejghrs"; verify_case(3, Arg1, encode(Arg0)); }
	void test_case_4() { string Arg0 = "adafaaaadafawafwfasdaa"; string Arg1 = "afawadafawafaafsadadaa"; verify_case(4, Arg1, encode(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    MiddleCode ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
