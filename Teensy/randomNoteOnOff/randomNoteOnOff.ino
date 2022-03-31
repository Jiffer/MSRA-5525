/* Random NoteOn/Off USB MIDI Example

   You must select MIDI from the "Tools > USB Type" menu

   This example code is in the public domain.

   Jiffer Harriman
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;


void setup() {

}

void loop() {  
  // Delay for a random interval from 0 - 3000 milliseconds
  delay(random(3000));

  // Select a random note between 36 - 72
  // with random velocity between 63 - 127
  int randomNote = 36 + random(36);
  usbMIDI.sendNoteOn(randomNote, 63 + random(64), channel);  

  // Delay for a random interval from 0 - 3000 milliseconds
  delay(random(3000));

  // turn off the same randomly selected note
  usbMIDI.sendNoteOff(randomNote, 0, channel);  


  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore/clear incoming messages
  }
}
