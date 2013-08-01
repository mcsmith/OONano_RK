/**
**    Definition of the Task class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#include "Task.hpp"

using edu::cmu::sv::OONano_RK::Kernel::Task;

Task::Task(uint8_t priority,
           uint8_t scheduleType,
           uint8_t type /*,
           Time    offset,
           Time    period,
           Time    reservation */):  firstActivation(true),
                                  // offset(offset),
                                  // period(period),
                                     priority(priority),
                                  // reservation(reservation),
                                     scheduleType(scheduleType),
                                     type(type)
   {
   }

void Task::execute()
   {
   // TODO:  See if this can be made into a pure virtual function.
   }
