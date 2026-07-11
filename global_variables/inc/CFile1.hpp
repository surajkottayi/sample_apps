
#ifndef CFile1_HPP
#define CFile1_HPP

#include <memory>
#include <iostream>
static int global_static_variable = 1;
inline int global_inline_variable = 2;
namespace sample_apps
{

    class CFile1
    {
    public:
        [[nodiscard]] static std::shared_ptr<CFile1> getInstance();
        void printGlobalVariable();
        ~CFile1() = default;

    private:
        CFile1() = default;
        CFile1(const CFile1 &) = delete;
        CFile1 &operator=(const CFile1 &) = delete;
        CFile1(CFile1 &&) = delete;
        CFile1 &operator=(CFile1 &&) = delete;
    };

} // namespace sample_apps

#endif // CFile1_HPP