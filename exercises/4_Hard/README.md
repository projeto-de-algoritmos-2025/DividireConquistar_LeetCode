# [4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/description/)

## Lógica da Solução 

A solução implementada utiliza um algoritmo baseado na ideia de divisão pela mediana para encontrar a mediana de dois vetores ordenados com complexidade O(log(min(m, n))). O algoritmo faz uma busca binária no vetor menor (nums1 ou nums2), tentando encontrar uma partição tal que os elementos à esquerda da partição (somando os dois vetores) sejam menores ou iguais aos elementos à direita. Isso garante que a mediana possa ser encontrada diretamente entre os maiores elementos da esquerda e os menores da direita. A cada iteração, o algoritmo calcula os limites da partição e verifica se os maiores valores da esquerda são menores que os menores da direita, ajustando a busca binária com base nessa comparação até encontrar a partição ideal.

Embora o algoritmo não use diretamente o método clássico da "mediana das medianas" para seleção linear em O(n), ele se baseia no mesmo princípio central: reduzir o espaço de busca progressivamente dividindo pelo ponto médio (mediana). A lógica central é encontrar a posição correta da mediana entre dois conjuntos ordenados, usando o conceito de mediana como ponto de equilíbrio entre duas metades. Assim, o algoritmo aproveita a ordenação dos vetores e aplica a ideia de dividir e conquistar por mediana, o que se alinha conceitualmente à técnica "mediana das medianas", mas com um foco em posicionamento e balanceamento entre dois arrays ao invés da seleção direta de um valor entre todos.

## Submissão

![Submissão](/assets/4_submit.png)
Submissão e caso de teste 1

![Caso de Teste 2](/assets/4_case2.png)
Caso de teste 2

## [Código](./4_MedianofTwoSortedArrays.cpp)