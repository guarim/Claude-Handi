// Code Arduino pour contrôle par détection oculaire
// À téléverser sur votre carte Arduino

const int OUTPUT1 = 8;  // Sortie 1 - Programme principal
const int OUTPUT2 = 9;  // Sortie 2 - Gauche
const int OUTPUT3 = 10; // Sortie 3 - Droite

String command = "";

void setup() {
  Serial.begin(9600);
  
  pinMode(OUTPUT1, OUTPUT);
  pinMode(OUTPUT2, OUTPUT);
  pinMode(OUTPUT3, OUTPUT);
  
  // Initialisation à LOW
  digitalWrite(OUTPUT1, LOW);
  digitalWrite(OUTPUT2, LOW);
  digitalWrite(OUTPUT3, LOW);
  
  Serial.println("Arduino prêt");
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
    Serial.println("Sortie 1 ON");
  } 
  else if (cmd == "OFF1") {
    digitalWrite(OUTPUT1, LOW);
    Serial.println("Sortie 1 OFF");
  }
  else if (cmd == "ON2") {
    digitalWrite(OUTPUT2, HIGH);
    Serial.println("Sortie 2 ON");
  }
  else if (cmd == "OFF2") {
    digitalWrite(OUTPUT2, LOW);
    Serial.println("Sortie 2 OFF");
  }
  else if (cmd == "ON3") {
    digitalWrite(OUTPUT3, HIGH);
    Serial.println("Sortie 3 ON");
  }
  else if (cmd == "OFF3") {
    digitalWrite(OUTPUT3, LOW);
    Serial.println("Sortie 3 OFF");
  }
}
