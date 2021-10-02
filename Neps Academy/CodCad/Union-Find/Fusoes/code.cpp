#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

int pai[1000010];

int find(int x)
{
    if (pai[x] == x)
        return x;
    return pai[x] = find(pai[x]);
}

void join(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y)
        return;

    pai[x] = y;
}

int main()
{
    int N, K, x, y;
    char action;

    cin >> N >> K;
    for (int i = 0; i < N; i++)
        pai[i] = i;

    while (K--)
    {
        cin >> action >> x >> y;
        if (action == 'F')
            join(x - 1, y - 1);
        else
        {
            if (find(x - 1) == find(y - 1))
                cout << "S" << endl;
            else
                cout << "N" << endl;
        }
    }

    return 0;
}