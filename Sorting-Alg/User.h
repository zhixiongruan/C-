//
// Created by zhixiong ruan on 2019-06-21.
//

#ifndef SORTING_ALG_USER_H
#define SORTING_ALG_USER_H

#include <iostream>
#include <string>

using namespace std;

struct User {
    int age;
    string name;
    // 运算符重载，小于号
    bool operator<(const User &userOther){
        return age == userOther.age ? name < userOther.name : age < userOther.age;
    }

    //输出符号重载，第一个参数必须是 ostream；所以需要使用友元函数（非友元函数第一个传参默认是对象或者结构体自己）
    friend ostream& operator<<(ostream &os, const User &userOther){
        os << "姓名：" << userOther.name << "年龄：" << userOther.age << endl;
        return os;
    }
};

#endif //SORTING_ALG_USER_H
