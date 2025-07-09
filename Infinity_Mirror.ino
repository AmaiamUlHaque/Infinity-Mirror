/*
   Amaiam ul Haque
   Last Updated: Jan 26, 2023
   Description:********************************************************************************************
   Let's-a-go! *insert super mario bros theme*
*/


/* Note:
 * Since this file has multiple tabs,
 * each of them run in a specific order.
 * It will always start off with the tab that the folder is named after,
 * and then the rest is determined by their alphabetical order.
 * Which is why each tab starts with a,b,c, so on and so forth,
 * and if there is a second letter following the first one, 
 * this is meant to serve as some sort of a subsection. 
 * 
 * For example, 
 * the transitions tabs start with the letter 'f',
 * while each different type of transition have their own tab/subsection (fa, fb, fc...) 
 * 
 * But in this case the only tabs that have to be in order are the declarations, setup, and loop.
 * Since all the other tabs are methods and will not run until called upon.
 */








// void loop() {
//   //since the IRTranslate method is not working, code will have to go through them each maually
//   //everything below is just for easy copy paste


//   //sets brightness and duration to what a value that the IR remote could have done and goes through each transition


//   brightness = 75;
//   FastLED.setBrightness(brightness);
//   duration = 10;
//   Default();

//   brightness = 175;
//   FastLED.setBrightness(brightness);
//   duration = 5;
//   Default();

//   brightness = 255;
//   FastLED.setBrightness(brightness);
//   duration = 1;
//   Default();


//   Fade(crease);  //this one only has duraution of one since it takes really long

//   brightness = 75;
//   FastLED.setBrightness(brightness);
//   duration = 10;
//   for (int i = 0; i < 5; i++)
//     Spiral();

//   brightness = 175;
//   FastLED.setBrightness(brightness);
//   duration = 5;
//   for (int i = 0; i < 7; i++)
//     Spiral();

//   brightness = 255;
//   FastLED.setBrightness(brightness);
//   duration = 1;
//   for (int i = 0; i < 10; i++)
//     Spiral();


//   brightness = 75;
//   FastLED.setBrightness(brightness);
//   duration = 10;
//   for (int i = 0; i < 5; i++)
//     Reload();

//   brightness = 175;
//   FastLED.setBrightness(brightness);
//   duration = 5;
//   for (int i = 0; i < 7; i++)
//     Reload();

//   brightness = 255;
//   FastLED.setBrightness(brightness);
//   duration = 1;
//   for (int i = 0; i < 10; i++)
//     Reload();

//   brightness = 75;
//   FastLED.setBrightness(brightness);
//   duration = 10;
//   for (int i = 0; i < 100; i++)
//     Random();

//   brightness = 175;
//   FastLED.setBrightness(brightness);
//   duration = 5;
//   for (int i = 0; i < 250; i++)
//     Random();

//   brightness = 255;
//   FastLED.setBrightness(brightness);
//   duration = 1;
//   for (int i = 0; i < 555; i++)
//     Random();


//   brightness = 175;
//   FastLED.setBrightness(brightness);
//   duration = 5;
//   Purples();

//   brightness = 255;
//   FastLED.setBrightness(brightness);
//   duration = 1;
//   Purples();
// }
