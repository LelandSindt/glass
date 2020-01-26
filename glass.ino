


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    6

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 10

// Declare our NeoPixel strip object:
//Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRBW + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

uint8_t animation = 0;

void setup() {
  animation = get_next_count(3);
  Serial.begin(9600);
  Serial.print(animation, DEC);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}

void loop() {
  switch (animation) {
    case 0:
      // Fill along the length of the strip in various colors...
      colorWipe(strip.Color(255,   0,   0), 50); // Red
      colorWipe(strip.Color(  0, 255,   0), 50); // Green
      colorWipe(strip.Color(  0,   0, 255), 50); // Blue
      break;
    case 1:
      rainbow(10);             // Flowing rainbow cycle along the whole strip
      break;
    case 2:
      for (int thisPixel = 0; thisPixel <= LED_COUNT; thisPixel++) {
        strip.setPixelColor(thisPixel, 0, 0, 0, 255);
      }
      strip.show();
  }
}
