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

class FoxAndGo2
{
public: 
	int move[4][2] = {{0,1},{-1,0},{1,0},{0,-1}};
	int matrixWhite[20][20];
	int matrixBlack[20][20];
	int littleMark[400];
	int pollution[20][20];
	int pure[400];
	int cal[400][400];
	int sumW[400];
	int ct;
	int bt;
	int sum;
	bitset<400> recB[400];
    int maxKill(vector <string> board) {
    	memset(matrixWhite, 0, sizeof(int)*400);
    	memset(matrixBlack, 0, sizeof(int)*400);
    	memset(pollution, 0, sizeof(int)*400);
    	memset(pure,0,sizeof(int)*400);
    	memset(sumW,0,sizeof(int)*400);
    	memset(cal,0,sizeof(int)*160000);
    	ct = 0;
    	for(int i = 0;i < board.size();i ++) {
    		for(int j = 0;j < board[i].size();j ++) {
    			if(board[i][j] == 'o' && matrixWhite[i][j] == 0) {
    				ct += 1;
    				sum = 0;
    				dfsForWhite(board,i,j,ct);
    				sumW[ct] = sum;
    			}
    		}
    	}
    	bt = 0;
    	for(int i = 0;i < board.size();i ++) {
			for(int j = 0;j < board[i].size();j ++) {
				if(board[i][j] == '.' && matrixBlack[i][j] == 0) {
					bt += 1;
					dfsForBlack(board,i,j,bt);
				}
			}
		}
    	int ans = 0;
    	bool flag = true;

    	while(flag) {
    		flag = false;
			for(int i = 1;i <= ct;i ++) {
				if(recB[i].any()) {
					int notPu = 0;
					for(int j = 1;j <= bt;j ++) {
						if(recB[i][j] == 1) {

							if(pure[j] == 0 &&  (cal[j][0] - cal[j][i] == 0)) {
								notPu ++;
							}

						}
					}
					if(notPu <= 1) {
						ans += sumW[i];
						flag = true;
						for(int j = 1;j <= bt;j ++) {
							if(recB[i][j] == 1) {
								pure[j] = 1;
							}
						}
						recB[i].reset();
					}
				}
			}
    	}

    	for(int i = 1;i <= ct;i ++) {
    		recB[i].reset();
    	}

    	return ans;
    }
    
    void dfsForBlack(vector<string>& board,int i,int j,int bt) {
    	if(board[i][j] == 'o') {
    		recB[matrixWhite[i][j]].set(bt);
    		return;
    	}
    	if(board[i][j] == '.' && matrixBlack[i][j] == 0) {
    		matrixBlack[i][j] = bt;
    		if(pollution[i][j] == 0) {
    			pure[bt] = 1;
    		}

    		cal[bt][0] ++;
    		memset(littleMark,0,sizeof(int)*400);
    		for(int k = 0;k < 4;k ++) {
    			int ni = move[k][0] + i;
    			int nj = move[k][1] + j;
    			if(check(ni,nj,board.size(),board[0].size())) {
    				if(board[ni][nj] == 'o' && littleMark[matrixWhite[ni][nj]] == 0) {
    					cal[bt][matrixWhite[ni][nj]] ++;
    					littleMark[matrixWhite[ni][nj]] = 1;
    				}
    			}
    		}

			for(int k = 0;k < 4;k ++) {
				int ni = move[k][0] + i;
				int nj = move[k][1] + j;
				if(check(ni,nj,board.size(),board[0].size())) {
					dfsForBlack(board,ni,nj,bt);
				}
			 }
		}
    	return;
    }

    void dfsForWhite(vector<string>& board,int i,int j,int ct) {
    	if(board[i][j] == '.') {
    		pollution[i][j] = 1;
    		return;
    	}
    	if(board[i][j] == 'o' && matrixWhite[i][j] == 0) {
    		matrixWhite[i][j] = ct;
    		sum += 1;
    		for(int k = 0;k < 4;k ++) {
    		    int ni = move[k][0] + i;
    		    int nj = move[k][1] + j;
    		    if(check(ni,nj,board.size(),board[0].size())) {
    		    	dfsForWhite(board,ni,nj,ct);
    		    }
    		 }
    	}
    	return;

    }

    bool check(int x,int y,int r,int c) {
    	if(x >= 0 && x < r && y >= 0 && y < c)
    		return true;
    	else
    		return false;
    }

    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 ".o.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"o.",
 "oo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 ".o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".o.o.",
 "o.o.o",
 ".o.o.",
 "o.o.o",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".o.o.o.o.o.",
 "o.ooo.ooo.o",
 ".o.......o.",
 "oo.......oo",
 ".o...o...o.",
 "o...o.o...o",
 ".o...o...o.",
 "oo.......oo",
 ".o.......o.",
 "o.ooo.ooo.o",
 ".o.o.o.o.o."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"...ooo.....",
 "...o.o.....",
 ".ooo.ooo...",
 ".o.....o...",
 ".ooo.ooo...",
 "...o.o.....",
 "...ooo.....",
 "....o......",
 "....o...ooo",
 "....ooooo.o",
 "........ooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 38; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {"ooooooooooo",
 "o.........o",
 "o...ooo...o",
 "o...o.o...o",
 "o...ooo...o",
 "o....o....o",
 "o....oooooo",
 "o..........",
 "o.......ooo",
 "o.......o.o",
 "ooooooooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {
 "oo.o.ooo.o..o..",
 "...ooo.o..oo.oo",
 "o..o.o.ooo.o..o",
 "oo.......oo.ooo",
 "..oo.o.o.o.ooo.",
 "..oo..oo..o.ooo",
 "oo.o.oo..o.oooo",
 ".oo.o..ooo.o.oo",
 "o..o.o.o.o.oo..",
 ".oo.oo...o....o",
 "o.o.oo....oo..o",
 ".o.o..o.oo..ooo",
 "o.o.o..o..o....",
 "ooo.oooooooo..o",
 "o..oo.o..o.ooo."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 60; verify_case(7, Arg1, maxKill(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
    FoxAndGo2 ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
