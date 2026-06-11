/*
 * 继承（二）：继承方式 —— public / protected / private 继承
 *
 * 这是继承中最容易混淆的知识点，一张表就能说清楚：
 *
 * ================ 基类成员在派生类中的访问权限 ================
 *
 *   继承方式\基类成员   |  public成员    |  protected成员  |  private成员
 *   -------------------|---------------|----------------|---------------
 *   public 继承        |  public       |  protected     | 不可访问
 *   protected 继承     |  protected    |  protected     | 不可访问
 *   private 继承       |  private      |  private       | 不可访问
 *
 *   规律：继承方式只会"收紧"权限，不会"放宽"。
 *   派生类拿到的权限 = min(继承方式, 基类成员权限)
 *
 *   实际开发中 99% 都用 public 继承，但面试常考三种区别。
 */

#include <iostream>
using namespace std;

// ==================== 基类 ====================
class Base {
public:
    int pub = 1;

protected:
    int pro = 2;   // protected: 派生类内部可以访问，外部不能访问

private:
    int pri = 3;   // private: 只有基类自己能访问

public:
    void showBase() {
        cout << "Base: pub=" << pub << ", pro=" << pro << ", pri=" << pri << endl;
    }
};

// ==================== public 继承（最常用）====================
class PublicDerived : public Base {
public:
    void test() {
        cout << "--- PublicDerived::test() ---" << endl;

        pub = 10;   // OK: 基类的 public → 派生类中仍是 public
        cout << "pub = " << pub << endl;

        pro = 20;   // OK: 基类的 protected → 派生类中仍是 protected（内部可访问）
        cout << "pro = " << pro << endl;

        // pri = 30;  // 错误！基类的 private 在任何继承方式下都不可访问！
        // cout << "pri = " << pri << endl;  // 编译错误
        cout << "pri 无法访问（基类 private 成员，派生类看不到）" << endl;
        cout << endl;
    }
};

// ==================== protected 继承 ====================
class ProtectedDerived : protected Base {
public:
    void test() {
        cout << "--- ProtectedDerived::test() ---" << endl;

        pub = 10;   // OK: 基类的 public → 派生类中变成 protected
        cout << "pub = " << pub << " (在基类是 public, 这里变成了 protected)" << endl;

        pro = 20;   // OK: 基类的 protected → 派生类中仍是 protected
        cout << "pro = " << pro << " (在基类是 protected, 这里仍是 protected)" << endl;

        // pri = 30;  // 错误！基类的 private 不可访问
        cout << "pri 无法访问" << endl;
        cout << endl;
    }
};

// protected 继承的影响：再下一代能看到什么？
class GrandChild : public ProtectedDerived {
public:
    void test() {
        cout << "--- GrandChild::test() (ProtectedDerived 的子类) ---" << endl;

        pub = 100;  // OK: pub 在 ProtectedDerived 中是 protected，所以 GrandChild 能访问
        cout << "pub = " << pub << " (爷爷是 public, 父亲是 protected 继承, 我能访问)" << endl;

        pro = 200;  // OK: 同理
        cout << "pro = " << pro << endl;
        cout << endl;
    }
};

// ==================== private 继承 ====================
class PrivateDerived : private Base {
public:
    void test() {
        cout << "--- PrivateDerived::test() ---" << endl;

        pub = 10;   // OK: 基类的 public → 派生类中变成 private
        cout << "pub = " << pub << " (在基类是 public, 这里变成了 private)" << endl;

        pro = 20;   // OK: 基类的 protected → 派生类中变成 private
        cout << "pro = " << pro << " (在基类是 protected, 这里变成了 private)" << endl;

        cout << "pri 无法访问" << endl;
        cout << endl;
    }
};

// private 继承后再派生：什么都访问不到了
class GrandChild2 : public PrivateDerived {
public:
    void test() {
        cout << "--- GrandChild2::test() (PrivateDerived 的子类) ---" << endl;

        // pub = 100;  // 错误！pub 在 PrivateDerived 中是 private，再派生就看不到了
        // pro = 200;  // 错误！同理
        cout << "pub 和 pro 都无法访问！" << endl;
        cout << "因为爷爷的成员在父亲(private 继承)那里变成了 private," << endl;
        cout << "到了我这一代就完全看不到了。" << endl;
        cout << endl;
    }
};

int main() {
    cout << "========== 一、public 继承（最常用）==========" << endl;
    PublicDerived obj1;
    obj1.test();
    obj1.pub = 999;   // OK: pub 在派生类中仍是 public，外部可访问
    cout << "外部访问 obj1.pub = " << obj1.pub << endl;
    // obj1.pro = 999;  // 错误！protected 外部不可访问
    cout << endl;

    cout << "========== 二、protected 继承 ==========" << endl;
    ProtectedDerived obj2;
    obj2.test();
    // obj2.pub = 999;  // 错误！pub 在这里变成了 protected，外部不可访问！
    // obj2.pro = 999;  // 错误！protected 外部本身就不可访问
    cout << "注意：protected 继承后，obj2.pub 外部访问不了！" << endl;
    cout << endl;

    cout << "========== 三、protected 继承的孙子类 ==========" << endl;
    GrandChild obj3;
    obj3.test();
    cout << endl;

    cout << "========== 四、private 继承 ==========" << endl;
    PrivateDerived obj4;
    obj4.test();
    // obj4.pub = 999;  // 错误！pub 在这里变成了 private
    cout << "注意：private 继承后，obj4.pub 外部也访问不了！" << endl;
    cout << endl;

    cout << "========== 五、private 继承的孙子类 ==========" << endl;
    GrandChild2 obj5;
    obj5.test();

    cout << "========== 总结 ==========" << endl;
    cout << "1. 基类的 private 成员：任何继承方式下，派生类都不可直接访问" << endl;
    cout << "2. public 继承：权限不变（public→public, protected→protected）" << endl;
    cout << "3. protected 继承：public→protected, protected→protected" << endl;
    cout << "4. private 继承：全部变 private" << endl;
    cout << "5. 实际开发中几乎只用 public 继承" << endl;
    cout << "6. protected/private 继承多用于特殊设计（比如实现 has-a 或限制接口）" << endl;

    return 0;
}
