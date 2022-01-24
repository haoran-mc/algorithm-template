#include <cstdio>
#include <cstring>
const int maxn = 1000;
int cnt;
char sec[100][maxn];
FILE* tex = NULL;
char buff[maxn];
char File_name[maxn], File_file[maxn];

void File_div(const char s[]) {
    int nl = 0, fl = 0;
    int i = 0;
    while (s[i] && s[i] != '<') ++i;
    if (s[i]) ++i;
    while (s[i] && s[i] != '>')
        File_name[nl++] = s[i++];
    while (s[i] && s[i] != '<') ++i;
    if (s[i]) ++i;
    while (s[i] && s[i] != '>')
        File_file[fl++] = s[i++];
    File_name[nl] = File_file[fl] = 0;
}

void readContents() {
    FILE* dirname = fopen("Contents", "r");
    while (fgets(sec[cnt++], maxn, (FILE*)dirname) != NULL) {
        continue;
    }
    fclose(dirname);
    //去除最后一个
    while (sec[cnt-1][0] == 0 && cnt > 0)
        --cnt;
    for (int i = 0; i < cnt; ++i)
        //如果最后一位不是回车，就换成回车
        if (sec[i][strlen(sec[i])-1] != 0)
            sec[i][strlen(sec[i])-1] = 0;
}

void LaTeXFile(const char* filename) {
    FILE* fp = fopen(filename, "r");
    while (fgets(buff, maxn, fp) != NULL)
        fprintf(tex, "%s", buff);
    fclose(fp);
}

int main() {
    tex = fopen("template.tex", "w");
    LaTeXFile("LaTeX-Head");
    readContents();
    for (int i = 0; i < cnt; ++ i) {
        fprintf(tex, "\\section{%s}\n", sec[i]);
        memcpy(buff, sec[i], sizeof buff);
        strcat(buff, "/Files");
        FILE* fp = fopen(buff, "r");
        while(fgets(buff, maxn, fp)) {
            if (buff[0] != '<') break;
            // lb.solve(buff);
            File_div(buff);
            fprintf(tex, "\\subsection{%s}\n", File_name);
            memcpy(buff, sec[i], sizeof buff);
            //添加回车，否则strcat就会把后面的也连接起来
            buff[strlen(buff)+1] = 0;
            buff[strlen(buff)] = '/';
            strcat(buff, File_file);
            fprintf(tex, "\\lstinputlisting{%s}\n", buff);
        }
        fclose(fp);
    }
    LaTeXFile("LaTeX-Tail");
    fclose(tex);
    return 0;
}
