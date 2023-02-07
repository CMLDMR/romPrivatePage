#ifndef WEBWIDGET_BUILDING_BASEWIDGET_H
#define WEBWIDGET_BUILDING_BASEWIDGET_H

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
