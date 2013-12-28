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

class WinterAndMandarins
{
public: 
    int getNumber(vector <int> bags, int K) {
    	sort(bags.begin(),bags.end());
    	int min = -1;
    	for(int i = 0;i < bags.size()-K+1;i ++) {
    		int tmp = bags[i+K-1] - bags[i];
    		if(min == -1 || min > tmp) {
    			min = tmp;
    		}
    	}
    	return min;
    }
    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {10, 20, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 10; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 7, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5, 4, 6, 1, 9, 4, 2, 7, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 1; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {47, 1000000000, 1, 74}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 27; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WinterAndMandarins ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
