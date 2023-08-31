//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"

//#include "sndlayout.h"

//TEST_CASE("Test catch2", "[tag]") {
    //REQUIRE(true);
    //REQUIRE(false);
//};
#include "test.h"
int main()
{
    //=== CASE: ====================================
    // caseDescript
    //=== PREREQUISITES: ===========================
    //=== TESTS: ===================================
    

    //=== TEMPLATE TEST CASE: ======================
    //=== PREREQUISITES: ===========================
    int a = 1;
    
    //=== TESTS: ===================================
    TEST("description", 
        true);
    
    //==============================================
    //==============================================
    printf("\n[SUMMARY]: %i tests failed.\n", fails_counter);
}
