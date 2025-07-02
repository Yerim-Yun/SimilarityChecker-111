#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

TEST(TG, TC1) {
	EXPECT_EQ(1, 1);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();

}