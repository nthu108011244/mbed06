#include "mbed.h"
using namespace std::chrono;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
Thread thread;
Thread thread2;

void led2_thread()
{
   while (true)
   {
      led2 = !led2;
      ThisThread::sleep_for(1s);
   }
}

void led3_thread()
{
    while (true)
    {
        led3 = !led3;
        ThisThread::sleep_for(1s);
    }
    
}

int main()
{
    led2 = 1;
    led3 = 0;
   thread.start(led2_thread);
   thread2.start(led3_thread);

   while (true)
   {
      led1 = !led1;
      ThisThread::sleep_for(500ms);
   }
}