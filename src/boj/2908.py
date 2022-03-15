import sys

input = sys.stdin.readline

a, b = input().rstrip().split()
a = int(a[::-1])
b = int(b[::-1])
print(a if a > b else b)
