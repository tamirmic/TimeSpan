#include "time_span.h"
#include <cmath>

//Constructors
TimeSpan::TimeSpan(){
    ConvertTimeSpan(0, 0, 0);
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds){
    ConvertTimeSpan(hours, minutes, seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds){
    ConvertTimeSpan(0, minutes, seconds);
}

TimeSpan::TimeSpan(double seconds){
    ConvertTimeSpan(0, 0, seconds);
}

//Getters
int TimeSpan::hours() const{
    return hours_;
}

int TimeSpan::minutes() const{
    return minutes_;
}

int TimeSpan::seconds() const{
    return seconds_;
}

//Setter
void TimeSpan::set_time(int hours, int minutes, int seconds){
    hours_ = hours;
    minutes_ = minutes;
    seconds_ = seconds;
}

void TimeSpan::ConvertTimeSpan(double hours, double minutes, double seconds){
    //Converts all the time to seconds
    double totalSeconds = (hours * 3600) + (minutes * 60) + seconds;
    //Checks if (0,0,0)
    if(totalSeconds == 0){
        hours_ = 0;
        minutes_ = 0;
        seconds_ = 0;
    } else {
        //Converts totalSeconds into each appropriate time unit and casts as int
        hours_ = static_cast<int>(totalSeconds / 3600);
        minutes_ = static_cast<int>((fmod(totalSeconds, 3600)) / 60);
        seconds_ = static_cast<int>(round(fmod((fmod(totalSeconds, 3600)), 60)));
    }
    //Checks to make sure the TimeSpan doesn't round up without converting the 60 seconds to a minute
    if(seconds_ == 60){
        seconds_ = 0;
        minutes_ += 1;
    }
    //Checks to make sure the TimeSpan doesn't round up without converting the 60 minutes to a hour
    if(minutes_ == 60){
        minutes_ = 0;
        hours_ += 1;
    }
    //Same logic as above but with negative seconds and minutes
    if(seconds_ == -60){
        seconds_ = 0;
        minutes_ -= 1;
    }
    if(minutes_ == -60){
        minutes_ = 0;
        hours_ -= 1;
    }
}

//Overload math operators
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const{
    return TimeSpan(hours() + ts.hours(), minutes() + ts.minutes(), seconds() + ts.seconds());
}

TimeSpan TimeSpan::operator-(const TimeSpan &ts) const{
    return TimeSpan(hours() - ts.hours(), minutes() - ts.minutes(), seconds() - ts.seconds());
}

TimeSpan TimeSpan::operator-() const{
    return TimeSpan(-hours(), -minutes(), -seconds());
}

//Overload assignment statements
TimeSpan& TimeSpan::operator+=(const TimeSpan &ts){
    hours_ += ts.hours();
    minutes_ += ts.minutes();
    seconds_ += ts.seconds();
    ConvertTimeSpan(hours_, minutes_, seconds_);
    return *this;
}

TimeSpan& TimeSpan::operator-=(const TimeSpan &ts){
    hours_ -= ts.hours();
    minutes_ -= ts.minutes();
    seconds_ -= ts.seconds();
    ConvertTimeSpan(hours_, minutes_, seconds_);
    return *this;
}

//Overload comparison operators
bool TimeSpan::operator==(const TimeSpan &ts) const{
    return (hours() == ts.hours() && minutes() == ts.minutes() && seconds() == ts.seconds());
}

bool TimeSpan::operator!=(const TimeSpan &ts) const{
    return (hours() != ts.hours() || minutes() != ts.minutes() || seconds() != ts.seconds());
}

bool TimeSpan::operator<(const TimeSpan &ts) const{
    if(hours() < ts.hours()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() < ts.minutes()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() == ts.minutes() && seconds() < ts.seconds()){
        return true;
    }
    else{
        return false;
    }
}

bool TimeSpan::operator<=(const TimeSpan &ts) const{
    if (hours() < ts.hours()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() < ts.minutes()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() == ts.minutes() && seconds() < ts.seconds()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() == ts.minutes() && seconds() == ts.seconds()){
        return true;
    }
    return false;
}

bool TimeSpan::operator>(const TimeSpan &ts) const{
    if(hours() > ts.hours()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() > ts.minutes()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() == ts.minutes() && seconds() > ts.seconds()){
        return true;
    }
    else{
        return false;
    }
}

bool TimeSpan::operator>=(const TimeSpan &ts) const{
    if (hours() > ts.hours()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() > ts.minutes()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() == ts.minutes() && seconds() > ts.seconds()){
        return true;
    }
    else if(hours() == ts.hours() && minutes() == ts.minutes() && seconds() == ts.seconds()){
        return true;
    }
    return false;
}

//Overload input/output operators
ostream& operator<<(ostream& stream, const TimeSpan& ts){
    stream << "Hours: " << ts.hours() << ", Minutes: " << ts.minutes() << ", Seconds: " << ts.seconds();
    return stream;
}

istream& operator>>(istream& stream, TimeSpan& ts){
    stream >> ts.hours_ >> ts.minutes_ >> ts.seconds_;
    ts.ConvertTimeSpan(ts.hours_, ts.minutes_, ts.seconds_);
    return stream;
}