#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct my_key {
    int    num;
    string name;

    //构造函数
    my_key(){}
    ~my_key(){}
    my_key(int a, string b) : num(a), name(b){}

    //重载==运算符
    bool operator==(const my_key &t)const {
        return this->num == t.num;
    }
};

//自定义hash函数
struct myHashFuc {
	std::size_t operator()(const my_key &key) const {
		return std::hash<int>()(key.num);
	}
};

int main() {
    unordered_map <my_key, bool, myHashFuc> mmp;
    my_key myuin(1, "bob");
    mmp[myuin] = true;

    cout << mmp[myuin] << endl;
    return 0;
}
