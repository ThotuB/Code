def encode(flag):
    return ''.join([chr((ord(flag[i]) << 8) + ord(flag[i + 1])) for i in range(0, len(flag), 2)])

def decode(flag):
    return ''.join([chr(ord(char) >> 8) + chr(ord(char) & 0xFF) for char in flag])

text = "灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸彥ㄴㅡて㝽"
print(decode(text))