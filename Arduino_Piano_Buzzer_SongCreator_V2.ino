// ARDUINO PIANO BUZZER SONG APP by Momentology Productions


// Define the tempo (in beats per minute)
int tempo = 100;


#define BUZZER_PIN 3 //Avtive Buzzer 


//Define which line number the song starts on for the console edit. 
#define SONG_ARRAY_LINE_NUMBER 189

#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_F2 87

// Calculate the duration of each note based on the tempo and milliseconds per beat
unsigned long ms_per_beat = 60000 / tempo;
#define NOTE_SIXTY_FOURTH   ms_per_beat/16
#define NOTE_THIRTY_SECOND  ms_per_beat/8
#define NOTE_SIXTEENTH      ms_per_beat/4
#define NOTE_EIGHTH         ms_per_beat/2
#define NOTE_DOTTED_EIGHTH  3*ms_per_beat/4
#define NOTE_QUARTER        ms_per_beat
#define NOTE_DOTTED_QUARTER 3*ms_per_beat/2
#define NOTE_HALF           2*ms_per_beat
#define NOTE_WHOLE          4*ms_per_beat


const char* getNoteName(int note) {
  switch (note) {
  
    case NOTE_C2: return "NOTE_C2";
    case NOTE_CS2: return "NOTE_CS2";
    case NOTE_D2: return "NOTE_D2";
    case NOTE_DS2: return "NOTE_DS2";
    case NOTE_E2: return "NOTE_E2";
    case NOTE_F2: return "NOTE_F2";
    case NOTE_FS2: return "NOTE_FS2";
    case NOTE_G2: return "NOTE_G2";
    case NOTE_GS2: return "NOTE_GS2";
    case NOTE_A2: return "NOTE_A2";
    case NOTE_AS2: return "NOTE_AS2";
    case NOTE_B2: return "NOTE_B2";
    case NOTE_C3: return "NOTE_C3";
    case NOTE_CS3: return "NOTE_CS3";
    case NOTE_D3: return "NOTE_D3";
    case NOTE_DS3: return "NOTE_DS3";
    case NOTE_E3: return "NOTE_E3";
    case NOTE_F3: return "NOTE_F3";
    case NOTE_FS3: return "NOTE_FS3";
    case NOTE_G3: return "NOTE_G3";
    case NOTE_GS3: return "NOTE_GS3";
    case NOTE_A3: return "NOTE_A3";
    case NOTE_AS3: return "NOTE_AS3";
    case NOTE_B3: return "NOTE_B3";
    case NOTE_C4: return "NOTE_C4";
    case NOTE_CS4: return "NOTE_CS4";
    case NOTE_D4: return "NOTE_D4";
    case NOTE_DS4: return "NOTE_DS4";
    case NOTE_E4: return "NOTE_E4";
    case NOTE_F4: return "NOTE_F4";
    case NOTE_FS4: return "NOTE_FS4";
    case NOTE_G4: return "NOTE_G4";
    case NOTE_GS4: return "NOTE_GS4";
    case NOTE_A4: return "NOTE_A4";
    case NOTE_AS4: return "NOTE_AS4";
    case NOTE_B4: return "NOTE_B4";
    case NOTE_C5: return "NOTE_C5";
    case NOTE_CS5: return "NOTE_CS5";
    case NOTE_D5: return "NOTE_D5";
    case NOTE_DS5: return "NOTE_DS5";
    case NOTE_E5: return "NOTE_E5";
    case NOTE_F5: return "NOTE_F5";
    case NOTE_FS5: return "NOTE_FS5";
    case NOTE_G5: return "NOTE_G5";
    case NOTE_GS5: return "NOTE_GS5";
    case NOTE_A5: return "NOTE_A5";
    case NOTE_AS5: return "NOTE_AS5";
    case NOTE_B5: return "NOTE_B5";
    case NOTE_C6: return "NOTE_C6";
    case NOTE_CS6: return "NOTE_CS6";
    case NOTE_D6: return "NOTE_D6";
    case NOTE_DS6: return "NOTE_DS6";
    case NOTE_E6: return "NOTE_E6";
    case NOTE_F6: return "NOTE_F6";
    case NOTE_FS6: return "NOTE_FS6";
    case NOTE_G6: return "NOTE_G6";
    case NOTE_GS6: return "NOTE_GS6";
    case NOTE_A6: return "NOTE_A6";
    case NOTE_AS6: return "NOTE_AS6";
    case NOTE_B6: return "NOTE_B6";
    case NOTE_C7: return "NOTE_C7";
   
    default:       return "Unknown Note";
  }
}


const char* getDurationName(int duration) {
  if (duration == static_cast<int>(NOTE_WHOLE)) {
    return "NOTE_WHOLE";
  } else if (duration == static_cast<int>(NOTE_HALF)) {
    return "NOTE_HALF";
  } else if (duration == static_cast<int>(NOTE_QUARTER)) {
    return "NOTE_QUARTER";
  } else if (duration == static_cast<int>(NOTE_EIGHTH)) {
    return "NOTE_EIGHTH";
  } else if (duration == static_cast<int>(NOTE_SIXTEENTH)) {
    return "NOTE_SIXTEENTH";
  } else if (duration == static_cast<int>(NOTE_THIRTY_SECOND)) {
    return "NOTE_THIRTY_SECOND";
  } else if (duration == static_cast<int>(NOTE_SIXTY_FOURTH)) {
    return "NOTE_SIXTY_FOURTH";
  } else if (duration == 0) {
    return "REST";
  } else {
    return "UNKNOWN";
  }
}




////////////////////////////////////     BUZZER SONG    ///////////////////////////////////////////


//Make sure first note matches line number in the "#define SONG_ARRAY_LINE_NUMBER 110" 

int Untitled_Song_1[83][2] =
{
  {NOTE_G4, NOTE_EIGHTH},
  {0, NOTE_EIGHTH},
  {NOTE_G4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_EIGHTH},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_E5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_E5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_D5, NOTE_DOTTED_QUARTER},
  {0, NOTE_EIGHTH},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_A4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_A4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_G4, NOTE_DOTTED_QUARTER},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_A4, NOTE_DOTTED_QUARTER},
  {0, NOTE_EIGHTH},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_A4, NOTE_DOTTED_QUARTER},
  {0, NOTE_EIGHTH},
  {NOTE_G4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_G4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_D5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_E5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_E5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_D5, NOTE_DOTTED_QUARTER},
  {0, NOTE_EIGHTH},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_C5, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_B4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_A4, NOTE_DOTTED_EIGHTH},
  {0, NOTE_SIXTEENTH},
  {NOTE_A4, NOTE_QUARTER},
  {0, NOTE_THIRTY_SECOND},
  {NOTE_G4, NOTE_HALF},
};

//SOUND
void playNote(unsigned int frequency, unsigned long duration) // play 1 note at given freq for given duration.
{
  tone(BUZZER_PIN, frequency);
  delay(duration);
  noTone(BUZZER_PIN);
}

void playSong(int songName[][2], int numNotes, int tempo) {
  unsigned long ms_per_beat = 60000 / tempo;
  bool playing = true;
  bool paused = false;

  while (Serial.available() > 0) Serial.read(); // Clear the Serial buffer before starting

  int i = 0;
  while (playing) {
    if (Serial.available() > 0) {
      String command = Serial.readString();

      if (command.startsWith("1")) {
        paused = true;
        Serial.println("Type \"1\" to pause, \"2\" to unpause, \"3\" to stop, and \"4\" to play the song.");
      } else if (command.startsWith("2")) {
        int rewind_lines = 8 * (command.length() - 1); // Calculate the number of lines to rewind based on the number of "2"s entered
        paused = false;
        if (i >= rewind_lines) {
          i -= rewind_lines; // Resume the song from the specified number of lines back
        } else {
          i = 0;
        }
      } else if (command.startsWith("3")) {
        playing = false;
        Serial.println("Type \"1\" to PAUSE, \"2\" to UNPAUSE, \"3\" to STOP, and \"4\" to PLAY SONG FROM TOP.");
      } else if (command.startsWith("4")) {
        i = 0; // Restart the song from the beginning
        paused = false;
        continue;
      }
    }

    if (playing && !paused && i < numNotes) {
        unsigned long duration = songName[i][1];
        Serial.print("Line ");
        Serial.print(i + SONG_ARRAY_LINE_NUMBER);
        Serial.print(":   {");

        // Print the note name on the console
        if (songName[i][0] != 0) {
          Serial.print(getNoteName(songName[i][0]));
        } else {
          Serial.print("0");
        }
        Serial.print(", ");
        // Print the duration as it appears in the song definition
        Serial.print(getDurationName(static_cast<int>(songName[i][1])));
        Serial.println("},");

        tone(BUZZER_PIN, songName[i][0]); // Play the note
        delay(duration);
        noTone(BUZZER_PIN); // Stop playing the note
        i++; // Increment the note index after playing
    } else if (paused) {
        delay(50); // Add a small delay when the song is paused
    }
  }
}

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);  

  // Add a delay to give you time to switch to the Serial Monitor
  delay(100);

  Serial.println("Type \"1\" to PAUSE, \"2\" to UNPAUSE, \"3\" to STOP, and \"4\" to PLAY SONG FROM TOP.");

  delay(2000); // Add a delay to allow time for the user to read the instructions

 playSong(Untitled_Song_1, sizeof(Untitled_Song_1)/sizeof(Untitled_Song_1[0]), 100);
}

void loop() {
  // put your main code here, to run repeatedly:

}