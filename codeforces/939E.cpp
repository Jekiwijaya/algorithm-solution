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

#define MAXN 500006

int n = 0, q;
LL x;
LL arr[MAXN];
LL pre[MAXN] = {};

double binsearch(int low, int high) {
  if (high < low) return 0;
  int mid = (low + high) / 2;
  double res = ((double)pre[mid] + arr[n-1]) / ((double)mid + 2);
  if (arr[mid] < res) return max(arr[n-1] - res, binsearch(mid+1, high));
  return max(arr[n-1] - res, binsearch(low, mid-1));
}

int main() {
  scanf("%d",&q);
  REP(i, q) {
    scanf("%I64d", &x);
    if (x == 1) {
      scanf("%I64d",&x);
      arr[n] = x;
      pre[n] = arr[n];
      if (n) pre[n] += pre[n-1];
      n++;
    } else {
      double res = binsearch(0, n-2);
      printf("%lf\n",res);
    }
  }
  return 0;
}

/*
6
1 3
2
1 4
2
1 8
2
*/