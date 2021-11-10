from bits import *

def set_bit(num, pos):
    return num | (1 << pos)


def reset_bit(num, pos):
    return num & ~(1 << pos)


def flip_bit(num, pos):
    return num ^ (1 << pos)


def check_bit(num, pos):
    return num & (1 << pos)


def flip_trailing_zeros(num):
    return num | (num - 1)


def ls_1(num):
    return num & -num


def ls_0(num):
    return ls_1(~num)


def masked_copy(num1, num2, mask):
    return (num1 & ~mask) | (num2 & mask)


def swap_bits(num, pos1, pos2):
    diff = (num >> pos1) ^ (num >> pos2) & 0b1
    num ^= diff << pos1
    num ^= diff << pos2
    return num


def switch_mask(num):
    return num ^ (num >> 1)


def reset_ls_1(num):
    return num & (num - 1)


def count_1s(num):
    count = 0
    while num:
        count += 1
        num = reset_ls_1(num)
    return count


def count_switches(num):
    return (num & 0b1) + (count_1s(switch_mask(num))) >> 1


def bit_scan_forward(num):
    if num == 0:
        return -1
    num = ls_1(num)
    index = 0
    if num & 0xffff0000:
        index += 16
    if num & 0xff00ff00:
        index += 8
    if num & 0xf0f0f0f0:
        index += 4
    if num & 0xcccccccc:
        index += 2
    if num & 0xaaaaaaaa:
        index += 1
    return index


def next_lex_perm(num):
    t = flip_trailing_zeros(num)
    return (t + 1) | (ls_0(t) - 1) >> (bit_scan_forward(t) + 1)

num = 0b0111_0101_0100

print(f'num: {num:08b}')
print(f'set: {set_bit(num, 3):08b}')
print(f'reset: {reset_bit(num, 2):08b}')
print(f'flip: {flip_bit(num, 3):08b}')
print(f'check: {check_bit(num, 3):08b}')
print(f'flip trailing 0s: {flip_trailing_zeros(num):08b}')
print(f'ls_1: {ls_1(num):08b}')
print(f'masked copy: {masked_copy(num, 0b1010_1010, 0b1010):08b}')
print(f'swap bits: {swap_bits(num, 3, 4):08b}')
print(f'reset ls_1: {reset_ls_1(num):08b}')
print(f'count 1s: {count_1s(num)}')
print(f'count switches: {count_switches(num)}')
print(f'bit scan forward: {bit_scan_forward(num)}')