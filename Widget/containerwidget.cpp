#include "containerwidget.h"
#include <random>
#include <string>


ContainerWidget::ContainerWidget()
{

}

void ContainerWidget::setRandomBackgroundColor()
{
        this->setAttributeValue("style","background:url(test1.png);;background-repeat:no-repeat;");
}
