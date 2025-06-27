// Autor: Leonardo Fernandes - 200067036
// Leetcode Hard :: 493. Reverse Pairs
// https://leetcode.com/problems/reverse-pairs/description/

#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSortAndCount(nums, 0, nums.size() - 1);
    }

private:
    // Função principal que implementa o Merge Sort e conta os pares invertidos
    int mergeSortAndCount(vector<int>& nums, int left, int right) {
        if (left >= right) return 0; // Caso base: array de tamanho 1 ou vazio
        
        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, left, mid) + 
                    mergeSortAndCount(nums, mid + 1, right);
        
        // Conta os pares invertidos entre as duas metades
        count += countInvertedPairs(nums, left, mid, right);
        
        // Combina (merge) as duas metades ordenadas
        merge(nums, left, mid, right);
        
        return count;
    }

    // Função para contar os pares onde nums[i] > 2 * nums[j] e i está na metade esquerda, j na direita
    int countInvertedPairs(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        
        // Para cada elemento na metade esquerda, conta quantos na direita satisfazem nums[i] > 2 * nums[j]
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        return count;
    }

    // Função para fazer o merge de duas metades ordenadas
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        
        // Copia os elementos restantes da metade esquerda (se houver)
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        
        // Copia os elementos restantes da metade direita (se houver)
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        
        // Copia o array temporário de volta para o original
        for (int idx = 0; idx < temp.size(); ++idx) {
            nums[left + idx] = temp[idx];
        }
    }
};