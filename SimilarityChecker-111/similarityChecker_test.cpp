#include "gmock/gmock.h"
#include "similarityChecker.cpp"

using namespace testing;

TEST(TG, TCSameLength) {
	Checker checker;
	string str1 = "ABCDE";
	string str2 = "EDCBA";
	
	int actual = checker.getLengthPoints(str1, str2);
	EXPECT_EQ(60, actual);
}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();

}