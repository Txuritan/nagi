#include "digest.hpp"

namespace cpr {

const char* Digest::GetAuthString() const noexcept {
    return Authentication::GetAuthString();
}

} // namespace cpr
