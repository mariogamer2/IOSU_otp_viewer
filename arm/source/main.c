#include "types.h"
#include "utils.h"

extern void IOS_DCFlushAllCache(unsigned int addr);

void _main()
{
    unsigned char test_buf[0x400];
    int (*read_otp_internal)(int index, void* out_buf, u32 size) = (int (*)(int, void*, u32)) 0x08120248;

    read_otp_internal(0, test_buf, sizeof(test_buf));

    while(1)
    {
        m_memcpy((void*)0x0012F000, test_buf, sizeof(test_buf));
        IOS_DCFlushAllCache(0x0012F000);
    }
}
