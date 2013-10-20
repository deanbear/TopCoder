// BEGIN CUT HERE

// END CUT HERE
#line 5 "RaiseThisBarn.cpp"
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

class RaiseThisBarn
{
    public:
    int calc(string str)
    {
        int count = 0;
        for(int i = 0;i < str.size();i ++) {
            if(str[i] == 'c')
                count ++;
        }
        if(count & 1) {
            return 0;
        }
        
        if(! (count | 0)) {
            return (int)str.size() - 1;
        }
        
        int cut = count / 2;
        
        int g = 0;
        int index = 0;
        for(int i = 0;i < str.size();i ++) {
            if(g == cut) {
                index = i;
                break;
            }
            if(str[i] == 'c')
                g ++;
        }
        int final = 0;
        while(index != str.size() && str[index] != 'c') {
            final ++;
            index ++;
        }
        return final + 1;
    }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cc..c.c"; int Arg1 = 3; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arg0 = "c....c....c"; int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arg0 = "............"; int Arg1 = 11; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arg0 = ".c.c...c..ccc.c..c.c.cc..ccc"; int Arg1 = 3; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        RaiseThisBarn ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
