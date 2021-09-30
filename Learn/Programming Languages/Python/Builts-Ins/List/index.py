nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
objs = [
    { 'name': 'John'    , 'age': 20 },
    { 'name': 'Jane'    , 'age': 21 },
    { 'name': 'Joe'     , 'age': 22 },
    { 'name': 'Jack'    , 'age': 23 },
    { 'name': 'Jill'    , 'age': 24 },
    { 'name': 'Jim'     , 'age': 25 },
    { 'name': 'Jenny'   , 'age': 26 },
]

numIndex = nums.index(6)
objIndex1 = objs.index({ 'name': 'Jane', 'age': 21 })
objIndex2 = objs.index(objs[1])


print(numIndex)
print(objIndex1)
print(objIndex2)