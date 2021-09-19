def findMedianSortedArrays(nums1: list[int], nums2: list[int]) -> float:
    s = nums1 + nums2
    n = len(s)
    s.sort()

    if n % 2 == 0:
        m1 = s[n//2]
        m2 = s[n//2 - 1]
        m = (m1 + m2)/2
    else:
        m= s[n//2]
    return m