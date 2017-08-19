#include "NagiJSON.hpp"

namespace Nagi {
    namespace JSON {
        NagiJSON::NagiJSON() = default;

        NagiJSON::NagiJSON(const NagiJSON &obj) = default;

        NagiJSON &NagiJSON::operator=(const NagiJSON &other) = default;

        NagiJSON::NagiJSON(NagiJSON &&other) noexcept = default;

        NagiJSON &NagiJSON::operator=(NagiJSON &&other) noexcept = default;

        NagiJSON::~NagiJSON() = default;

        nlohmann::json NagiJSON::get() {
            nlohmann::json json;

            json["settings"]["language"] = "en_us";

            json["i18n"]["en_us"]["title"] = "Nagi";

            return json;
        }
    }
}