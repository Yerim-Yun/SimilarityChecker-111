#include <string>

using std::string;

class Checker {
public:
	Checker(const string& str1, const string& str2)
		: str1(str1), str2(str2) {}

	int getPartialPoints(int gap, int minLeng) {
		return (1 - (double)gap / minLeng) * 60;
	}

	int getLengthPoints() {
		int lengthStr1 = str1.length();
		int lengthStr2 = str2.length();
		int minLength = std::min(lengthStr1, lengthStr2);
		int maxLength = std::max(lengthStr1, lengthStr2);
		int gap = maxLength - minLength;

		if (lengthStr1 == lengthStr2)
			return 60;
		else if(maxLength >= (minLength * 2))
			return 0;
		else {
			return getPartialPoints(gap, minLength);
		}
	}
private:
	string str1;
	string str2;
};