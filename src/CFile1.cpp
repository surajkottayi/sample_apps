#include "CFile1.hpp"
using namespace sample_apps;

std::shared_ptr<CFile1> CFile1::getInstance()
{
    static std::shared_ptr<CFile1> instance(new CFile1());
    return instance;
}
void CFile1::printGlobalVariable()
{
    // function body
    std::cout << "Global static variable address: " << &global_static_variable << std::endl;
    std::cout << "Global inline variable address: " << &global_inline_variable << std::endl;
}