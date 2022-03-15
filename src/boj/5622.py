arr = [
	'ABC',
	'DEF',
	'GHI',
	'JKL',
	'MNO',
	'PQRS',
	'TUV',
	'WXYZ'
]
dic = {}
for idx, str in enumerate(arr):
	for ch in str:
		dic[ch] = idx + 3

print(sum([dic[ch] for ch in list(input())]))
