// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndGo.cpp"
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

class Node {
public:
    int x,y,count;
    Node(int i,int j,int k) {
        x = i;
        y = j;
        count = k;
    }
};

class FoxAndGo
{
        public:
    int step[4][2] =
            {{0,1},{0,-1},{1,0},{-1,0}};
    int record[20][20];
     int nullrec[20][20];
    int count,nullcount,x,y;
    int maxKill(vector <string> board)
    {
        memset(record, 0, sizeof(int)*400);
        vector<Node> nods;
        for(int i = 0;i < board.size();i ++) {
            for(int j = 0;j < board[i].size();j ++) {
                if(board[i][j] == 'o' && record[i][j] == 0){
                    record[i][j] = 1;
                    count = 1;
                    nullcount = 0;
                    x = y = -1;
                    memset(nullrec, 0, sizeof(int)*400);
                    
                    for(int k = 0;k < 4;k ++) {
                        if(i + step[k][0] >= 0 && i + step[k][0] < board.size()
                           && j + step[k][1] >= 0 && j+step[k][1] < board[i].size()) {
                            
                            dfs(board,i+step[k][0],j+step[k][1]);
                        }
                    }
                    if(nullcount <= 1) {
                        Node node(x,y,count);
                        nods.push_back(node);
                    }
                }
            }
        }
        int ans = 0;
        int max = 0;
       
        int cul[20][20];
        memset(cul, 0, sizeof(int)*400);
        for(int i = 0;i < nods.size();i ++) {
            if(nods[i].x == -1 && nods[i].y == -1) {
                ans += nods[i].count;
            } else {
                cul[nods[i].x][nods[i].y] += nods[i].count;
            }
        }
        for(int i = 0;i < 20;i ++) {
            for(int j = 0;j < 20;j ++) {
                max = max > cul[i][j] ? max : cul[i][j];
            }
        }
        return ans + max;
    };
    
    void dfs(vector<string> board,int tarX,int tarY) {
        if(board[tarX][tarY] == 'x') {
            return;
        }
        if(board[tarX][tarY] == '.' && nullrec[tarX][tarY] == 0) {
            nullrec[tarX][tarY] =1;
            nullcount ++;
            x = tarX;
            y = tarY;
            return;
        }
        if(board[tarX][tarY] == 'o' && record[tarX][tarY] == 0) {
            record[tarX][tarY] = 1;
            count ++;
            for(int k = 0;k < 4;k ++)
                if(tarX + step[k][0] >= 0 && tarX + step[k][0] < board.size()
                   && tarY + step[k][1] >= 0 && tarY + step[k][1] < board[tarX].size()) {
                    
                dfs(board,tarX+step[k][0],tarY+step[k][1]);
                }
        }
        return;
    }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(7, Arg1, maxKill(Arg0)); }
	void test_case_8() { string Arr0[] = {"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(8, Arg1, maxKill(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        FoxAndGo ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
