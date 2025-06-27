#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        const std::vector<int>& A = (nums1.size() < nums2.size()) ? nums1 : nums2;
        const std::vector<int>& B = (nums1.size() < nums2.size()) ? nums2 : nums1;
        int m = A.size();
        int n = B.size();

        int total = m + n;
        int half = total / 2;

        int left = 0;
        int right = m;

        while (true) {
            int i = (left + right) / 2;
            int j = half - i;

            int Aleft = (i == 0) ? INT_MIN : A[i - 1];
            int Aright = (i == m) ? INT_MAX : A[i];
            int Bleft = (j == 0) ? INT_MIN : B[j - 1];
            int Bright = (j == n) ? INT_MAX : B[j];

            if (Aleft <= Bright && Bleft <= Aright) {
                if (total % 2 == 0) {
                    return (std::max(Aleft, Bleft) + std::min(Aright, Bright)) / 2.0;
                } else {
                    return std::min(Aright, Bright);
                }
            } else if (Aleft > Bright) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
    }
};
