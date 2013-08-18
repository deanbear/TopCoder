// BEGIN CUT HERE

// END CUT HERE
#line 5 "GameInDarknessDiv2.cpp"
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

class Position {

    public:
    Position(int x1,int y1) {
        x = x1;
        y = y1;
    }
    Position(){
        
    }
    int x;
    int y;
};
int rec[50][50];
int bobMove[2600][50][50];

class GameInDarknessDiv2
{
    public:
    int row;
    int col;
    int safeAction;
    
    vector<Position> aliceMove;
    bool flag;
    string check(vector <string> field, vector <string> moves)
    {
        aliceMove.clear();
        
        row = (int)field.size();
        col = (int)field[0].size();
        memset(rec,0,sizeof(int)*50*50);
        
        Position a;
        Position b;
        for(int i = 0;i < row;i ++) {
            for(int j = 0;j < col;j ++) {
                if(field[i][j] == 'A') {
                    rec[i][j] = 0 ;
                    a.y = i;
                    a.x = j;
                } else if(field[i][j] == 'B') {
                    rec[i][j] = 0;
                    b.y = i;
                    b.x = j;
                } else if(field[i][j] == '#') {
                    rec[i][j] = -1;
                } else {
                    rec[i][j] = 0;
                }
            }
        }
        
        string move;
        for(string one : moves) {
            move += one;
        }
        memset(bobMove,0,sizeof(int)*2600*50*50);
        
        safeAction = (int)move.size();
        flag = false;
        Position k(a.x,a.y);
        for(int i = 0;i < move.size();i ++) {
            if(move[i] == 'D') {
                if(k.y + 1 < row) {
                    k.y += 1;
                    aliceMove.push_back(*new Position(k.x,k.y));
                } else {
                    return "Bob wins";
                }
            } else if(move[i] == 'U') {
                if(k.y - 1 >= 0) {
                    k.y -= 1;
                    aliceMove.push_back(*new Position(k.x,k.y));
                } else {
                    return "Bob wins";
                }
            } else if(move[i] == 'R') {
                if(k.x + 1 < col) {
                    k.x += 1;
                   aliceMove.push_back(*new Position(k.x,k.y));
                } else {
                    return "Bob wins";
                }
            } else if(move[i] == 'L') {
                if(k.x - 1 >= 0) {
                    k.x -= 1;
                    aliceMove.push_back(*new Position(k.x,k.y));
                } else {
                    return "Bob wins";
                }
            }
        }
        aliceMove.push_back(*new Position(-1,-1));
        
        if(b.x == aliceMove[0].x && b.y == aliceMove[0].y) {
            return "Alice wins";
        }
        dfs(b,1);
        if(flag) {
            return "Bob wins";
        } else {
            return "Alice wins";
        }
        
    }
    
    int action[4][2] = {0,1,
                        0,-1,
                        -1,0,
                        1,0};
    
    void dfs(Position b,int step) {
        if(flag) {
            return;
        }
        if(step > safeAction) {
            flag =true;
            return;
        }
        for(int i = 0;i < 4;i ++) {
            int nextX = b.x + action[i][0] ;
            int nextY = b.y + action[i][1] ;
            if(nextX >= 0 && nextX < col
               && nextY >= 0 && nextY < row) {
                if((nextX != aliceMove[step-1].x || nextY != aliceMove[step-1].y)
                   && (nextX != aliceMove[step].x || nextY != aliceMove[step].y)
                   && bobMove[step][nextY][nextX] != 1
                   && rec[nextY][nextX] != -1) {
                    bobMove[step][nextY][nextX] = 1;
                    b.x += action[i][0];
                    b.y += action[i][1];
                    dfs(b,step+1);
                    b.x -= action[i][0];
                    b.y -= action[i][1];
                }
            }
        }
    }
    
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A.B..",
 "##.##",
 "##.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RRDUR"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A.B..",
 "##.##",
 "##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RRRLD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob wins"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RR", "R", "UDD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.###",
 ".B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RDRRRLLLLUDUDRLURDLUD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob wins"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....",
 ".#.#.",
 "##.#.",
 "A###.",
 "B...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"D"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".#...#....#.......#....#......",
 "...###.#.#..#.#.#..###...#.#.#",
 ".#.#...#...#..#..#.....##.#...",
 "#..#.##..##..#.#..###.#....#.#",
 "..#..#..#...#...#....#..##.#..",
 "#..##..#..##.#.#.####..#.#...#",
 ".#....##.#.....#......##.#.#..",
 ".###.#...#.#.#..#.#.##...##.#.",
 ".....#.#.##..#.#..##...##...#.",
 "#.#.#...#...#.#.#...#.#.#.##.#",
 ".#..##.#..##..#.###...........",
 "..##.....####.......##.#.#.##.",
 "#....##.#.#...####.#...#.#.#..",
 "#.#.#......##.#...#..#.#..#..#",
 "..#..#.#.##...#.#..#..#..#..#.",
 ".#..#...#...#..#..#.#..#..#A#.",
 "..#..#.#.B##.##..#...#.#.##...",
 "#.#.##..#......#.#.#.#.#...#.#",
 "#.#...#.######...#.#.#.#.#.#..",
 "..#.##.#.....#.##..#...#.#.#.#",
 ".#..#..#.#.#.#.#..#.#####..#.#",
 "..#.#.##.#.#.##.#......#..#...",
 "#..#.....#.#.....#.#.##..##.#.",
 "##..###.#..#.#.#.#..##..#...##",
 "##.#...#..##.#.#..#.#..#.#.#..",
 "#..#.#.####..#..#..#..#......#",
 "..#..#.....####..#.##.#.###.#.",
 ".#..#.####.#.#..#.....#...#...",
 "..##.......#...#..####.##.#.#.",
 "#....#.#.#..#.###....#....#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU","RRUUURUULLD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(5, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        GameInDarknessDiv2 ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
