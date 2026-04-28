class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int l = 0, r = n1;
        int total = n1 + n2, half = total/2;//number of elements in the left partition
        while(l <= r){
            int mid = (l+r)/2; // number of elements from first array
            int l1 = mid - 1 < 0 ? INT_MIN  : nums1[mid-1];
            int r1 = mid >= n1 ? INT_MAX : nums1[mid];
            int l2 = half - mid -1 < 0 ? INT_MIN : nums2[half-mid-1];
            int r2 = half-mid >= n2 ? INT_MAX : nums2[half-mid];

            if(l1 <= r2 && l2 <= r1){
                if(total%2){
                    // odd
                    return min(r1,r2);
                }

                return (double)(max(l1,l2) + min(r1,r2)) /2;
            }

            if(l1 > r2){
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return -1;
    }
};
