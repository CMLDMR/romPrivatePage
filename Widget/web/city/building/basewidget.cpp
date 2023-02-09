#include "basewidget.h"
#include "utility/style.h"

#include <Wt/WCssDecorationStyle.h>

using namespace Wt;

namespace WebWidget {
namespace Building {

BaseWidget::BaseWidget(const ::Building::Type &_type)
    : ::Building::Building(_type)
{



}

BaseWidget &BaseWidget::addAttribute(const std::string &_attribute)
{
    bool exist = false;
    for( const auto &item : mAttriuteList ){
        if( item == _attribute ){
            exist = true;
            break;
        }
    }
    if( !exist ){
        this->mAttriuteList.push_back(_attribute);
        this->updateAttribute();
    }
    return *this;
}

void BaseWidget::updateAttribute()
{
    std::string _attribue;
    for( const auto &item : this->mAttriuteList ){
        _attribue += item;
    }
    this->setAttributeValue(Style::style,_attribue);
}



bool BaseWidget::selected() const
{
    return mSelected;
}

void BaseWidget::setSelected(bool _selected)
{
    this->mSelected = _selected;
    if( mSelected ){
        this->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor(StandardColor::DarkGray)));
    }else{
        this->decorationStyle().setBorder(WBorder(BorderStyle::None,BorderWidth::Thin,WColor(StandardColor::Black)));
    }
}

void BaseWidget::setPosition(const int &x, const int &y)
{
    this->mXPos = x;
    this->mYPos = y;
    this->setOffsets(this->mXPos-this->buildingWidth()/2,Side::Left);
    this->setOffsets(this->mYPos-this->buildingHeight()/2,Side::Top);
}

std::pair<int, int> BaseWidget::Position() const
{
    return std::make_pair(this->mXPos,this->mYPos);
}

int BaseWidget::xPos() const
{
    return mXPos;
}

int BaseWidget::yPos() const
{
    return mYPos;
}






void BaseWidget::removeAttribute(const std::string &_attribute)
{
    for( const auto &item : mAttriuteList ){
        if( item == _attribute ){
            mAttriuteList.remove(_attribute);
            this->updateAttribute();
            break;
        }
    }
}

bool BaseWidget::containAttribute(const std::string &_attribute) const
{
    bool exist = false;
    for( const auto &item : this->mAttriuteList ){
        if( _attribute == item ){
            exist = true;
            break;
        }
    }
    return exist;
}

void BaseWidget::togleSelected()
{
    mSelected = !mSelected;
    if( mSelected ){
        this->decorationStyle().setBorder(WBorder(BorderStyle::Solid,BorderWidth::Thin,WColor(StandardColor::DarkGray)));
    }else{
        this->decorationStyle().setBorder(WBorder(BorderStyle::None,BorderWidth::Thin,WColor(StandardColor::Black)));
    }
}






} // namespace Building
} // namespace WebWidget
