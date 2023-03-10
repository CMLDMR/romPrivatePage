#include "housebuilding.h"

#include "utility/style.h"

#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WCssDecorationStyle.h>



using namespace Wt;

namespace WebWidget {
namespace Building {

HouseBuilding::HouseBuilding(const bool buildMenu)
    : BaseWidget(::Building::Type::house)
{

    this->addAttribute(Style::background::url(this->assetPath()))
            .addAttribute(Style::background::size::contain)
            .addAttribute(Style::background::repeat::norepeat)
            .addAttribute(Style::background::position::center_center);

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

    //    this->clicked().connect([=](){
    //        if( !this->selected() ){
    //            this->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor(StandardColor::DarkGray)));
    //            this->togleSelected();
    //            _selectedBuild.emit(this->buildType(),true);
    //        }else{
    //            this->decorationStyle().setBorder(WBorder(BorderStyle::None,BorderWidth::Thin,WColor(StandardColor::Black)));
    //            this->togleSelected();
    //            _selectedBuild.emit(this->buildType(),false);

    //        }
    //    });

}

Wt::Signal<::Building::Type, bool> &HouseBuilding::SelectedBuild()
{
    return _selectedBuild;
}

} // namespace Building
} // namespace WebWidget
