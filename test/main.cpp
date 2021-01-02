#include <gtest/gtest.h>

extern "C" {
#include "../src/library.h"
}

TEST(PlaceHolderTest, Test1) {

    int ret = hello();

    ASSERT_EQ(ret, 12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
