n = eval(input())
res = 1

# 以换行结束输入
for i in range(n):
    x = eval(input())
    res = res * x

print(res)
