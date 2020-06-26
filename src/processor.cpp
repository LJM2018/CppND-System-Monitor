#include <unistd.h>

#include "linux_parser.h"
#include "processor.h"

float prevJiffies = (float)LinuxParser::Jiffies();
float prevActiveJiffies = (float)LinuxParser::ActiveJiffies();

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {

  jiffies = (float)LinuxParser::Jiffies();
  activeJiffies = (float)LinuxParser::ActiveJiffies();

  float JiffiesDiff = jiffies - prevJiffies;
  float activeJiffiesDiff = activeJiffies - prevActiveJiffies;

  prevJiffies = jiffies;
  prevActiveJiffies = activeJiffies;

  if (JiffiesDiff == 0) {
    return 0.0f;
  }

  return (activeJiffiesDiff / JiffiesDiff);
}