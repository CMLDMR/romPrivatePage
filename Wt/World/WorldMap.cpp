#include "WorldMap.h"
#include <Wt/WText.h>


using namespace Wt;



WorldMap::WorldMap()
{
    this->setPositionScheme(PositionScheme::Fixed);
    this->setWidth(WLength("100%"));
    this->setHeight(WLength("100%"));
    this->setOffsets(0,Side::Left|Side::Top);

    addNew<WText>("World Map");
}



//bool World::addItem(const int &row, const int &col)
//{


//    auto container = addNew<WContainerWidget>();
//    container->setPositionScheme(PositionScheme::Absolute);
//    container->setWidth(24);
//    container->setHeight(18);
//    container->setOverflow(Overflow::Visible);
//    container->decorationStyle().setCursor(Cursor::PointingHand);
//    container->setZIndex(1);

//    auto item = container->addNew<ContainerWidget>();
////    item->setPositionScheme(PositionScheme::Absolute);
////    item->setOffsets(-12,Side::Left);
////    item->setOffsets(-10,Side::Top);
//    item->setZIndex(-1);

//    item->setWidth(48);
//    item->setHeight(36);
//    item->setContentAlignment(AlignmentFlag::Center|AlignmentFlag::Middle);
//    item->addNew<WText>(WString("{1}-{2}").arg(row).arg(col));



//    if( row%2 == 1 ){
//        container->setOffsets(col*48+24,Side::Left);
//        container->setOffsets(row*18,Side::Top);
//    }else{
//        container->setOffsets(col*48,Side::Left);
//        container->setOffsets(row*18,Side::Top);
//    }


//    return true;
//}

//bool World::addTestItem(const int x, const int y)
//{

//    auto _x = 24*x;
//    auto _y = 18*y;

//    auto item = addNew<ContainerWidget>();
//    item->setPositionScheme(PositionScheme::Absolute);
//    item->setOffsets(_x-48/2,Wt::Side::Left);
//    item->setOffsets(_y-36/2,Wt::Side::Top);
//    item->setWidth(48);
//    item->setHeight(36);
//    item->addNew<WText>(WString("{1}-{2}").arg(x).arg(y))->addStyleClass("item");



//    return true;

//}

//bool World::addBuilding(std::unique_ptr<Building> building)
//{
//    auto item = this->addWidget(std::move(building));


//    return true;
//}
