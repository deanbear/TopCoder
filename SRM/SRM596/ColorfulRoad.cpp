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

class ColorfulRoad
{
public: 
	map<char,char> stepMap;
    int getMin(string road) {
    	stepMap['R'] = 'G';
    	stepMap['G'] = 'B';
    	stepMap['B'] = 'R';

    	int count[20];
    	memset(count,-1,sizeof(int)*20);
    	count[0] = 0;
    	for(int i = 0;i < road.size();i ++) {
    		if(count[i] != -1) {
				char init = road[i];
				char pvalue = stepMap[init];
				for(int j = i+1;j < road.size();j ++) {
					if(road[j] == pvalue) {
						int add = (j-i)*(j-i);
						if(add+count[i] < count[j] || count[j] == -1) {
							count[j] = add+count[i];
						}
					}
				}
    		}
    	}
    	return count[road.size()-1];
    }
    
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGGGB"; int Arg1 = 8; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "RGBRGBRGB"; int Arg1 = 8; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "RBBGGGRR"; int Arg1 = -1; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "RBRRBGGGBBBBR"; int Arg1 = 50; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "RG"; int Arg1 = 1; verify_case(4, Arg1, getMin(Arg0)); }
	void test_case_5() { string Arg0 = "RBRGBGBGGBGRGGG"; int Arg1 = 52; verify_case(5, Arg1, getMin(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    ColorfulRoad ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
