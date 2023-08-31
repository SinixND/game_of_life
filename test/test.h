#ifndef TEST_H
#define TEST_H

#include <stdio.h>
int fails_counter = 0;
#define TEST(name, cond) \
    if (cond) {} \
    else { \
        printf("[line %d] TEST FAILED: %s!\n", __LINE__, name); \
        ++fails_counter; \
        }       

#endif