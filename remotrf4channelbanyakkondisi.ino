#include <rm4.h>

static const int kData0Pin = 4;
static const int kData1Pin = 5;
static const int kData2Pin = 6;
static const int kData3Pin = 7;
const int relay1Mesin  = 8;
const int relay2Alarm  = 9;
const int relay3Sensor = 10;
const int relay4Lampu  = 11;

int tambahA = 0;
int tambahB = 0;
int tambahC = 0;
int tambahD = 0;
byte status_tambahanA;
byte status_tambahanB;
byte status_tambahanC;
byte status_tambahanD;
#define Anambah 1
#define Bnambah 1
#define Cnambah 1
#define Dnambah 1

RM4 remote(kData0Pin, kData1Pin, kData2Pin, kData3Pin);

void setup() {
  Serial.begin(9600);
  pinMode(relay1Mesin, OUTPUT);
  pinMode(relay2Alarm, OUTPUT);
  pinMode(relay3Sensor, OUTPUT);
  pinMode(relay4Lampu, OUTPUT);

  digitalWrite(relay1Mesin, HIGH);
  digitalWrite(relay2Alarm, HIGH);
  digitalWrite(relay3Sensor, HIGH);
  digitalWrite(relay4Lampu, HIGH);

}

void loop()
{
  const int button_code = remote.buttonCode();
  //Tombol B
   if (button_code == 8) {
    tambahB ++;
    if (tambahB == 4) tambahB = 0;
    status_tambahanB = Bnambah;
    switch (tambahB){
    case 1:
    Serial.println("MESIN Urip");
    digitalWrite(relay1Mesin, LOW);
    delay(500);
    break;

    delay(1000);

    default:
    delay(500);
    digitalWrite(relay1Mesin, HIGH);
    Serial.println("MESIN Mati");
    } 
  }
  //Tombol A
   if (button_code == 4) {
    tambahA ++;
    if (tambahA == 4) tambahA = 0;
    status_tambahanA = Anambah;
    switch (tambahA){
    case 1:
    Serial.println("ALARM Urip");
    digitalWrite(relay2Alarm, LOW);
    delay(500);
    break;

    delay(1000);

    default:
    delay(500);
    digitalWrite(relay2Alarm, HIGH);
    Serial.println("ALARM Mati");
    }
  }
  //Tombol C
   if (button_code == 1) {
    tambahC ++;
    if (tambahC == 4) tambahC = 0;
    status_tambahanC = Cnambah;
    switch (tambahC){
    case 1:
    Serial.println("SENSOR Urip");
    digitalWrite(relay3Sensor, LOW);
    delay(500);
    break;

    delay(1000);

    default:
    delay(500);
    digitalWrite(relay3Sensor, HIGH);
    Serial.println("SENSOR Mati");
    } 
  }
  //Tombol D
   if (button_code == 2) {
    tambahD ++;
    if (tambahD == 4) tambahD = 0;
    status_tambahanD = Dnambah;
    switch (tambahD){
    case 1:
    Serial.println("LAMPU Urip");
    digitalWrite(relay4Lampu, LOW);
    delay(500);
    break;

    delay(1000);

    default:
    delay(500);
    digitalWrite(relay4Lampu, HIGH);
    digitalWrite(relay2Alarm, HIGH);
    Serial.println("LAMPU & ALARM Mati");
    } 
  }
 Serial.println(button_code);
  
 delay(100);
  }
