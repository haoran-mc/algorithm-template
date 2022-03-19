# VECTOR
## vector的定义
vector翻译为映射，可以将任何基本类型(包括STL容器)映射到任何基本类型(包括STL容器) 

```cpp
vector<T> vec1; /+创建了vec1+/
vector<T> vec2(vec1); /+创建的vec2中包含vec1中所有副本+/
vector<T> vec2 = vec1; /+创建的vec2中包含vec1中所有副本+/
vector<T> vec3(n, val); /+创建的vec3中包含了n个重复的元素，每个元素的值都是val+/
vector<T> vec4(n); /+创建的vec4中包含了n个重复地执行了值初始化的对象+/
vector<T> vec5{a, b, c ...}; /+创建的vec5中包含了初始化个树的对象，每个元素被赋予相应的初始值+/
vector<T> vec5 = {a, b, c ...}; /+创建的vec5中包含了初始化个树的对象，每个元素被赋予相应的初始值+/
```
## 常用函数
‐ begin
‐ end
‐ push_back O(1)
‐ pop_back O(1)
‐ size O(1)
‐ clear O(N)
‐ insert(it, x) O(N)
‐ erase O(N)
‐ rbegin
‐ rend
‐ front
‐ back
‐ vec2 = vec1
## 去重
```cpp
sort(ys.begin(), ys.end());
ys.erase(unique(ys.begin(), ye.end()), ys.end());
```
# STRING
## 字符串的输入输出
‐ string的输入输出
+ cin遇到空格或换行停止输入
+ getline(cin, str)是iostream中一个独立的函数，遇到换行结束输入
+ str.c_str将string类型转换为字符数组进行输出
+ cin.get与cin.getline是cin的成员，不能完成string类型变量的输入
## 常用函数
‐ operator string字符串可以与ch字符之间进行operator运算
‐ size O(1)
‐ length O(1)
‐ insert O(1)
+ insert(pos, str)
+ insert(str1_it, str2_begin, str2_end)
‐ erase O(N)
+ erase(it)
+ erase(first, last)
+ erase(pos, length)
‐ clear O(1)
‐ substr(pos, len) O(len)
‐ string::npos 是一个常数，其本身的值为‐1，但由于是unsigned_int类型，因此实际上也可以认为是unsigned_int类型的最大值
+ string::npos用以作为find函数失配时的返回值
‐ find O(nm)
+ str1.find(str2)
+ str1.find(str2, pos)
+ 查询不到返回string::npos
‐ replace O(str1.length())
+ str1.replace(pos, len, str2)，把str从pos位开始，长度为len的子串替换为str2
+ str1.replace(it_begin, it_end, str2)，把str的迭代器[it_begin, it_end)范围内的子串替换为str2
# SET
## 常用函数
‐ count 判断元素是否在集合set中，存在返回1个，不存在返回0个
‐ insert O(logN)
‐ find O(logN) 没找到返回st.end()
chang university ACM template 第 4 页
‐ erase
+ st.erase(it) O(1)
+ st.erase(val) O(logN)
+ st.erase(first, last) O(last ‐ first)
‐ size O(1)
‐ clear O(N)
‐ lower_bound :: st.lower_bound(key)，返回set中第一个大于等于key的迭代器指针
‐ upper_bound :: st.upper_bound(key)，返回set中第一个大于key的迭代器指针

## 注意！
‐ set容器只能通过迭代器访问

```cpp
for (std::set<int>::iterator it = st.begin(); it != st.end(); ++ it)
printf("%d\n", *it);
```

# MAP
## 常用函数
‐ begin
‐ end
‐ find O(logN) 没有找到返回mp.end()
‐ mp.insert(make_pair(1, 2))
‐ erase
+ mp.erase(it) O(1)
+ mp.erase(key) O(logN)
+ mp.erase(first, last) O(last ‐ first)
‐ size O(1)
‐ clear O(N)
‐ empty
‐ lower_bound map :: mp.lower_bound(key)，返回map中第一个大于等于key的迭代器指针
‐ upper_bound map :: mp.upper_bound(key)，返回map中第一个大于key的迭代器指针
## 注意！
‐ 字符串到整型的映射，必须使用string而不能使用char数组
‐ map使用erase函数时需要预先将迭代器后移
‐ map新建一个的初始值为0
# QUEUE
## 常用函数
‐ quu.count(1) 在队列中找1的个数
‐ push O(1)
‐ front O(1)
‐ back O(1)
‐ pop O(1)
‐ empty O(1)
‐ size O(1)
## queue清空
### 直接用空的队列对象赋值
queue<int> q1;
q1 = queue<int>();
### 遍历出队列
```cpp
while (!Q.empty()) Q.pop();
```
### 使用swap
这种是最高效的，定义clear，保持STL容器的标准

```cpp
void clear(queue<int>& q) {
queue<int> empty;
swap(empty, q);
}
```
## 注意！
‐ 使用front和pop函数之前必须使用empty函数判断队列是否为空，否则可能因为队空出现错误
# PRIORITY_QUEUE
## 默认设置
‐ 默认设置数字的大的是优先级高
‐ 与queue不同的是，priority_queue没有front与back函数，只能使用top函数取队顶
‐ 使用top函数前必须要用empty函数判断优先队列是否为空
## 常用函数
‐ push
‐ top
‐ pop
hang university ACM template 第 5 页
‐ empty
‐ size
## 优先级的设置
```cpp
priority_queue<int> pqu;
priority_queue<int, vector<int>, less<int>> heap; /*默认是less，大根堆*/
priority_queue<int, vector<int>, greater<int>> heap;
```
# STACK
## 常用函数
‐ push
‐ top
‐ pop
‐ empty
‐ size
# PAIR
## pair容器内元素的访问
‐ pr.first
‐ pr.second
## pair常用函数
‐ mp.insert(make_pair("ABCD", 5));
# ALGORITHM
‐ sort
‐ max & min min(x, y) 参数必须是两个，比较三个数，min(x, min(y, z))
‐ reverse(it, it + i) 将数组指针或容器的迭代器在[it, it + i)范围内的元素进行反转
‐ swap(x, y) 交换x, y
‐ abs(x) 返回x的绝对值，x必须是整数，浮点型的绝对值应使用math头文件下的fabs
‐ next_permutation() 给出一个序列在全排列中的下一个序列，在已经到达全排列的最后一个时会返回false
‐ fill 和memset不同，fill()可以把数组或容器中的某一段区间赋为某个相同的值，可以是数组类型对应范围中的任意值
‐ lower_bound :: lower_bound(vec.begin(), vec.end(), val)，第一个大于等于val的值
‐ upper_bound :: upper_bound(vec.begin(), vec.end(), val)，第一个大于val的值
