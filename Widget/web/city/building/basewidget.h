#ifndef WEBWIDGET_BUILDING_BASEWIDGET_H
#define WEBWIDGET_BUILDING_BASEWIDGET_H

#include "Wt/WPoint.h"
#include "utility/style.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WPainter.h>
#include <Wt/WPaintedWidget.h>
#include <Wt/WPaintDevice.h>
#include <Wt/WPointF.h>
#include <Wt/WPainterPath.h>


#include <building/building.h>


namespace WebWidget {
namespace Building {

class BuildingPlaceArea;

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
//        if( collisioned ){

//            container->setAttributeValue(Style::style,Style::background::url(container->deniedPlaceAreaAssetPath())
//                                                           +Style::background::size::contain
//                                                           +Style::background::position::center_center
//                                                           +Style::background::repeat::norepeat
//                                         +Style::Border::border("1px solid black"));
//        }else{
//            container->setAttributeValue(Style::style,Style::background::url(container->acceptedPlaceAreaAssetPath())
//                                                           +Style::background::size::contain
//                                                           +Style::background::position::center_center
//                                                           +Style::background::repeat::norepeat
//                                         +Style::Border::border("1px solid black"));
//        }

        container->addNew<BuildingPlaceArea>(container->getPolyShape());

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


class BuildingPlaceArea : public Wt::WPaintedWidget
{
public:
    BuildingPlaceArea(const std::vector<::Building::Point> &_pList)
    {

        int xMax{0};
        int yMax{0};

        std::vector<Wt::WPointF> __pList;
        for( const auto &item : _pList ){
            __pList.push_back({static_cast<double>(item.x),static_cast<double>(item.y)});
            xMax = xMax < item.x ? item.x : xMax;
            yMax = yMax < item.y ? item.y : yMax;
        }
        mMaskPath.addPolygon(__pList);
        resize(xMax, yMax);  // Provide a default size.

        this->update();
    }



protected:
    void paintEvent(Wt::WPaintDevice *paintDevice){
        Wt::WPainter painter(paintDevice);

        painter.fillPath(mMaskPath,Wt::WBrush(Wt::WColor(75,200,150,125)));

    }


    Wt::WPainterPath mMaskPath;


};

} // namespace Building
} // namespace WebWidget

#endif // WEBWIDGET_BUILDING_BASEWIDGET_H
