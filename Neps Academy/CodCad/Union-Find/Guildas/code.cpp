#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

int pai[1000010], qnt[1000010];

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
    qnt[y] += qnt[x];
}

int main()
{
    int N, M, P, Q, A, B, win = 0;
    while ((cin >> N >> M) && (N + M))
    {
        win = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> P;
            qnt[i] = P;
            pai[i] = i;
        }

        while (M--)
        {
            cin >> Q >> A >> B;

            if (Q == 1)
            {
                join(A - 1, B - 1);
            }
            else
            {
                A = find(A - 1);
                B = find(B - 1);
                P = find(0);

                if (A == P)
                {
                    if (qnt[A] > qnt[B])
                        win++;
                }
                else if (B == P)
                {
                    if (qnt[B] > qnt[A])
                        win++;
                }
            }
        }
        cout << win << endl;
    }

    return 0;
}