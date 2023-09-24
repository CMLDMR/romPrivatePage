#include "City/controlpanel.h"

#include <Wt/WCssDecorationStyle.h>
#include <Wt/WColor.h>
#include <Wt/WText.h>
#include <Wt/WHBoxLayout.h>


using namespace Wt;


namespace City {

ControlPanel::ControlPanel()
{
    this->setPositionScheme(PositionScheme::Absolute);
    this->setWidth(WLength("100%"));
    this->setContentAlignment(AlignmentFlag::Center);
    this->setZIndex(10);


    initializePanel();

}

Signal<Map> &ControlPanel::selectedMap()
{
    return m_selectMap;
}

void ControlPanel::initializePanel()
{

    auto container = this->addNew<WContainerWidget>();
    container->setMaximumSize(1280,WLength::Auto);
    container->decorationStyle().setBackgroundColor(WColor(StandardColor::Cyan));
    container->setHeight(50);
    container->setPositionScheme(PositionScheme::Relative);
    container->setMargin(40,Side::Top);

    auto avatarContainer = container->addNew<WContainerWidget>();
    avatarContainer->setPositionScheme(PositionScheme::Absolute);
    avatarContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::DarkGray));
    avatarContainer->setOffsets(25,Side::Left);
    avatarContainer->setWidth(80);
    avatarContainer->setHeight(80);
    avatarContainer->setOffsets(-30,Side::Top);
    avatarContainer->setContentAlignment(AlignmentFlag::Center);
    avatarContainer->setPadding(20,AllSides);
    avatarContainer->addNew<WText>("Avatar");




    auto controlPanelContainer = container->addNew<WContainerWidget>();
    controlPanelContainer->setPositionScheme(PositionScheme::Absolute);
    controlPanelContainer->setHeight(70);
    controlPanelContainer->setWidth(720);
    controlPanelContainer->setOffsets(0,Side::Right);
    controlPanelContainer->setOffsets(-20,Side::Top);


    auto hLayout = controlPanelContainer->setLayout(std::make_unique<WHBoxLayout>());

    hLayout->addStretch(1);

    auto depoContainer = hLayout->addWidget(std::make_unique<WContainerWidget>());
    depoContainer->setWidth(100);
    depoContainer->setHeight(70);
    depoContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::DarkGreen));
    depoContainer->addNew<WText>("Depo");

    hLayout->addSpacing(15);

    auto askerContainer = hLayout->addWidget(std::make_unique<WContainerWidget>());
    askerContainer->setWidth(100);
    askerContainer->setHeight(70);
    askerContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::DarkCyan));
    askerContainer->addNew<WText>("Askeri Durum");


    hLayout->addSpacing(15);

    auto savunmaContainer = hLayout->addWidget(std::make_unique<WContainerWidget>());
    savunmaContainer->setWidth(100);
    savunmaContainer->setHeight(70);
    savunmaContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::Magenta));
    savunmaContainer->addNew<WText>("Savunma");


    hLayout->addSpacing(15);

    auto messageContainer = hLayout->addWidget(std::make_unique<WContainerWidget>());
    messageContainer->setWidth(100);
    messageContainer->setHeight(70);
    messageContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::LightGray));
    messageContainer->addNew<WText>("Mesaj Kutusu");

    hLayout->addSpacing(15);

    auto helpContainer = hLayout->addWidget(std::make_unique<WContainerWidget>());
    helpContainer->setWidth(100);
    helpContainer->setHeight(70);
    helpContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::DarkRed));
    helpContainer->addNew<WText>("Yardım?");

    hLayout->addSpacing(15);

    auto worldContainer = hLayout->addWidget(std::make_unique<WContainerWidget>());
    worldContainer->setWidth(100);
    worldContainer->setHeight(70);
    worldContainer->decorationStyle().setBackgroundColor(WColor(StandardColor::DarkYellow));
    m_mapTitleText = worldContainer->addNew<WText>("Dünya");
        worldContainer->clicked().connect([=](){
        if( m_currentMap == Map::City ){
            m_currentMap = Map::World;
            m_selectMap.emit(m_currentMap);
            m_mapTitleText->setText(("Şehir"));
        }else{
            m_currentMap = Map::City;
            m_selectMap.emit(m_currentMap);
            m_mapTitleText->setText(("Dünya"));
        }
    });

}

} // namespace City
