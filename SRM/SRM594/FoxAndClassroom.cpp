// BEGIN CUT HERE

// END CUT HERE
#line 5 "FoxAndClassroom.cpp"
#include <string>
#include <vector>
using namespace std;
class FoxAndClassroom {
	public:
	string ableTo(int n, int m) {
        int sn = 0 , sm = 0;
        int mark[101][101];
        memset(mark,0,sizeof(int)*101*101);
        while(mark[sn][sm] != 1) {
            mark[sn][sm] = 1;
            sn = (sn + 1) % n;
            sm = (sm + 1) % m;
        }
        int tag = 0;
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < m;j ++) {
                if(mark[i][j] == 0) {
                    tag = 1;
                    break;
                }
            }
        }
        if(tag == 1)
            return "Impossible";
        else
            return "Possible";
	}
};
