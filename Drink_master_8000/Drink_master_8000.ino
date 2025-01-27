#include <BLEDevice.h>
#include <RemoteXY.h>

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP32CORE_BLE

// RemoteXY connection settings
#define REMOTEXY_BLUETOOTH_NAME "BN_DrinkMaster8000"


// RemoteXY GUI configuration
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =  // 796 bytes
  { 255, 27, 0, 0, 0, 21, 3, 18, 0, 0, 0, 8, 1, 106, 200, 5, 1, 0, 0, 0,
    0, 4, 0, 129, 3, 17, 98, 12, 64, 179, 68, 114, 105, 110, 107, 32, 77, 97, 115, 116,
    101, 114, 32, 56, 48, 48, 48, 0, 131, 5, 81, 97, 22, 9, 179, 165, 24, 77, 105, 120,
    101, 100, 32, 68, 114, 105, 110, 107, 115, 0, 38, 2, 131, 33, 130, 40, 14, 9, 121, 123,
    24, 68, 114, 105, 110, 107, 115, 0, 42, 1, 1, 8, 157, 90, 25, 3, 138, 27, 67, 108,
    101, 97, 110, 80, 114, 111, 103, 114, 97, 109, 0, 14, 0, 1, 0, 0, 53, 43, 3, 1,
    31, 65, 112, 101, 114, 111, 108, 32, 83, 112, 114, 105, 116, 122, 0, 130, 247, 43, 119, 1,
    27, 17, 1, 53, 0, 53, 43, 3, 119, 31, 77, 111, 106, 105, 116, 111, 0, 1, 0, 44,
    53, 43, 3, 163, 31, 68, 97, 105, 113, 117, 105, 114, 105, 0, 130, 247, 87, 119, 1, 27,
    17, 1, 53, 44, 53, 43, 3, 65, 31, 71, 105, 110, 32, 83, 117, 110, 114, 105, 115, 101,
    0, 1, 0, 88, 53, 44, 3, 79, 31, 83, 99, 114, 101, 119, 100, 114, 105, 118, 101, 114,
    0, 130, 247, 132, 119, 1, 27, 17, 1, 53, 88, 53, 44, 3, 124, 26, 84, 111, 109, 67,
    111, 108, 108, 105, 110, 115, 0, 1, 0, 133, 53, 43, 3, 67, 31, 66, 101, 101, 115, 75,
    110, 101, 101, 0, 1, 53, 133, 53, 43, 3, 39, 31, 71, 105, 110, 80, 111, 109, 0, 130,
    249, 175, 119, 1, 27, 17, 130, 53, 219, 1, 213, 27, 17, 131, 31, 180, 49, 16, 2, 17,
    2, 31, 78, 101, 120, 116, 32, 80, 97, 103, 101, 0, 26, 2, 14, 0, 131, 27, 177, 54,
    22, 2, 17, 2, 31, 78, 101, 120, 116, 32, 80, 97, 103, 101, 0, 42, 2, 1, 0, 0,
    53, 43, 3, 152, 27, 71, 105, 109, 108, 101, 116, 0, 130, 247, 43, 119, 1, 27, 17, 1,
    53, 0, 53, 43, 3, 141, 31, 82, 105, 99, 107, 101, 121, 0, 1, 0, 44, 53, 43, 3,
    96, 26, 71, 105, 110, 70, 105, 122, 122, 0, 130, 247, 87, 119, 1, 27, 17, 1, 53, 44,
    53, 43, 3, 124, 26, 83, 111, 117, 116, 104, 115, 105, 100, 101, 0, 1, 0, 88, 53, 44,
    3, 1, 31, 70, 111, 114, 75, 105, 100, 115, 0, 130, 247, 132, 119, 1, 27, 17, 1, 53,
    88, 53, 44, 3, 31, 25, 71, 105, 110, 83, 111, 100, 97, 0, 1, 0, 133, 53, 43, 3,
    51, 31, 71, 105, 110, 83, 112, 114, 105, 116, 122, 0, 1, 53, 133, 53, 43, 3, 193, 31,
    71, 105, 110, 78, 74, 117, 105, 99, 101, 0, 130, 249, 175, 119, 1, 27, 17, 130, 53, 219,
    1, 213, 27, 17, 10, 0, 130, 249, 45, 119, 1, 27, 17, 130, 249, 89, 119, 1, 27, 17,
    130, 233, 134, 78, 1, 27, 17, 130, 55, 224, 1, 167, 27, 17, 131, 29, 174, 50, 22, 2,
    17, 2, 31, 76, 97, 115, 116, 32, 112, 97, 103, 101, 0, 170, 1, 1, 0, 0, 55, 45,
    3, 94, 28, 86, 111, 100, 107, 97, 76, 101, 109, 111, 110, 0, 1, 56, 0, 50, 45, 3,
    134, 31, 86, 111, 100, 107, 97, 32, 83, 111, 100, 97, 0, 1, 0, 46, 55, 43, 3, 36,
    31, 86, 111, 100, 107, 97, 32, 83, 112, 114, 105, 116, 122, 0, 1, 56, 46, 50, 43, 3,
    51, 31, 82, 117, 109, 80, 117, 110, 99, 104, 0, 1, 0, 90, 55, 44, 3, 5, 31, 82,
    117, 109, 32, 83, 111, 100, 97, 0, 13, 0, 1, 255, 0, 55, 45, 3, 0, 31, 83, 111,
    100, 97, 0, 130, 249, 45, 119, 1, 27, 17, 1, 54, 0, 53, 45, 3, 52, 31, 74, 117,
    105, 99, 101, 0, 1, 0, 46, 54, 43, 3, 68, 27, 83, 121, 114, 117, 112, 0, 130, 249,
    89, 119, 1, 27, 17, 1, 54, 46, 53, 43, 3, 177, 31, 80, 114, 111, 115, 101, 99, 99,
    111, 0, 1, 0, 90, 54, 44, 3, 1, 31, 65, 112, 101, 114, 111, 108, 0, 130, 249, 134,
    119, 1, 27, 17, 1, 54, 90, 53, 44, 3, 31, 25, 82, 117, 109, 0, 1, 0, 135, 54,
    42, 3, 166, 27, 71, 105, 110, 0, 1, 55, 135, 52, 42, 3, 193, 31, 86, 111, 100, 107,
    97, 0, 130, 251, 177, 119, 1, 27, 17, 130, 54, 221, 1, 213, 27, 17 };

// this structure defines all the variables and events of your control interface
struct {

  // input variables
  uint8_t clean_program;  // =1 if button pressed, else =0
  uint8_t AperolSpritz;   // =1 if button pressed, else =0
  uint8_t Mojito;         // =1 if button pressed, else =0
  uint8_t Daiquiri;       // =1 if button pressed, else =0
  uint8_t GinSunrise;     // =1 if button pressed, else =0
  uint8_t Screwdriver;    // =1 if button pressed, else =0
  uint8_t TomCollins;     // =1 if button pressed, else =0
  uint8_t BeesKnee;       // =1 if button pressed, else =0
  uint8_t GinPom;         // =1 if button pressed, else =0
  uint8_t Southside;      // =1 if button pressed, else =0
  uint8_t ForKids;        // =1 if button pressed, else =0
  uint8_t GinSoda;        // =1 if button pressed, else =0
  uint8_t GinSpritz;      // =1 if button pressed, else =0
  uint8_t GinNJuice;      // =1 if button pressed, else =0
  uint8_t VodkaLemon;     // =1 if button pressed, else =0
  uint8_t VodkaSoda;      // =1 if button pressed, else =0
  uint8_t VodkaSpritz;    // =1 if button pressed, else =0
  uint8_t RumPunch;       // =1 if button pressed, else =0
  uint8_t RumSoda;        // =1 if button pressed, else =0
  uint8_t Soda;           // =1 if button pressed, else =0
  uint8_t Juice;          // =1 if button pressed, else =0
  uint8_t Syrup;          // =1 if button pressed, else =0
  uint8_t Prosecco;       // =1 if button pressed, else =0
  uint8_t Aperol;         // =1 if button pressed, else =0
  uint8_t Rum;            // =1 if button pressed, else =0
  uint8_t Gin;            // =1 if button pressed, else =0
  uint8_t Vodka;          // =1 if button pressed, else =0

  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)  // netusim co to je je to z toho programu aj vsetko nad comentom je odtial

//#define PIN_GINSUNRISE 2  // from remotexy takto oni zadefinovaly pin 2 idk co je lepsie

//>> motor names to pin-outs
int SodaM = 12;
int JuiceM = 14;
int SyrupM = 27;
int ProseccoM = 26;
int AperolM = 25;
int RumM = 33;
int GinM = 32;
int VodkaM = 35;
//<< motor names to pin-outs



void setup() {
  //speed na ktorej bezi procesor>>
  Serial.begin(115200);

  // tu hovorim ze hej tento pin je output
  pinMode(SodaM, OUTPUT);
  pinMode(JuiceM, OUTPUT);
  pinMode(SyrupM, OUTPUT);
  pinMode(ProseccoM, OUTPUT);

  pinMode(AperolM, OUTPUT);
  pinMode(RumM, OUTPUT);
  pinMode(GinM, OUTPUT);
  pinMode(VodkaM, OUTPUT);

  BLEDevice::init("RemoteXY");
  RemoteXY_Init();  // Initialize RemoteXY
}
float ml_50 = 1000;  //in milseconds use for delay

void nalievaj(int motor_pin, int ML) {
  delay(1500);
  analogWrite(motor_pin, 127);
  delay(ML);
  analogWrite(motor_pin, 0);
  delay(1500);
}

void makeTomCollins() {
  nalievaj(GinM, ml_60);
  nalievaj(JuiceM, ml_30);
  nalievaj(SyrupM, ml_15);
}
void makeBeesKnee() {
  nalievaj(GinM, ml_60);
  nalievaj(JuiceM, ml_25);
  nalievaj(SyrupM, ml_15);
}
void makeGinNJuice() {
  nalievaj(GinM, ml_50);
  nalievaj(JuiceM, ml_100);
  nalievaj(SyrupM, ml_25);
}

void makeGinPom() {
  nalievaj(GinM, ml_50);
  nalievaj(JuiceM, ml_50);
  nalievaj(SodaM, ml_50);
}

void makeGimlet() {
  nalievaj(GinM, ml_60);
  nalievaj(JuiceM, ml_25);
  nalievaj(SyrupM, ml_25);
}

void makeRickey() {
  nalievaj(GinM, ml_60);
  nalievaj(SodaM, ml_30);
  nalievaj(SyrupM, ml_10);
}
void makeGinSpritz() {
  nalievaj(GinM, ml_75);
  nalievaj(ProseccoM, ml_50);
}
void makeGinFizz() {
  nalievaj(GinM, ml_75);
  nalievaj(SyrupM, ml_30);
  nalievaj(JuiceM, ml_20);
  nalievaj(SodaM, ml_30);
}
void makeSouthside() {
  nalievaj(GinM, ml_50);
  nalievaj(JuiceM, ml_20);
  nalievaj(SyrupM, ml_15);
}
void makeVodkasoda() {
  nalievaj(VodkaM, ml_60);
  nalievaj(SodaM, ml_120);
  nalievaj(JuiceM, ml_25);
}

void makeGinSunrise() {
  nalievaj(GinM, ml_60);
  nalievaj(SyrupM, ml_15);
  nalievaj(JuiceM, ml_120);
}
void makeMojito() {
  nalievaj(WhiteRumM, ml_60);
  nalievaj(SodaM, ml_90);
  nalievaj(SyrupM, ml_15);
  nalievaj(JuiceM, ml_30);
}
void makeRumPunch() {
  nalievaj(WhiteRumM, ml_60);
  nalievaj(SyrupM, ml_15);
  nalievaj(JuiceM, ml_90);
}

void makeScrewdriver() {
  nalievaj(VodkaM, ml_50);
  nalievaj(JuiceM, ml_100);
}

void makeAperolSpritz() {
  nalievaj(AperolM, ml_60);
  nalievaj(ProseccoM, ml_90);
  nalievaj(SodaM, ml_30);
}

void makeGinSoda() {
  nalievaj(GinM, ml_60);
  nalievaj(SodaM, ml_120);
}

void makeRumSoda() {
  nalievaj(WhiteRumM, ml_60);
  nalievaj(SodaM, ml_120);
}
void makeVodkaSpritz() {
  nalievaj(VodkaM, ml_30);
  nalievaj(ProseccoM, ml_90);
  nalievaj(JuiceM, ml_15);
}
void makeDaiquiri() {
  nalievaj(WhiteRumM, ml_50);
  nalievaj(JuiceM, ml_25);
  nalievaj(SyrupM, ml_10);
}
void makeVodkaLemon() {
  nalievaj(VodkaM, ml_60);
  nalievaj(JuiceM, ml_90);
  nalievaj(SyrupM, ml_30);
  nalievaj(SodaM, ml_90);
}
void makeForKids() {
  nalievaj(SodaM, ml_250);
  nalievaj(SyrupM, ml_25);
}


void makeSoda() {
  nalievaj(SodaM, ml_300);
}
void makeJuice() {
  nalievaj(JuiceM, ml_300);
}
void makeSyrup() {
  nalievaj(SyrupM, ml_30);
}
void makeProsecco() {
  nalievaj(ProseccoM, ml_100);
}
void makeAperol() {
  nalievaj(AperolM, ml_50);
}
void makeRum() {
  nalievaj(RumM, ml_50);
}
void makeGin() {
  nalievaj(GinM, ml_50);
}
void makeVodka() {
  nalievaj(VodkaM, ml_50);
}


void cleanAll() {
  nalievaj(SodaM, ml_100);
  nalievaj(JuiceM, ml_100);
  nalievaj(SyrupM, ml_100);
  nalievaj(ProseccoM, ml_100);
  nalievaj(AperolM, ml_100);
  nalievaj(WhiteRumM, ml_100);
  nalievaj(GinM, ml_100);
  nalievaj(VodkaM, ml_100);
}

void loop() {
  // Poll RemoteXY
  RemoteXY_Handler();

  // Check for each button and call the corresponding function
  if (RemoteXY.clean_program) {
    cleanAll();  // Clean all components
  }

  if (RemoteXY.AperolSpritz) {
    makeAperolSpritz();
  }

  if (RemoteXY.Mojito) {
    makeMojito();
  }

  if (RemoteXY.Daiquiri) {
    makeDaiquiri();
  }

  if (RemoteXY.VodkaLemon) {
    makeVodkaLemon();
  }

  if (RemoteXY.VodkaSoda) {
    makeVodkasoda();
  }
  if (RemoteXY.VodkaSpritz) {
    makeVodkaSpritz();
  }
  if (RemoteXY.RumSoda) {
    makeRumSoda();
  }
  if (RemoteXY.Juice) {
    makeJuice();
  }
  if (RemoteXY.Soda) {
    makeSoda();
  }
  if (RemoteXY.Syrup) {
    makeSyrup();
  }
  if (RemoteXY.Prosecco) {
    makeProsecco();
  }
  if (RemoteXY.Aperol) {
    makeAperol();
  }
  if (RemoteXY.Rum) {
    makeRum();
  }
  if (RemoteXY.Gin) {
    makeGin();
  }
  if (RemoteXY.Vodka) {
    makeVodka();
  }
  //tu nemam v apke
  if (RemoteXY.GinSunrise) {
    makeGinSunrise();
  }
  if (RemoteXY.GinSoda) {
    makeGinSoda();
  }
  if (RemoteXY.RumPunch) {
    makeRumPunch();
  }
  if (RemoteXY.Screwdriver) {
    makeScrewdriver();
  }
  if (RemoteXY.TomCollins) {
    makeTomCollins();
  }
  if (RemoteXY.BeesKnee) {
    makemakeBeesKnee();
  }
  if (RemoteXY.GinNJuice) {
    makeGinNJuice();
  }
  if (RemoteXY.GinPom) {
    makeGinPom();
  }
  if (RemoteXY.Gimlet) {
    makeGimlet();
  }
  if (RemoteXY.Rickey) {
    makeRickey();
  }
  if (RemoteXY.GinSpritz) {
    makeGinSpritz();
  }
  if (RemoteXY.GinFizz) {
    makeGinFizz();
  }
  if (RemoteXY.Southside) {
    makeSouthside();
  }
  if (RemoteXY.ForKids) {
    makeForKids();
  }
}
