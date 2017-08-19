#include <gtkmm/paned.h>
#include <gtkmm/stack.h>
#include "ApplicationWindowNagi.hpp"

namespace Nagi {
    ApplicationWindowNagi::ApplicationWindowNagi(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refBuilder)
            : Gtk::ApplicationWindow(cobject),
              m_refBuilder(refBuilder) {
    }

    ApplicationWindowNagi *ApplicationWindowNagi::create() {
        Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create_from_resource(
                "/com/github/txuritan/nagi/ui/WindowNagi.ui");

        ApplicationWindowNagi *window = nullptr;
        refBuilder->get_widget_derived("windowNagi", window);
        if (!window)
            throw std::runtime_error("No \"windowNagi\" object in WindowNagi.ui");

        Gtk::Paned *panedHeaderBar = nullptr;
        refBuilder->get_widget("panedHeaderBar", panedHeaderBar);
        if (!panedHeaderBar) {
            throw std::runtime_error("No \"panedHeaderBar\" object to set as titlebar");
        } else {
            window->set_titlebar(*panedHeaderBar);
        }

        return window;
    }
}