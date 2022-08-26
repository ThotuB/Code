open_parentheses = ['(', '{', '[']
close_parentheses = [')', '}', ']']

def isValid(s: str) -> bool:
    stack = []
    
    for char in s:
        if char in open_parentheses:
            stack.append(char)
        elif char in close_parentheses:
            if not stack:
                return False
            if stack.pop() != open_parentheses[close_parentheses.index(char)]:
                return False
            
    return len(stack) == 0

if __name__ == '__main__':
    