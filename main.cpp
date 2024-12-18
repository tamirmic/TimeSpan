#include "time_span.h"
#include <sstream>

bool CheckValues(TimeSpan time, int hours, int minutes, int seconds){
    if ((time.hours() != hours) || (time.minutes() != minutes) || (time.seconds() != seconds)){
        return false;
    }
    return true;
}

bool CheckOperators(bool actual_result, bool expected_result){
    if(actual_result == expected_result){
        return true;
    } else{
        return false;
    }
}

//Professor test cases
bool TestZeros(){
    TimeSpan ts(0, 0, 0);
    return CheckValues(ts, 0, 0, 0);
}

bool TestFloatSeconds(){
    TimeSpan ts(127.86);
    return CheckValues(ts, 0, 2, 8);
}

bool TestNegativeMinute(){
    TimeSpan ts(8, -23, 0);
    return CheckValues(ts, 7, 37, 0);
}

bool TestNegativeHour(){
    TimeSpan ts(-3, 73, 2);
    return CheckValues(ts, -1, -46, -58);
}

bool TestAddInPlace(){
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
    {
    return false;
    }
    ts1 += ts2;
    if ((!CheckValues(ts1, 6, 7, 8)) || (!CheckValues(ts2, 1, 1, 1)))
    {
    return false;
    }
    return true;
}

//My test cases
bool TestConvert1(){
    TimeSpan ts(1.5, 4, -10);
    return CheckValues(ts, 1, 33, 50);
}

bool TestConvert2(){
    TimeSpan ts(7, -3);
    return CheckValues(ts, 0, 6, 57);
}

bool TestConvert3(){
    TimeSpan ts(-190);
    return CheckValues(ts, 0, -3, -10);
}

bool TestConvert4(){
    TimeSpan ts(3, -90, 120);
    return CheckValues(ts, 1, 32, 0);
}

bool TestConvert5(){
    TimeSpan ts(1000);
    return CheckValues(ts, 0, 16, 40);
}

bool TestConvert6(){
    TimeSpan ts(1000, 1000, 1000);
    return CheckValues(ts, 1016, 56, 40);
}

bool TestConvert7(){
    TimeSpan ts(1.57, -1.86);
    return CheckValues(ts, 0, 1, 32);
}

bool TestConvert8(){
    TimeSpan ts(4, -999, -86);
    return CheckValues(ts, -12, -40, -26);
}

bool TestConvert9(){
    TimeSpan ts(-100, 20, -50);
    return CheckValues(ts, -99, -40, -50);
}

bool TestConvert10() {
    TimeSpan ts(0, 60.99999, 0);
    return CheckValues(ts, 1, 1, 0);
}

bool TestConvert11() {
    TimeSpan ts(0, 0, -59.9);
    return CheckValues(ts, 0, -1, 0);
}

bool TestConvert12() {
    TimeSpan ts(0, 0, 59.9);
    return CheckValues(ts, 0, 1, 0);
}

bool TestAdd(){
    TimeSpan ts1, ts2(0, 5), ts3(5, 5, 2), ts4(0, 1, -1);
    TimeSpan add_it_up = ts1 + ts2 + ts3 + ts4;
    return CheckValues(add_it_up, 5, 6, 6);
}

bool TestSubtract(){
    TimeSpan ts1, ts2(1, 1, 1), ts3(1, 2);
    TimeSpan subtract_it_up = ts1 - ts2 - ts3;
    return CheckValues(subtract_it_up, -1, -2, -3);
}

bool TestNegation(){
    TimeSpan ts(1, -1, 1);
    TimeSpan negation = -ts;
    return CheckValues(negation, 0, -59, -1);
}

bool TestEqual(){
    TimeSpan ts1(1, 2, 10);
    TimeSpan ts2(1, 2, 10);
    bool actual_result = (ts1 == ts2);
    bool expected_result = true;
    return CheckOperators(actual_result, expected_result);
}

bool TestNotEqual(){
    TimeSpan ts1(1, -2, 10);
    TimeSpan ts2(1, 2, 10);
    bool actual_result = (ts1 != ts2);
    bool expected_result = true;
    return CheckOperators(actual_result, expected_result);
}

bool TestLessThan(){
    TimeSpan ts1(1, -2, 10);
    TimeSpan ts2(1, 2, 10);
    bool actual_result = (ts1 < ts2);
    bool expected_result = true;
    return CheckOperators(actual_result, expected_result);
}

bool TestLessThanOrEqualTo(){
    TimeSpan ts1(1, 2, 5);
    TimeSpan ts2(1, 2, 10);
    bool actual_result = (ts1 < ts2);
    bool expected_result = true;
    return CheckOperators(actual_result, expected_result);
}

bool TestGreaterThan(){
    TimeSpan ts1(1, 2, 5);
    TimeSpan ts2(1, 2, -10);
    bool actual_result = (ts1 > ts2);
    bool expected_result = true;
    return CheckOperators(actual_result, expected_result);
}

bool TestGreaterThanOrEqualTo(){
    TimeSpan ts1(-2, 2, 5);
    TimeSpan ts2(-2, 5, 10);
    bool actual_result = (ts1 >= ts2);
    bool expected_result = false;
    return CheckOperators(actual_result, expected_result);
}

bool TestMinusInPlace1(){
    TimeSpan ts1(5, 6, 7);
    TimeSpan ts2(1, 1, 1);
    if ((!CheckValues(ts1, 5, 6, 7)) || (!CheckValues(ts2, 1, 1, 1)))
    {
    return false;
    }
    ts1 -= ts2;
    if ((!CheckValues(ts1, 4, 5, 6)) || (!CheckValues(ts2, 1, 1, 1)))
    {
    return false;
    }
    return true;
}

bool TestMinusInPlace2(){
    TimeSpan ts1(1,-2), ts2(4, 3, 2);
    ts1 -= ts2;
    return CheckValues(ts1, -4, -2, -4);
}

bool TestAddInPlace2(){
    TimeSpan ts(1, -2);
    ts += ts;
    return CheckValues(ts, 0, 1, 56);
}

bool TestInStream(){
    TimeSpan ts;
    stringstream stream("3 120 30");
    stream >> ts;
    return CheckValues(ts, 5, 0, 30);
}

int main(){
    cout << "Testing TimeSpan Class" << endl;
    if (!TestZeros()) cout << "Failed: TestZeros" << endl;
    if (!TestFloatSeconds()) cout << "Failed: TestFloatSeconds" << endl;
    if (!TestNegativeMinute()) cout << "Failed: TestNegativeMinute" << endl;
    if (!TestNegativeHour()) cout << "Failed: TestNegativeHour" << endl;
    if (!TestAddInPlace()) cout << "Failed: TestAddInPlace" << endl;
    if (!TestConvert1()) cout << "Failed: TestConvert1" << endl;
    if (!TestConvert2()) cout << "Failed: TestConvert2" << endl;
    if (!TestConvert3()) cout << "Failed: TestConvert3" << endl;
    if (!TestConvert4()) cout << "Failed: TestConvert4" << endl;
    if (!TestConvert5()) cout << "Failed: TestConvert5" << endl;
    if (!TestConvert6()) cout << "Failed: TestConvert6" << endl;
    if (!TestConvert7()) cout << "Failed: TestConvert7" << endl;
    if (!TestConvert8()) cout << "Failed: TestConvert8" << endl;
    if (!TestConvert9()) cout << "Failed: TestConvert9" << endl;
    if (!TestConvert10()) cout << "Failed: TestConvert10" << endl;
    if (!TestConvert11()) cout << "Failed: TestConvert11" << endl;
    if (!TestConvert12()) cout << "Failed: TestConvert12" << endl;
    if (!TestAdd()) cout << "Failed: TestAdd" << endl;
    if (!TestSubtract()) cout << "Failed: TestSubtract" << endl;
    if (!TestNegation()) cout << "Failed: TestNegation" << endl;
    if (!TestEqual()) cout << "Failed: TestEqual" << endl;
    if (!TestNotEqual()) cout << "Failed: TestNotEqual" << endl;
    if (!TestLessThan()) cout << "Failed: TestLessThan" << endl;
    if (!TestLessThanOrEqualTo()) cout << "Failed: TestLessThanOrEqualTo" << endl;
    if (!TestGreaterThan()) cout << "Failed: TestGreaterThan" << endl;
    if (!TestGreaterThanOrEqualTo()) cout << "Failed: TestGreaterThanOrEqualTo" << endl;
    if (!TestMinusInPlace1()) cout << "Failed: TestMinusInPlace1" << endl;
    if (!TestMinusInPlace2()) cout << "Failed: TestMinusInPlace2" << endl;
    if (!TestAddInPlace2()) cout << "Failed: TestAddInPlace2" << endl;
    if (!TestInStream()) cout << "Failed: TestInStream" << endl;
    cout << "Testing Complete" << endl;
}