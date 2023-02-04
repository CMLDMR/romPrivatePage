#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H
#include <Wt/WBrush.h>
#include <Wt/WColor.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WPaintDevice.h>
#include <Wt/WPaintedWidget.h>
#include <Wt/WPainter.h>
#include <Wt/WPainterPath.h>
#include <Wt/WPen.h>
#include <Wt/WPointF.h>
#include <Wt/WSpinBox.h>
#include <Wt/Signals/signals.hpp>

using namespace Wt;

class ShapeWidget : public Wt::WPaintedWidget
{
public:
    ShapeWidget(const std::string &mBuildingPath);


    void updatew(bool increase = true);
protected:
    void paintEvent(Wt::WPaintDevice *paintDevice);

public:
    Signal<int,int> &onDragged();
private:
    double mRotate{0};
    std::string mBuildingPic;

    Signal<int,int> _Dragged;

    int mClickedPointX,mClickedPointY;
    int mDraggedX{0},mDraggedY{0};
    int mLastX{0},mLastY{0};




};

#endif // SHAPEWIDGET_H
