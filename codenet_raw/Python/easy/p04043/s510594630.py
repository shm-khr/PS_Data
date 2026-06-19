require = ['5','7','5']
data = input().split()
result = True
for d in data:
    if d in require:
        require.pop(require.index(d))
    else:
        result = False
        break
print(result)