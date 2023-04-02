#ifndef _TIMER_H
#define _TIMER_H

#include <SDL.h>

class Timer {
    private:
        static Timer* instance;

        unsigned int startTicks;
        unsigned int elapsedTicks;
        float deltaTime;
        float timeScale;

        Timer();
        ~Timer();
    public:
        static Timer* getInstance();
        static void Free();

        void Reset();
        float getDeltaTime();

        void TimeScale(float t = 1.0f);
        float getTimeScale();

        void Update();
};


#endif
