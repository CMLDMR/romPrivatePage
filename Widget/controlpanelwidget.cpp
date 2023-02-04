#include "controlpanelwidget.h"
#include <Wt/WCssDecorationStyle.h>
#include <Wt/WColor.h>
using namespace Wt;


ControlPanelWidget::ControlPanelWidget()
{
    this->setPositionScheme(PositionScheme::Absolute);
    this->setWidth(WLength("100%"));
    this->setHeight(50);
    this->decorationStyle().setBackgroundColor(WColor(StandardColor::Cyan));
}
