
//https://htmldom.dev/drag-to-scroll/
//https://dribbble.com/shots/19829812-Crypto-City-Web-site-design


#include "mainapplication.h"


int main(int argc1, char **argv1)
{

    int argc = 6;
    auto argv = std::unique_ptr<char*[]>(new char*[argc]);

    argv[0] = (char *) "multiple";
    argv[1] = (char *) "--http-address=127.0.0.1";
    argv[2] = (char *) "--http-port=8085";
    argv[3] = (char *) "--deploy-path=/";
    argv[4] = (char *) "--docroot=../romPrivatePage/docroot";
    argv[5] = (char *) "--approot=approot";
    return WRun(argc, argv.get(), [](const Wt::WEnvironment &env){
        return std::make_unique<MainApplication>(env);
    });
}
