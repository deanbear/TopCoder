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

class TheShuttles
{
public: 
    int getLeastCost(vector <int> cnt, int baseCost, int seatCost) {
    	sort(cnt.begin(),cnt.end());
    	int max = cnt[cnt.size()-1];
    	int ans = -1;
    	for(int i = 1;i <= max;i ++) {
    		int sum = 0;
    		int seatC = i * seatCost;
    		for(int j = 0;j < cnt.size();j ++) {
    			int mod = cnt[j] % i == 0 ? 0 : 1;
    			sum += (baseCost+seatC)*(cnt[j]/i + mod) ;
    		}
    		if(ans != -1) {
    			ans = ans > sum ? sum: ans;
    		} else {
    			ans = sum;
    		}
    	}
    	return ans;
    }
    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 5; int Arg3 = 75; verify_case(0, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {9, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 30; int Arg2 = 5; int Arg3 = 150; verify_case(1, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {9, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 5; int Arg3 = 105; verify_case(2, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {51, 1, 77, 14, 17, 10, 80}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; int Arg2 = 40; int Arg3 = 12096; verify_case(3, Arg3, getLeastCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    TheShuttles ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
