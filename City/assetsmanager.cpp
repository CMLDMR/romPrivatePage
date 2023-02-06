#include "assetsmanager.h"

#include <Wt/WText.h>
#include <Wt/WGridLayout.h>
#include <Wt/WBreak.h>

#include "utility/style.h"


#include "Widget/web/city/building/mainbuilding.h"
#include "Widget/web/city/building/castlebuilding.h"
#include "Widget/web/city/building/housebuilding.h"

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

    this->addNew<WBreak>();
    auto container = this->addNew<WContainerWidget>();
    container->setWidth(WLength("100%"));


    auto gLaoyut = container->setLayout(std::make_unique<WGridLayout>());


    auto anaBina = gLaoyut->addWidget(std::make_unique<WebWidget::Building::MainBuilding>(),0,0,AlignmentFlag::Justify);
    anaBina->setWidth(100);
    anaBina->setHeight(100);
    anaBina->setMaximumSize(100,100);

    auto anaBina1 = gLaoyut->addWidget(std::make_unique<WebWidget::Building::CastleBuilding>(),0,1,AlignmentFlag::Justify);
    anaBina1->setWidth(100);
    anaBina1->setHeight(100);
    anaBina1->setMaximumSize(100,100);

    auto anaBina2 = gLaoyut->addWidget(std::make_unique<WebWidget::Building::HouseBuilding>(),0,2,AlignmentFlag::Justify);
    anaBina2->setWidth(100);
    anaBina2->setHeight(100);
    anaBina2->setMaximumSize(100,100);

}

} // namespace City
