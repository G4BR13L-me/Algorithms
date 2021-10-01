#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

bool sortByRate(pair<string, int> a, pair<string, int> b)
{
    return (a.second > b.second);
}

bool sortByName(pair<string, int> a, pair<string, int> b)
{
    return (a.first < b.first);
}

int main()
{
    optimize;
    int N, T, rate;
    string name;
    cin >> N >> T;

    vector<pair<string, int>> players;
    for (int i = 0; i < N; i++)
    {
        cin >> name >> rate;
        players.push_back({name, rate});
    }
    sort(players.begin(), players.end(), sortByRate);

    cerr << "Sort: " << players[0].second << endl;

    vector<vector<pair<string, int>>> teams(T, vector<pair<string, int>>());
    for (int i = 0; i < N; i++)
    {
        teams[i % T].push_back(players[i]);
    }

    for (int i = 0; i < T; i++)
    {
        cout << "Time " << i + 1 << endl;
        sort(teams[i].begin(), teams[i].end(), sortByName);
        for (int j = 0; j < teams[i].size(); j++)
        {
            cout << teams[i][j].first << endl;
        }
        cout << endl;
    }

    return 0;
}