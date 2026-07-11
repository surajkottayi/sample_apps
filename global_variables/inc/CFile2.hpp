#ifndef CFile2_HPP
#define CFile2_HPP

#include <memory>
#include "CFile1.hpp"

namespace sample_apps {

class CFile2 {
public:
    [[nodiscard]] static std::shared_ptr<CFile2> getInstance();
    void printGlobalVariable();
    ~CFile2() = default;

private:
    CFile2() = default;
    CFile2(const CFile2&) = delete;
    CFile2& operator=(const CFile2&) = delete;
    CFile2(CFile2&&) = delete;
    CFile2& operator=(CFile2&&) = delete;
};

} // namespace sample_apps

#endif // CFile2_HPP