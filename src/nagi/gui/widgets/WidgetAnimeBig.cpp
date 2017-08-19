#include <gtkmm/image.h>
#include <gtkmm/label.h>
#include "WidgetAnimeBig.hpp"

namespace Nagi {
    WidgetAnimeBig::WidgetAnimeBig(BaseObjectType *cobject, const Glib::RefPtr<Gtk::Builder> &refBuilder)
            : Gtk::Button(cobject),
              m_refBuilder(refBuilder) {

    }

    WidgetAnimeBig *WidgetAnimeBig::create(
            Glib::ustring title,
            Glib::ustring aired,
            Glib::ustring episodes,
            Glib::ustring status,
            Glib::ustring producer,
            Glib::ustring score,
            Glib::ustring popularity,
            Glib::ustring description
    ) {
        Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create_from_resource(
                "/com/github/txuritan/nagi/ui/WidgetAnimeBig.ui");

        WidgetAnimeBig *widgetAnimeBig = nullptr;
        refBuilder->get_widget_derived("buttonAnimeBig", widgetAnimeBig);
        if (widgetAnimeBig == nullptr)
            throw std::runtime_error("No \"buttonAnimeBig\" object in WidgetAnimeBig.ui");

        Gtk::Image *animeImage = nullptr;
        refBuilder->get_widget("animeImage", animeImage);
        if (animeImage == nullptr)
            throw std::runtime_error("No \"animeImage\" object in WidgetAnimeBig.ui");

        Gtk::Label *animeTitle = nullptr;
        refBuilder->get_widget("animeTitle", animeTitle);
        if (animeTitle == nullptr)
            throw std::runtime_error("No \"animeTitle\" object in WidgetAnimeBig.ui");
        animeTitle->set_label(title);

        Gtk::Label *animeAired = nullptr;
        refBuilder->get_widget("animeAired", animeAired);
        if (animeAired == nullptr)
            throw std::runtime_error("No \"animeAired\" object in WidgetAnimeBig.ui");
        animeAired->set_label(aired);

        Gtk::Label *animeEpisodes = nullptr;
        refBuilder->get_widget("animeEpisodes", animeEpisodes);
        if (animeEpisodes == nullptr)
            throw std::runtime_error("No \"animeEpisodes\" object in WidgetAnimeBig.ui");
        animeEpisodes->set_label(episodes);

        Gtk::Label *animeStatus = nullptr;
        refBuilder->get_widget("animeStatus", animeStatus);
        if (animeStatus == nullptr)
            throw std::runtime_error("No \"animeStatus\" object in WidgetAnimeBig.ui");
        animeStatus->set_label(status);

        Gtk::Label *animeProducer = nullptr;
        refBuilder->get_widget("animeProducer", animeProducer);
        if (animeProducer == nullptr)
            throw std::runtime_error("No \"animeProducer\" object in WidgetAnimeBig.ui");
        animeProducer->set_label(producer);

        Gtk::Label *animeScore = nullptr;
        refBuilder->get_widget("animeScore", animeScore);
        if (animeScore == nullptr)
            throw std::runtime_error("No \"animeScore\" object in WidgetAnimeBig.ui");
        animeScore->set_label(score);

        Gtk::Label *animePopularity = nullptr;
        refBuilder->get_widget("animePopularity", animePopularity);
        if (animePopularity == nullptr)
            throw std::runtime_error("No \"animePopularity\" object in WidgetAnimeBig.ui");
        animePopularity->set_label(popularity);

        Gtk::Label *animeDescription = nullptr;
        refBuilder->get_widget("animeDescription", animeDescription);
        if (animeDescription == nullptr)
            throw std::runtime_error("No \"animeDescription\" object in WidgetAnimeBig.ui");
        animeDescription->set_label(description);

        return widgetAnimeBig;
    }
}