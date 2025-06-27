class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<pair<int, int>> num_with_index;
        for (int i = 0; i < n; ++i) {
            num_with_index.emplace_back(nums[i], i);
        }
        mergeSort(num_with_index, 0, n, counts);
        return counts;
    }

private:
    void mergeSort(vector<pair<int, int>>& vec, int left, int right, vector<int>& counts) {
        if (right - left <= 1) return;
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid, counts);
        mergeSort(vec, mid, right, counts);

        vector<pair<int, int>> temp;
        int i = left, j = mid;
        int right_passed = 0;

        while (i < mid && j < right) {
            if (vec[i].first <= vec[j].first) {
                counts[vec[i].second] += right_passed;
                temp.push_back(vec[i++]);
            } else {
                right_passed++;
                temp.push_back(vec[j++]);
            }
        }

        while (i < mid) {
            counts[vec[i].second] += right_passed;
            temp.push_back(vec[i++]);
        }

        while (j < right) {
            temp.push_back(vec[j++]);
        }

        for (int k = 0; k < temp.size(); ++k) {
            vec[left + k] = temp[k];
        }
    }
};
