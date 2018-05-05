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

int t, n, D[MAXN], A[MAXN], B[MAXN], M[MAXN], N[MAXN];
int preM[MAXN], preN[MAXN];

vvii res;

int get(int arr[], int idx) {
  if (idx >= n) return 0;
  return arr[idx];
}

int main() {
  scanf("%d", &t);
  REPN(tc, t) {
    scanf("%d",&n);
    REP(i,n) scanf("%d%d%d",&D[i],&A[i],&B[i]);
    memset(preM, -1, sizeof(preM));
    memset(preN, -1, sizeof(preN));
    res.clear();
    REP(i, n) {
      M[i] = D[i] + A[i];
      N[i] = D[i] - B[i];
    }
    for(int i = n-1; i >= 0; i--) {
      if (i == n-1) {
        preM[i] = 1;
        preN[i] = 1;
      } else {
        preM[i] = 1 + ((M[i] == M[i+1] ? 1 : 0) * preM[i+1]);
        preN[i] = 1 + ((N[i] == N[i+1] ? 1 : 0) * preN[i+1]);
      }
    }
    int currentMaxLength = 0, c = 0;
    REP(i,n) {
      int length = 0;
      {
        int Midx = i + get(preM, i) - 1;
        int Nidx = min(n - 1, Midx + get(preN, Midx + 1));
        int lastIdx = Nidx;
        FOR(j, lastIdx, n) {
          if (M[j] != M[Midx] && N[j] != N[Nidx]) break;
          lastIdx = j;
        }
        length = max(length, lastIdx - i + 1);
        // printf("i | M | %d %d |%d %d\n",i, Midx, Nidx, lastIdx);
      }

      {
        int Nidx = i + get(preN, i) - 1;
        int Midx = min(n - 1, Nidx + get(preM, Nidx + i));
        int lastIdx = Midx;
        FOR(j, lastIdx, n) {
          if (M[j] != M[Midx] && N[j] != N[Nidx]) break;
          lastIdx = j;
        }
        length = max(length, lastIdx - i + 1);
        // printf("i | N | %d %d |%d %d\n",i, Midx, Nidx, lastIdx);
      }
      if (currentMaxLength < length) {
        currentMaxLength = length;
        c = 1;
      } else if ( currentMaxLength == length ) c++;
    }
    printf("Case #%d: %d %d\n", tc, currentMaxLength, c);
  }
  return 0;
}

/*
1
5
3 1 1
3 1 1
2 0 0
2 2 2
2 2 2

1
5
7 1 1
2 2 2
5 3 3
4 4 4
2 2 2

3
1
1 1 1
5
2 7 12
6 3 11
8 10 1
11 11 12
13 9 14
5
1 3 3
2 2 2
3 1 1
4 2 2
5 3 3
*/