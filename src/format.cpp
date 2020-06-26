#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {    
    long minutes = seconds / 60;
    long hour = minutes / 60;
    std::string hh = std::to_string(hour);
    std::string mm = std::to_string(minutes%60);
    std::string ss = std::to_string(seconds%60);
    std::string output = hh + ":" + mm + ":" + ss;  
    return output; 
}