// BEGIN CUT HERE

// END CUT HERE
#line 5 "LittleElephantAndArray.cpp"
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

static int MOD = 1000000007;

class node {
public:
    node(long long x,int y) {
        a = x;
        b = y;
    }
    long long a;
    int b;
};

bool cmp(const node x, const node y) {
    return x.a < y.a;
}
class LittleElephantAndArray
{
    public:
    
    int getNumber(long long A, int N)
    {
        vector<node> ohNo;
        vector<node> ohYes;
        ohYes.push_back(node(0,1));
        for(int i = 0;i <= N;i ++) {
            long long cas = A + i;
            vector<int> tv;
            while(cas != 0) {
                int m = cas % 10;
                cas = cas / 10;
                tv.push_back(m);
            }
            
            map<long long,int> tm;
            for(vector<int>::reverse_iterator it = tv.rbegin();it != tv.rend();it ++) {
                vector<node> ttm;
                for(map<long long,int>::reverse_iterator mit = tm.rbegin();mit != tm.rend();mit ++) {
                    int k = 0;
                    if(tm[mit->first] != 0)
                        k = (tm[mit->first] + k) % MOD;
                    if(k != 0)
                        ttm.push_back(node(mit->first * 10 + *it,k));
                }
                ttm.push_back(node(*it, 1));
                for(vector<node>::iterator it = ttm.begin();it != ttm.end();it ++) {
                    tm[it->a] = (it->b + tm[it->a] ) % MOD;
                }
            }
            for(map<long long,int>::iterator it = tm.begin();it != tm.end();it ++) {
                ohNo.push_back(node(it->first,it->second));
            }
            long long sum = 0;
            int y = 0;
            for(int x = 0;x < ohNo.size();x ++) {
                for(;y < ohYes.size() && ohNo[x].a >= ohYes[y].a;y ++) {
                    sum = ( sum + ohYes[y].b ) % MOD;
                }
                ohNo[x].b = (sum *  ohNo[x].b) % MOD;
            }
            ohYes.swap(ohNo);
           
            ohNo.clear();
        }
        int ans = 0;
        for(int i = 0;i < ohYes.size();i ++) {
            ans = ( ans + ohYes[i].b ) % MOD;
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1234567891011LL; int Arg1 = 100; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 10LL; int Arg1 = 2; int Arg2 = 15; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 4747774LL; int Arg1 = 1; int Arg2 = 8369; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 6878542150015LL; int Arg1 = 74; int Arg2 = 977836619; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        LittleElephantAndArray ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
