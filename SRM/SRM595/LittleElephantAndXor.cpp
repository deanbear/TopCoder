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

class LittleElephantAndXor
{
public: 
	bitset<32> A_;
	bitset<32> B_;
	bitset<32> C_;
	long long dp[40][2][2][2];

    long long getNumber(int A, int B, int C) {

    	memset(dp,-1,sizeof(dp));

    	bitset<32> a(A);
    	bitset<32> b(B);
    	bitset<32> c(C);

    	A_ = a;
    	B_ = b;
    	C_ = c;

    	long long ans = dfs(31,0,0,0);

    	return ans;
    }

    long long dfs(int pos,int statusA,int statusB,int statusC) {
    	long long subAns = dp[pos+1][statusA][statusB][statusC];
    	if(subAns != -1) {
    		return subAns;
    	}
    	if(pos == -1) {
    		dp[pos+1][statusA][statusB][statusC] = 1;
    		return 1;
    	}
    	subAns = 0;
    	for(int i = 0;i < 2;i ++) {
    		if(statusA > 0 || (i <= A_[pos])) {
    			for(int j = 0;j < 2;j ++) {
    				if(statusB > 0 || (j <= B_[pos])){
    					for(int k = 0;k < 2;k ++) {
    						if(statusC > 0 || (k <= C_[pos])) {
    							if((i^j) == k) {
    								subAns += dfs(pos-1,
											(statusA > 0 || (i < A_[pos]))?1:0,
											(statusB > 0 || (j < B_[pos]))?1:0,
											(statusC > 0 || (k < C_[pos]))?1:0);

    							}
    						}
    					}
    				}
    			}
    		}
    	}
    	dp[pos+1][statusA][statusB][statusC] = subAns;
    	return subAns;
    }
    
    

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 3; long long Arg3 = 20LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 57LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 774; int Arg1 = 477; int Arg2 = 447; long long Arg3 = 214144LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 500000000; long long Arg3 = 468566946385621507LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    LittleElephantAndXor ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
