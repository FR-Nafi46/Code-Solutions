/*
 * Name : Md. Fahmidur Rahman Nafi
 * Date : 2025-03-01   Time : 18:41:27
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ld long double
#define ull unsigned long long
#define lcm(a,b) ((a*b)/__gcd(a,b))
#define debug(x) cout << "Debug : " << x << endl;
const double PI = 2 * acos(0.0);
const int MOD = 1000000007;

int n, m;
bool possible = false;
vector <vector <char>> g(101, vector <char> (101));

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(vector <vector <bool>> &v, int i, int j, char c, pair<int, int> st, int cnt){
    if (possible)
        return;
    if (i < 0 || i >= n)
        return;
    if (j < 0 || j >= m)
        return;

    if (cnt >= 4 && i == st.first && j == st.second){
        possible = true;
        return;
    }

    if (g[i][j] != c || v[i][j])
        return;

    v[i][j] = true;
    for (int k = 0; k < 4; k++){
        int xx = i + dx[k];
        int yy = j + dy[k];

        if (xx == st.first && yy == st.second && cnt + 1 < 4)
            continue;
        
        dfs(v, xx, yy, c, st, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            vector <vector <bool>> visited(n, vector <bool> (m, false));
            dfs(visited, i, j, g[i][j], {i, j}, 0);

            if (possible){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
}