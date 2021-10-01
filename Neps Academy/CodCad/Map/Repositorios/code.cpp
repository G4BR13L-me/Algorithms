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
    int C, N, p, v;
    cin >> C >> N;
    map<int, int> programs, internet;
    for (int i = 0; i < C; i++)
    {
        cin >> p >> v;
        programs[p] = v;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> p >> v;
        if (internet[p] == 0 || internet[p] < v)
            internet[p] = v;
    }

    for (auto x : internet)
    {
        if (programs[x.first] == 0 || programs[x.first] < x.second)
            cout << x.first << " " << x.second << endl;
    }

    return 0;
}