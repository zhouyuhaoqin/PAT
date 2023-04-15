/*
*	author:		zhouyuhao
*	created:	2023-04-03 12:41:21
*	modified:	2023-04-04 09:46:29
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct score {
    string id;
    int v;
};

struct stu {
    string id;
    int gp, gm, gf, g;
    bool isgp, isgm, isgf;
    bool iscertificate;
};

bool cmp(stu a, stu b) {
    if (a.g != b.g) {
        return a.g > b.g;
    } else {
        return a.id < b.id;
    }
}

int cnt = 1;
map<string, int> loc;
void getid(string s) {
    if (loc[s] == 0) {
        loc[s] = cnt++;
    }
}

int main(int argc, char const *argv[]) {

    int p, m, n;
    cin >> p >> m >> n;
    vector<score> d;
    for (int i = 0; i < p + m + n; i++) {
        string id;
        int v;
        cin >> id >> v;
        getid(id);
        d.push_back({id, v});
    }
    vector<stu> s(cnt);
    for (int i = 0; i < p; i++) {
        s[loc[d[i].id]].id = d[i].id;
        s[loc[d[i].id]].gp = d[i].v;
        s[loc[d[i].id]].isgp = true;
    }
    for (int i = p; i < p + m; i++) {
        s[loc[d[i].id]].id = d[i].id;
        s[loc[d[i].id]].gm = d[i].v;
        s[loc[d[i].id]].isgm = true;
    }
    for (int i = p + m; i < p + m + n; i++) {
    // for (int i = p; i < p + m + n; i++) {
        s[loc[d[i].id]].id = d[i].id;
        s[loc[d[i].id]].gf = d[i].v;
        s[loc[d[i].id]].isgf = true;
    }
    for (int i = 1; i < cnt; i++) {
        if (s[i].gm > s[i].gf) {
            s[i].g = 0.4 * s[i].gm + 0.6 * s[i].gf + 0.5;
        } else {
            s[i].g = s[i].gf;
        }
        if (s[i].gp >= 200 && s[i].g >= 60) {
            s[i].iscertificate = true;
        }
    }
    s[0].iscertificate = false;
    sort(s.begin(), s.end(), cmp);
    for (int i = 0; i < s.size(); i++) {
        if (s[i].iscertificate) {
            cout << s[i].id << " ";
            if (s[i].isgp) {
                cout << s[i].gp << " ";
            } else {
                cout << "-1 ";
            }
            if (s[i].isgm) {
                cout << s[i].gm << " ";
            } else {
                cout << "-1 ";
            }
            if (s[i].isgf) {
                cout << s[i].gf << " ";
            } else {
                cout << "-1 ";
            }
            cout << s[i].g << "\n";
        }
    }
    
    return 0;
}