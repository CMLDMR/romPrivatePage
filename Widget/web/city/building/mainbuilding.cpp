#include "mainbuilding.h"

#include "utility/style.h"

#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WCssDecorationStyle.h>

using namespace Wt;


namespace WebWidget {

Building::MainBuilding::MainBuilding(const bool buildMenu)
    : BaseWidget(::Building::Type::main)
{


    this->setAttributeValue(Style::style,Style::background::url(this->assetPath())+
                            Style::background::size::contain+
                            Style::background::repeat::norepeat+
                            Style::background::position::center_center);

    if( buildMenu ){

        auto vLayout = this->setLayout(std::make_unique<Wt::WVBoxLayout>());

        vLayout->addStretch(1);

        auto container = vLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(75,156,134)+Style::color::color(Style::color::White::AliceBlue));
        container->addNew<WText>(this->buildingName());
    }else{
        this->setWidth(this->buildingWidth());
        this->setHeight(this->buildingHeight());
    }
    this->decorationStyle().setCursor(Wt::Cursor::PointingHand);
}



Wt::Signal<::Building::Type, bool> &Building::MainBuilding::SelectedBuild()
{
    return _selectedBuild;
}




} // namespace WebWidget
