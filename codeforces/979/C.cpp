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

#define MAXN 300005

int n, x, y, u, v;
vvi ver(MAXN);
int tNode[MAXN];

bool visited[MAXN];
bool hasY[MAXN];

int dfs(int now) {
  if (visited[now]) return 0;
  visited[now] = true;
  int ret = 1;
  REP(i, ver[now].size()) {
    int w = ver[now][i];
    ret += dfs(w);
  }
  tNode[now] = ret;
  return ret;
}

LL calc(int now, int p) {
  if (visited[now]) return 0;
  visited[now] = true;
  LL ret = (tNode[now] - 1) * 2 - (now == x ? tNode[y] : 0);
  REP(i, ver[now].size()) {
    REP(j, i) {
      int left = ver[now][i];
      int right = ver[now][j];
      // printf("%d - %d | %d\n",left, right, now);
      if (left == p || right == p) continue;
      LL totalLeft = tNode[left];
      LL totalRight = tNode[right];
      ret += totalLeft * totalRight;
      if (now == x) {
        if (hasY[left]) {
          totalLeft -= tNode[y];
        } else if (hasY[right]) {
          totalRight -= tNode[y];
        }
      }
      ret += totalLeft * totalRight;
      // printf("%d %d | %d %d\n",left, right, totalLeft, totalRight);
    }
    ret += calc(ver[now][i], now);
  }
  // printf("calc[%d] = %d\n",now, ret);
  return ret;
}

bool findY(int now) {
  if (visited[now]) return false;
  visited[now] = true;
  bool ret = now == y;
  REP(i, ver[now].size()) {
    int w = ver[now][i];
    ret |= findY(w);
  }
  hasY[now] = ret;
  return ret;
}

int main() {
  scanf("%d%d%d",&n, &x, &y);
  REP(i, n-1) {
    scanf("%d%d",&u,&v);
    ver[u].PB(v);
    ver[v].PB(u);
  }
  memset(visited, false, sizeof(visited));
  dfs(x);
  memset(visited, false, sizeof(visited));
  memset(hasY, false, sizeof(hasY));
  findY(x);
  memset(visited, false, sizeof(visited));
  LL res = calc(x, -1);
  cout << res << endl;
  return 0;
}
/*
4 1 2
1 2
2 3
2 4
*/