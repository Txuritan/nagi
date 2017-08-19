#ifndef NAGI_APPLICATION_NAGI_HPP
#define NAGI_APPLICATION_NAGI_HPP

#include <gtkmm/application.h>
#include "gui/ApplicationWindowNagi.hpp"

namespace Nagi {
    class ApplicationNagi : public Gtk::Application {
    protected:
        ApplicationNagi();

    public:
        static Glib::RefPtr<ApplicationNagi> create();

    protected:
        // Override default signal handlers:
        void on_startup() override;
        void on_activate() override;

    private:
        ApplicationWindowNagi* create_appwindow();
        void on_hide_window(Gtk::Window* window);
    };
}

#endif //NAGI_APPLICATION_NAGI_HPP
