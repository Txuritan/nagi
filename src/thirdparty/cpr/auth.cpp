#include "auth.hpp"

namespace cpr {

const char* Authentication::GetAuthString() const noexcept {
    return auth_string_.data();
}

} // namespace cpr
