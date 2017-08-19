#ifndef NAGI_NAGI_JSON_HPP
#define NAGI_NAGI_JSON_HPP

#include "../../thirdparty/json.hpp"

namespace Nagi {
    namespace JSON {
        class NagiJSON {
        public:
            NagiJSON();

            // Copy
            NagiJSON(const NagiJSON &obj);

            NagiJSON &operator=(const NagiJSON &other);

            // Move
            NagiJSON(NagiJSON &&other) noexcept;

            NagiJSON &operator=(NagiJSON &&other) noexcept;

            // Deconstruct
            virtual ~NagiJSON();

            nlohmann::json get();
        };
    }
}

#endif //NAGI_NAGI_JSON_HPP
