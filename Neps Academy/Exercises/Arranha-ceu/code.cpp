#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long
#define INF 1000010

int arvore[INF];
void altera(int no, int i, int j, int posicao, int novo_valor)
{

    if (i == j)
    { // se tivermos i = j, temos i = posicao = j. Logo, estamos no nó mais baixo da ávore

        // fazemos então as alterações triviais
        arvore[no] = novo_valor;
    }

    else
    {

        int esquerda = 2 * no;    // índice do filho da esquerda
        int direita = 2 * no + 1; // índice do filho da direita

        // chamamos a função recursiva no nó necessário
        int meio = (i + j) / 2;

        // se (posicao <= meio), vamos para o nó da esquerda (segmento [i, meio])
        if (posicao <= meio)
            altera(esquerda, i, meio, posicao, novo_valor);

        // se não, vamos para o nó da direita (segmento [meio+1, j])
        else
            altera(direita, meio + 1, j, posicao, novo_valor);

        arvore[no] = arvore[esquerda] + arvore[direita];
    }
}

// queremos saber o índice da ação mais barata dentro do intervalo [A, B]
int busca(int no, int i, int j, int A, int B)
{

    if (i >= A && j <= B)
    { // primeiro caso: [i, j] está contido em [A, B]
        return arvore[no];
    }

    if (i > B || j < A)
    { // segundo caso: [i, j] e [A, B] são disjuntos (ou i > j, que significa um nó inválido)
        return -1;
    }

    // terceiro caso: chamaremos a função nos dois filhos e retornaremos a melhor resposta
    int esquerda = 2 * no;    // índice do filho da esquerda
    int direita = 2 * no + 1; // índice do filho da direita

    int meio = (i + j) / 2;

    // calculamos a resposta para cada filho
    int resposta_esquerda = busca(esquerda, i, meio, A, B);
    int resposta_direita = busca(direita, meio + 1, j, A, B);

    // retornamos a melhor resposta
    if (resposta_esquerda == -1)
        return resposta_direita; // se o filho da esquerda não possui valor que nos interessa, retornamos o da direita
    if (resposta_direita == -1)
        return resposta_esquerda; // se o filho da direita não possui valor que nos interessa, retornamos o da esquerda

    return resposta_esquerda + resposta_direita;
}

int main()
{
    int N, Q, A, K, P;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        altera(1, 1, N, i, A);
    }

    while (Q--)
    {
        cin >> A;
        if (A)
        {
            cin >> K;
            cout << busca(1, 1, N, 1, K) << endl;
        }
        else
        {
            cin >> K >> P;
            altera(1, 1, N, K, P);
        }
    }

    return 0;
}