/*
 * 继承（四）：同名成员处理
 *
 * 当派生类和基类有同名的成员变量或成员函数时，会发生什么？
 *
 * 核心规则：
 *   派生类的同名成员会"隐藏"基类的同名成员。
 *   要访问基类被隐藏的成员，需要用作用域解析符 ::  (Base::成员名)
 *
 * 注意区分三个概念（面试常见）：
 *   重载(overload)：    同一个作用域，函数名相同，参数不同
 *   重写(override)：    继承中，派生类重新定义基类的 virtual 函数（学了多态才涉及）
 *   隐藏(hide)：        继承中，派生类的同名成员让基类的"看不见"
 *
 *   本文件的例子属于"隐藏"，不是重载也不是重写！
 */

#include <iostream>
using namespace std;

// ==================== 基类 ====================
class Base {
public:
    int value = 100;

    void show() {
        cout << "Base::show() 被调用, value = " << value << endl;
    }

    void show(int x) {   // 重载版本：带一个参数
        cout << "Base::show(int) 被调用, x = " << x << endl;
    }

    void work() {
        cout << "Base::work() 被调用" << endl;
    }

    static void staticFunc() {
        cout << "Base::staticFunc() 静态函数" << endl;
    }
};

// ==================== 派生类 ====================
class Derived : public Base {
public:
    int value = 200;   // 和基类同名！基类的 value 被"隐藏"了

    void show() {      // 和基类同名！基类的所有 show() 重载都被隐藏了
        cout << "Derived::show() 被调用, value = " << value << endl;
    }

    // 关键：show(int) 没有在派生类中定义，但它也被隐藏了！
    // 因为派生类只定义了一个 show()，基类的所有 show 重载版本全部隐藏！

    void newFunc() {
        cout << "Derived::newFunc() 被调用" << endl;
    }

    static void staticFunc() {   // 静态成员函数同名也会隐藏
        cout << "Derived::staticFunc() 静态函数" << endl;
    }
};

int main() {
    Derived d;

    cout << "========== 一、同名成员变量 ==========" << endl;
    cout << "d.value = " << d.value << endl;            // 访问派生类的 value
    cout << "d.Base::value = " << d.Base::value << endl; // 用 :: 访问基类的 value
    cout << endl;

    cout << "========== 二、同名成员函数（隐藏）==========" << endl;
    d.show();          // 调用派生类的 show()
    d.Base::show();    // 用 :: 调用基类的 show()
    cout << endl;

    // d.show(10);     // 错误！基类的 show(int) 被派生类的 show() 隐藏了！
    // 即使签名不同，只要派生类定义了同名函数，基类所有重载版本都会被隐藏。
    cout << "d.show(10) 会编译错误！因为基类的 show(int) 被隐藏了" << endl;
    cout << "解决办法：d.Base::show(10);  ← 用作用域解析符" << endl;
    d.Base::show(10);   // OK
    cout << endl;

    cout << "========== 三、没有被隐藏的函数 ==========" << endl;
    d.work();          // 基类的 work() 没有被隐藏，正常调用
    d.Base::work();    // 显式调用也一样
    cout << endl;

    cout << "========== 四、同名静态成员函数 ==========" << endl;
    d.staticFunc();        // 调用派生类的
    d.Base::staticFunc();  // 调用基类的
    // 也可以通过类名直接调用
    Derived::staticFunc();
    Derived::Base::staticFunc();  // 通过派生类的作用域链到基类
    cout << endl;

    cout << "========== 五、指针/引用的类型影响调用哪个函数 ==========" << endl;
    Derived derivedObj;
    Base& ref = derivedObj;    // 基类引用指向派生类对象

    cout << "通过基类引用调用 show():" << endl;
    ref.show();    // 调用的是 基类 的 show()！（没有 virtual 时，看引用/指针的类型）
    cout << "（因为 show() 不是 virtual，所以是静态绑定，看引用类型）" << endl;
    cout << endl;

    cout << "通过基类引用访问 value:" << endl;
    cout << "ref.value = " << ref.value << " (基类的 value)" << endl;
    cout << "derivedObj.value = " << derivedObj.value << " (派生类的 value)" << endl;
    cout << endl;

    cout << "========== 总结 ==========" << endl;
    cout << "1. 派生类同名成员会隐藏基类所有同名成员（不管参数是否相同）" << endl;
    cout << "2. 要访问被隐藏的基类成员：对象.Base::成员名" << endl;
    cout << "3. 隐藏 ≠ 重载（重载必须在同一个作用域）" << endl;
    cout << "4. 隐藏 ≠ 重写（重写需要 virtual，后面学多态会讲到）" << endl;
    cout << "5. 没有 virtual 时，通过基类引用/指针调用的是基类的版本（静态绑定）" << endl;
    cout << "6. 有了 virtual 之后（多态），通过基类引用/指针调用的是派生类的版本（动态绑定）" << endl;

    return 0;
}
