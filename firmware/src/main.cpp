/*
 * @file main.cpp
 *
 * @author C. Smith
 */

#include <Arduino.h>
#include <SevSeg.h>

enum TimerState
{
  STOPPED,
  RUNNING
};

static SevSeg sevSeg;

static const auto START_STOP_BUTTON = A0;
static const auto RESET_BUTTON = A1;

static unsigned long timer = 0;
static int deciSeconds = 0;
static TimerState timerState = STOPPED;

void setup()
{
  const byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevSeg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins,
               false, false, true);
  sevSeg.setBrightness(70);

  pinMode(START_STOP_BUTTON, INPUT);
  pinMode(RESET_BUTTON, INPUT);

  timer = millis();
}

void loop()
{
  if (digitalRead(START_STOP_BUTTON) == HIGH)
  {
    timerState = (timerState == STOPPED) ? RUNNING : STOPPED;
    sevSeg.setNumber(deciSeconds, 1);
    while (digitalRead(START_STOP_BUTTON) == HIGH)
    {
      sevSeg.refreshDisplay();
    }
    return;
  }

  if (digitalRead(RESET_BUTTON) == HIGH)
  {
    deciSeconds = 0;
    sevSeg.setNumber(deciSeconds, 1);
    while (digitalRead(RESET_BUTTON) == HIGH)
    {
      sevSeg.refreshDisplay();
    }
    return;
  }

  if (timerState == RUNNING)
  {
    auto currentTime = millis();
    if (currentTime >= timer)
    {
      deciSeconds++;
      timer = currentTime + 100;
      if (deciSeconds == 10000)
      {
        deciSeconds = 0;
      }
    }
  }

  sevSeg.setNumber(deciSeconds, 1);
  sevSeg.refreshDisplay();
}
