#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

struct ligacao
{
    int atendente;
    int duracao;

    ligacao(int a, int d)
    {
        atendente = a;
        duracao = d;
    }

    bool operator<(const ligacao &a) const
    {
        if (duracao == a.duracao)
            return (atendente > a.atendente);
        return (duracao > a.duracao);
    }
};

int main()
{
    map<int, int> ligacoes;
    priority_queue<int, vector<int>, greater<int>> atendente_livre;
    priority_queue<ligacao> atendimentos;
    int N, L, T, last;
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        atendente_livre.push(i);
        ligacoes[i] = 0;
    }

    for (int i = 0; i < L; i++)
    {
        cin >> T;

        if (atendente_livre.empty())
        {
            atendente_livre.push(atendimentos.top().atendente);
            ligacoes[atendente_livre.top()]++;
            atendimentos.push(ligacao(atendente_livre.top(), T + atendimentos.top().duracao));
            atendente_livre.pop();
            atendimentos.pop();
        }
        else
        {
            ligacoes[atendente_livre.top()]++;
            atendimentos.push(ligacao(atendente_livre.top(), T));
            atendente_livre.pop();
        }
    }

    for (auto x : ligacoes)
        cout << x.first << " " << x.second << endl;

    return 0;
}