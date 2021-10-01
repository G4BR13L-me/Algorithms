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
    int C, taco, fabricados = 0;
    set<int> s;
    cin >> C;
    while (C--)
    {
        cin >> taco;
        auto added = s.insert(taco);
        if (added.second)
        {
            fabricados += 2;
        }
        else
        {
            s.erase(taco);
        }
    }
    cout << fabricados << endl;

    return 0;
}