from collections import Counter

def intersect(nums1: list[int], nums2: list[int]) -> list[int]:
    intersection = []

    count = Counter(nums1)
    for num in nums2:
        if num in count and count[num] > 0:
            intersection.append(num)
            count[num] -= 1

    return intersection

if __name__ == "__main__":
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    print(intersect(nums1, nums2))