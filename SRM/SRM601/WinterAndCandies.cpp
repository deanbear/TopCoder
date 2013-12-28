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

class WinterAndCandies
{
public: 
    int getNumber(vector <int> type) {
    	map<int,int> typeMap;
    	int max = -1;
    	for(int i = 0;i < type.size();i ++) {
    		typeMap[type[i]] ++;
    		if(max == -1 || max < type[i]) {
    			max = type[i];
    		}
    	}
    	int k = 0;
    	int count = 1;
    	int ans = 0;
    	int pre = -1;
    	while(count <= max) {
    		k = typeMap[count];
    		if(k == 0) {
    			break;
    		}
    		if(pre == -1) {
    			ans = k;
    			pre = k;
    		} else {
    			ans += k*pre;
    			pre = k*pre;
    		}

    		count ++;
    	}
    	return ans;

    }
    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 3, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 3, 2, 5, 7, 4, 5, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 62; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    WinterAndCandies ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
