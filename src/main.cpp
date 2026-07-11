#include "CFile1.hpp"
#include "CFile2.hpp"
using namespace sample_apps;


int main()
{
    auto instance1 = CFile1::getInstance();
    instance1->printGlobalVariable();

    auto instance2 = CFile2::getInstance();
    instance2->printGlobalVariable();

    return 0;
}