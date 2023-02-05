#include "citymanager.h"


#include <Wt/WText.h>
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

    this->addNew<WText>("Şehir Kontrol Paneli");

    this->setZIndex(10);
}

} // namespace City
