def product_of_array_except_self(inputs: list):
    product = 1
    for i in inputs:
        product *= i
        
    products = [product // inputs[i] for i in range(len(inputs))]
    
    return products

def product_of_array_except_self_no_division(inputs: list):
    left_products = [1]
    right_products = [1]

    for i in range(len(inputs) - 1):
        left_products = left_products + [left_products[i] * inputs[i]]
        
    for i in range(len(inputs) - 1):
        right_products = [right_products[0] * inputs[len(inputs) - i - 1]] + right_products

    products = [left_products[i] * right_products[i] for i in range(len(inputs))]

    return products


lst = [1, 2, 3, 4]
print(product_of_array_except_self(lst))
print(product_of_array_except_self_no_division(lst))