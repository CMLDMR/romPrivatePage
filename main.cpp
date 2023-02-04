
//https://htmldom.dev/drag-to-scroll/
//https://dribbble.com/shots/19829812-Crypto-City-Web-site-design


#include "mainapplication.h"
#include <memory.h>



#include <algorithm>


void test(){

    std::cout << "Delimited\n";

    std::string delimited = "this is a string\"(with an embedded message)\" that continues";

    auto start = std::adjacent_find(delimited.begin(),delimited.end(),[](char l , char r){
            return l == '"' && r == '(';
});

    auto end = std::adjacent_find(start,delimited.end(),[](char l , char r){
            return l == ')' && r == '"';
});


    std::cout << delimited << "\n";
    std::string embedded(start+2,end);

        std::cout << embedded << "\n";
    delimited.erase(start,end+2);

        std::cout << delimited << "\n";

    return;
}





int main(int argc1, char **argv1)
{

    int argc = 6;
    auto argv = std::unique_ptr<char*[]>(new char*[argc]);

    argv[0] = (char *) "multiple";
    argv[1] = (char *) "--http-address=127.0.0.1";
    argv[2] = (char *) "--http-port=8085";
    argv[3] = (char *) "--deploy-path=/";
    argv[4] = (char *) "--docroot=../CanvasWT/docroot";
    argv[5] = (char *) "--approot=approot";
    return WRun(argc, argv.get(), [](const Wt::WEnvironment &env){
        return std::make_unique<MainApplication>(env);
    });
}
