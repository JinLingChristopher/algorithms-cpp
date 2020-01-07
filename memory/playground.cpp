#include <memory>
#include <iostream>

using namespace std;

void foo(shared_ptr<int> i) {
    (*i)++;
}

void shared() {
    auto pointer = std::make_shared<int>(10);
    auto pointer2 = pointer; // 引用计数+1
    auto pointer3 = pointer; // 引用计数+1
    int *p = pointer.get(); // 这样不会增加引用计数
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 3
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 3
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 3

    pointer2.reset();
    std::cout << "reset pointer2:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 2
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0, pointer2 已 reset
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl; // 2
    pointer3.reset();
    std::cout << "reset pointer3:" << std::endl;
    std::cout << "pointer.use_count() = " << pointer.use_count() << std::endl; // 1
    std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl; // 0
    std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;
}

void unique() {
    unique_ptr<int> ptr = make_unique<int>(10);
    ptr.release();
    cout << *ptr << endl;
}

struct Foo {
    Foo() { std::cout << "Foo::Foo" << std::endl; }
    ~Foo() { std::cout << "Foo::~Foo" << std::endl; }
    void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) {
    std::cout << "f(const Foo&)" << std::endl;
}

void foo() {
    unique_ptr<Foo> p1(std::make_unique<Foo>());
    // p1 不空, 输出
    if (p1) {
        p1->foo();
    }
    std::unique_ptr<Foo> p2(std::move(p1));
    // p2 不空, 输出
    f(*p2);
    // p2 不空, 输出
    if(p2) p2->foo();
    // p1 为空, 无输出
    if(p1) p1->foo();
    p1 = std::move(p2);
    // p2 为空, 无输出
    if(p2) p2->foo();
    std::cout << "p2 被销毁" << std::endl;
    // p1 不空, 输出
    if (p1) {
        p1->foo();
    }
    // Foo 的实例会在离开作用域时被销毁
}

struct A;
struct B;

struct A {
    shared_ptr<B> ptr;
    ~A() {
        cout << "A destroyed" << endl;
    }
};

struct B {
    weak_ptr<A> ptr;
    ~B() {
        cout << "B destroyed" << endl;
    }
};

void weak() {
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();

    a->ptr = b;
    b->ptr = a;
}

int main() {

    weak();

    return 0;
}
