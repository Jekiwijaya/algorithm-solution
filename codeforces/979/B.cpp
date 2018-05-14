/*
 * Created by Jacky Wijaya
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
#include <map>

#define FOREACH(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)

#define ALL(c) (c).begin(), (c).end()
#define F first
#define S second
#define INS insert
#define MP make_pair
#define PB push_back
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

template <class T> inline T MAX(T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN(T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS(T x) { if (x < 0) return -x; return x; }

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const static int INF = 2123123123;

int n;
string s[3];
int tot[3][300] = {};
int maxn[3][2] = {};
int res[3] = {};

string nama[] = {"Kuro", "Shiro", "Katie"};

int calc(int v, int sisa, int turn) {
  if (sisa >= turn) {
    return v + turn;
  } else {
    return v + sisa - (sisa == 0 && turn == 1 ? 1 : 0);
  }
}

int main() {
  cin >> n;
  REP(i, 3) cin >> s[i];
  int len = s[0].size();
  REP(i, 3) {
    REP(j, len) {
      tot[i][s[i][j]]++;
    }
    int maxO = 0, maxE = 0;
    REP(j, 255) {
      if(tot[i][j] % 2 == 0) maxE = max(maxE, tot[i][j]);
      else maxO = max(maxO, tot[i][j]);
    }
    maxn[i][0] = maxE;
    maxn[i][1] = maxO;
  }
  REP(i, 3) {
    res[i] = max(calc(maxn[i][0], len - maxn[i][0], n), calc(maxn[i][1], len - maxn[i][1], n));
    // printf("res[%d] = %d\n",i, res[i]);
  }
  bool isDraw = false;
  int cMax = 0;
  int cIdx = -1;
  REP(i, 3) {
    if (cMax < res[i]) {
      cMax = res[i];
      cIdx = i;
    }
  }
  int tot = 0;
  REP(i, 3) {
    if(cMax == res[i]) tot++;
  }
  isDraw = tot > 1;
  if (isDraw) printf("Draw\n");
  else {
    printf("%s\n",nama[cIdx].c_str());
  }
  return 0;
}

/*
1
aaaaaaaaaa
AAAAAAcAAA
bbbbbbzzbb
*/ 