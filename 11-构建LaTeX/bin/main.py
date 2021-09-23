import os


cnt = 0
buff = ""
sect = []
File_name = ""
File_file = ""


def File_div(str):
    name = 0
    file = 0
    global File_name
    global File_file
    i = 0
    while str[i] and str[i] != "<":
        i += 1
    if str[i]:
        i += 1
    while str[i] and str[i] != ">":
        if name == 0:
            File_name = str[i]
        else:
            File_name = File_name[:name] + str[i]
        name += 1
        i += 1
    while str[i] and str[i] != "<":
        i += 1
    if str[i]:
        i += 1
    while str[i] and str[i] != ">":
        if file == 0:
            File_file = str[i]
        else:
            File_file = File_file[:file] + str[i]
        file += 1
        i += 1


def readContents():
    global cnt
    dirname = open("./build/Contents", "r")
    while True:
        cnt += 1
        line = dirname.readline()
        if len(line) == 0:
            break
        sect.append(line)
    dirname.close()


def LaTeXFile(filename):
    fp = open(filename, "r")
    while True:
        buff = fp.readline()
        if len(buff) == 0:
            break
        tex.write(buff)
    fp.close()


os.chdir("..")                                                      # 设置路径为..
tex = open("./build/template.tex", "w")                             # 打开template.tex文件
LaTeXFile("./build/LaTeX-Head")                                     # 写入准备好的模板头
readContents()                                                      # 一级目录
for i in range(cnt - 1):                                            # 遍历一级目录
    tex.write("\\section{" + sect[i][: len(sect[i]) - 1] + "}\n")
    buff = sect[i]
    buff = buff[: len(buff) - 1]   # 删去回车
    if len(buff) == 0:
        break
    buff += "/Files"
    fp = open(buff, "r")
    while True:
        buff = fp.readline()
        if len(buff) == 0:
            break
        if buff[0] != "<":
            break
        File_div(buff)
        tex.write("\\subsection{" + File_name + "}\n")
        buff = sect[i]
        buff = buff[: len(buff) - 1]
        buff += "/"
        buff += File_file
        tex.write("\\lstinputlisting{" + "../" + buff + "}\n")
    fp.close()
LaTeXFile("./build/LaTeX-Tail")
tex.close()
