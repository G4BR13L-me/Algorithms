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
    int goalL, goalR, fase = 8;
    vector<pair<int, int>> results;
    queue<char> teams;
    char left, right;
    for (int i = 0; i < 15; i++)
    {
        cin >> goalL >> goalR;
        results.push_back({goalL, goalR});
        teams.push('A' + i);
    }
    teams.push('P');

    for (int i = 0; i < 15; i++)
    {
        left = teams.front();
        teams.pop();
        right = teams.front();
        teams.pop();
        if (results[i].first > results[i].second)
        {
            teams.push(left);
        }
        else
        {
            teams.push(right);
        }
    }
    cout << teams.front() << endl;

    return 0;
}