#ifndef WEBWIDGET_BUILDING_BASEWIDGET_H
#define WEBWIDGET_BUILDING_BASEWIDGET_H

#include "utility/style.h"
#include <Wt/WContainerWidget.h>

#include <building/building.h>


namespace WebWidget {
namespace Building {

class BaseWidget : public Wt::WContainerWidget, public ::Building::Building
{
public:
    BaseWidget( const ::Building::Type &_type );


    BaseWidget& addAttribute( const std::string &_attribute );
    void removeAttribute( const std::string &_attribute );
    bool containAttribute(const std::string &_attribute) const;

    template<typename T>
    static std::unique_ptr<T> isRightPlaceToBuild(const bool collisioned = false){
        auto container = std::make_unique<T>();
        container->setPositionScheme(Wt::PositionScheme::Absolute);
        if( collisioned ){
            container->setAttributeValue(Style::style,Style::background::url(container->deniedPlaceAreaAssetPath())
                                                           +Style::background::size::contain
                                                           +Style::background::position::center_center
                                                           +Style::background::repeat::norepeat
                                         +Style::Border::border("1px solid black"));
        }else{
            container->setAttributeValue(Style::style,Style::background::url(container->acceptedPlaceAreaAssetPath())
                                                           +Style::background::size::contain
                                                           +Style::background::position::center_center
                                                           +Style::background::repeat::norepeat
                                         +Style::Border::border("1px solid black"));
        }

        return container;
    }


    void togleSelected();
    bool selected() const;
    void setSelected( bool _selected = true );

    void setPosition( const int &x , const int &y );
    std::pair<int,int> Position() const;

    int xPos() const;

    int yPos() const;



private:
    std::list<std::string> mAttriuteList;
    void updateAttribute();
    bool mSelected{false};




    int mXPos;
    int mYPos;


};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_BASEWIDGET_H
