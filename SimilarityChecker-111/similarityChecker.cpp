#include <string>

using std::string;

class Checker {
public:
	int getLengthPoints(const string& str1, const string& str2) {
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
			return (1 - (double)gap / minLength) * 60;
		}
	}

};