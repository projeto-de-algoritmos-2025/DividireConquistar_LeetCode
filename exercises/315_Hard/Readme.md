# [315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/)

## Lógica da Solução 

A solução utiliza um algoritmo inspirado na contagem de inversões com merge sort para calcular, de forma eficiente, quantos números menores aparecem à direita de cada elemento no vetor original. Cada número é associado ao seu índice original e o vetor é recursivamente dividido em metades. Durante a etapa de merge, sempre que um número da metade direita é menor que um da metade esquerda, sabemos que esse número estaria à direita no vetor original e é menor — então contamos essa ocorrência para o elemento da esquerda.

Ao acumular essas contagens durante o processo de junção das metades ordenadas, obtemos para cada posição do vetor original a quantidade exata de elementos menores que ela à sua direita. Essa abordagem evita comparações diretas entre todos os pares, resultando em uma solução com complexidade O(n log n), bem mais eficiente que uma abordagem ingênua O(n²).

## Submissão

![Submissão](/assets/315_submit.png)
Submissão e caso de teste 1

![Caso de Teste 2](/assets/315_case2.png)
Caso de teste 2

![Submissão](/assets/315_case3.png)

## [Código](./315_CountofSmaller.cpp)