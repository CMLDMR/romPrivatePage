#include "assetsmanager.h"

#include <Wt/WText.h>
#include "utility/style.h"

using namespace Wt;

namespace City {

AssetsManager::AssetsManager()
{
    this->setPositionScheme(Wt::PositionScheme::Absolute);

    this->setOffsets(0,Side::Right);
    this->setOffsets(250,Side::Top);

    this->setWidth(350);
    this->setHeight(768);
    this->setAttributeValue( Style::style,Style::background::color::color(Style::color::Pink::DeepPink)+Style::color::color(Style::color::White::AliceBlue));

    this->addNew<WText>("Assets Kontrol Paneli");

    this->setZIndex(10);
}

} // namespace City
