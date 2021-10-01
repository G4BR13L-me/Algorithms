#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

int main()
{
    optimize;
    unordered_map<int, int> my_map;
    vector<int> v;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        my_map[m]++;
        v.push_back(m);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        my_map[n]--;
    }

    for (auto x : v)
    {
        if (my_map[x])
            cout << x << " ";
    }

    return 0;
}