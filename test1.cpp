
#include <stdint.h>
#include <stddef.h>

int process(const uint8_t *data, size_t size);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    return process(data, size);
}

int process(const uint8_t *data, size_t size)
{
    // 正常的逻辑
    if (size > 0 && data[0] == 'g')
        if (size > 1 && data[1] == 'o')
            return 0;

    // 如果发送的数据为 baidu2020 就会触发 bug
    // size 为 9 byte * 8 = 72 bit, 有 2 ^ 72 个可能
    if (size > 0 && data[0] == 'b')
        if (size > 1 && data[1] == 'a')
            if (size > 2 && data[2] == 'i')
                if (size > 3 && data[3] == 'd')
                    if (size > 4 && data[4] == 'u')
                        if (size > 5 && data[5] == '2')
                            if (size > 6 && data[6] == '0')
                                if (size > 7 && data[7] == '2')
                                    if (size > 8 && data[8] == '1')
                                    {
                                        int *p = NULL;
                                        *p = 123;
                                    }
    return 0;
}