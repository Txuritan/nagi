#include "nagi/ApplicationNagi.hpp"

int main(int argc, char *argv[]) {
    auto application = Nagi::ApplicationNagi::create();

    return application->run(argc, argv);
}