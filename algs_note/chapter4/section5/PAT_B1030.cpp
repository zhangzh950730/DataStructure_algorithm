// ��������
// Created by zhang on 2020/8/20.
//
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100010;
int n, p, a[MAXN];

int binarySearch(int i, long long x) {
    if (a[n - 1] <= x) return n;
    int l = i + 1, r = n - 1, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (a[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
//        int j = binarySearch(i, (long long) a[i] * p);
        int j = upper_bound(a + i + 1, a + n, (long long) a[i] * p) - a;
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}
