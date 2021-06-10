#include "FastLED.h"
#define NUM_LEDS 60
#define DATA_PIN 6
#define STAR_NUM 10
CRGB leds[NUM_LEDS];


class Star{
  public:
  int position = round(random(NUM_LEDS - 1));
  int speed = round(random(4) + 1);
  int tailLength = round(random(4)+2);
  int moveCount = 1;
  
};
Star stars[STAR_NUM];
void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS); 
  //create stars and add to array
  for (int i = 0; i < STAR_NUM; i++)
  {
    Star s;
    stars[i] = s;
  }
  
  
}

void loop() {

  //loop through stars and update positions based on speeds
  for (int i = 0; i < STAR_NUM; i++)
  {
    if (stars[i].moveCount < 1)
    {
      stars[i].position++;
      stars[i].moveCount = stars[i].speed;
    }else{
      stars[i].moveCount--;
    }
    
    if (stars[i].position > NUM_LEDS + stars[i].tailLength)
    {
      stars[i].position = 0-(round(random(10)));
      stars[i].speed = round(random(4) + 1);
      stars[i].tailLength = round(random(4)+2);
    }
    
  }
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(255,0,255);
  }
  for (int i = 0; i < STAR_NUM; i++){
    for(int j = 0; j <= stars[i].tailLength; j++){
      if((stars[i].position - j) >= 0 && (stars[i].position - j) <= NUM_LEDS){
        leds[stars[i].position - j] = CRGB (255, 255, 255);
      }
      
    }
  }
  FastLED.setBrightness(50);
  FastLED.show();
  delay(10);
}