#include "assetsmanager.h"

#include <Wt/WText.h>
#include <Wt/WGridLayout.h>
#include <Wt/WBreak.h>

#include "utility/style.h"


#include "Widget/web/city/building/mainbuilding.h"
#include "Widget/web/city/building/castlebuilding.h"
#include "Widget/web/city/building/housebuilding.h"
#include "Widget/web/city/building/farmer.h"

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
    this->addBuildMenu<WebWidget::Building::Farmer>(1,0);

    mSelected = false;
}

std::tuple<bool, Building::Type> AssetsManager::selected() const
{
    return std::make_tuple(mSelected,mSelectedType);
}

void AssetsManager::unSelectAll()
{
    for( auto &item : mBuildList ){
        item->setSelected(false);
    }
    mSelected = false;
}



template<typename T>
void AssetsManager::addBuildMenu(const int &x, const int &y)
{
    auto buildObj = std::make_unique<T>(true);
    auto buildObjPtr = buildObj.get();
    mGLayout->addWidget(std::move(buildObj),x,y,AlignmentFlag::Justify);
    buildObjPtr->setWidth(100);
    buildObjPtr->setHeight(100);
    buildObjPtr->setMaximumSize(100,100);

    mBuildList.push_back(buildObjPtr);


    buildObjPtr->clicked().connect([=](){
        bool isSelected = buildObjPtr->selected();
        for( auto &item : mBuildList ){
            item->setSelected(false);
        }

        if( !isSelected ){
            buildObjPtr->setSelected(true);
            mSelected = true;
            mSelectedType = buildObjPtr->buildType();
        }else{
            mSelected = false;
        }
    });


}

} // namespace City
