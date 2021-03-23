#include "mbed.h"
using namespace std::chrono;

DigitalOut ledBlue(LED3);
Ticker period;

void blink()
{
    ledBlue = !ledBlue;
}

int main()
{
    ledBlue = 0;
    period.attach(&blink, 500ms);
}