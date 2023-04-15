/*
*	author:		zhouyuhao
*	created:	2023-04-14 23:05:51
*	modified:	2023-04-14 23:12:48
*	item:		Progrmming Ability Test
*	site:		Shahu, Yugan
*/
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cctype>
#include <iomanip>

using namespace std;

const int maxn = 1e4;

stack<int> st;
map<int, int> level;
map<int, bool> exist;
vector<vector<int>> g(maxn);
vector<int> temp, ans;

void dfs(int r, int e) {
	if (r == e) {
		ans = temp; // temporary storage
		return;
	}
	for (int i = 0; i < g[r].size(); i++) {
		temp.push_back(g[r][i]);
		dfs(g[r][i], e);
		temp.pop_back();
	}
}

int main(int argc, char const *argv[]) {

	int n;
	cin >> n;
	int r;
	cin >> r;
	getchar();
	st.push(r);
	level[r] = 0;
	exist[r] = true;
	for (int i = 0; i < n - 1; i++) {
		string s;
		getline(cin, s);
		int l = 0;
		while (isspace(s[0])) {
			s.erase(0, 1);
			l++;
		}
		int id = stoi(s);
		level[id] = l;
		exist[id] = true;
		int p = st.top();
		if (l > level[p]) {
			st.push(id);
			g[p].push_back(id);
		} else {
			while (l <= level[p]) {
				st.pop();
				p = st.top();
			}
			st.push(id);
			g[p].push_back(id);
		}
	}
	temp.push_back(r); // special
	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int id;
		cin >> id;
		if (exist[id]) { // id maybe not the leaf point
			dfs(r, id); // temp is clear when dfs return
			for (int i = 0; i < ans.size(); i++) {
				cout << setfill('0') << setw(4) << ans[i];
				if (i < ans.size() - 1) {
					cout << "->";
				} else {
					cout << "\n";
				}
			}
		} else {
			cout << "Error: " << setfill('0') << setw(4) << id << " is not found.\n";
		}
	}
	
	return 0;
}