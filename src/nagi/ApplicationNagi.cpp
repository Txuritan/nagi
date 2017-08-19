#include <iostream>
#include <gtkmm/stack.h>
#include "ApplicationNagi.hpp"

namespace Nagi {
    ApplicationNagi::ApplicationNagi() : Gtk::Application("org.gtkmm.examples.application",
                                                          Gio::APPLICATION_HANDLES_OPEN) {
    }

    Glib::RefPtr<ApplicationNagi> ApplicationNagi::create() {
        return Glib::RefPtr<ApplicationNagi>(new ApplicationNagi());
    }

    ApplicationWindowNagi *ApplicationNagi::create_appwindow() {
        auto appwindow = ApplicationWindowNagi::create();

        // Make sure that the application runs for as long this window is still open.
        add_window(*appwindow);

        // Gtk::Application::add_window() connects a signal handler to the window's
        // signal_hide(). That handler removes the window from the application.
        // If it's the last window to be removed, the application stops running.
        // Gtk::Window::set_application() does not connect a signal handler, but is
        // otherwise equivalent to Gtk::Application::add_window().

        // Delete the window when it is hidden.
        appwindow->signal_hide().connect(sigc::bind<Gtk::Window *>(sigc::mem_fun(*this,
                                                                                 &ApplicationNagi::on_hide_window),
                                                                   appwindow));

        return appwindow;
    }

    void ApplicationNagi::on_activate() {
        // The application has been started, so let's show a window.
        try {
            // The application has been started, so let's show a window.
            auto appwindow = create_appwindow();
            appwindow->present();
        }
            // If create_appwindow() throws an exception (perhaps from Gtk::Builder),
            // no window ore the application will stop running.
        catch (const Glib::Error &ex) {
            std::cerr << "ApplicationNagi::on_activate(): " << ex.what() << std::endl;
        }
        catch (const std::exception &ex) {
            std::cerr << "ApplicationNagi::on_activate(): " << ex.what() << std::endl;
        }
    }

    void ApplicationNagi::on_hide_window(Gtk::Window *window) {
        delete window;
    }

    void ApplicationNagi::on_startup() {
        Gtk::Application::on_startup();

        auto refBuilder = Gtk::Builder::create();
        try {
            refBuilder->add_from_resource("/com/github/txuritan/nagi/ui/nagi.ui");
        }
        catch (const Glib::Error &ex) {
            std::cerr << "ApplicationNagi::on_startup(): " << ex.what() << std::endl;
            return;
        }

        auto object = refBuilder->get_object("menuApp");
        auto app_menu = Glib::RefPtr<Gio::MenuModel>::cast_dynamic(object);
        if (app_menu) {
            set_app_menu(app_menu);
        } else {
            std::cerr << "ApplicationNagi::on_startup(): No \"menuApp\" object in nagi.ui"
                      << std::endl;
        }
    }
}