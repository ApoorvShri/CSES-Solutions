// Problem -> https://cses.fi/problemset/task/1193

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  for (string &it : a) cin >> it;

  for (int startX = 0; startX < n; startX++) {
    for (int startY = 0; startY < m; startY++) {
      if (a[startX][startY] == 'A') {
        vector<int> x{ -1,0,0,1 }, y{ 0,-1,1,0 };
        string dir = "ULRD";

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m));
        vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m));

        q.push({ startX,startY });
        vis[startX][startY] = 1;
        par[startX][startY] = { startX,startY };

        while (!q.empty()) {
          int ii = q.front().first, jj = q.front().second;
          q.pop();

          if (a[ii][jj] == 'B') {
            string ans = "";

            while (ii != startX || jj != startY) {
              int curX = ii - par[ii][jj].first, curY = jj - par[ii][jj].second;

              for (int ind = 0; ind < 4; ind++) {
                if (curX == x[ind] && curY == y[ind]) {
                  ans += dir[ind];
                  break;
                }
              }

              int temp = ii;
              ii = par[ii][jj].first;
              jj = par[temp][jj].second;
            }

            reverse(ans.begin(), ans.end());

            cout << "YES" << endl << ans.size() << endl << ans << endl;
            return 0;
          }

          for (int ind = 0; ind < 4; ind++) {
            int i = ii + x[ind], j = jj + y[ind];

            if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j]) {
              q.push({ i,j });
              vis[i][j] = 1;
              par[i][j] = { ii,jj };
            }
          }
        }

        cout << "NO" << endl;
        return 0;
      }
    }
  }
}

// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//   int n, m;
//   cin >> n >> m;

//   vector<string> a(n);
//   for (string &it : a) cin >> it;

//   for (int startX = 0; startX < n; startX++) {
//     for (int startY = 0; startY < m; startY++) {
//       if (a[startX][startY] == 'A') {
//         vector<int> x{ -1,0,0,1 }, y{ 0,-1,1,0 };
//         string dir = "ULRD";

//         queue<tuple<int, int, string>> q;
//         vector<vector<bool>> vis(n, vector<bool>(m));

//         q.push({ startX,startY,"" });
//         vis[startX][startY] = 1;

//         while (!q.empty()) {
//           auto it = q.front();
//           q.pop();

//           int ii = get<0>(it), jj = get<1>(it);
//           string ans = get<2>(it);

//           if (a[ii][jj] == 'B') {
//             cout << "YES" << endl << ans.size() << endl << ans << endl;
//             return 0;
//           }

//           for (int ind = 0; ind < 4; ind++) {
//             int i = ii + x[ind], j = jj + y[ind];

//             if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j]) {
//               q.push({ i,j,ans + dir[ind] });
//               vis[i][j] = 1;
//             }
//           }
//         }

//         cout << "NO" << endl;
//         return 0;
//       }
//     }
//   }
// }