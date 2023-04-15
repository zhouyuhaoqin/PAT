/*
*	author:		zhouyuhao
*	created:	2023-03-31 09:36:52
*	modified:	2023-03-31 10:14:37
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>
#include <map>
#include <climits>

using namespace std;

struct city {
	int v, cost;
	friend bool operator< (city a, city b) {
		return a.cost > b.cost;
	}
};

vector<bool> vis;
vector<int> h, c, pre, num, sum, cnt;
vector<vector<city>> g;

void dijkstra(int s) {
	fill(vis.begin(), vis.end(), false);
	fill(c.begin(), c.end(), INT_MAX);
	c[s] = 0;
	sum[s] = h[s];
	num[s] = 1;
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
		    		pre[v] = u;
		    		num[v] = num[u];
		    		sum[v] = sum[u] + h[v];
		    		cnt[v] = cnt[u] + 1;
		    		q.push({v, c[v]});
		    	} else if (c[u] + g[u][i].cost == c[v]) {
		    		num[v] += num[u];
		    		if (sum[u] + h[v] > sum[v]) {
		    			sum[v] = sum[u] + h[v];
		    			pre[v] = u;
		    			cnt[v] = cnt[u] + 1;
		    		} else if (sum[u] + h[v] == sum[v]) {
		    			if ((float) (sum[u] + h[v]) / (cnt[u] + 1) > (float) sum[v] / cnt[v]) {
		    				pre[v] = u;
		    				cnt[v] = cnt[u] + 1;
		    			}
		    		}
		    	}
		    }
		}
	}
}

vector<int> ans;
void dfs(int s, int v) {
	if (v == s) {
		ans.push_back(v);
		return;
	}
	dfs(s, pre[v]);
	ans.push_back(v);
}

int main(int argc, char const *argv[]) {

	int n, k;
	string s;
	cin >> n >> k >> s;
	vis.resize(n);
	h.resize(n);
	c.resize(n);
	pre.resize(n);
	num.resize(n);
	sum.resize(n);
	cnt.resize(n);
	g.resize(n);
	map<string, int> mid;
	map<int, string> mstr;
	mid[s] = 0, mstr[0] = s;
	for (int i = 1; i < n; i++) {
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
	cout << num[e] << " " << c[e] << " " << sum[e] << " " << sum[e] / cnt[e] << "\n";
	dfs(mid[s], e);
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