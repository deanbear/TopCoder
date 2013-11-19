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

class FoxAndSightseeing
{
public: 
    int getMin(vector <int> position) {
    	int origin = 0;
    	for(int i = 0;i < position.size() - 1;i ++) {
    		origin += abs(position[i] - position[i+1]);
    	}

    	int ans = -1;
    	for(int i = 1;i < position.size() - 1;i ++) {
    		int pre = abs(position[i-1] - position[i]) + abs(position[i] - position[i+1]);
    		int now = abs(position[i-1] - position[i+1]);
    		int mix = origin - pre + now;
    		if((ans != -1 && ans > mix) || ans == -1) {
    			ans = mix;
    		}
    	}
    	return ans;
    }
    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 4, -1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { int Arr0[] = {-2, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { int Arr0[] = {100, -100, 99, -99}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 199; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { int Arr0[] = {74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 836; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { int Arr0[] = {2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 535; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndSightseeing ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
