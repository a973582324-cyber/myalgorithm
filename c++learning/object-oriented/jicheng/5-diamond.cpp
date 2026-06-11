/*
 * 继承（五）：菱形继承（钻石继承）与 virtual 虚继承
 *
 * 多继承时可能出现的一种问题：
 *
 *        Animal
 *        /    \
 *     Horse   Donkey
 *        \    /
 *        Mule
 *
 * Mule（骡子）同时继承了 Horse 和 Donkey，
 * 而 Horse 和 Donkey 又都继承自 Animal。
 *
 * 问题：Mule 中有 两 份 Animal 的数据！
 *      → 访问 Animal::name 时是哪一个？歧义！
 *      → 浪费内存，有两份一模一样的 Animal 成员。
 *
 * 解决办法：virtual 继承（虚继承）
 *      在 Horse 和 Donkey 继承 Animal 时加上 virtual 关键字，
 *      这样 Mule 中就只有 一 份 Animal 的数据了。
 */

#include <iostream>
using namespace std;

// ==================== 问题演示：不加 virtual ====================

class Animal {
public:
    int age = 0;
    Animal() { cout << "  [Animal] 构造" << endl; }
};

class Horse : public Animal {   // 普通继承
public:
    Horse() { cout << "  [Horse] 构造" << endl; }
};

class Donkey : public Animal {  // 普通继承
public:
    Donkey() { cout << "  [Donkey] 构造" << endl; }
};

class Mule : public Horse, public Donkey {  // 多继承
public:
    Mule() { cout << "  [Mule] 构造" << endl; }
};

// ==================== 解决方案：加 virtual ====================

class Animal2 {
public:
    int age = 0;
    Animal2() { cout << "  [Animal2] 构造" << endl; }
};

class Horse2 : virtual public Animal2 {   // ★ virtual 继承
public:
    Horse2() { cout << "  [Horse2] 构造" << endl; }
};

class Donkey2 : virtual public Animal2 {  // ★ virtual 继承
public:
    Donkey2() { cout << "  [Donkey2] 构造" << endl; }
};

class Mule2 : public Horse2, public Donkey2 {
public:
    Mule2() { cout << "  [Mule2] 构造" << endl; }
};

int main() {
    cout << "========== 一、不用 virtual 的问题 ==========" << endl;
    cout << "创建 Mule 对象:" << endl;
    Mule mule;

    // mule.age = 10;  // 错误！二义性：不知道是 Horse::age 还是 Donkey::age
    cout << endl;
    cout << "mule.age = 10;  // 编译错误！不明确是哪个 Animal::age" << endl;
    cout << "必须显式指定路径：mule.Horse::age = 5;  mule.Donkey::age = 6;" << endl;
    cout << "这意味着 Mule 中有两套 age，两套 Animal 数据，浪费内存！" << endl;

    mule.Horse::age = 5;
    mule.Donkey::age = 6;
    cout << "mule.Horse::age = " << mule.Horse::age << endl;
    cout << "mule.Donkey::age = " << mule.Donkey::age << endl;
    cout << "注意：Animal 被构造了 2 次！（看上面的输出）" << endl;
    cout << endl;

    cout << "========== 二、用了 virtual 继承（解决方案）==========" << endl;
    cout << "创建 Mule2 对象:" << endl;
    Mule2 mule2;

    mule2.age = 10;  // OK！没有二义性，因为只有一份 Animal2 数据
    cout << endl;
    cout << "mule2.age = " << mule2.age << endl;
    cout << "注意：Animal2 只被构造了 1 次！（看上面的输出）" << endl;
    cout << endl;

    cout << "========== 三、virtual 继承的底层原理 ==========" << endl;
    cout << "普通继承：派生类直接包含基类的所有数据" << endl;
    cout << "" << endl;
    cout << "  普通继承 Mule 的内存布局：" << endl;
    cout << "  ┌─────────────┐" << endl;
    cout << "  │ Horse部分    │→ 包含 Animal 的 age" << endl;
    cout << "  │ Donkey部分   │→ 包含另一个 Animal 的 age" << endl;
    cout << "  │ Mule自己的部分│" << endl;
    cout << "  └─────────────┘" << endl;
    cout << "  Animal 出现了 2 次！" << endl;
    cout << "" << endl;
    cout << "  虚继承 Mule2 的内存布局：" << endl;
    cout << "  ┌─────────────┐" << endl;
    cout << "  │ Horse2部分   │→ 包含一个指向 Animal2 的指针(vbptr)" << endl;
    cout << "  │ Donkey2部分  │→ 包含一个指向 Animal2 的指针(vbptr)" << endl;
    cout << "  │ Mule2自己的部分│" << endl;
    cout << "  │ Animal2部分  │← 共享的，只有 1 份！" << endl;
    cout << "  └─────────────┘" << endl;
    cout << endl;

    cout << "========== 总结 ==========" << endl;
    cout << "1. 菱形继承导致基类数据重复（被构造多次，数据有多份）" << endl;
    cout << "2. 虚继承(virtual)让公共基类只保留一份数据" << endl;
    cout << "3. virtual 加在中间层的继承上（不是最底层的多继承类）" << endl;
    cout << "4. 虚继承有额外开销（vbptr 指针），不过大多数情况下可忽略" << endl;
    cout << "5. 尽量避免复杂的多继承，能用组合(has-a)解决的别用多继承" << endl;

    return 0;
}
