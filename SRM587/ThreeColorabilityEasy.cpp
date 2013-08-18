// BEGIN CUT HERE

// END CUT HERE
#line 5 "ThreeColorabilityEasy.cpp"
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

class ThreeColorabilityEasy
{
        public:
        string isColorable(vector <string> cells)
        {
            int mt[50][50];
            for(int i = 0;i < cells.size();i ++) {
                for(int j = 0;j < cells[i].size();j++) {
                    mt[i][j] = cells[i][j] == 'N' ? 1 : 2;
                }
            }
            int flag=0;
            for(int i = 0;i < cells.size()-1;i ++) {
                for(int j=0;j < cells[0].size() -1;j ++) {
                    int count = 0;
                    if(mt[i][j] == 1) {
                        count ++;
                    }
                    if(mt[i][j+1] == 1) {
                        count ++;
                    }
                    if(mt[i+1][j+1] == 1) {
                        count ++;
                    }
                    if(mt[i+1][j] == 1) {
                        count ++;
                    }
                    if(count == 3 || count ==1) {
                        flag =1;
                        break;
                    }
                }
            }
            if(flag==1) {
                return "No";
            }else {
                return "Yes";
            }
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, isColorable(Arg0)); }
	void test_case_1() { string Arr0[] = {"NZ"
,"NZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(1, Arg1, isColorable(Arg0)); }
	void test_case_2() { string Arr0[] = {"ZZZ"
,"ZNZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(2, Arg1, isColorable(Arg0)); }
	void test_case_3() { string Arr0[] = {"NZNZNNN"
,"NNZNNNZ"
,"NNNNZZZ"
,"ZZZNZZN"
,"ZZNZNNN"
,"NZZZZNN"
,"ZZZNZNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(3, Arg1, isColorable(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZ"
,"ZZZZ"
,"ZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, isColorable(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        ThreeColorabilityEasy ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
