#ifndef TIMER__H
#define TIMER__H

#include <cstdlib>
#include <sys/time.h>

class Timer{
public:
    Timer();
    int timeLeft();
    void start(int t);
private:
    int then;
    int ttl;
    
};

#endif
