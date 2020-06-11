let a = [1 ,2];
let b = [3, 4];


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    let n = nums1.length;
    let m = nums2.length;
    let tmp;
    if (n < m) {
        tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        tmp = n;
        n = m;
        m = tmp;
    }
    if (m === 0) {
        m = n;
        nums2 = nums1;
    }
    let l = 0, r = n;
    while (l <= r) {
        let mid = (l +r) >> 1;
        let res = ((m + n + 1) >> 1) - mid;
        if (res > 0 && nums2[res - 1] > nums1[mid]) {  // it means mid is too small, res is too big
            l = mid + 1;
        } else if (mid > 0 && nums1[mid - 1] > nums2[res]) { // it means mid is too big, res is too small
            r = mid - 1;
        } else { // correct
            let max_left, min_right;
            if (mid === 0) max_left = nums2[res - 1];
            else if (res === 0) max_left = nums1[mid - 1];
            else max_left = Math.max(nums1[mid - 1], nums2[res - 1]);
            if (mid === n) min_right = nums2[res];
            else if (res === m) min_right = nums1[mid];
            else min_right = Math.min(nums1[mid], nums2[res]);
            if (((m + n) & 1) === 1) {
                return max_left;
            } else {
                return (max_left + min_right) / 2.0;
            }
        }
    }
};

console.log(findMedianSortedArrays(a, b));