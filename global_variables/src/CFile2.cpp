#include "CFile2.hpp"
using namespace sample_apps;

std::shared_ptr<CFile2> CFile2::getInstance()
{
    static std::shared_ptr<CFile2> instance(new CFile2());
    return instance;
}
void CFile2::printGlobalVariable()
{
    // function body
    std::cout << "Global static variable address: " << &global_static_variable << std::endl;
    std::cout << "Global inline variable address: " << &global_inline_variable << std::endl;
}