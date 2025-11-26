// Code Arduino - Eye Control System v2
// 4 sorties contrôlées

const int OUTPUT1 = 8;  // Programme principal
const int OUTPUT2 = 9;  // Œil gauche fermé
const int OUTPUT3 = 10; // Œil droit fermé
const int OUTPUT4 = 11; // Validation centre (yeux ouverts + iris centre)

String command = "";

void setup() {
  Serial.begin(9600);
  
  pinMode(OUTPUT1, OUTPUT);
  pinMode(OUTPUT2, OUTPUT);
  pinMode(OUTPUT3, OUTPUT);
  pinMode(OUTPUT4, OUTPUT);
  
  // Initialisation
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  digitalWrite(OUTPUT4, LOW);
  
  Serial.println("Arduino Eye Control Ready");
}

void loop() {
  if (Serial.available() > 0) {
    char c = Serial.read();
    
    if (c == '\n') {
      processCommand(command);
      command = "";
    } else {
      command += c;
    }
  }
}

void processCommand(String cmd) {
  cmd.trim();
  
  if (cmd == "ON1") {
    digitalWrite(OUTPUT1, HIGH);
    Serial.println("OUTPUT1 ON");
  } 
  else if (cmd == "OFF1") {
    digitalWrite(OUTPUT1, LOW);
    Serial.println("OUTPUT1 OFF");
  }
  else if (cmd == "ON2") {
    digitalWrite(OUTPUT2, HIGH);
    Serial.println("OUTPUT2 ON");
  }
  else if (cmd == "OFF2") {
    digitalWrite(OUTPUT2, LOW);
    Serial.println("OUTPUT2 OFF");
  }
  else if (cmd == "ON3") {
    digitalWrite(OUTPUT3, HIGH);
    Serial.println("OUTPUT3 ON");
  }
  else if (cmd == "OFF3") {
    digitalWrite(OUTPUT3, LOW);
    Serial.println("OUTPUT3 OFF");
  }
  else if (cmd == "ON4") {
    digitalWrite(OUTPUT4, HIGH);
    Serial.println("OUTPUT4 ON");
  }
  else if (cmd == "OFF4") {
    digitalWrite(OUTPUT4, LOW);
    Serial.println("OUTPUT4 OFF");
  }
}
