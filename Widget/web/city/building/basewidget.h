#ifndef WEBWIDGET_BUILDING_BASEWIDGET_H
#define WEBWIDGET_BUILDING_BASEWIDGET_H

#include "utility/style.h"
#include <Wt/WContainerWidget.h>

namespace WebWidget {
namespace Building {

class BaseWidget : public Wt::WContainerWidget
{
public:
    BaseWidget( );


    BaseWidget& addAttribute( const std::string &_attribute );
    void removeAttribute( const std::string &_attribute );
    bool containAttribute(const std::string &_attribute) const;

    template<typename T>
    static std::unique_ptr<T> isRightPlaceToBuild(){
        auto container = std::make_unique<T>();
        container->setPositionScheme(Wt::PositionScheme::Absolute);
        container->setAttributeValue(Style::style,Style::background::url(container->acceptedPlaceAreaPath())
                                                       +Style::background::size::contain
                                                       +Style::background::position::center_center
                                                       +Style::background::repeat::norepeat
                                     +Style::Border::border("1px solid black"));
        return container;
    }


    void togleSelected();
    bool selected() const;
    void setSelected( bool _selected = true );

private:
    std::list<std::string> mAttriuteList;
    void updateAttribute();
    bool mSelected{false};

};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_BASEWIDGET_H
