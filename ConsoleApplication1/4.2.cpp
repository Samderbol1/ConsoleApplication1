#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 定义一个结构体，存储图书信息
struct Book {
    string id; // 书号
    string name; // 书名
    double price; // 价格
};

// 定义一个顺序表，存储图书信息表
struct List {
    Book* data; // 动态数组，存储图书信息
    int size; // 表的大小
    int capacity; // 表的容量
};

// 初始化一个空的顺序表，给定初始容量
void init_list(List& L, int cap) {
    L.data = new Book[cap]; // 分配动态数组空间
    L.size = 0; // 初始化表的大小为0
    L.capacity = cap; // 记录表的容量
}

// 销毁顺序表，释放动态数组空间
void destroy_list(List& L) {
    delete[] L.data; // 释放动态数组空间
    L.size = 0; // 将表的大小设为0
    L.capacity = 0; // 将表的容量设为0
}

// 在顺序表的末尾插入一个图书信息
void insert_list(List& L, Book b) {
    // 如果表的大小等于表的容量，说明没有空间插入，需要扩容
    if (L.size == L.capacity) {
        // 创建一个新的动态数组，容量为原来的两倍
        Book* new_data = new Book[L.capacity * 2];
        // 将原来的数据复制到新的数组中
        for (int i = 0; i < L.size; i++) {
            new_data[i] = L.data[i];
        }
        // 删除原来的数组空间
        delete[] L.data;
        // 将新的数组赋值给L.data，并更新L.capacity
        L.data = new_data;
        L.capacity *= 2;
    }
    // 在表的末尾插入图书信息，并更新L.size
    L.data[L.size] = b;
    L.size++;
}
// 查找价格最高的图书，并输出相应信息
void find_max_price(List& L) {
    // 如果表为空，直接返回
    if (L.size == 0) {
        return;
    }
    // 定义一个变量，记录最高价格
    double max_price = L.data[0].price;
    // 遍历表中的每本图书，更新最高价格
    for (int i = 1; i < L.size; i++) {
        if (L.data[i].price > max_price) {
            max_price = L.data[i].price;
        }
    }
    // 定义一个计数器，记录最高价格的图书个数
    int count = 0;
    // 遍历表中的每本图书，如果价格等于最高价格，则计数器加一，并输出图书信息
    for (int i = 0; i < L.size; i++) {
        if (L.data[i].price == max_price) {
            count++;
            if (count == 1) { // 如果是第一本最高价格的图书，则先输出个数
                cout << count << endl;
            }
            cout << L.data[i].id << " " << L.data[i].name << " " << fixed << setprecision(2) << L.data[i].price << endl;
        }
    }
}
int main() {
    // 输入图书数目和初始容量（可以任意设置）
    int n, cap;
    cin >> n >> cap;
    // 初始化一个空的顺序表
    List L;
    init_list(L, cap);
    // 输入每本图书的信息，并插入到顺序表中
    for (int i = 0; i < n; i++) {
        Book b;
        cin >> b.id >> b.name >> b.price;
        insert_list(L, b);
    }
    // 查找价格最高的图书，并输出相应信息
    find_max_price(L);
    // 销毁顺序表，释放动态数组空间
    destroy_list(L);
    return 0;
}