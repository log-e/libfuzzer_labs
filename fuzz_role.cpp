#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "role.pb.h"
#include <sstream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
bool registered = false;

DEFINE_PROTO_FUZZER(const GameRole &role)
{
    // // 前置处理
    // if (!registered)
    // {
    //     protobuf_mutator::libfuzzer::RegisterPostProcessor(
    //         GameRole::descriptor(),
    //         [](google::protobuf::Message *message, unsigned int seed) {
    //             GameRole *r = static_cast<GameRole *>(message);
    //             r->set_hp(803);
    //         }

    //     );
    //     registered = true;
    // }

    if (role.level() == 60)
        if (role.name() == "baidu")
            if (role.isvip() == true)
                if (role.hp() > 800 && role.hp() < 802)
                    if (role.mp() > 90000000 && role.mp() < 888888888)
                    {
                        int *p = NULL;
                        *p = 123;
                    }
}