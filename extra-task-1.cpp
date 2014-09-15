#include <iostream>
#include <cassert>
#include <cmath>
using namespace std; 

double seconds_difference(double time_1, double time_2)
{
	return (time_2 - time_1);
}


double hours_difference(double time_1, double time_2)
{
	return (time_2 - time_1)/3600;
}

double to_float_hours(int hours, int minutes, int seconds)
{
	return hours + static_cast<double>(minutes) / 60 + static_cast<double>(seconds) / 3600;
}


double to_24_hour_clock(double hours)
{
   return fmod(hours, 24.0);
}
    
double get_hours(int seconds) {
	return (seconds / 3600)%24;
}
double get_minutes(int seconds) {
	return (seconds / 60) %60;
}
double get_seconds(int seconds) {
	return seconds % 60;
}


double time_to_utc(int utc_offset, double time) { 
	if (utc_offset < 0)
		return to_24_hour_clock(time + abs(utc_offset));
	else
		return to_24_hour_clock(time - abs(utc_offset));
}
	

double time_from_utc(int utc_offset, double time)
{
	double t = to_24_hour_clock(time + utc_offset);
	if (t < 0)
		return 24 + t;
	else return t;
}

int main() {
	
	assert(seconds_difference(1800.0, 3600.0) - 1800.0 < DBL_EPSILON);
	assert(seconds_difference(3600.0, 1800.0) + 1800.0 < DBL_EPSILON);
	assert(seconds_difference(1800.0, 2160.0) - 360.0 < DBL_EPSILON);
	assert(seconds_difference(1800.0, 1800.0) < DBL_EPSILON);
	
	assert(hours_difference(1800.0, 3600.0) - 0.5 < DBL_EPSILON);
	assert(hours_difference(3600.0, 1800.0) + 0.5 < DBL_EPSILON);
	assert(hours_difference(1800.0, 2160.0) - 0.1 < DBL_EPSILON);
	assert(hours_difference(1800.0, 1800.0) < DBL_EPSILON);
	
	assert(to_float_hours(0, 15, 0) - 0.25 < DBL_EPSILON); 
	assert(to_float_hours(2, 45, 9) - 2.7525 < DBL_EPSILON);
	assert(to_float_hours(1, 0, 36) - 1.01 < DBL_EPSILON);
	
	assert(to_24_hour_clock(24) < DBL_EPSILON); 
	assert(to_24_hour_clock(48) < DBL_EPSILON);
	assert(to_24_hour_clock(25) - 1 < DBL_EPSILON);
	assert(to_24_hour_clock(4) - 4 < DBL_EPSILON);
	assert(to_24_hour_clock(28.5) - 4.5 < DBL_EPSILON);

	assert(get_hours(3800) - 1 < DBL_EPSILON);
	assert(get_minutes(3800) - 3 < DBL_EPSILON);
	assert(get_seconds(3800) - 20 < DBL_EPSILON);
	
	assert(time_to_utc(0, 12.0) - 12.0 < DBL_EPSILON); 
	assert(time_to_utc(-1, 12.0) - 13.0 < DBL_EPSILON);
	assert(time_to_utc(-11, 18.0) - 5.0 < DBL_EPSILON);
	assert(time_to_utc(1, 12.0) - 12.0 < DBL_EPSILON);
	assert(time_to_utc(-1, 0.0) - 1.0 < DBL_EPSILON);
	assert(time_to_utc(-1, 23.0) < DBL_EPSILON);
	
	assert(time_from_utc(0, 12.0) - 12.0 < DBL_EPSILON);
	assert(time_from_utc(1, 12.0) - 13.0 < DBL_EPSILON);
	assert(time_from_utc(-1, 12.0) - 11.0 < DBL_EPSILON);
	assert(time_from_utc(6, 6.0) - 12.0 < DBL_EPSILON);
	assert(time_from_utc(-7, 6.0) - 23.0 < DBL_EPSILON);
	assert(time_from_utc(-1, 0.0) - 23.0 < DBL_EPSILON);
	assert(time_from_utc(-1, 23.0) - 22.0 < DBL_EPSILON);
	assert(time_from_utc(1, 23.0) < DBL_EPSILON);
	
	
}

