#include <iostream>

#include "test_base.hh"
#include <pt/pt.h>

PT_THREAD(thread1(pt_t *pt)) {
    static u8 test_cnt;
    PT_BEGIN(pt);

    while (1) {
        PT_WAIT_BEGIN(pt);
        test_cnt++;
        PT_WAIT_UNTIL_END(test_cnt == 100);

        if (test_cnt == 100) {
            printf("test_cnt %d\n", test_cnt);
        }

        PT_WAIT_BEGIN(pt);
        test_cnt--;
        PT_WAIT_UNTIL_END(test_cnt == 20);
        if (test_cnt == 20) {
            printf("test_cnt %d\n", test_cnt);
        }
        break;
    }

    PT_END(pt);
}

TEST(PT, PT1) {
    pt_t pt_1;
    PT_INIT(&pt_1);

    while (PT_SCHEDULE(thread1(&pt_1))) {
    }
}
