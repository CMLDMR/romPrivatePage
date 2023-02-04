#include "shapewidget.h"
#include <Wt/WImage.h>
#include <Wt/WPainter.h>
#include <Wt/WLink.h>
#include <typeinfo>

ShapeWidget::ShapeWidget(const std::string &mBuildingPath)
    : Wt::WPaintedWidget(),
      mBuildingPic(mBuildingPath)
{
    resize(500, 500);  // Provide a default size.

    this->mouseWentDown().connect([=](const Wt::WMouseEvent &event){
//        std::cout << "mouseWentDown: " << event.document().x << " "<< event.document().y <<  "\n";
//        mClickedPointX = event.document().x;
//        mClickedPointY = event.document().y;
    });

    this->mouseWentOut().connect([=](const Wt::WMouseEvent &event){
        std::cout << "mouseWentOut: " <<event.document().x << " "<< event.document().y <<  "\n";
    });

    this->mouseWentUp().connect([=](const Wt::WMouseEvent &event){
        std::cout << "mouseWentUp: " <<event.document().x << " "<< event.document().y <<  "\n";
        mLastX += mDraggedX;
        mLastY += mDraggedY;
    });

    this->mouseDragged().connect([=](const Wt::WMouseEvent &event){
        std::cout << "mouseDragged: " <<event.dragDelta().x << " "<<event.dragDelta().y << "   -  "<<event.document().x << " "<< event.document().y <<  "\n";
        mDraggedX = event.dragDelta().x;
        mDraggedY = event.dragDelta().y;
        this->update();
    });

    this->touchStarted().connect([=](/*Wt::WMouseEvent &event*/){
        std::cout << "touchStarted: ";// << event.document().x << " "<< event.document().y <<  "\n";
    });

    this->touchMoved().connect([=](const Wt::WTouchEvent &event){
        std::cout << "Size: "<<event.changedTouches().size() << "\n";
        std::cout << "touchMoved: " << event.changedTouches().front().document().x << " "<< event.changedTouches().front().document().y <<  "\n";
    });

    this->touchEnded().connect([=](const Wt::WTouchEvent &event){
        std::cout << "touch ended" << "\n";
    });

}

void ShapeWidget::updatew(bool increase)
{
    if( increase ){
        mRotate = mRotate+45;
    }else{
        mRotate = mRotate-45;
    }
   this->update();
}

void ShapeWidget::paintEvent(Wt::WPaintDevice *paintDevice)
{
    Wt::WPainter painter(paintDevice);
    painter.setPen(Wt::WColor(Wt::StandardColor::Red));
    painter.drawRect(0, 0, 500, 500);

    _Dragged.emit(mLastX+mDraggedX,mLastY+mDraggedY);

    painter.translate(mLastX+mDraggedX,mLastY+mDraggedY);

//    painter.translate(50,50);

    std::cout << "Translate: " << mLastX << " " << mLastY << "\n";
//    painter.rotate(mRotate);
//    painter.drawRect(0, 0, 100, 100);
    painter.drawImage(0,-35,Wt::WPainter::Image(mBuildingPic,50,55));



//    painter.rotate(-mRotate);

//    painter.resetTransform();
//    painter.setPen(Wt::WColor(Wt::StandardColor::Black));
//    painter.drawRect(0, 0, 100, 100);

//    painter.setPen(Wt::WColor(Wt::StandardColor::Green));

//    painter.drawRect(0, 0, 50, 55);

//    painter.resetTransform();

}

Signal<int, int> &ShapeWidget::onDragged()
{
    return _Dragged;
}
