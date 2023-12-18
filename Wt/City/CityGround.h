#ifndef CITYGROUND_H
#define CITYGROUND_H

#include <Wt/WContainerWidget.h>

namespace Wt {
class WImage;
}

//TODO: City Ground Ayrı Bir Sınıfa Taşınacak
class CityGround : public Wt::WContainerWidget
{
public:
    CityGround();


private:
    Wt::WImage *m_cityMap   { nullptr };
};

#endif // CITYGROUND_H
