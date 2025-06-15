//
//  thread_synchronization_test.cpp
//  MutithreadingProject
//
//  Created by Walter Djeutsop on 20.06.23.
//
#include "thread_synchronizer.h"
#include <gtest/gtest.h>

// mutex used to avoid data race when displaying current thread state
mutex coutMutex;

// waiting thread
void workerThread(int id, ThreadSynchronizer& thread_synchronizer_) {

    coutMutex.lock();
    std::cout << "Thread " << id << " waiting for countdown..." << std::endl;
    coutMutex.unlock();

    thread_synchronizer_.waitForCountdown();
    
    if(!thread_synchronizer_.hasErrorOccured()){
        coutMutex.lock();
        std::cout << "Thread " << id << " starting work!" << std::endl;
        coutMutex.unlock();
    }
    
    // Do some work here ...
}

//this test if the counter is set to 0,
TEST(ThreadSynchronizerTest, SuccessfullCountdown)
{
    const int numberOfThreads = 10;
    const int numberOfRequirements= 10;

    ThreadSynchronizer thread_synchronizer(numberOfRequirements);

    vector<thread> threads;

    // Start worker threads
    for (int i = 1; i <numberOfThreads+1; ++i) {
        threads.emplace_back(workerThread,i,ref(thread_synchronizer));
    }

    // Simulate fulfilling the requirements by other threads
    for (int i = 1; i < numberOfRequirements+1; ++i) {
        this_thread::sleep_for(std::chrono::milliseconds(100));
        thread_synchronizer.fulfillRequirement();
        coutMutex.lock();
        cout << "Requirement " << i << " fulfilled!" << std::endl;
        coutMutex.unlock();
    }
    
    // wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    
    EXPECT_TRUE(thread_synchronizer.isCountdownFulfilled());
}


TEST(ThreadSynchronizerTest, UnsuccessfullCountdown)
{
    const int numberOfThreads = 10;
    const int numberOfRequirements= 10;

    ThreadSynchronizer thread_synchronizer(numberOfRequirements);

    vector<thread> threads;

    // Start worker threads
    for (int i = 1; i <numberOfThreads+1; ++i) {
        threads.emplace_back(workerThread,i,ref(thread_synchronizer));
    }

    // Simulate fulfilling the requirements by other threads
    for (int i = 1; i < numberOfRequirements; ++i) {
        this_thread::sleep_for(std::chrono::milliseconds(100));
        thread_synchronizer.fulfillRequirement();
        coutMutex.lock();
        cout << "Requirement " << i << " fulfilled!" << std::endl;
        coutMutex.unlock();
    }
    
    
    thread_synchronizer.setCountDownErrorFlag();

    // wait for all threads to finish
    for (auto& thread : threads) {
        thread.join();
    }
    
    EXPECT_FALSE(thread_synchronizer.isCountdownFulfilled());
}

// Countdown aborted due to a system error
TEST(ThreadSynchronizerTest, CountDownAboted)
{
    const int numberOfThreads = 10;
    const int numberOfRequirements= 10;

    ThreadSynchronizer thread_synchronizer(numberOfRequirements);

    vector<thread> threads;

    // Start worker threads
    for (int i = 1; i <numberOfThreads+1; ++i) {
        threads.emplace_back(workerThread,i,ref(thread_synchronizer));
    }

    // Simulate fulfilling the requirements by other threads
    for (int i = 1; i < numberOfRequirements+1; ++i) {
        
        if(numberOfRequirements>5 && i>numberOfRequirements-3){
            
            // simulate an error
            cout<< "a system error occured"<<endl;
            thread_synchronizer.abort();
        }else{
            this_thread::sleep_for(std::chrono::milliseconds(100));
            thread_synchronizer.fulfillRequirement();
            coutMutex.lock();
            cout << "Requirement " << i << " fulfilled!" << std::endl;
            coutMutex.unlock();
        }
    }

   // wait for all threads to finish
   for (auto& thread : threads) {
        thread.join();
    }
    
    
    EXPECT_FALSE(thread_synchronizer.isCountdownFulfilled());
}


