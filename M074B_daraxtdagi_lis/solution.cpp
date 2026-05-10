#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005; 
vector<int> adj[MAXN];
int a[MAXN];
int ans[MAXN];
vector<int> LIS_tails; 

void dfs(int u, int p) {
    // lower_bound a[u] dan kichik bo'lmagan birinchi elementga iteratordan indeksni qaytaradi.
    // Bu, LIS_tails dagi a[u] ning o'rnini yoki qo'shiladigan joyini aniqlaydi.
    int pos = lower_bound(LIS_tails.begin(), LIS_tails.end(), a[u]) - LIS_tails.begin();
    
    int original_val = -1; // a[u] o'rniga qo'yilishi mumkin bo'lgan dastlabki qiymat
    bool pushed_back = false; // a[u] LISni kengaytirdimi yoki yo'qmi

    if (pos == LIS_tails.size()) { // Agar a[u] LIS_tails dagi barcha elementlardan katta bo'lsa
        LIS_tails.push_back(a[u]);
        pushed_back = true;
    } else { // a[u] mavjud elementni almashtiradi, LIS uchun potensial "yaxshiroq" qator hosil qiladi
        original_val = LIS_tails[pos]; // Orqaga qaytish uchun dastlabki qiymatni saqlash
        LIS_tails[pos] = a[u];
    }

    ans[u] = LIS_tails.size(); // 1 dan u gacha bo'lgan yo'l uchun LIS uzunligi

    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }

    // Orqaga qaytish: LIS_tails ni u tugunini qayta ishlashdan oldingi holatiga qaytarish
    if (pushed_back) {
        LIS_tails.pop_back(); // Qo'shilgan elementni o'chirish
    } else {
        LIS_tails[pos] = original_val; // 'pos' dagi dastlabki qiymatni tiklash
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0); // 1-tugundan (ildiz) boshlab DFS ni chaqirish, 0 soxta ota-ona sifatida

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}
