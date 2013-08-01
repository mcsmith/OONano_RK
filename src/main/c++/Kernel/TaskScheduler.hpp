/**
**    Declaration of the TaskScheduler class.
**
**    Created: 2013-06-07
**    Author:  mcsmith
*/

#ifndef TaskScheduler_hpp
#define TaskScheduler_hpp

#include "Task.hpp"

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
               class TaskScheduler;
               }
            }
         }
      }
   };

using edu::cmu::sv::OONano_RK::Kernel::Task;

class edu::cmu::sv::OONano_RK::Kernel::TaskScheduler
   {
   public:

   TaskScheduler();
   uint8_t activateTask(Task task);
   };

#endif
