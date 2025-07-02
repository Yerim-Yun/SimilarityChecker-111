#include <string>

using std::string;

class Checker {
public:
	Checker(const string& str1, const string& str2)
		: str1(str1), str2(str2) {}

	int getPartialPoints(int gap, int minLeng) {
		return (1 - (double)gap / minLeng) * 60;
	}
private:
	int getLengthPoints() {
		int lengthStr1 = str1.length();
		int lengthStr2 = str2.length();
		int minLength = std::min(lengthStr1, lengthStr2);
		int maxLength = std::max(lengthStr1, lengthStr2);
		int gap = maxLength - minLength;

		if (lengthStr1 == lengthStr2)
			return MAX_LENGTH_POINT;
		else if(maxLength >= (minLength * 2))
			return MIN_LENGTH_POINT;
		else {
			return getPartialPoints(gap, minLength);
		}
	}
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 60;

	string str1;
	string str2;
};