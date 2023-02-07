#ifndef CITY_ASSETSMANAGER_H
#define CITY_ASSETSMANAGER_H

#include <Wt/WContainerWidget.h>
#include <Wt/WSignal.h>



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


};

} // namespace City

#endif // CITY_ASSETSMANAGER_H
