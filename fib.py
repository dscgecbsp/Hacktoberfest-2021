def fib(n):
    if n==0:
        return 0
    if n<=2:
        return 1
    arr=[-1 for i in range(n+1)]
    arr[0]=0
    arr[1]=1
    arr[2]=1
    return fib3(arr,n)
def fib3(arr,n):
    if arr[n]!=-1:
        return arr[n]
    arr[n] = fib3(arr,n-1)+fib3(arr,n-2)+fib3(arr,n-3)
    print(arr,n)
    return arr[n]
print(fib(25))