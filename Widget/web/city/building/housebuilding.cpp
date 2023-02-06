#include "housebuilding.h"

#include "utility/style.h"

#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>


using namespace Wt;

namespace WebWidget {
namespace Building {

HouseBuilding::HouseBuilding()
{
    this->setAttributeValue(Style::style,Style::background::url("assets/building/house1building.png")
                            +Style::background::size::contain
                            +Style::background::repeat::norepeat
                            +Style::background::position::center_center);

    auto vLayout = this->setLayout(std::make_unique<Wt::WVBoxLayout>());

    vLayout->addStretch(1);


    auto container = vLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setAttributeValue(Style::style,Style::background::color::rgba(75,156,134)+Style::color::color(Style::color::White::AliceBlue));
    container->addNew<WText>("Ev");
}

} // namespace Building
} // namespace WebWidget
