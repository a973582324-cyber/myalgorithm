/*
 * 继承（一）：基本语法
 *
 * 语法:  class 派生类名 : 继承方式 基类名 { ... };
 *
 * 继承的本质是代码复用 + "is-a"关系。
 * 派生类（子类）自动拥有基类（父类）的所有非私有成员。
 *
 * 先搞清楚三个问题：
 * 1. 派生类能从基类继承什么东西？
 * 2. 派生类能用继承来的东西干什么？
 * 3. 基类的 private 成员能不能被派生类访问？
 */

#include <iostream>
#include <string>
using namespace std;

// ==================== 基类（父类）====================
class Animal {
public:
    string name;
    int age;

    void eat() {
        cout << name << " 在吃东西" << endl;
    }

    void sleep() {
        cout << name << " 在睡觉" << endl;
    }

private:
    // 私有的，派生类无法直接访问
    string secretDNA = "ATCG";

public:
    // 但可以通过基类的公有函数间接访问
    string getDNA() {
        return secretDNA;
    }
};

// ==================== 派生类（子类）====================
// Dog "is-a" Animal，Dog 继承了 Animal 的所有非私有成员
class Dog : public Animal {    // public 继承：最常用
public:
    // Dog 自己的新成员
    string breed;   // 品种

    void bark() {
        cout << name << " 汪汪叫！" << endl;
    }

    // 可以调用从 Animal 继承来的成员
    void introduce() {
        cout << "我叫 " << name << ", 今年 " << age << " 岁, 品种是 " << breed << endl;
    }

    void showDNA() {
        // cout << secretDNA << endl;  // 错误！派生类不能直接访问基类的 private 成员
        cout << "DNA: " << getDNA() << endl;  // 正确！通过基类的公有函数间接访问
    }
};

// ==================== 另一个派生类 ====================
class Cat : public Animal {
public:
    string color;

    void meow() {
        cout << name << " 喵喵叫！" << endl;
    }

    void introduce() {
        cout << "我叫 " << name << ", 颜色是 " << color << endl;
    }
};

int main() {
    cout << "========== Dog ==========" << endl;
    Dog dog;
    dog.name = "旺财";     // 继承自 Animal
    dog.age = 3;           // 继承自 Animal
    dog.breed = "金毛";     // Dog 自己的成员
    dog.eat();             // 继承自 Animal
    dog.sleep();           // 继承自 Animal
    dog.bark();            // Dog 自己的成员
    dog.introduce();       // Dog 自己的成员
    dog.showDNA();         // 间接访问基类的私有成员
    cout << endl;

    cout << "========== Cat ==========" << endl;
    Cat cat;
    cat.name = "咪咪";     // 继承自 Animal
    cat.color = "白色";    // Cat 自己的成员
    cat.eat();             // 继承自 Animal
    cat.meow();            // Cat 自己的成员
    cat.introduce();       // Cat 自己的成员

    cout << endl;
    cout << "核心要点：" << endl;
    cout << "1. 派生类继承了基类除 private 外的所有成员" << endl;
    cout << "2. private 成员被继承了，但不能直接访问（只能通过基类的公有函数）" << endl;
    cout << "3. 派生类可以新增自己的成员变量和成员函数" << endl;
    cout << "4. 继承体现了 'is-a' 关系:Dog is an Animal" << endl;

    return 0;
}
