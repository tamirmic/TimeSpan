#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;
#include <string>

/*
    By: Tamir Michaely

    A TimeSpan class that represents a span of time including hours, minutes, and seconds.
    It normalizes time values and overloads several arithmetic and comparison operators.
    
*/

class TimeSpan {
    public:
        //Constructors
        TimeSpan();
        TimeSpan(double seconds);
        TimeSpan(double minutes, double seconds);
        TimeSpan(double hours, double minutes, double seconds);

        //Getters and Setters
        int hours() const;
        int minutes() const;
        int seconds() const;
        void set_time(int hours, int minutes, int seconds);

        //Operator Overloads
        TimeSpan operator+(const TimeSpan& ts) const;
        TimeSpan operator-(const TimeSpan &ts) const;
        TimeSpan operator-() const;
        TimeSpan& operator+=(const TimeSpan& ts);
        TimeSpan& operator-=(const TimeSpan& ts);
        bool operator==(const TimeSpan &ts) const;
        bool operator!=(const TimeSpan &ts) const;
        bool operator<(const TimeSpan &ts) const;
        bool operator<=(const TimeSpan &ts) const;
        bool operator>(const TimeSpan &ts) const;
        bool operator>=(const TimeSpan &ts) const;
        friend ostream& operator<<(ostream& stream, const TimeSpan& ts);
        friend istream& operator>>(istream& stream, TimeSpan& ts);
        
    private:
        //Private data members
        int hours_;
        int minutes_;
        int seconds_;

        //Converts a TimeSpan into reduced form
        void ConvertTimeSpan(double hours, double minutes, double seconds);

};
#endif