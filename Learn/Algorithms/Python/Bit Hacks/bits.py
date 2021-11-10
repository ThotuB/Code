def nibble(num):
    def nibble_gen(num):
        """
        Generator for nibbles of a number
        """
        while num:
            yield f'{num & 0xF:b}'.zfill(4)
            num >>= 4
    return "-".join(list(nibble_gen(num))[::-1])

def byte(num):
    def byte_gen(num):
        """
        Generator for bytes of a number
        """
        while num:
            yield f'{num & 0xFF:b}'.zfill(8)
            num >>= 8
    return "-".join(list(byte_gen(num))[::-1])