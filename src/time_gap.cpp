#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <assert.h>

using namespace std;

void print_time(char *str);
int StrToTime(const string str, struct tm * tm);
int Gap(const struct tm &, const struct tm &);


int main(int argc, char * argv[]) {


	char curTime[100];
	print_time(curTime);

	//cout << curTime << endl;

	/*
	std::string text = curTime;//"Let me split this into words";
	std::vector<std::string> results;

	boost::split(results, text, [](char c){return c == ':';});
	*/

	/*
	for (vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) {
		cout << *it << endl;
	}
	*/

	cout << curTime << endl;

	struct tm tm1, tm2;

	if(StrToTime("12:37:23_833957", &tm1) == 0) {

		cout << tm1.tm_hour << "||" << tm1.tm_min << "||" << tm1.tm_sec << endl;
	}

	if(StrToTime(curTime, &tm2) == 0) {

		cout << tm2.tm_hour << "||" << tm2.tm_min << "||" << tm2.tm_sec << endl;
	}

	cout << Gap(tm1, tm2) << endl;




}

void print_time(char *str) {
	struct timeval tv;
	struct timezone tz;
	struct tm *tm;
	gettimeofday(&tv, &tz);
	tm=localtime(&tv.tv_sec);
	sprintf(str, "%d:%02d:%02d_%d", tm->tm_hour, tm->tm_min,
		  tm->tm_sec, tv.tv_usec);
}

int StrToTime(const string str, struct tm * tm) {


	/*
	for (vector<string>::const_iterator it = results.begin(); it != results.end(); ++it) {
		cout << *it << endl;
	}
	*/

	vector<std::string> results;
	try {


		boost::split(results, str, [](char c){return c == ':';});

		assert(results.size() == 3);
		tm->tm_hour = stoi(results[0]);
		tm->tm_min = stoi(results[1]);
		boost::split(results, results[2], [](char c){return c == '_';});
		assert(results.size() == 2);
		tm->tm_sec = stoi(results[0]);

 	}
	catch (const exception & e) {
		cout << "Error occured " << e.what() << endl;
		return -1;
	}

	return 0;
	//cout << curTime << endl;

}

int Gap(const struct tm &tm1, const struct tm &tm2) {
	//int sec1 = tm1.tm_hour*3600+tm1.tm_min*60+tm1.tm
	auto secs = [](const struct tm &t) {return (t.tm_hour*3600+t.tm_min*60+t.tm_sec); };
	return secs(tm2) - secs(tm1);

}
