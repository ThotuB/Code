arr = [1, 2, 3, 4]
rres = map(lambda x: x if (x % 2 == 0) else x + 1, arr)
print(list(rres))