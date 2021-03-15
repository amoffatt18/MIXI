void startUp() {
  
  strip.clear();
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(178, 34, 34));

    strip.show();
    delay(100);
  }
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 255, 0));

    strip.show();
    delay(100);
  }
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 225));

    strip.show();
    delay(100);
  }
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255));

    strip.show();
    delay(100);

 
  }

     switchVal = 1;
}
