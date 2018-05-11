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

#define MAXN 100

string s;
int n, m;
char arr[5][MAXN];

int d[5][MAXN];
int total[5][MAXN];

int dx[] = {1, 0 , -1, 0};
int dy[] = {0, 1, 0, -1};

void print() {
  REP(i,4) {
    REP(j,n) {
      printf("%d ", total[i][j]);
    }
    printf("\n");
  }
}

int start(ii fc, int iD) {
  memset(d, -1, sizeof(d));
  queue< pair<ii, int> > q;
  q.push(MP(fc, iD));
  while(!q.empty()) {
    pair<ii, int> last = q.front();
    q.pop();
    ii coor = last.F;
    int dis = last.S;
    if (d[coor.F][coor.S] != -1) continue;
    d[coor.F][coor.S] = dis;
    REP(i, 4) {
      int ddx = dx[i] + coor.S;
      int ddy = dy[i] + coor.F;
      if (ddx < 0 || ddx >= n || ddy < 0 || ddy >= 4) continue;
      if (arr[ddy][ddx] == '#') continue;
      q.push(MP(MP(ddy, ddx), dis+1));
    }
  }
}

int dfs(int r, int c, int tr, int tc) {
  if (r == tr && c == tc) return 1;
  // printf("masuk %d %d\n",r,c);
  int &ret = total[r][c];
  ret = 0;
  REP(i, 4) {
    int dr = r + dy[i];
    int dc = c + dx[i];
    if (dr < 0 || dr >= 4 || dc < 0 || dc >= n) continue;
    // printf("[%d][%d] = %d | [%d][%d] = %d\n",r,c,d[r][c],dr,dc,d[dr][dc]);
    if (d[r][c] + 1 == d[dr][dc] ) {
      ret += dfs(dr, dc, tr, tc);
    }
  }
  return ret;
}

void hitung() {
  scanf("%d", &n);
  REP(i, 4) {
    scanf("%s",arr[i]);
  }
  start(MP(0, 0), 0);
  memset(total, -1, sizeof(total));
  dfs(0, 0, 3, n-1);
  print();
  printf("---\n");
  start(MP(3, 0), 0);
  memset(total, -1, sizeof(total));
  dfs(3, 0, 0, n-1);
  print();
}

int main() {
  // hitung();
  scanf("%d %d",&n, &m);
  if (m == 1) {
    printf("YES\n");
    REP(i, 4) {
      REP(j, n) {
        if (i == 0 || i == 3 || j == 0 || j == n-1) printf(".");
        else {
          if (i == 1 && (j == n/2)) printf("#");
          else printf(".");
        }
      }
      printf("\n");
    }
    return 0;
  }
  if (m == 3) {
    printf("YES\n");
    REP(i, 4) {
      REP(j, n) {
        if (i == 0 || i == 3 || j == 0 || j == n-1) printf(".");
        else {
          if (i == 1 && (j == 1 || j == n-2 || j == n/2)) printf("#");
          else printf(".");
        }
      }
      printf("\n");
    }
    return 0;
  }
  int res = true;
  printf("%s\n", res ? "YES": "NO");
  int totalM = m;
  if (res) {
    REP(i, 4) {
      REP(j, n) {
        if (i == 0 || i == 3 || j == 0 || j == n-1) printf(".");
        else {
          if ((j - 1) < ((m+1) / 2)) {
            if (m % 2  == 1) {
              if (((j - 1) != ((m+1) / 2) - 2) || i != 2) printf("#");
              else printf(".");
            } else printf("#");
          }
          else printf(".");
        }
      }
      printf("\n");
    }
  }
  return 0;
}