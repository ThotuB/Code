def rot(text: str, n):
    new_s = ""
    for char in text:
        if char.isalpha():
            if char.isupper():
                new_s += chr((ord(char) - ord('A') + n) % 26 + ord('A'))
            else:
                new_s += chr((ord(char) - ord('a') + n) % 26 + ord('a'))
        else:
            new_s += char
    return new_s

if __name__ == '__main__':
    cypher_flag = "cvpbPGS{arkg_gvzr_V'yy_gel_2_ebhaqf_bs_ebg13_nSkgmDJE}"
    
    print(rot(cypher_flag, 13))
    # print('a' + 4)
    