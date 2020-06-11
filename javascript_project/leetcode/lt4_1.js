let a = [4];
let b = [1, 2, 3, 5, 6];

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
        //console.log(l, r);
        let mid = (l +r) >> 1;
        let res = ((m + n + 1) >> 1) - mid;
        //console.log(mid, res)
        if (nums2[res - 1] > nums1[mid] || res > m || mid < 0) {  // it means mid is too small, res is too big
            l = mid + 1;
        } else if (nums1[mid - 1] > nums2[res] || mid > n || res < 0) { // it means mid is too big, res is too small
            r = mid - 1;
        } else { // correct
            //console.log(mid, res);
            if (res === 0 && mid === n) {
                if (((m + n) & 1) === 1) {
                    return nums1[mid - 1];
                } else {
                    return (nums1[mid - 1] + nums2[res]) / 2.0;
                }
            }
            if (mid === 0 && res === m) {
                if (((m + n) & 1) === 1) {
                    //console.log(res);
                    return nums2[res - 1];
                } else {
                    //console.log(res);
                    return (nums1[mid] + nums2[res - 1]) / 2.0;
                }
            }
            if (res === 0) {
                if (((m + n) & 1) === 1) {
                    //console.log(mid);
                    return nums1[mid - 1];
                } else {
                    //console.log(mid);
                    return (nums1[mid - 1] + Math.min(nums2[res], nums1[mid])) / 2.0;
                }
            }
            if (mid === 0) {
                if (((m + n) & 1) === 1) {
                    //console.log(res);
                    return nums2[res - 1];
                } else {
                    //console.log(res);
                    return (nums2[res - 1] + Math.min(nums2[res], nums1[mid])) / 2.0;
                }
            }
            if (res === m) {
                if (((m + n) & 1) === 1) {
                    return Math.max(nums1[mid - 1], nums2[res - 1]);
                } else {
                    return (Math.max(nums1[mid - 1], nums2[res - 1]) + nums1[mid]) / 2.0;
                }
            }

            if (res === n) {
                if (((m + n) & 1) === 1) {
                    return Math.max(nums1[mid - 1], nums2[res - 1]);
                } else {
                    return (Math.max(nums1[mid - 1], nums2[res - 1]) + nums2[res]) / 2.0;
                }
            }

            let max_left = Math.max(nums1[mid - 1], nums2[res - 1]);
            let min_right = Math.min(nums1[mid], nums2[res]);
            if (((m + n) & 1) === 1) {
                return max_left;
            } else {
                return (max_left + min_right) / 2.0;
            }
        }
    }
};

console.log(findMedianSortedArrays(a, b));