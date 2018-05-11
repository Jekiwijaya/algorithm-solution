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

#define MAXN 200005

int n;
int arr[MAXN];

int ne[MAXN];
map<int,int> idx;

int dp[MAXN];

int dfs(int x) {
  if (x < 0) return 0;
  int &ret = dp[x];
  if (ret != -1) return ret;
  ret = 1;
  ret += dfs(ne[x]);
  return ret;
}

vi resV;
void p(int v) {
  if (v < 0) return;
  resV.PB(v);
  p(ne[v]);
}

int main() {
  scanf("%d", &n);
  REP(i,n) scanf("%d",&arr[i]);
  memset(ne, -1, sizeof(ne));
  for(int i = n-1; i>=0;i--) {
    idx[arr[i]] = i;
    if (idx.count(arr[i]+1)) {
      int nextIdx = idx[arr[i]+1];
      ne[i] = nextIdx;
    }
  }
  memset(dp, -1, sizeof(dp));
  int res = 0, resIdx = -1;
  REP(i,n){
    int curRes = dfs(i);
    if (curRes > res) {
      res = curRes;
      resIdx = i;
    }
  }
  p(resIdx);
  printf("%d\n",resV.size());
  REP(i,resV.size()) {
    if(i) printf(" ");
    printf("%d", resV[i]+1);
  }
  printf("\n");
  return 0;
}