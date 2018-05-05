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

#define MAXN 30

int t, n, m;
char arr[MAXN][MAXN];

char findRight(int r, int c) {
  for(int i = c+1; i < m; i++) {
    if (arr[r][i] != '?') return arr[r][i];
  }
  return '?';
}

char findBottom(int r, int c) {
  for(int i = r+1; i < n; i++) {
    if (arr[i][c] != '?') return arr[i][c];
  }
  return '?';
}

void solve() {
  // right
  REP(i, n) {
    char currentChar = -1;
    REP(j, m) {
      if (arr[i][j] == '?') {
        if (currentChar == -1) currentChar = findRight(i,j);
        arr[i][j] = currentChar;
      } else {
        currentChar = arr[i][j];
      }
    }
  }

  // bottom
  REP(j, m) {
    char currentChar = -1;
    REP(i, n) {
      if (arr[i][j] == '?') {
        if (currentChar == -1) currentChar = findBottom(i,j);
        arr[i][j] = currentChar;
      } else {
        currentChar = arr[i][j];
      }
    }
  }
}

int main() {
  OPEN("A-large-practice");
  cin >> t;
  REPN(tc, t) {
    cin >> n >> m;
    REP(i,n) {
      scanf("%s", arr[i]);
    }
    solve();
    printf("Case #%d:\n",tc);
    REP(i,n) printf("%s\n", arr[i]);
  }
  return 0;
}