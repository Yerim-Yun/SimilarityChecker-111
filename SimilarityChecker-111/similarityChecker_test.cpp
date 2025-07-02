#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

TEST(TG, TCSameLength) {
	Checker checker{ "ABCDE" , "EDCBA" };
	int actual = checker.getLengthPoints();
	EXPECT_EQ(60, actual);
}

TEST(TG, TCDiffDoubleLength) {
	Checker checker{ "ABCD" , "ED" };

	int actual = checker.getLengthPoints();
	EXPECT_EQ(0, actual);
}

TEST(TG, TCDiffPartialLength) {
	Checker checker{ "AAABB" , "BAA" };

	int actual = checker.getLengthPoints();
	EXPECT_EQ(20, actual);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();

}