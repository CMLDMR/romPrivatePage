#include "castlebuilding.h"

#include "utility/style.h"

#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WCssDecorationStyle.h>

using namespace Wt;


namespace WebWidget {
namespace Building {

CastleBuilding::CastleBuilding(const bool buildMenu)
    : BaseWidget("Kale")
{
    this->setBuildType(::Building::Type::castle);
    this->addAttribute(Style::background::url(this->assetPath()))
            .addAttribute(Style::background::size::contain)
            .addAttribute(Style::background::repeat::norepeat)
            .addAttribute(Style::background::position::center_center);

    this->setGeometry(this->assetWidth(),this->assetHeight());

    if( buildMenu ){

        auto vLayout = this->setLayout(std::make_unique<Wt::WVBoxLayout>());

        vLayout->addStretch(1);

        auto container = vLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(75,156,134)+Style::color::color(Style::color::White::AliceBlue));
        container->addNew<WText>(this->itemName());
    }else{
        this->setWidth(this->assetWidth());
        this->setHeight(this->assetHeight());
    }
    this->decorationStyle().setCursor(Wt::Cursor::PointingHand);
}

Wt::Signal<::Building::Type, bool> &CastleBuilding::SelectedBuild()
{
    return _selectedBuild;
}



} // namespace Building
} // namespace WebWidget
