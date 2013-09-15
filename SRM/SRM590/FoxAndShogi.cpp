// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndShogi.cpp"
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

class FoxAndShogi
{
        public:
        const int MOD = 1000000007;
        int differentOutcomes(vector <string> board)
        {
            int width = (int)board[0].size();
            int length = (int)board.size();
            long long dp[55][55];
            int bd[55][55];
            int amount[55];
            memset(bd, 0, sizeof(int)*55*55);
            for(int i = 0;i < width;i ++) {
                for(int j = 0;j < length;j ++) {
                    if(board[j][i] == 'U') {
                        bd[i][j+1] = 1;
                    }
                    if(board[j][i] == 'D') {
                        bd[i][j+1] = -1;
                    }
                }
            }
            long ans = 1;
            
            for(int i = 0;i < width;i ++) {
                int count = 0;
                int mark;
                
                memset(dp,0,sizeof(long long)*55*55);
                memset(amount,0,sizeof(int)*55);
                
                for(int j = 1;j <= length;j ++) {
                    if(bd[i][j] == 1 || bd[i][j] == -1) {
                        count += 1;
                        amount[j] = count ;
                    }
                }
                mark=0;
                for(int j = 1;j <= length;j ++) {
                    if(bd[i][j] == 1) {
                        int ct = amount[j];
                        int k;
                        for(k = j; k > mark && bd[i][k] != -1;k --) {
                            dp[ct][k] = 1;
                        }
                        mark = k+1;
                    }
                }
                mark = length+1;
                for(int j = length;j >= 1;j --) {
                    if(bd[i][j] == -1) {
                        int ct = amount[j];
                        int k;
                        for(k = j;k < mark && bd[i][k] != 1;k ++) {
                            dp[ct][k] = 1;
                        }
                        mark = k-1;
                    }
                }
                for(int l = 1;l <= count;l ++) {
                    for(int m = 1;m <= length;m ++) {
                        if(dp[l][m] != 0) {
                            long partAns = 0;
                            for(int g = 1;g < m;g ++) {
                                if(dp[l-1][g] != 0)
                                    partAns =  (partAns + dp[l-1][g]) % MOD;
                            }
                            if(partAns != 0) {
                                dp[l][m] = partAns;
                            }
                        }
                    }
                }
                long long subAns = 0;
                for(int m = 1;m <= length;m ++) {
                    subAns =  (subAns + dp[count][m]) % MOD;
                }
                if(subAns != 0)
                    ans = ans * subAns % MOD;
                
                
            }
            return (int)ans;
    }
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".D.",
 "...",
 "..."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, differentOutcomes(Arg0)); }
	void test_case_1() { string Arr0[] = {".D.",
 "...",
 ".U."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, differentOutcomes(Arg0)); }
	void test_case_2() { string Arr0[] = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3125; verify_case(2, Arg1, differentOutcomes(Arg0)); }
	void test_case_3() { string Arr0[] = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(3, Arg1, differentOutcomes(Arg0)); }
	void test_case_4() { string Arr0[] = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2268; verify_case(4, Arg1, differentOutcomes(Arg0)); }
	void test_case_5() { string Arr0[] = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999937; verify_case(5, Arg1, differentOutcomes(Arg0)); }
	void test_case_6() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, differentOutcomes(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
    FoxAndShogi ___test;
    vector <string> t;
    string n;
    string d;
    
    for(int i = 0;i < 50;i ++) {
        n += ".";
    }
    
    for(int i = 0;i < 50;i ++) {
        d += "U";
    }
    for(int i = 0;i < 50;i ++) {
        if((i+1) % 3 == 0) {
            t.push_back(d);
        } else {
            t.push_back(n);
        }
    }
     
    ___test.run_test(-1);
    cout << ___test.differentOutcomes(t);
    return 0;
}
// END CUT HERE
