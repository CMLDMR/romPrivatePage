#include "citymanager.h"


#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>

#include "utility/style.h"

using namespace Wt;

namespace City {

CityManager::CityManager()
{

    this->setPositionScheme(Wt::PositionScheme::Absolute);

    this->setOffsets(0,Side::Left);
    this->setOffsets(250,Side::Top);

    this->setWidth(350);
    this->setHeight(768);
    this->setAttributeValue( Style::style,Style::background::color::color(Style::color::Green::ForestGreen)+Style::color::color(Style::color::White::AliceBlue));

    auto controlPanel = this->addNew<WContainerWidget>();
    auto hLayout = controlPanel->setLayout(std::make_unique<WHBoxLayout>());

    auto CityBtn = hLayout->addWidget(std::make_unique<WPushButton>("Şehir"));
    auto villageBtn = hLayout->addWidget(std::make_unique<WPushButton>("Köy"));



    auto contentContainer = this->addNew<WContainerWidget>();
    contentContainer->addNew<WText>("Kontrol Arayüz");

    CityBtn->clicked().connect([=](){
        contentContainer->clear();
        contentContainer->addNew<WText>("Şehir Kontrolü");
    });

    villageBtn->clicked().connect([=](){
        contentContainer->clear();
        contentContainer->addNew<WText>("Köy Kontrolü");
    });


    this->setZIndex(10);
}

} // namespace City
