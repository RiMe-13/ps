#include <iostream>

using namespace std;

int n, k, cnt;
int a[500001];

void merge(int start, int mid, int end) {
    int tmp[end + 2];
    int i = start, j = mid + 1, t = 1;

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) tmp[t++] = a[i++];
        else tmp[t++] = a[j++];
    }

    while (i <= mid) tmp[t++] = a[i++];
    while (j <= end) tmp[t++] = a[j++];

    i = start, t = 1;
    while (i <= end) {
        a[i++] = tmp[t++];
        cnt++;
        if (cnt == k) cout << tmp[t - 1] << "\n";
    }
}

void merge_sort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];

    merge_sort(0, n - 1);

    if (cnt < k) cout << "-1\n";

    return 0;
}