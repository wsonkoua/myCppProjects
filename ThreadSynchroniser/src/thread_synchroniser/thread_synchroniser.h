//
//  thread_synchronizer.h
//  MutithreadingProject
//
//  Created by Walter Djeutsop on 20.06.23.
//

#pragma once

#include <iostream>
#include <thread>
//#include <pthread.h>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

/* ***************************************************************************************
this class is responsible for the management and synchronization of threads based on the fullfillment of some requirement
*****************************************************************************************/

class ThreadSynchronizer{
public:
    // the constructor of class ThreadSynchonizer
    ThreadSynchronizer(int count);
    
    /*
     The waitForCountdown method is called by the waiting threads and is blocked until the countdown is down to 0 or error flag ist set to true. 
     */
    void waitForCountdown();
    
    /*
     The method fulfillRequirement is called by other threads to count down the countdown by one.
     */
    void fulfillRequirement();
    
    /*
     The abort method sets the counter to 0 to release all waiting threads.
     it is call when a system error occured
     */
    void abort();
    
    /*
     The isCountdownFullfilled method check if all Requirements are fullfilled.
     that means that the counter has reached value 0.
     */
    bool isCountdownFulfilled() const;
    
    /*
     The setCountDownErrorFlag method set the errorCountDownFlag_ if a Countdown error
     occured.that means that the counter has reached value 0.
     */
    void setCountDownErrorFlag();
    
    /*
       The hasErrorOccured method check if an error has error during programm execution.
     */
    bool hasErrorOccured();

private:
    int counter_;
    mutex mutex_;
    condition_variable cv_;
    bool systemErrorFlag_{false};
    bool errorCountDownFlag_{false};
};

