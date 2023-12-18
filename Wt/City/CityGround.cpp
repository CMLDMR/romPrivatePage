#include "CityGround.h"

#include <Wt/WLink.h>
#include <Wt/WImage.h>



using namespace Wt;


CityGround::CityGround() {


    setPositionScheme( PositionScheme::Relative );

    m_cityMap = addNew<WImage>(WLink("cityground1.jpg"));
    m_cityMap->setWidth(2000);
    m_cityMap->setHeight(2000);
    m_cityMap->setPositionScheme(PositionScheme::Absolute);
    m_cityMap->setOffsets(0,Side::Left|Side::Top);

    m_cityMap->setId("citymap");
    m_cityMap->doJavaScript("handDrag();");

}
