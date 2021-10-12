#ifndef TIMERMANAGER_H
#define TIMERMANAGER_H


//定时器timer_create timerfd_create
//https://blog.csdn.net/weixin_42639771/article/details/89065854


#include <memory>
#include <thread>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>




class EventHander{
public:
    virtual void onEvent(int signo) = 0;
};

class TimerEventHander : public EventHander
{
    virtual void onEvent(int signo)
    {
        
    }
};





class SigleTimer
{
public:
    SigleTimer();

    void setTimerEventHander(const std::shared_ptr<EventHander>& hander );

    void timerstart(const struct itimerval& dest);

    void setTimerInterval(int seconds);

    void timerstop();

    static void timerEventHander(int signo);
private:
    std::shared_ptr<EventHander>            m_hander;
    static SigleTimer*                      m_sigle_timer;
    int                                     m_timer_id = 0;
};

class MultiTimer
{

};



#endif // TIMERMANAGER_H
