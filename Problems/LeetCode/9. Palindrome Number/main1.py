def isPalindrome(x: int) -> bool:
    if x < 0:
        return False

    copy_x = x
    reverse_x = 0
    while copy_x > 0:
        reverse_x = reverse_x * 10 + copy_x % 10
        copy_x = copy_x // 10

    return reverse_x == x

if __name__ == '__main__':
    isPalindrome(121)
    isPalindrome(-121)
    isPalindrome(10)
    isPalindrome(0)
    isPalindrome(22344322)
    isPalindrome(22345322)