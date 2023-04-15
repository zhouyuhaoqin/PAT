/*
*	author:		zhouyuhao
*	created:	2023-03-30 21:36:42
*	modified:	2023-03-30 22:19:55
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

struct city {
	int v, cost;
	friend bool operator< (city a, city b) {
		return a.cost > b.cost;
	}
};

vector<bool> vis;
vector<int> h, c;
vector<vector<int>> pre;
vector<vector<city>> g;

void dijkstra(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(c.begin(), c.end(), INT_MAX);
	c[s] = 0;
	priority_queue<city> q;
	q.push({s, 0});
	while (!q.empty()) {
		city t = q.top();
		q.pop();
		int u = t.v;
		if (c[u] < t.cost) {
			continue;
		}
		vis[u] = true;
		for (int i = 0; i < g[u].size(); i++) {
		    int v = g[u][i].v;
		    if (!vis[v]) {
		    	if (c[u] + g[u][i].cost < c[v]) {
		    		c[v] = c[u] + g[u][i].cost;
		    		pre[v].clear();
		    		pre[v].push_back(u);
		    		q.push({v, c[v]});
		    	} else if (c[u] + g[u][i].cost == c[v]) {
		    		pre[v].push_back(u);
		    	}
		    }
		}
	}
}

int maxh = -1, cnt = 0;
float maxhavr = -1;
vector<int> ans, temp;
void dfs(int s, int v) {
	if (v == s) {
		cnt++;
		temp.push_back(v);
		int sumh = 0;
		for (int i = 0; i < temp.size(); i++) {
		    sumh += h[temp[i]];
		    // sum += h[i];
		}
		if (sumh > maxh) {
			maxh = sumh;
			maxhavr = (float) sumh / (temp.size() - 1);
			ans = temp;
		} else if (sumh == maxh) {
			if ((float) sumh / (temp.size() - 1) > maxhavr) {
				maxhavr = (float) sumh / (temp.size() - 1);
				ans = temp;
			}
		}
		temp.pop_back();
		return;
		// return;
	}
	temp.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
	    dfs(s, pre[v][i]);
	}
	temp.pop_back();
}

int main(int argc, char const *argv[]) {

	int n, k;
	string s;
	cin >> n >> k >> s;
	vis.resize(n);
	h.resize(n);
	c.resize(n);
	pre.resize(n);
	g.resize(n);
	map<string, int> mid;
	map<int, string> mstr;
	mid[s] = 0, mstr[0] = s;
	pre[0].resize(n);
	for (int i = 1; i < n; i++) {
		pre[i].resize(n);
		string c;
		cin >> c >> h[i];
		mid[c] = i, mstr[i] = c;
	}
	for (int i = 0; i < k; i++) {
		string c1, c2;
		int cost;
		cin >> c1 >> c2 >> cost;
		g[mid[c1]].push_back({mid[c2], cost});
		g[mid[c2]].push_back({mid[c1], cost});
	}
	dijkstra(mid[s]);
	int e = mid["ROM"];
	dfs(mid[s], e);
	reverse(ans.begin(), ans.end());
	cout << cnt << " " << c[e] << " " << maxh << " " << (int) maxhavr << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << mstr[ans[i]];
	    if (i < ans.size() - 1) {
	        cout << "->";
	    } else {
	        cout << "\n";
	    }
	}
	
	return 0;
}