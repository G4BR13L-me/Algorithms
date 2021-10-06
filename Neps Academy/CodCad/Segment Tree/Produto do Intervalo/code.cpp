#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define PB push_back
#define ALL(x) x.begin(), x.end()
#define INF 2'000'000'000'020LL
#define MAXN 20000020

int arvore[MAXN], valores[MAXN];
void setup(int no, int i, int j)
{
    if (i == j)
    {
        if (valores[i] > 0)
            arvore[no] = 1;
        else if (valores[i] < 0)
            arvore[no] = -1;
        else
            arvore[no] = 0;
    }
    else
    {
        int l = 2 * no;
        int r = l + 1;
        int mid = (i + j) / 2;

        setup(l, i, mid);
        setup(r, mid + 1, j);

        arvore[no] = arvore[l] * arvore[r];
    }
}

void update(int no, int i, int j, int k, int new_value)
{
    if (i == j)
    {
        if (new_value > 0)
            arvore[no] = 1;
        else if (new_value < 0)
            arvore[no] = -1;
        else
            arvore[no] = 0;
    }
    else
    {
        int l = 2 * no;
        int r = l + 1;
        int mid = (i + j) / 2;

        if (k <= mid)
            update(l, i, mid, k, new_value);
        else
            update(r, mid + 1, j, k, new_value);

        arvore[no] = arvore[l] * arvore[r];
    }
}

int query(int no, int i, int j, int A, int B)
{
    if (i >= A && j <= B)
    {
        return arvore[no];
    }

    if (i > B || j < A)
    {
        return -2;
    }

    int l = 2 * no;
    int r = l + 1;
    int mid = (i + j) / 2;

    int left = query(l, i, mid, A, B);
    int right = query(r, mid + 1, j, A, B);

    if (left == -2)
        return right;
    if (right == -2)
        return left;

    return left * right;
}

int main()
{
    int N, K;
    while ((cin >> N >> K))
    {
        for (int i = 1; i <= N; i++)
            cin >> valores[i];

        setup(1, 1, N);

        char cmd;
        int I, V, J;
        while (K--)
        {
            cin >> cmd;
            if (cmd == 'C')
            {
                cin >> I >> V;
                update(1, 1, N, I, V);
            }
            else
            {
                cin >> I >> J;
                int output = query(1, 1, N, I, J);
                if (output == 1)
                    cout << '+';
                else if (output == -1)
                    cout << '-';
                else
                    cout << '0';
            }
        }
        cout << endl;
    }

    return 0;
}