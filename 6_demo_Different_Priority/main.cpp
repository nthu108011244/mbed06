#include "mbed.h"
#include "mbed_events.h"
using namespace std::chrono;

DigitalOut led1(LED1);
DigitalOut led2(LED2);
InterruptIn btn(USER_BUTTON);

EventQueue led1Queue;
EventQueue led2Queue;

void turn_led1()
{
    led1 = !led1;
    printf("led1 turn on/off\n");
}
void turn_led2()
{
    led2 = !led2;
    printf("led2 turn on/off\n");
}
void turn()
{
    led1Queue.call(&turn_led1);
    led2Queue.call(&turn_led2);
}

int main()
{
    Thread led1Thread(osPriorityNormal);
    Thread led2Thread(osPriorityLow);

    led1Thread.start(callback(&led1Queue, &EventQueue::dispatch_forever));
    led2Thread.start(callback(&led2Queue, &EventQueue::dispatch_forever));

    btn.fall(&turn);
    while (1)
    {
        ThisThread::sleep_for(1s);
    }
}