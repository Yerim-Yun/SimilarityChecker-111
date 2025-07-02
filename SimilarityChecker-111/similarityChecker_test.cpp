#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

class CheckerFixture :public testing::Test {
public:
	void checkLength(int expected, string str1, string str2) {
		Checker checker{ str1 , str2 };
		int actual = checker.getLengthPoints();
		EXPECT_EQ(expected, actual);
	}

	void checkAlpha(int expected, string str1, string str2) {
		Checker checker{ str1 , str2 };
		int actual = checker.getAlphaPoints();
		EXPECT_EQ(expected, actual);
	}
};

TEST_F(CheckerFixture, TCSameLength) {
	checkLength(60, "ABCDE" , "EDCBA");
}

TEST_F(CheckerFixture, TCDiffDoubleLength) {
	checkLength(0, "ABCD" , "ED");
}

TEST_F(CheckerFixture, TCDiffPartialLength) {
	checkLength(20, "AAABB" , "BAA");
}

TEST_F(CheckerFixture, TCSameAlpha) {
	checkAlpha(40, "ASD", "DSA");
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();

}