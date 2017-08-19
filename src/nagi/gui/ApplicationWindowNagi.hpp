#ifndef NAGI_APPLICATION_WINDOW_NAGI_HPP
#define NAGI_APPLICATION_WINDOW_NAGI_HPP

#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>

namespace Nagi {
    class ApplicationWindowNagi : public Gtk::ApplicationWindow {
    public:
        ApplicationWindowNagi(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refBuilder);

        static ApplicationWindowNagi *create();

    protected:
        Glib::RefPtr<Gtk::Builder> m_refBuilder;
    };
}

#endif //NAGI_APPLICATION_WINDOW_NAGI_HPP
