#ifndef BUILDING_H
#define BUILDING_H

#include "Widget/containerwidget.h"
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WString.h>


class Building : public Wt::WContainerWidget
{


public:
    Building(const int &_x, const int &_y):mX{_x},mY{_y}{
        setPositionScheme(Wt::PositionScheme::Absolute);


    }

    struct Area{
        int x;
        int y;
    };


    void appendSize( const Area &area){
        mSize.push_back(area);
    }



    std::list<Area> AreaSize() const;

    int baseWidth() const;

    int baseHeight() const;

    void setBackGround( const std::string &_imgUrl );

    int x() const;

    int y() const;

    void setBaseWidth(int newBaseWidthMultiplier );

    void setBaseHeight(int newBaseHeightMultiplier );


    const int mBaseOffSetW{24};
    const int mBaseOffSetH{20};
private:
    std::list<Area> mSize;



    int mBaseWidth{2};
    int mBaseHeight{2};

    int mX;
    int mY;
};



class House : public Building
{
public:
    House(const int &_x, const int &_y):Building(_x,_y){

        auto __x = 24*_x;
        auto __y = 18*_y;
        setOffsets(__x-48/2,Wt::Side::Left);
        setOffsets(__y-36/2-18,Wt::Side::Top);
        setWidth(48*2);
        setHeight(36*2);
        addNew<WText>(WString("{1}-{2}").arg(_x).arg(_y))->addStyleClass("item");
        this->setAttributeValue("style","background:url(test2x2.png);;background-repeat:no-repeat;");
    }
private:
};


class House3x3 : public Building
{
public:
    House3x3(const int &_x, const int &_y):Building(_x,_y){

        auto __x = 24*_x;
        auto __y = 18*_y;


        addNew<WText>(WString("{1}-{2}").arg(_x).arg(_y))->addStyleClass("item");
        if( _x == 17 ){
            this->setAttributeValue("style","background:url(b001-3x3.png);;background-repeat:no-repeat;");

            setOffsets(__x-48/2,Wt::Side::Left);
            setOffsets(__y-144/2-36,Wt::Side::Top);

            setWidth(96);
            setHeight(144);
        }else{
            this->setAttributeValue("style","background:url(test3x3.png);;background-repeat:no-repeat;");
            setOffsets(__x-48/2,Wt::Side::Left);
            setOffsets(__y-36/2-36,Wt::Side::Top);

            setWidth(48*3);
            setHeight(36*3);
        }
    }
private:
};



class House5x3 : public Building
{
public:
    House5x3(const int &_x, const int &_y):Building(_x,_y){

        auto __x = 24*_x;
        auto __y = 18*_y;
        setOffsets(__x-48/2,Wt::Side::Left);
        setOffsets(__y-36/2-36,Wt::Side::Top);
        setWidth(48*4);
        setHeight(36*4);
        addNew<WText>(WString("{1}-{2}").arg(_x).arg(_y))->addStyleClass("item");
        this->setAttributeValue("style","background:url(test5x3.png);;background-repeat:no-repeat;");
    }
private:
};



#endif // BUILDING_H
