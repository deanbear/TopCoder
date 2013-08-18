// BEGIN CUT HERE

// END CUT HERE
#line 5 "InsertZ.cpp"
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
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

class InsertZ
{
        public:
        string canTransform(string init, string goal)
        {
            string tmp = "";
            for(int i=0 ;i< goal.size();i++) {
                if(goal[i] != 'z') {
                    tmp += goal[i];
                }
            }
            if(tmp == init) {
                return "Yes";
            } else {
                return "No";
            }
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "fox"; string Arg1 = "fozx"; string Arg2 = "Yes"; verify_case(0, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "fox"; string Arg1 = "zfzoxzz"; string Arg2 = "Yes"; verify_case(1, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "foon"; string Arg1 = "foon"; string Arg2 = "Yes"; verify_case(2, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "zopzoder"; string Arg2 = "No"; verify_case(3, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaa"; string Arg1 = "a"; string Arg2 = "No"; verify_case(4, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "mvixrdnrpxowkasufnvxaq"; string Arg1 = "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq"; string Arg2 = "Yes"; verify_case(5, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "opdlfmvuicjsierjowdvnx"; string Arg1 = "zzopzdlfmvzuicjzzsizzeijzowvznxzz"; string Arg2 = "No"; verify_case(6, Arg2, canTransform(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        InsertZ ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
