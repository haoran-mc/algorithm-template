<!-- -------------------------2020年11月17日 ---- 17时11分------------------------- -->

```cpp
vector<int> radius, let;
string expa_str;
void Manacher(const string &str, int &pos, int &max_len) {
    int orig_len = str.length();
    int expa_len = (orig_len + 1) << 1;
    max_len  = 0;
    radius.resize(expa_len + 1);
    expa_str.resize(expa_len + 1);
    //@#0#1#2#3#4#5#6#7#8#9#$
    expa_str[0] = '@';
    expa_str[1] = '#';
    expa_str[expa_len] = '$';
    for (int i = 1; i <= orig_len; ++i) {
        expa_str[i << 1] = str[i-1];
        expa_str[i << 1 | 1] = '#';
    }
    radius[1] = 1;
    for (int max_R = 0, center = 0, i = 2; i < expa_len; ++i) {
        radius[i] = i < max_R ? min(max_R-i, radius[2*center-i]) : 1;
        while (expa_str[i-radius[i]] == expa_str[i+radius[i]])
            ++radius[i];
        if (radius[i] + i > max_R) {
            max_R = radius[i] + i;
            center = i;
        }
        if (radius[i]-1 > max_len) {
            max_len = radius[i]-1;
            pos     = (center - radius[i] + 1) << 1;
        }
    }
}

//odd为false，字符串为奇回文串
int start_mid(int x, bool odd) {
    return odd ? radius[(x+1) << 1] - 1 : radius[(x+1) << 1 | 1] - 1;
}

//知道回文左边界，且在Manacher函数运行结束后使用
int start_left(int x, string str) {
    int expand_len = (str.length() + 1) << 1;
    let.resize(expand_len + 1);
    for (int i = 0; i <= expand_len; i++)
        let[i] = 0;
    for (int i = 2; i < expand_len; i++)
        if (let[i - radius[i] + 1] < i + 1)
            let[i - radius[i] + 1] = i + 1;
    for (int i = 1; i <= expand_len; i++)
        if (let[i] < let[i - 1])
            let[i] = let[i - 1];
    return let[(x + 1) << 1] - ((x + 1) << 1);
}
```
