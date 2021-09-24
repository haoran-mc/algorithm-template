import os


fileignore = [
        ".git", ".font", "00-测试", "11-构建LaTeX", "in",
        "in.txt", "out.txt", ".ogmc", "o-o", ".gitignore", "README.md"
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
    files = os.listdir(path)                                    # 得到文件夹下的所有文件(包括文件夹)名称
    files.sort()                                                # 排序
    for file in files:                                          # 遍历当前文件夹下所有文件
        # 除去文件的数字前缀
        if len(file) > 3 and file[2] == "-":
            fileNameWithoutNum = file[3: len(file)]
        else:
            fileNameWithoutNum = file
        if os.path.isdir(path + file):                          # 如果是文件夹，递归；如果是文件，写入.tex
            if file in fileignore:                              # 排除无关文件夹
                continue
            if depth == 3:                                      # 四级及以上的目录直接过滤
                continue
            if not os.listdir(path + file):                     # 空文件夹
                continue
            else:
                str = "sub" * depth
                str += "section"                                # 根据depth生成相应等级的目录
                tex.write("\\" + str + "{" + fileNameWithoutNum + "}\n")
                getLaTeX(path + file + "/", depth + 1)          # 递归寻找下一级目录
        elif os.path.isfile(path + file):                       # 如果是文件
            if file in fileignore:                              # 排除无关文件
                continue
            if depth == 3:                                      # 四级文件使用\paragraph
                tex.write("\\paragraph{" + fileNameWithoutNum + "}\n")
                tex.write("\\noindent\n")
                tex.write("\\lstinputlisting{" + "." + path + file + "}\n")
            else:
                str = "sub" * depth
                str += "section"
                tex.write("\\" + str + "{" + fileNameWithoutNum + "}\n")
                tex.write("\\lstinputlisting{" + "." + path + file + "}\n")


os.chdir("..")                                      # 设置路径为..
tex = open("./11-构建LaTeX/template.tex", "w")      # 打开template.tex文件
writetex("./11-构建LaTeX/LaTeX-Head")               # 写入准备好的模板头
path = "./"                                         # 路径还是..
getLaTeX(path, 0)                                   # 从path开始写入模板
writetex("./11-构建LaTeX/LaTeX-Tail")               # 写入准备好的模板尾
tex.close()                                         # 关闭文件
