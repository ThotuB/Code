import re

# TODO
def isMatch(text: str, pattern: str) -> bool:
    text_idx, pattern_idx = 0, 0
    
    while text_idx < len(text):
        pattern_char = pattern[pattern_idx]
        
        if pattern_char == '.':
            continue
        else:
            pattern_next_char = pattern[pattern_idx + 1]
            
            if pattern_next_char == '*':
                while text[text_idx] == 
            

def regex_test(text: str, pattern: str) -> bool:
    return 

if __name__ == '__main__':
    assert isMatch('aa', 'a') == False
    assert isMatch('aaa', 'a*') == True
    assert isMatch('ab', '.*') == True
    assert isMatch('aab', 'c*a*b') == True