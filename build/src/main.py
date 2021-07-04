#  import os


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
    #  File_name = File_name[:name] + "\0"
    #  File_file = File_file[:file] + "\0"


def readContents():
    global cnt
    dirname = open("Contents", "r")
    while True:
        cnt += 1
        line = dirname.readline()
        if len(line) == 0:
            break
        #  line = line[: len(line) - 1]
        #  print(line)
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


tex = open("template.tex", "w")
LaTeXFile("LaTeX-Head")
readContents()
#  os.chdir("..")
for i in range(cnt - 1):
    #  print(i, sect[i])
    tex.write("\\section{" + sect[i][: len(sect[i]) - 1] + "}\n")
    buff = sect[i]
    buff = buff[: len(buff) - 1]
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
        #  buff[len(buff) + 1] = 0
        #  buff[len(buff)] += "/"
        buff = buff[: len(buff) - 1]
        buff += "/"
        buff += File_file
        tex.write("\\lstinputlisting{" + buff + "}\n")
    fp.close()
LaTeXFile("LaTeX-Tail")
tex.close()
