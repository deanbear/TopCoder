// BEGIN CUT HERE

// END CUT HERE
#line 5 "FlippingBitsDiv2.cpp"
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

class FlippingBitsDiv2
{
public:
    
    
    int getmin(vector <string> S, int M)
    {
        string bin = "" ;
        for(string tmp : S) {
            bin += tmp;
        }
        // BEGIN CUT HERE
        /**
         * define f(k) as the number of k bits that flipping from 1 to 0
         *        times[bin.size/M] is the division of binString by M.
         *
         *
         * if   1 <= k < bin.size , l < k ,  0 < i < n
         *    times[k] =
         *      min(
         *          times[i] + f(k)-f(l) + 2,   ## a) flip 1 to 0 one by one in (l,k] (f(k))
         *                                         b) flip all l bits, which is before k, from 1 to 0 (+1)
         *                                         c) flip all k bits from 0 to 1 (+1)
         *          times[i] + i*M - f(k) + f(l) ## flip 0 to 1 one by one
         *          f(k) + 1,    ## from the 1st place to k.th bit , flip 1 to 0 one by one ,then flip all.
         *          i*M - f(k)   ## ..... , flip 0 to 1 one by one.
         *
         * if k = bin.size , l < k ,0 < i < n  because it is the tail , it needs only flip all 0 to 1 .
         *    times[k] =
         *      min(
         *          times[i] + f(k)-f(l) + 1 ,## a)flip 1 to 0 1by1 in (bin.size - m , bin.size] (f(k))
         *                                            ## b)flip all k bits from 0 to 1 (+1)
         *          times[i] + i*M - f(k) + f(l) ,
         *          f(k) + 1,  
         *          i*M - f(k)
         *
         */
         // END CUT HERE
        int div = (int)bin.size() / M ;
        
        //define f(k)
        int cumul[3000];
        cumul[0] = 0;
        for(int i = 1;i <= div;i ++) {
            int flip1To0Count = 0;
            for(int j = (i-1)*M;j < i*M;j ++) {
               flip1To0Count += bin[j] - '0';
            }
            cumul[i] = cumul[i-1] + flip1To0Count;
        }
        
        //define times[]
        int times[3000];
        
        times[0] = 0;
        
        
        for(int i = 1;i < div;i ++) {
            
            times[i] = min(
                           cumul[i] + 1,
                           i*M - cumul[i]
                        );
            
            for(int j = 1;j < i;j ++) {
                times[i] = min(
                               times[i],
                               min(
                                   times[j] + cumul[i] - cumul[j] + 2,
                                   times[j] + M*(i-j) - cumul[i] + cumul[j]
                               ));
            }
        }
        
        times[div] = min(
                         cumul[div] + 1,
                         div*M - cumul[div]
                         );
        for(int j = 1;j < div;j ++) {
            times[div] = min(
                            times[div],
                            min(
                                times[j] + cumul[div] - cumul[j] + 1,
                                times[j] + M*(div-j) - cumul[div] + cumul[j]
                            )
                         );
        }
        return times[div];
    };
    
    int min(int a,int b) {
        return a > b ? b : a;
    }
    
    // BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00010","11010110","1010111","110001010","0110001100"
        ,"000110110","011010101","00","111","100"}
        ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 31; verify_case(4, Arg2, getmin(Arg0, Arg1)); }
    
    // END CUT HERE
    
};
// BEGIN CUT HERE
int main()
{
    FlippingBitsDiv2 ___test;
    ___test.run_test(-1);
    
    return 0;
}
// END CUT HERE
