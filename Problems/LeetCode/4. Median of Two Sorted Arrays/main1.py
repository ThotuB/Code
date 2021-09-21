def merge(nums1: list[int], nums2: list[int]) -> list:
    merged_arr = []
    
    i = 0
    j = 0

    while i < len(nums1) and j < len(nums2):
        if nums1[i] < nums2[j]:
            merged_arr.append(nums1[i])
            i += 1
        else:
            merged_arr.append(nums2[j])
            j += 1
    
    while i < len(nums1):
        merged_arr.append(nums1[i])
        i += 1
    
    while j < len(nums2):
        merged_arr.append(nums2[j])
        j += 1

    return merged_arr

def findMedianSortedArrays(nums1: list[int], nums2: list[int]) -> float:
    merged_arr = merge(nums1, nums2)
    n = len(merged_arr)

    if n % 2 == 0:
        return (merged_arr[n // 2] + merged_arr[n // 2 - 1]) / 2
    else:
        return merged_arr[n // 2]


if __name__ == '__main__':
    print(findMedianSortedArrays([1, 2], [3, 4]))