#ifndef CITY_ASSETSMANAGER_H
#define CITY_ASSETSMANAGER_H

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>

#include <list>


namespace Wt{
class WGridLayout;
}


namespace City {

class AssetsManager : public Wt::WContainerWidget
{
public:
    AssetsManager();


    template<typename T>
    void addBuildMenu(const int &x, const int &y);


    Wt::WGridLayout* mGLayout;


    Wt::Signal<Wt::NoClass> &SelectedBuild();
private:

    Wt::Signal<Wt::NoClass> _selectedBuild;

//    std::list<buildType> mBuildType;


};

} // namespace City

#endif // CITY_ASSETSMANAGER_H
