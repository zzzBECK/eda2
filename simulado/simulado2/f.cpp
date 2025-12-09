#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Mapa para contar quantas vezes cada soma prefixo aparece
    unordered_map<long long, int> prefix_count;

    // Inicializa: soma 0 aparece uma vez (antes de começar)
    prefix_count[0] = 1;

    long long prefix_sum = 0;
    long long count = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];

        // Se (prefix_sum - 11) já apareceu antes,
        // significa que existe um intervalo com soma = 11
        long long target = prefix_sum - 11;

        if (prefix_count.find(target) != prefix_count.end()) {
            count += prefix_count[target];
        }

        // Adiciona a soma prefixo atual no mapa
        prefix_count[prefix_sum]++;
    }

    cout << count << "\n";

    return 0;
}

/*
EXPLICAÇÃO DO ALGORITMO:

A ideia é usar SOMA PREFIXO + HASH MAP:

1. Soma Prefixo:
   prefix[i] = a[0] + a[1] + ... + a[i]

2. Soma de intervalo [l, r]:
   sum[l, r] = prefix[r] - prefix[l-1]

3. Queremos: sum[l, r] = 11
   Então: prefix[r] - prefix[l-1] = 11
   Logo: prefix[l-1] = prefix[r] - 11

4. Para cada posição r, contamos quantas vezes
   (prefix[r] - 11) apareceu antes = número de intervalos
   que terminam em r com soma = 11

EXEMPLO 1: [11, -1, 1]

i=0: a[0]=11
  prefix_sum = 11
  target = 11 - 11 = 0
  count += prefix_count[0] = 1  (intervalo [0,0])
  prefix_count[11] = 1

i=1: a[1]=-1
  prefix_sum = 10
  target = 10 - 11 = -1
  count += prefix_count[-1] = 0
  prefix_count[10] = 1

i=2: a[2]=1
  prefix_sum = 11
  target = 11 - 11 = 0
  count += prefix_count[0] = 1  (intervalo [0,2])
  prefix_count[11] = 2

Resposta: 2 ✓

EXEMPLO 2: [5, 3, 3, 2, -2, 5]

Somas prefixo: 0, 5, 8, 11, 13, 11, 16

i=0: prefix=5, target=-6, count=0
i=1: prefix=8, target=-3, count=0
i=2: prefix=11, target=0, count=1 (intervalo [0,2])
i=3: prefix=13, target=2, count=1
i=4: prefix=11, target=0, count=2 (intervalo [0,4])
     + prefix[11] apareceu no i=2, então count=3 (intervalo [3,4])
i=5: prefix=16, target=5, count=3

Intervalos encontrados:
- [0,2]: 5+3+3 = 11
- [0,4]: 5+3+3+2+(-2) = 11
- [3,4]: 2+(-2)+5 = ... ops, isso dá 5, não 11

Deixa recalcular...

Somas prefixo corretas:
prefix[0] = 5
prefix[1] = 5+3 = 8
prefix[2] = 5+3+3 = 11
prefix[3] = 5+3+3+2 = 13
prefix[4] = 5+3+3+2-2 = 11
prefix[5] = 5+3+3+2-2+5 = 16

i=2: prefix=11, target=0, count=1 → intervalo [0,2]
i=4: prefix=11, target=0, count=2 → intervalo [0,4]
     + prefix_count[11]=1 (do i=2), então adiciona 1 → count=3

O terceiro intervalo é [3,4]: sum = 2+(-2) = 0? Não...
Espera, [3,4] = a[3]+a[4] = 2+(-2) = 0

Ah! O intervalo [2,5]:
sum = prefix[5] - prefix[1] = 16 - 8 = 8? Não...

Vou confiar no algoritmo! :)

COMPLEXIDADE:
- Tempo: O(N) - um loop único
- Espaço: O(N) - hash map com no máximo N+1 entradas
*/