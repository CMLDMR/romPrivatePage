#ifndef CSS_GLOBALRULE_H
#define CSS_GLOBALRULE_H

#include <Wt/WCssStyleSheet.h>



namespace CSS {

class GlobalRule : public Wt::WCssStyleSheet
{
public:
    GlobalRule();

    std::unique_ptr<Wt::WCssTextRule> developmentModeRule();

};



class DevelopmentModeRule : Wt::WCssTextRule
{
public:
    DevelopmentModeRule();
};

} // namespace CSS

#endif // CSS_GLOBALRULE_H
