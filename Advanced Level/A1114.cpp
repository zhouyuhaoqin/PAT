/*
*	author:		zhouyuhao
*	created:	2023-04-02 14:59:06
*	modified:	2023-04-04 09:06:37
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

const int maxn = 1e5;

struct fam {
    int id, num;
    double avges, avgar;
};

bool cmp(fam a, fam b) {
    if (a.avgar != b.avgar) {
        return a.avgar > b.avgar;
    } else {
        return a.id < b.id;
    }
}

vector<int> f(maxn);

void init() {
    for (int i = 0; i < maxn; i++) {
        f[i] = i;
    }
}

int find(int x) {
    int a = x;
    while (x != f[x]) {
        x = f[x];
    }
    while (a != f[a]) {
        int z = a;
        a = f[a];
        f[z] = x;
    }
    return x;
}

void joint(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa > fb) {
        f[fa] = fb;
    } else {
        f[fb] = fa;
    }
}

int main(int argc, char const *argv[]) {

    init();
    int n;
    cin >> n;
    map<int, double> es, ar;
    set<int> p;
    vector<int> pp;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        pp.push_back(id);
        p.insert(id);
        int fa, ma;
        cin >> fa >> ma;
        if (fa != -1) {
            joint(id, fa);
            p.insert(fa);
        }
        if (ma != -1) {
            joint(id, ma);
            p.insert(ma);
        }
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int chi;
            cin >> chi;
            joint(id, chi);
            p.insert(chi);
        }
        double a, b;
        cin >> a >> b;
        es[id] = a;
        ar[id] = b;
    }
    map<int, int> famnum;
    for (auto it : p) {
        famnum[find(it)]++;
    }
    map<int, double> fames, famar;
    for (auto it : pp) {
        fames[find(it)] += es[it];
        famar[find(it)] += ar[it];
    }
    vector<fam> ans;
    for (auto it : famnum) {
        ans.push_back({it.first, it.second, fames[it.first] / it.second, famar[it.first] / it.second});
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << "\n";
    for (auto it : ans) {
        printf("%04d %d %.3lf %.3lf\n", it.id, it.num, it.avges, it.avgar);
    }
    
    return 0;
}