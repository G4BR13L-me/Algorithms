#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

bool compareInterval(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return (a.second > b.second);
    return (a.first < b.first);
}

int main()
{
    optimize;
    int P, S, a, b;
    cin >> P >> S;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < S; i++)
    {
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    sort(intervals.begin(), intervals.end(), compareInterval);
    cerr << "Sort: " << intervals[0].first << " " << intervals[0].second << endl;
    pair<int, int> current = intervals[0];
    vector<pair<int, int>> ans;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].first < current.first && intervals[i].second < current.first)
        {
            ans.push_back(current);
            current = intervals[i];
        }
        if (intervals[i].first > current.second && intervals[i].second > current.second)
        {
            ans.push_back(current);
            current = intervals[i];
        }
        if (intervals[i].first < current.first && intervals[i].second < current.second)
        {
            current.first = intervals[i].first;
        }
        if (intervals[i].second > current.second && intervals[i].first > current.first)
        {
            current.second = intervals[i].second;
        }
    }
    ans.push_back(current);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}