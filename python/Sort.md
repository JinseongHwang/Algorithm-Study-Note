# 정렬 (Sort)

<br>

## sort 함수 사용하기

```python
int_ls = [3, 4, 2, 5, 6, 2, 7, 9, 8, 7]
# 오름차순 정렬하기
int_ls.sort()
print(int_ls)  # [2, 2, 3, 4, 5, 6, 7, 7, 8, 9]

# 내림차순 정렬하기
int_ls.sort(reverse=True)
print(int_ls)  # [9, 8, 7, 7, 6, 5, 4, 3, 2, 2]

str_ls = ['Donghyuk', 'Sangkeun', 'Sunyoung', 'Wonseob', 'Sanghyun', 'Sei',
		  'Kangsoo', 'Haebin', 'Junkyu', 'Soong', 'Taewhan']
# 문자열 사전 순 정렬. 단, ASCII 상 정렬이기 때문에 대문자가 소문자보다 앞에 온다.
str_ls.sort()
print(str_ls)

# 문자열 길이 순 정렬.
str_ls.sort(key=lambda s: len(s))
print(str_ls)
```

- `sorted()` 와 다른 점으로, `sorted()` 는 대상 시퀀스를 정렬한 결과를 반환하며, 실제 대상 시퀀스에는 영향을 미치지 않는다. 
- 반면에, `sort()` 는 대상 시퀀스 자체를 정렬한다.

<br>

## sorted 함수 사용하기

```python
int_ls = [3, 4, 2, 5, 6, 2, 7, 9, 8, 7]
sorted_int_ls = sorted(int_ls)

print(int_ls)  # [3, 4, 2, 5, 6, 2, 7, 9, 8, 7]
print(sorted_int_ls)  # [2, 2, 3, 4, 5, 6, 7, 7, 8, 9]
```

<br>

## 커스텀 정렬 함수 만들기(key 재정의)

- [백준 10825 국영수](https://www.acmicpc.net/problem/10825) 로 실습해보자.

```python
n = int(input())
data = []
for _ in range(n):
	inp = input().split()
	# [0]: 학생 이름
	stu = [inp[0]]
	# [1]: 국어 점수, [2]: 영어 점수, [3] 수학 점수
	stu.extend(map(int, inp[1:]))
	data.append(stu)

# lambda의 반환 값으로 정렬 기준을 순서대로 tuple로 작성
# 인자 그대로 넣으면 오름차순, 인자에 - 를 붙이면 내림차순
data.sort(key=lambda d: (-d[1], d[2], -d[3], d[0]))
```

<br>

## 커스텀 정렬 함수 만들기(cmp_to_key 활용)

```python
from functools import cmp_to_key

```

<br>

## 커스텀 정렬 함수 만들기(cmp_to_key 활용)

- [백준 10825 국영수](https://www.acmicpc.net/problem/10825) 로 실습해보자.

```python
from functools import cmp_to_key

# 항상 앞 인자(arg1)를 기준으로 한다.
# -1, 0을 반환하면 그대로, +1을 반환하면 뒤집기 
def compare(arg1, arg2):
	# 국어 점수가 작은 경우
	if arg1[1] < arg2[1]:
		return +1

	# 국어 점수가 같은 경우
	elif arg1[1] == arg2[1]:

		# 영어 점수가 작은 경우
		if arg1[2] < arg2[2]:
			return -1

		# 영어 점수가 같은 경우
		elif arg1[2] == arg2[2]:

			# 수학 점수가 작은 경우
			if arg1[3] < arg2[3]:
				return +1

			# 수학 점수가 같은 경우
			elif arg1[3] == arg2[3]:

				# 이름 사전 순 정렬
				if arg1[0] < arg2[0]:
					return -1
				elif arg1[0] == arg2[0]:
					return 0
				elif arg1[0] > arg2[0]:
					return +1

			# 수학 점수가 큰 경우
			elif arg1[3] > arg2[3]:
				return -1

		# 영어 점수가 큰 경우
		elif arg1[2] > arg2[2]:
			return +1

	# 국어 점수가 다른 경우
	elif arg1[1] > arg2[1]:
		return -1


def solution():
	n = int(input())
	data = []
	for _ in range(n):
		inp = input().split()
		# [0]: 학생 이름
		stu = [inp[0]]
		# [1]: 국어 점수, [2]: 영어 점수, [3] 수학 점수
		stu.extend(map(int, inp[1:]))
		data.append(stu)

	data.sort(key=cmp_to_key(compare))
```
