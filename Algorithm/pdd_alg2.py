# 给定两个排列line2,line3; 要求line3在s步变成line2，期间每步可使用如下三种方法变成line2：
# 取line3最左边的元素放在新排列的最左边
# 取line3最左边的元素放在新排列的最右边
# 删除line3最左边的元素

import sys

while True:
    line1 = sys.stdin.readline().strip()
    if line1 == '':
        break
    line2 = sys.stdin.readline().strip()
    line3 = sys.stdin.readline().strip()
    s = int(line1)
    path = []

    def dfs(cnt, p, cur, extra):
        if cnt == s:
            if cur == line3:
                path.append(cur)
                return
            else:
                return
        cnt += 1
        t = extra[0]
        extra = extra[1:]
        if t not in line3:
            p.append('')


