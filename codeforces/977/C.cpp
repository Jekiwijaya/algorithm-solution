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

int n, k;
int arr[MAXN];
int diff[MAXN];

int main() {
  scanf("%d%d",&n,&k);
  REP(i,n) scanf("%d",&arr[i]);
  sort(arr, arr+n);
  if (k == 0) {
    printf("%d\n", arr[0] == 1 ? -1 : 1);
    return 0;
  }
  diff[n-1] = n;
  int res = -1;
  for(int i = n-2; i >= 0; i--) {
    diff[i] = arr[i] == arr[i+1] ? diff[i+1] : i + 1;
  }
  REP(i,n) {
    if(diff[i] == k) {
      res = arr[i]; break;
    }
  }
  printf("%d\n",res);
  return 0;
}