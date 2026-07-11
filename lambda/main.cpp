#include <functional>
#include <iostream>
#include <memory>
#include <typeinfo>

int square(int x)
{
    return x * x;
}

struct Functor
{
    int operator()(int x) const
    {
        return x * x;
    }
};

int main()
{
    std::cout << "==============================\n";
    std::cout << "1. Lambda has its own type\n";
    std::cout << "==============================\n";

    auto l1 = [](int x)
    { return x * x; };
    auto l2 = [](int x)
    { return x * x; };

    std::cout << "Type of l1 : " << typeid(l1).name() << '\n';
    std::cout << "Type of l2 : " << typeid(l2).name() << '\n';

    std::cout << "\n";

    //------------------------------------------------------------

    std::cout << "==============================\n";
    std::cout << "2. Lambda is actually an object\n";
    std::cout << "==============================\n";

    std::cout << l1(5) << '\n';

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "3. Captures become data members\n";
    std::cout << "==============================\n";

    int a = 10;
    double b = 20.5;

    auto capture = [a, b]()
    {
        return a + b;
    };

    std::cout << "Result : " << capture() << '\n';

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "4. Lambda size depends on captures\n";
    std::cout << "==============================\n";

    auto empty = []() {};

    auto one = [a]() {};

    auto two = [a, b]() {};

    std::cout << "sizeof(empty) = " << sizeof(empty) << '\n';
    std::cout << "sizeof(one)   = " << sizeof(one) << '\n';
    std::cout << "sizeof(two)   = " << sizeof(two) << '\n';

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "5. std::function can store different callables\n";
    std::cout << "==============================\n";

    std::function<int(int)> f;

    f = square;

    std::cout << "Function pointer : "
              << f(5) << '\n';

    f = Functor();

    std::cout << "Functor          : "
              << f(5) << '\n';

    f = [](int x)
    {
        return x * x;
    };

    std::cout << "Lambda           : "
              << f(5) << '\n';

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "6. Lambda type is fixed\n";
    std::cout << "==============================\n";

    auto lambda1 = []()
    {
        std::cout << "Lambda1\n";
    };

    auto lambda2 = [a]()
    {
        std::cout << "Lambda2\n";
    };

    lambda1();
    lambda2();

    // lambda1 = lambda2;      // Compilation error

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "7. std::function can replace callable\n";
    std::cout << "==============================\n";

    std::function<void()> func;

    func = lambda1;
    func();

    func = lambda2;
    func();

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "8. Large capture\n";
    std::cout << "==============================\n";

    int arr[100];

    auto huge = [arr]() {};

    std::cout << "sizeof(huge lambda) = "
              << sizeof(huge)
              << '\n';

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "9. Move-only capture\n";
    std::cout << "==============================\n";

    auto ptr = std::make_unique<int>(100);

    auto moveOnly =
        [p = std::move(ptr)]()
    {
        std::cout << *p << '\n';
    };

    moveOnly();

    // std::function<void()> g = moveOnly;
    // Uncomment -> compilation error

    //------------------------------------------------------------

    std::cout << "\n";
    std::cout << "Done\n";
}