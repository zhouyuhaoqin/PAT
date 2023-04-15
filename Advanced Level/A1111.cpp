/*
*	author:		zhouyuhao
*	created:	2023-04-01 20:54:56
*	modified:	2023-04-02 20:23:52
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct nodel {
	int v, l, t;
	friend bool operator< (nodel a, nodel b) {
		return a.l > b.l;
	}
};

struct nodet {
	int v, l, t;
	friend bool operator< (nodet a, nodet b) {
		return a.t > b.t;
	}
};

vector<bool> vis;
vector<int> dl, dt;
vector<vector<nodel>> gl;
vector<vector<nodet>> gt;
vector<vector<int>> prel, pret;
vector<vector<int>> ll, tt;

void dijkstral(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(dl.begin(), dl.end(), INT_MAX);
	fill(dt.begin(), dt.end(), INT_MAX);
	dl[s] = 0;
	priority_queue<nodel> q;
	q.push({s, 0, 0});
	while (!q.empty()) {
		nodel t = q.top();
		q.pop();
		int u = t.v;
		if (dl[u] < t.l) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < gl[u].size(); i++) {
			int v = gl[u][i].v;
			if (!vis[v]) {
				if (dl[u] + gl[u][i].l < dl[v]) {
					dl[v] = dl[u] + gl[u][i].l;
					dt[v] = dt[u] + gl[u][i].t;
					prel[v].clear();
					prel[v].push_back(u);
					q.push({v, dl[v], dt[v]});
				} else if (dl[u] + gl[u][i].l == dl[v]) {
					prel[v].push_back(u);
				}
			}
		}
	}
}

void dijkstrat(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(dl.begin(), dl.end(), INT_MAX);
	fill(dt.begin(), dt.end(), INT_MAX);
	dt[s] = 0;
	priority_queue<nodet> q;
	q.push({s, 0, 0});
	while (!q.empty()) {
		nodet t = q.top();
		q.pop();
		int u = t.v;
		if (dt[u] < t.t) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < gt[u].size(); i++) {
			int v = gt[u][i].v;
			if (!vis[v]) {
				if (dt[u] + gt[u][i].t < dt[v]) {
					dt[v] = dt[u] + gt[u][i].t;
					dl[v] = dl[u] + gt[u][i].l;
					pret[v].clear();
					pret[v].push_back(u);
					q.push({v, dl[v], dt[v]});
				} else if (dt[u] + gt[u][i].t == dt[v]) {
					pret[v].push_back(u);
				}
			}
		}
	}
}

int maxt = INT_MAX;
vector<int> templ, ansl;
void dfsl(int s, int v) {
	if (v == s) {
		templ.push_back(v);
		int sumt = 0;
		for (int i = templ.size() - 1; i > 0; i--) {
			sumt += tt[templ[i]][templ[i - 1]];
		}
		if (sumt < maxt) {
			maxt = sumt;
			ansl = templ;
		}
		templ.pop_back();
		return;
	}
	templ.push_back(v);
	for (int i = 0; i < prel[v].size(); i++) {
		dfsl(s, prel[v][i]);
	}
	templ.pop_back();
}

int maxl = INT_MAX;
vector<int> tempt, anst;
void dfst(int s, int v) {
	if (v == s) {
		tempt.push_back(v);
		if (tempt.size() < maxl) {
			maxl = tempt.size();
			anst = tempt;
		}
		tempt.pop_back();
		return;
	}
	tempt.push_back(v);
	for (int i = 0; i < pret[v].size(); i++) {
		dfst(s, pret[v][i]);
	}
	tempt.pop_back();
}

void print(vector<int> v) {
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
		if (i > 0) {
			cout << " -> ";
		} else {
			cout << "\n";
		}
	}
}

int main(int argc, char const *argv[]) {

	int n, m;
	cin >> n >> m;
	vis.resize(n);
	dl.resize(n);
	dt.resize(n);
	gl.resize(n);
	gt.resize(n);
	prel.resize(n);
	pret.resize(n);
	ll.resize(n);
	tt.resize(n);
	for (int i = 0; i < n; i++) {
		ll[i].resize(n);
		tt[i].resize(n);
	}
	for (int i = 0; i < m; i++) {
	    int v1, v2, w, l, t;
	    cin >> v1 >> v2 >> w >> l >> t;
	    gl[v1].push_back({v2, l, t});
	    gt[v1].push_back({v2, l, t});
	    ll[v1][v2] = l;
	    tt[v1][v2] = t;
	    if (w == 0) {
	    	gl[v2].push_back({v1, l, t});
	    	gt[v2].push_back({v1, l, t});
	    	ll[v2][v1] = l;
	    	tt[v2][v1] = t;
	    }
	}
	int s, e;
	cin >> s >> e;
	dijkstral(s);
	dfsl(s, e);
	int dis = dl[e];
	dijkstrat(s);
	dfst(s, e);
	if (ansl == anst) {
		cout << "Distance = " << dis << "; Time = " << dt[e] << ": ";
		print(ansl);
	} else {
		cout << "Distance = " << dis << ": ";
		print(ansl);
		cout << "Time = " << dt[e] << ": ";
		print(anst);
	}
	
	return 0;
}