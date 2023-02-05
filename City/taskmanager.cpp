#include "taskmanager.h"
#include <Wt/WText.h>
#include "utility/style.h"

using namespace Wt;
namespace City {

TaskManager::TaskManager()
{

    this->setPositionScheme(Wt::PositionScheme::Absolute);

    this->setOffsets(20,Side::Bottom);
//    this->setOffsets(250,Side::Top);

    this->setWidth(WLength("100%"));
    this->setHeight(150);
    this->setContentAlignment(AlignmentFlag::Center);


    auto panelContainer = this->addNew<WContainerWidget>();


    panelContainer->setWidth(1024);
    panelContainer->setMaximumSize(1024,WLength::Auto);
    panelContainer->setHeight(150);

    panelContainer->setAttributeValue( Style::style,Style::background::color::color(Style::color::Red::FireBrick)+Style::color::color(Style::color::White::AliceBlue));

    panelContainer->addNew<WText>("Görev Listesi");

    this->setZIndex(10);
}

} // namespace City
