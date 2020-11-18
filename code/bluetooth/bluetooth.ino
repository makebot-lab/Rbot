/* makebot R BOT bluetooth code
 * makebot homepage(English) : http://makebot.mystrikingly.com/
 * makebot homepage(Korean) : https://makebot.modoo.at
 * files : https://github.com/makebot-lab/rbot
 * R BOT is humanoid robot made by WONDAEHAN.
 */
#include <SoftwareSerial.h>
 
#include <Rbot.h>

Rbot Rbot;

SoftwareSerial bluetooth(0, 1);

void setup() {
  Rbot.ready();
  bluetooth.begin(9600);
}

void loop() {
  if(bluetooth.available()) {
    char bluetooth_read = bluetooth.read();
    switch(bluetooth_read) {
      case 'a': //home
        Rbot.home();
        break;
      case 'b': //move
        Rbot.move(bluetooth.parseInt());
        break;
      case 'c': //motion
        Rbot.motion(bluetooth.parseInt());
        break;
      case 'd': //sound
        Rbot.sound(bluetooth.parseInt());
        break;
    }
  }
}
