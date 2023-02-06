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


    mGLayout = container->setLayout(std::make_unique<WGridLayout>());


    this->addBuildMenu<WebWidget::Building::MainBuilding>(0,0);
    this->addBuildMenu<WebWidget::Building::CastleBuilding>(0,1);
    this->addBuildMenu<WebWidget::Building::HouseBuilding>(0,2);

}

Wt::Signal<NoClass> &AssetsManager::SelectedBuild()
{
    return _selectedBuild;
}

template<typename T>
void AssetsManager::addBuildMenu(const int &x, const int &y)
{
    auto anaBina2 = mGLayout->addWidget(std::make_unique<T>(true),x,y,AlignmentFlag::Justify);
    anaBina2->setWidth(100);
    anaBina2->setHeight(100);
    anaBina2->setMaximumSize(100,100);

    anaBina2->clicked().connect([=](){
        std::cout << "Bina: " << anaBina2->itemName() << "\n";
    });


}

} // namespace City
