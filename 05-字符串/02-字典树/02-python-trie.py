class trie:
    nex = [[0 for i in range(26)] for j in range(100000)]
    cnt = 0
    exist = [False] * 100000 # 该结点结尾的字符串是否存在

    def insert(s, l): # 插入字符串
        p = 0

        for i in range(0, l):
            c = ord(s[i]) - ord('a')
            if nex[p][c] == 0:
                nex[p][c] = cnt # 如果没有，就添加结点
            cnt += 1
            p = nex[p][c]
            exist[p] = True

    def find(s, l): # 查找字符串
        p = 0
        for i in range(0, l):
            c = ord(s[i]) - ord('a')
            if nex[p][c] == 0:
                return False
            p = nex[p][c]
            return exist[p]
