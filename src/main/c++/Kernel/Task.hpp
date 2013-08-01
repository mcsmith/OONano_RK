/**
**    Declaration of the Task class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#ifndef Task_hpp
#define Task_hpp

#include <stdint.h>
#if 0
#include "Time.hpp"
#endif

namespace edu
   {
   namespace cmu
      {
      namespace sv
         {
         namespace OONano_RK
            {
            namespace Kernel
               {
               class Task;
               }
            }
         }
      }
   };

// using edu::cmu::sv::OONano_RK::Kernel::Time;

class edu::cmu::sv::OONano_RK::Kernel::Task
   {
   public:

   static const uint8_t invalidTask = 0;
   static const uint8_t basicTask   = 1;
   static const uint8_t idleTask    = 2;

   static const uint8_t nonPreemptive = 0;
   static const uint8_t preemptive    = 1;

   Task(uint8_t priority,
        uint8_t scheduleType,
        uint8_t type /*,
        Time    offset,
        Time    period,
        Time    reservation */);
   void execute();

   private:

   bool    firstActivation;
// int8_t  id;
// Time    offset;
// Time    period;
   uint8_t priority;
// Time    reservation;
   uint8_t scheduleType;
   uint8_t type;
/*
   int8_t  task_ID;          id
   void *Ptos;               not understood; always points to last element in stack (array)???
   void *Pbos;               not understood; always points to first element in stack (array)???
   void (*task)();           obsolete, using virtual execute();  // TODO:  See strangeness on msp430x149 and msp430x1611
   bool    FirstActivation;  firstActivation
   uint8_t prio;             priority
   uint8_t Type;             type
   uint8_t SchType;          scheduleType
   nrk_time_t period;
   nrk_time_t cpu_reserve;
   nrk_time_t offset;
 */
   };

#endif
