//
//  thread_synchronizer.cpp
//  MutithreadingProject
//
//  Created by Walter Djeutsop on 20.06.23.
//

#include "thread_synchronizer.h"

ThreadSynchronizer::ThreadSynchronizer(int count) : counter_(count) {}

void ThreadSynchronizer::waitForCountdown() {
        unique_lock<mutex> lock(mutex_);
        cv_.wait(lock, [this]() { return counter_ == 0 || systemErrorFlag_ || errorCountDownFlag_; });
    
        // Terminate the program if an error occurred
    if(this->hasErrorOccured()){
        return;
        // call of std::terminate() lead to termination of the entire programm
        // call it by severe problems
        // std::terminate();
    }
}

void ThreadSynchronizer::fulfillRequirement() {
        unique_lock<mutex> lock(mutex_);
        --counter_;
        if (counter_ == 0) {
            cv_.notify_all();
        }
}

void ThreadSynchronizer::abort() {
        std::unique_lock<std::mutex> lock(mutex_);
        systemErrorFlag_ = true;
        cv_.notify_all();
}

bool ThreadSynchronizer::isCountdownFulfilled() const {
        return counter_ == 0;
}

bool ThreadSynchronizer::hasErrorOccured(){
        return systemErrorFlag_|errorCountDownFlag_;
}

void ThreadSynchronizer::setCountDownErrorFlag(){
    std::unique_lock<std::mutex> lock(mutex_);
    errorCountDownFlag_= true;
    cv_.notify_all();
}

