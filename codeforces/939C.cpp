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

#define MAXN 100005

int n, s, f;
LL a[MAXN];
LL sum[MAXN] = {};

LL getTotal(LL firstIdx, LL lastIdx) {
  if (lastIdx >= firstIdx)
    return sum[lastIdx] - sum[firstIdx - 1];
  return getTotal(firstIdx, n) + getTotal(1, lastIdx);
}

int main() {
  scanf("%d", &n);
  REPN(i, n) {
    scanf("%I64d",&a[i]);
  }
  scanf("%d%d",&s, &f);
  if (s == f) {
    printf("%d\n",0);
    return 0;
  }
  REPN(i,n) {
    sum[i] = a[i];
    if (i) sum[i] += sum[i-1];
  }

  LL resTotal = 0;
  LL resTime = -1;
  REPN(i,n) {
    int first = i;
    int last = ( i + (f - s - 1) - 1) % n + 1;
    LL total = getTotal(i, last);
    LL xTime = (s - i + 1 + n - 1) % n + 1;
    if (total > resTotal) {
      resTotal = total;
      resTime = xTime;
    } else if (total == resTotal && resTime > xTime) {
      resTime = xTime;
    }
    // printf("[%d] (%d - %d) : %d\n",resTime, first, last, resTotal);
  }
  printf("%I64d\n",resTime);
  return 0;
}

/*
3
3 1 5
1 3
*/