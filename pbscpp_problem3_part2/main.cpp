#include "gtest/gtest.h"
#include "tests/tests.h"

using ShopBasePtr = std::shared_ptr< ShopBase >;
using ProductBasePtr = std::shared_ptr< ProductBase >;

int main( int argc, char **argv ) {	
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
