/*
*	author:		zhouyuhao
*	created:	2023-03-30 23:09:15
*	modified:	2023-03-31 11:41:21
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct sta {
	int v, dis;
	friend bool operator< (sta a, sta b) {
		return a.dis > b.dis;
	}
};

vector<bool> vis;
vector<int> d, b;
vector<vector<sta>> g;
vector<vector<int>> pre;

void dijkstra(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(d.begin(), d.end(), INT_MAX);
	d[s] = 0;
	priority_queue<sta> q;
	q.push({s, 0});
	while (!q.empty()) {
		sta t = q.top();
		q.pop();
		int u = t.v;
		if (d[u] < t.dis) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
		    int v = g[u][i].v;
		    if (!vis[v]) {
		    	if (d[u] + g[u][i].dis < d[v]) {
		    		d[v] = d[u] + g[u][i].dis;
		    		pre[v].clear();
		    		pre[v].push_back(u);
		    		q.push({v, d[v]});
		    	} else if (d[u] + g[u][i].dis == d[v]) {
		    		pre[v].push_back(u);
		    	}
		    }
		}
	}
}

int mtt = INT_MAX, mtb = INT_MAX;
vector<int> ans, temp;
void dfs(int s, int v) {
	if (v == s) {
		temp.push_back(v);
		int tt = 0, tb = 0;
		for (int i = temp.size() - 2; i >= 0; i--) {
			int nb = b[temp[i]];
			// if (nb > 0) {
			// 	if (tt >= nb) {
			// 		tt -= nb;
			// 	} else {
			// 		tb += (nb - tt);
			// 		tt = 0;
			// 	}
			// } else if (nb < 0) {
			// 	nb = abs(nb);
			// 	if (tb >= nb) {
			// 		tb -= nb;
			// 	} else {
			// 		tt += (nb - tb);
			// 		tb = 0;
			// 	}
			// }
            if (nb < 0) {
                if (tb >= abs(nb)) {
                    tb -= abs(nb);
                } else {
                    tt += abs(nb) - tb;
                    tb = 0;
                }
            } else {
                tb += nb;
            }
		}
		if (tt < mtt) {
			mtt = tt;
			mtb = tb;
			ans = temp;
		} else if (tt == mtt && tb < mtb) {
			mtb = tb;
			ans = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(s, pre[v][i]);
	}
	temp.pop_back();
}

int main(int argc, char const *argv[]) {

	int cmax, n, sp, m;
	cin >> cmax >> n >> sp >> m;
	vis.resize(n + 1);
	d.resize(n + 1);
	b.resize(n + 1);
	g.resize(n + 1);
	pre.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[i] -= cmax / 2;
	}
	for (int i = 0; i < m; i++) {
	    int id1, id2, dist;
	    cin >> id1 >> id2 >> dist;
	    g[id1].push_back({id2, dist});
	    g[id2].push_back({id1, dist});
	}
	dijkstra(0);
	dfs(0, sp);
	cout << mtt << " ";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
		if (i > 0) {
			cout << "->";
		}
	}
	cout << " " << mtb << "\n";
	
	return 0;
}