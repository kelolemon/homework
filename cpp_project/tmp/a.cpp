# include <cstdio>
# include <cmath>
# include <cstring>
# include <iostream>

using namespace std;

int main() {
	int tot;
	scanf("%d",&tot);
    for (int i = 0; i < tot; i++) {
        int n,k,nub(0);
        scanf("%d%d",&n,&k);
        int a[300];
        int v[500];
        memset(v, 0, sizeof(v));
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[j]);
            if (v[a[j]] == 0) {
                v[a[j]] = 1;
                nub++;
            }
        }
        if (nub > k) {
            cout << "-1" << endl;
        } else {
            int result[1000000], ans = 0, tot_ans = 0;
            for (int j = 0; j < 500; j++) {
                if (v[j] == 0) continue;
                result[ans] = j;
                ans++;
            }
            for (int j = 0; j < k - ans; j++) {
                result[ans + j] = a[j];
            }
            tot_ans = k;
            for (int j = 0, p = 0; j < n - k + ans;p++) {
                if (result[p] != a[j + k - ans]) {
                    result[p + k] = result[p];
                    tot_ans++;
                } else {
                    result[p + k] = a[j + k - ans];
                    j++;
                    tot_ans++;
                }
            }
            printf("%d\n",tot_ans);
            for (int j = 0; j < tot_ans; j++) {
                printf("%d ", result[j]);
            }
            cout << endl;
        }
        
    }
}
