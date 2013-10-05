// BEGIN CUT HERE

// END CUT HERE
#line 5 "ConvertibleStrings.cpp"
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

class ConvertibleStrings
{
        public:
    
        int leastRemovals(string A, string B)
        {
            set<int> order;
            int record[10][10];
            int tot[10];
            int fp[10];
            
            memset(record,0,sizeof(int)*100);
            memset(tot,0,sizeof(int)*10);

            
            for(int i = 0;i < A.size();i ++) {
                record[A[i]-'A'][B[i]-'A'] ++;
                order.insert(A[i]-'A');
                tot[A[i]-'A'] ++;
            }
            vector<int> vOrder;
            for(set<int>::iterator it = order.begin();it != order.end();it ++) {
                vOrder.push_back(*it);
            }
            int ans = -1;
           
            do {
                memset(fp,0,sizeof(int)*10);
                int subAns = 0;
                for(vector<int>::iterator it = vOrder.begin();it != vOrder.end();it ++) {
                    int max = 0;
                    int mark = -1;
                    for(int i = 0;i < 10;i ++) {
                        if(fp[i] != 1) {
                            if(record[*it][i] > max) {
                                max = record[*it][i];
                                mark = i;
                            }
                        }
                    }
                    if(mark != -1) {
                        fp[mark] = 1;
                        subAns += tot[*it] - max;
                    } else {
                        subAns += tot[*it];
                    }
                }
                if(ans != -1) {
                    ans = subAns < ans ? subAns:ans;
                } else {
                    ans = subAns;
                }
            } while(next_permutation(vOrder.begin(), vOrder.end()) );
            
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DD"; string Arg1 = "FF"; int Arg2 = 0; verify_case(0, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAA"; string Arg1 = "ABCD"; int Arg2 = 3; verify_case(1, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAIAIA"; string Arg1 = "BCDBEE"; int Arg2 = 3; verify_case(2, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABACDCECDCDAAABBFBEHBDFDDHHD"; string Arg1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE"; int Arg2 = 9; verify_case(3, Arg2, leastRemovals(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        ConvertibleStrings ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
