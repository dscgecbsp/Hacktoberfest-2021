def maxDepth(s: str) -> int:
    res = cur = 0
    for c in s:
        if c == '(':
            cur += 1
            res = max(res, cur)
        if c == ')':
            cur -= 1
    return res 

s = str(input())
print(maxDepth(s))
