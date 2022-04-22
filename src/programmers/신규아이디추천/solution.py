import re

def solution(new_id):
    # 1
    s = new_id.lower()
    # 2
    s = re.sub('[^a-z0-9\-_.]', '', s)
    # 3
    s = re.sub('[.]+', '.', s)
    # 4
    s = re.sub('^[.]|[.]$', '', s)
    # 5
    if len(s) == 0:
        s = 'a'
    # 6
    if len(s) >= 16:
        s = s[:15]
    s = re.sub('[.]$', '', s)
    # 7
    if len(s) <= 2:
        while len(s) < 3:
            s += s[-1]

    return s

if __name__ == '__main__':
    print(solution("...!@BaT#*..y.abcdefghijklm"))