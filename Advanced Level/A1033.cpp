/*
*	author:		zhouyuhao
*	created:	2023-03-26 14:01:26
*	modified:	2023-03-31 23:06:10
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

struct sta {
    double p, d;
};

bool cmp(sta a, sta b) {
    return a.d < b.d;
}

int main(int argc, char const *argv[]) {

    double cmax, d, davg;
    int n;
    cin >> cmax >> d >> davg >> n;
    vector<sta> s(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> s[i].p >> s[i].d;
    }
    s[n].p = 0, s[n].d = d;
    sort(s.begin(), s.end(), cmp);
    if (s[0].d == 0) {
        double pri = 0, dis = 0, tank = 0, ld = cmax * davg;
        int nextid = 0;
        while (true) {
            int nowid = nextid;
            if (nowid < n && s[nowid].d + ld < s[nowid + 1].d) {
                dis += ld;
                cout << "The maximum travel distance = " << fixed << setprecision(2) << dis << "\n";
                break;
            }
            for (int i = nowid + 1; i < n + 1; i++) {
                if (s[i].d - s[nowid].d <= ld) {
                    if (s[i].p < s[nowid].p) {
                        nextid = i;
                        break;
                    }
                } else {
                    break;
                }
            }
            if (nowid != nextid) {
                double dif = s[nextid].d - s[nowid].d;
                dis += dif;
                double needtank = dif / davg;
                if (needtank > tank) {
                    pri += s[nowid].p * (needtank - tank);
                    tank = 0;
                } else {
                    tank -= needtank;
                }
            } else {
                double lp = INT_MAX;
                for (int i = nowid + 1; i < n + 1; i++) {
                    if (s[i].d - s[nowid].d <= ld) {
                        if (s[i].p < lp) {
                            lp = s[i].p;
                            nextid = i;
                        }
                    } else {
                        break;
                    }
                }
                double dif = s[nextid].d - s[nowid].d;
                dis += dif;
                pri += s[nowid].p * (cmax - tank);
                tank = cmax - dif / davg;
            }
            if (nextid == n) {
                cout << fixed << setprecision(2) << pri << "\n";
                break;
            }
        }
    } else {
        cout << "The maximum travel distance = 0.00\n";
    }

    return 0;
}