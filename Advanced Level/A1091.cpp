/*
*	author:		zhouyuhao
*	created:	2023-03-28 16:13:24
*	modified:	2023-03-28 16:48:45
*	item:		Progrmming Ability Test
*	site:		Yugan, Shangrao
*/
#include <iostream>
#include <queue>

using namespace std;

struct p {
	int x, y, z;
};

int m, n, l, t;
vector<vector<vector<int> > > b;
vector<vector<vector<bool> > > v;

int X[6] = {-1, 1, 0, 0, 0, 0};
int Y[6] = {0, 0, -1, 1, 0, 0};
int Z[6] = {0, 0, 0, 0, -1, 1};

bool islaw(int x, int y, int z) {
	if (x < 0 || x >= l || y < 0 || y >= m || z < 0 || z >= n) {
		return false;
	}
	if (b[x][y][z] == 0 || v[x][y][z] == true) {
		return false;
	}
	return true;
}

int bfs(int x, int y, int z) {
	int cnt = 0;
	p tt;
	tt.x = x, tt.y = y, tt.z = z;
	queue<p> q;
	q.push(tt);
	v[x][y][z] = true;
	while (!q.empty()) {
		p f = q.front();
		q.pop();
		cnt++;
		for (int i = 0; i < 6; i++) {
			int vx = f.x + X[i];
			int vy = f.y + Y[i];
			int vz = f.z + Z[i];
			if (islaw(vx, vy, vz)) {
				v[vx][vy][vz] = true;
				tt.x = vx, tt.y = vy, tt.z = vz;
				q.push(tt);
			}
		}
	}
	if (cnt >= t) {
		return cnt;
	} else {
		return 0;
	}
}

int main(int argc, char const *argv[]) {

	cin >> m >> n >> l >> t;
	b.resize(l);
	v.resize(l);
	for (int i = 0; i < l; i++) {
		b[i].resize(m);
		v[i].resize(m);
		for (int j = 0; j < m; j++) {
			b[i][j].resize(n);
			v[i][j].resize(n);
			for (int k = 0; k < n; k++) {
				cin >> b[i][j][k];
				v[i][j][k] = false;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (b[i][j][k] == 1 && v[i][j][k] == false) {
					cnt += bfs(i, j, k);
				}
			}
		}
	}
	cout << cnt << "\n";
	
	return 0;
}