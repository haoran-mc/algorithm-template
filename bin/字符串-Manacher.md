<!-- -------------------------2020年11月17日 ---- 17时11分------------------------- -->

### Manacher

```cpp
vector<int> radius, let;  /*回文子串半径*/
string expa_str; /*扩展后的串*/
/*原串、最长回文子串开始位置、最长回文子串长度*/
void Manacher(const string &str, int &pos, int &max_len) {
    int orig_len = str.length(); /*原串长度*/
    int expa_len = (orig_len + 1) << 1; /*扩展串长度*/
    max_len  = 0;
    radius.resize(expa_len + 1);
    expa_str.resize(expa_len + 1);
    //@#0#1#2#3#4#5#6#7#8#9#$
    expa_str[0] = '@';
    expa_str[1] = '#';
    /*expa_len是扩展串的长度减一，不过串从零开始*/
    expa_str[expa_len] = '$';
    for (int i = 1; i <= orig_len; ++i) {
        /*偶位置对应原串字符*/
        expa_str[i << 1] = str[i-1];
        /*不更改奇位置，只更改偶位置*/
        expa_str[i << 1 | 1] = '#';
    }
    radius[1] = 1; /*显然回文子串半径大于等于1*/
    //本应该计算到enpa_len + 1的，但那个位置是'#'，不需要计算了
    for (int max_R = 0, center = 0, i = 2; i < expa_len; ++i) {
        /*根据i探查到的位置是否超过了最右回文子串的右边界，初始化i的回文半径，核心操作*/
        radius[i] = i < max_R ? min(max_R-i, radius[2*center-i]) : 1;
        /*暴力拓展中心在i位置的最长回文子串半径radius[i]*/
        while (expa_str[i-radius[i]] == expa_str[i+radius[i]])
            ++radius[i];
        /*更新最右回文子串的右边界*/
        if (radius[i] + i > max_R) {
            max_R = radius[i] + i;
            center = i;
        }
        /*更新最长回文子串的位置与长度*/
        if (radius[i] - 1 > max_len) {
            /*原串的最长回文子串*/
            max_len = radius[i] - 1;
            /*原串的最长回文子串的起点*/
            pos     = (center - radius[i] + 1) >> 1;
        }
    }
}

//odd为false，字符串为奇回文串
//以x为中心的最长回文子串的长度
//如果为偶回文串，则以x, x+1中心为中心的最长回文子串的长度
int start_mid(int x, bool odd) {
    return odd ? radius[(x+1) << 1] - 1 : radius[(x+1) << 1 | 1] - 1;
}

//知道回文左边界，且在Manacher函数运行结束后使用
int start_left(int x, string str) {
    //let[i]表示以x为起点，的最长回文子串的中心位置
    int expand_len = (str.length() + 1) << 1;
    //let数组在扩展之后的字符串上，以位置i为起点的最长回文子串的中心在哪里
    let.resize(expand_len + 1);
    //计算维护以每个位置为起点的最长回文串
    for (int i = 0; i <= expand_len; i++)
        let[i] = 0;
    for (int i = 2; i < expand_len; i++)
        if (let[i - radius[i] + 1] < i + 1)
            let[i - radius[i] + 1] = i + 1;
    for (int i = 1; i <= expand_len; i++)
        if (let[i] < let[i - 1])
            let[i] = let[i - 1];
    //返回以x为起点的最长回文子串的长度
    return let[(x + 1) << 1] - ((x + 1) << 1);
}

int main() {
    //string str = "0123456789";
    string str = "DDDDBBDBA|BCBAAABBAAABCB|DB";
    string subStr;
    int pos;
    int max_len;
    Manacher(str, pos, max_len);
    printf("pos     = %d\n", pos);
    printf("max_len = %d\n", max_len);
    cout << "subStr  = " << str.substr(pos, max_len) << endl;
    printf("length  = %d\n", start_left(pos, str));
    printf("length  = %d\n", start_mid(pos+max_len/2-1, false));
    return 0;
}
```
