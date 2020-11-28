#include "role.pb.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    GameRole t;
    t.set_hp(200);
    t.set_isvip(true);
    t.set_name("baidu");
    t.set_mp(400);
    t.set_level(100);

    cout << "This is a test Game Role -> t" << std::endl;
    cout << "name:  " << t.name() << std::endl;
    cout << "level: " << t.level() << std::endl;
    cout << "isvip: " << t.isvip() << std::endl;
    cout << "hp:    " << t.hp() << std::endl;
    cout << "mp:    " << t.mp() << std::endl;
    return 0;
}