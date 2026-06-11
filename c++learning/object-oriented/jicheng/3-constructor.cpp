/*
 * 继承（三）：构造与析构的调用顺序
 *
 * 核心规则：
 *   构造：先基类 → 再成员对象 → 再派生类自身    （从内到外，从父到子）
 *   析构：先派生类自身 → 再成员对象 → 再基类    （从外到内，从子到父）
 *         ↑ 正好和构造相反！
 *
 * 类比：盖房子，先打地基（基类），再砌墙（成员对象），最后装修（派生类）。
 *       拆房子，先拆装修，再拆墙，最后拆地基。
 *
 * 关键问题：派生类怎么给基类的构造函数传参？
 *   答案：用初始化列表！ 派生类名(参数) : 基类名(参数) { 派生类自己的初始化 }
 */

#include <iostream>
using namespace std;

// ==================== 基类 ====================
class Animal {
public:
    Animal() {
        cout << "  [Animal] 默认构造函数被调用" << endl;
    }

    Animal(string name) {
        this->name = name;
        cout << "  [Animal] 有参构造函数被调用, name = " << name << endl;
    }

    ~Animal() {
        cout << "  [Animal] 析构函数被调用" << endl;
    }

    string name;
};

// ==================== 成员对象类（作为派生类的成员）====================
class Leg {
public:
    Leg() { cout << "    [Leg] 默认构造函数" << endl; }
    Leg(int num) { cout << "    [Leg] 有参构造函数, num = " << num << endl; }
    ~Leg() { cout << "    [Leg] 析构函数" << endl; }
};

class Heart {
public:
    Heart() { cout << "    [Heart] 默认构造函数" << endl; }
    Heart(string type) { cout << "    [Heart] 有参构造函数, type = " << type << endl; }
    ~Heart() { cout << "    [Heart] 析构函数" << endl; }
};

// ==================== 派生类 ====================
class Dog : public Animal {
public:
    // 构造函数一：什么都不传，全部用默认构造
    Dog() {
        cout << "  [Dog] 默认构造函数" << endl;
    }

    // 构造函数二：通过初始化列表给基类和成员对象传参
    //             ↓ 给基类传参          ↓ 给成员对象传参
    Dog(string name, int legCount, string heartType)
        : Animal(name),              // 调用基类的有参构造
          leg(legCount),             // 调用成员对象的有参构造
          heart(heartType)           // 调用成员对象的有参构造
    {
        cout << "  [Dog] 有参构造函数, 我处理完自己的事了" << endl;
    }

    ~Dog() {
        cout << "  [Dog] 析构函数" << endl;
    }

private:
    // 成员对象（类类型的成员）
    Leg leg;      // Dog "has-a" Leg
    Heart heart;  // Dog "has-a" Heart
};

// ==================== 多层继承 ====================
class Animal2 {
public:
    Animal2() { cout << "  [Animal2] 构造" << endl; }
    ~Animal2() { cout << "  [Animal2] 析构" << endl; }
};

class Mammal : public Animal2 {
public:
    Mammal() { cout << "  [Mammal] 构造" << endl; }
    ~Mammal() { cout << "  [Mammal] 析构" << endl; }
};

class Dog2 : public Mammal {
public:
    Dog2() { cout << "  [Dog2] 构造" << endl; }
    ~Dog2() { cout << "  [Dog2] 析构" << endl; }
};

int main() {
    cout << "========== 一、默认构造（全用默认值）==========" << endl;
    cout << "创建 Dog 对象:" << endl;
    Dog dog1;
    // dog1 超出作用域时会自动析构
    cout << endl;

    {
        cout << "========== 二、有参构造（通过初始化列表传参）==========" << endl;
        cout << "创建 Dog 对象（带参数）:" << endl;
        Dog dog2("旺财", 4, "健康心脏");
        cout << "dog2 的名字是: " << dog2.name << endl;
        cout << endl;
        cout << "离开作用域，dog2 即将被销毁:" << endl;
    }  // dog2 在这里析构
    cout << endl;

    cout << "========== 三、多层继承的构造/析构顺序 ==========" << endl;
    cout << "创建 Dog2 对象（三层继承）:" << endl;
    Dog2 dog3;
    cout << "观察构造顺序: Animal2 → Mammal → Dog2" << endl;
    cout << endl;

    cout << "========== 总结 ==========" << endl;
    cout << "构造顺序（以 Dog 为例）：" << endl;
    cout << "  1. 基类 Animal 构造" << endl;
    cout << "  2. 成员对象构造（按声明顺序：先 Leg，再 Heart）" << endl;
    cout << "  3. 派生类 Dog 自身的构造函数体" << endl;
    cout << endl;
    cout << "析构顺序：正好反过来" << endl;
    cout << endl;
    cout << "给基类/成员对象传参的唯一方式：初始化列表！" << endl;
    cout << "  派生类(参数) : 基类(参数), 成员1(参数), 成员2(参数) { }" << endl;

    cout << endl;
    cout << "dog1 也即将被销毁:" << endl;
    return 0;
}
