import os

fileignore = [
    ".git", ".font", "01-STL", "11-构建LaTeX", "in", "00-封装类",
    "in.txt", "out.txt", ".ogmc", "o-o", ".gitignore"
]

# 向要生成的模板写入准备好的头部与尾部
def writetex(filename):
    fp = open(filename, "r")
    while True:
        buff = fp.readline()
        if len(buff) == 0:
            break
        tex.write(buff)
    fp.close()


def getLaTeX(path, depth):
    files = os.listdir(path)                        # 得到文件夹下的所有文件(包括文件夹)名称
    files.sort()                                    # 排序
    for file in files:                              # 遍历当前文件夹下所有文件
        if os.path.isdir(path + file):              # 如果是文件夹，递归
            if file in fileignore:                  # 排除无关文件夹
                continue
            if depth == 0:                          # 一级目录特判
                tex.write("\\section{" + file + "}\n")
            else:
                str = "sub"
                for i in range(1, depth):
                    str += "sub"
                if (len(str) > 6):                  # 三级目录特判
                    tex.write("\\paragraph{" + file + "}\n")
                    continue
                tex.write("\\" + str + "section{" + file + "}\n")
            getLaTeX(path + file + "/", depth + 1)  # 递归寻找下一级目录
        elif os.path.isfile(path + file):           # 如果是文件
            if file in fileignore:                  # 排除无关文件夹
                continue
            #  if depth == 1:
            #      str = "sub"
            #  elif depth == 2:
            #      str = "subsub"
            str = "sub"
            for i in range(1, depth):
                str += "sub"
            if (len(str) > 6):
                tex.write("\\paragraph{" + file + "}\n")
                tex.write("\\lstinputlisting{" + "." + path + file + "}\n")
                continue
            tex.write("\\" + str + "section{" + file + "}\n")
            tex.write("\\lstinputlisting{" + "." + path + file + "}\n")


os.chdir("..")                                      # 设置路径为..
tex = open("./11-构建LaTeX/template.tex", "w")      # 打开template.tex文件
writetex("./11-构建LaTeX/LaTeX-Head")               # 写入准备好的模板头
path = "./"                                         # 路径还是..
getLaTeX(path, 0)                                   # 从path开始写入模板
writetex("./11-构建LaTeX/LaTeX-Tail")               # 写入准备好的模板尾
tex.close()                                         # 关闭文件
