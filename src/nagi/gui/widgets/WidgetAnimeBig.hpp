#ifndef NAGI_WIDGET_ANIME_BIG_HPP
#define NAGI_WIDGET_ANIME_BIG_HPP

#include <gtkmm/builder.h>
#include <gtkmm/button.h>

namespace Nagi {
    class WidgetAnimeBig : public Gtk::Button {
    public:
        WidgetAnimeBig(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refBuilder);

        static WidgetAnimeBig *create(
                Glib::ustring title,
                Glib::ustring aired,
                Glib::ustring episodes,
                Glib::ustring status,
                Glib::ustring producer,
                Glib::ustring score,
                Glib::ustring popularity,
                Glib::ustring description
        );

    protected:
        Glib::RefPtr<Gtk::Builder> m_refBuilder;
    };
}

#endif //NAGI_WIDGET_ANIME_BIG_HPP
