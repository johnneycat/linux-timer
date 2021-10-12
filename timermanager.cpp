#include "timermanager.h"

SigleTimer* SigleTimer::m_sigle_timer = NULL;

SigleTimer::SigleTimer()
{
    SigleTimer::m_sigle_timer = this;
}


void SigleTimer::setTimerEventHander(const std::shared_ptr<EventHander>& hander )
{
    m_hander = hander;
}

void SigleTimer::timerstart(const struct itimerval& dest)
{
    signal(SIGALRM, SigleTimer::timerEventHander);
    struct itimerval  ovalue;
    setitimer(ITIMER_REAL, &dest, &ovalue);
}

void SigleTimer::setTimerInterval(int seconds)
{

}

void SigleTimer::timerstop()
{
    struct itimerval  ovalue;
    setitimer(ITIMER_REAL, &ovalue, &ovalue);
}

void SigleTimer::timerEventHander(int signo)
{
    SigleTimer::m_sigle_timer->m_hander->onEvent(signo);
    qDebug() << "timerID: " << SigleTimer::m_sigle_timer->m_timer_id << " is onTimer";
}
