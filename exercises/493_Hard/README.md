# [493. Reverse Pairs](https://leetcode.com/problems/reverse-pairs/description/)

## Descrição

Dado um array nums, um par invertido é definido como um par (i, j) onde i < j e nums[i] > 2 * nums[j]. O objetivo é contar o número total de pares invertidos no array.

## Lógica da Solução

Este problema pode ser resolvido eficientemente usando uma abordagem Dividir e Conquistar, semelhante ao Merge Sort. A ideia é dividir o array em duas metades, contar os pares invertidos em cada metade recursivamente e, durante o merge, contar os pares invertidos que cruzam as metades.

## Submissão

![Submissão](/assets/493_submit.png)

## [Código](./493_ReversePairs.cpp)
