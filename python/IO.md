# 파이썬 입출력(Input/Output)

## 입력 최적화

```python
import sys

# input 메서드를 아래와 같이 재정의 해서 사용하자.
input = sys.stdin.readline

a, b = map(int, input().split()) # input : 1 2
print(a + b) # 3

""" input
1 2 3 4 5 
6 7 8 9 0
"""
raw = 2
data = [list(map(int, input().split())) for _ in range(raw)]
print(data) # [[1, 2, 3, 4, 5], [6, 7, 8, 9, 0]]
```

- `input` 과 `sys.stdin.readline` 는 무엇이 다를까?
- `input` 은 한 줄을 입력 받고, 마지막에 개행 문자를 삭제한다. 인자로 문자열을 넣어주면 prompt message 역할을 수행한다.
- `sys.stdin.readline` 은 한 줄 입력만 해준다. 개행문자 삭제 X, prompt message 기능 X
- 참고자료는 [여기](https://buyandpray.tistory.com/7)

## 입력(Input)

```python
value1 = input('숫자를 입력하세요: ')  # input: 10
value2 = input('숫자를 입력하세요: ')  # input: 20
print(value1 + value2)  # expected output: '1020'

value1 = int(input('숫자를 입력하세요: '))  # input: 10
value2 = int(input('숫자를 입력하세요: '))  # input: 20
print(value1 + value2)  # expected output: 30

value1, value2 = input('숫자 두 개를 입력하세요: ').split()  # input: 10 20
print(value1 + value2)  # expected output: '1020'

value1, value2 = input('숫자 두 개를 입력하세요: ').split()  # input: 10 20
value1 = int(value1)  # 정수로 변환
value2 = int(value2)  # 정수로 변환
print(value1 + value2)  # expected output: 30

value1, value2 = input('숫자 두 개를 입력하세요: ').split()  # input: 10 20
print(int(value1) + int(value2))  # expected output: 30

value1, value2 = map(int, input('숫자 두 개를 입력하세요: ').split())  # input: 10 20
print(value1 + value2)  # expected output: 30
```

## 출력(Output)

```python
# 가장 기본적인 형태의 출력
print('hello') # hello

# default seperator = ' ' 이지만, 재정의 할 수 있다.
print('hello', 'world', sep='_') # hello world

# default end = '\n' 이지만, 재정의 할 수 있다.
print('hello', end='@') # hello@ (개행없음)
print('world') # world (개행있음)

# 시퀀스를 출력하고 싶은데, delimiter를 바꾸고 싶다면 문자열에 join을 쓰자.
res = ['A', 'B', 'C']
print('#'.join(res)) # A#B#C

# f-string (formated string literal) 활용 (3.6+)
idx = 1
name = 'jinseong'
res = f'{idx} : {name}'
print(res) # 1 : jinseong
print(f'{idx + 10} : {name + "ABC"}') # 11 : jinseongABC
```