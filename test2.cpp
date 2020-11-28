
#include <stdint.h>
#include <stddef.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int process(const uint8_t *data, size_t size);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    return process(data, size);
}

int process(const uint8_t *data, size_t size)
{
    if (data == nullptr || size == 0)
    {
        return -1;
    }

    try
    {
        json j = json::parse(data, data + size);
        if (j.is_object())
        {
            // {"fuzz":true}
            if (j.contains("fuzz") && j["fuzz"].is_boolean() && j["fuzz"] == true)
            {
                // 只有 data 是一个 json ，且存在 fuzz 这个 key，并且 fuzz 的类型为 bool, 值为 true，才会触发此逻辑
                int *p = NULL;
                *p = 123;
            }
        }
    }
    catch (const json::parse_error &)
    {
        return -1;
    }
    catch (const json::out_of_range &)
    {
        return -1;
    }

    return 0;
}