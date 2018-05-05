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

int t;
int n;
int arr[MAXN];
vi genap, ganjil;

int main() {
  scanf("%d", &t);
  REPN(tc, t) {
    scanf("%d",&n);
    REP(i,n) scanf("%d",&arr[i]);
    genap.clear();
    ganjil.clear();

    REP(i,n) {
      if (i%2 == 0) genap.PB(arr[i]);
      else ganjil.PB(arr[i]);
    }
    sort(ALL(genap));
    sort(ALL(ganjil));

    int idx = -1;

    REP(i, (n+1) / 2) {
      if (idx != -1) break;
      if (i < n/2 && genap[i] > ganjil[i]) {
        idx = i * 2;
      } else if (i > 0 && genap[i] < ganjil[i-1]) {
        idx = (i-1) * 2 + 1;
      }
    }
    if (idx == -1) printf("Case #%d: OK\n", tc);
    else printf("Case #%d: %d\n", tc, idx);
  }
  return 0;
}