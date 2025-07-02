#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

class CheckerFixture :public testing::Test {
public:
	void check(int expected, string str1, string str2) {
		Checker checker{ str1 , str2 };
		int actual = checker.getLengthPoints();
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(CheckerFixture, TCSameLength) {
	check(60, "ABCDE" , "EDCBA");
}

TEST_F(CheckerFixture, TCDiffDoubleLength) {
	check(0, "ABCD" , "ED");
}

TEST_F(CheckerFixture, TCDiffPartialLength) {
	check(20, "AAABB" , "BAA");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();

}