#include <iostream>
#include <memory>

using namespace std;

template<typename T>
static void print(T arg)
{
    std::cout << arg << std::endl;
}

class B;
class C;


class B
{
public:
    B()
    {
        print("constructor B");
    }
    ~B()
    {
        print("destructor B");
    }
    shared_ptr<C> c;
};

class C
{
public:
    C()
    {
        print("constructor C");
    }
    ~C()
    {
        print("destructor C");
    }
    weak_ptr<B> b;
};

int main()
{
    std::cout << "Hello, World!" << std::endl;

    {
        auto pb = make_shared<B>();
        auto pc = make_shared<C>();
        pb->c = pc;
        pc->b = pb;
    }

    return 0;
}
