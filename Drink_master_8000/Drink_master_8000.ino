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



// Motor Control Pins for 10 Liquids
const int pwmPins[10] = {12, 14, 27, 26, 25, 33, 32, 35, 23, 22}; // Assign each liquid to a PWM pin

// Mapping for Liquids
enum Liquids {
  APEROL = 0,
  PROSECCO,
  SODA_WATER,
  VODKA,
  GIN,
  WHITE_RUM,
  TEQUILA,
  BOURBON,
  TRIPLE_SEC,
  SWEET_VERMOUTH
};

// Time calibration for dispensing liquids
float ml_to_ms = 17.0; // Example: 20 milliseconds per ml (calibration needed)

// Motor State Tracking
struct Motor {
  bool isRunning;
  unsigned long startTime;
  unsigned long duration;
} motorState[10]; // One state for each motor

// Recipe Step Structure
struct RecipeStep {
  int liquidIndex;
  int ml;
};

// Recipes
const RecipeStep AperolSpritzRecipe[] = {
  {APEROL, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

const RecipeStep MojitoRecipe[] = {
  {WHITE_RUM, 60},
  {SODA_WATER, 90},
  {SWEET_VERMOUTH, 15}
};

const RecipeStep DaiquiriRecipe[] = {
  {WHITE_RUM, 50},
  {SWEET_VERMOUTH, 25},
  {TRIPLE_SEC, 10}
};

const RecipeStep TomCollinsRecipe[] = {
  {GIN, 60},
  {SODA_WATER, 30},
  {SWEET_VERMOUTH, 15}
};

const RecipeStep NegroniRecipe[] = {
  {GIN, 50},
  {SWEET_VERMOUTH, 50},
  {APEROL, 50}
};

const RecipeStep MargaritaRecipe[] = {
  {TEQUILA, 50},
  {TRIPLE_SEC, 25},
  {SWEET_VERMOUTH, 25}
};

const RecipeStep OldFashionedRecipe[] = {
  {BOURBON, 60},
  {SWEET_VERMOUTH, 25}
};

const RecipeStep ManhattanRecipe[] = {
  {BOURBON, 50},
  {SWEET_VERMOUTH, 50}
};

const RecipeStep CosmopolitanRecipe[] = {
  {VODKA, 50},
  {TRIPLE_SEC, 25},
  {SODA_WATER, 25}
};

const RecipeStep MartiniRecipe[] = {
  {GIN, 60},
  {SWEET_VERMOUTH, 20}
};

const RecipeStep WhiskeySourRecipe[] = {
  {BOURBON, 50},
  {SODA_WATER, 50},
  {TRIPLE_SEC, 20}
};

const RecipeStep TequilaSunriseRecipe[] = {
  {TEQUILA, 50},
  {SODA_WATER, 50},
  {APEROL, 25}
};

// Recipe List
const RecipeStep* recipes[] = {
  AperolSpritzRecipe,
  MojitoRecipe,
  DaiquiriRecipe,
  TomCollinsRecipe,
  NegroniRecipe,
  MargaritaRecipe,
  OldFashionedRecipe,
  ManhattanRecipe,
  CosmopolitanRecipe,
  MartiniRecipe,
  WhiskeySourRecipe,
  TequilaSunriseRecipe
};

const int recipeSizes[] = {
  sizeof(AperolSpritzRecipe) / sizeof(RecipeStep),
  sizeof(MojitoRecipe) / sizeof(RecipeStep),
  sizeof(DaiquiriRecipe) / sizeof(RecipeStep),
  sizeof(TomCollinsRecipe) / sizeof(RecipeStep),
  sizeof(NegroniRecipe) / sizeof(RecipeStep),
  sizeof(MargaritaRecipe) / sizeof(RecipeStep),
  sizeof(OldFashionedRecipe) / sizeof(RecipeStep),
  sizeof(ManhattanRecipe) / sizeof(RecipeStep),
  sizeof(CosmopolitanRecipe) / sizeof(RecipeStep),
  sizeof(MartiniRecipe) / sizeof(RecipeStep),
  sizeof(WhiskeySourRecipe) / sizeof(RecipeStep),
  sizeof(TequilaSunriseRecipe) / sizeof(RecipeStep)
};

// Non-blocking Motor Control Function
void nalievaj(int liquidIndex, int ml) {
  if (!motorState[liquidIndex].isRunning) {
    motorState[liquidIndex].isRunning = true;
    motorState[liquidIndex].startTime = millis();
    motorState[liquidIndex].duration = ml * ml_to_ms;
    analogWrite(pwmPins[liquidIndex], 64); // Run motor at 25% speed
  }
}

// Update Motors Function (Non-blocking timing)
void updateMotors() {
  unsigned long currentTime = millis();
  for (int i = 0; i < 10; i++) {
    if (motorState[i].isRunning && (currentTime - motorState[i].startTime >= motorState[i].duration)) {
      analogWrite(pwmPins[i], 0); // Stop motor
      motorState[i].isRunning = false; // Mark motor as stopped
    }
  }
}

// Run Recipe Function (Non-blocking)
void runRecipe(const RecipeStep* recipe, int size) {
  for (int i = 0; i < size; i++) {
    nalievaj(recipe[i].liquidIndex, recipe[i].ml);
  }
}

// Cleaning Function (Non-blocking)
void cleanAll() {
  for (int i = 0; i < 10; i++) {
    Serial.print("Cleaning motor ");
    Serial.println(i);
    nalievaj(i, 100);
  }
}


// Setup Function
void setup() {
  Serial.begin(115200);

  // Initialize motor pins
  for (int i = 0; i < 10; i++) {
    pinMode(pwmPins[i], OUTPUT);
    analogWrite(pwmPins[i], 0); // Ensure motors are off at start
    motorState[i] = {false, 0, 0}; // Initialize motor states
  }

  // Initialize RemoteXY
  BLEDevice::init("RemoteXY");
  RemoteXY_Init();  // Initialize RemoteXY
}

// Main Loop
void loop() {
  updateMotors(); // Update motor states
  RemoteXY_Handler();

  // Check and run recipes based on button presses
  if (RemoteXY.clean_program) {
    cleanAll();
    RemoteXY.clean_program = 0; // Reset clean flag
  }

  if (RemoteXY.AperolSpritz) {
    runRecipe(AperolSpritzRecipe, recipeSizes[0]);
    RemoteXY.AperolSpritz = 0;
  }
  if (RemoteXY.Mojito) {
    runRecipe(MojitoRecipe, recipeSizes[1]);
    RemoteXY.Mojito = 0;
  }
  if (RemoteXY.Daiquiri) {
    runRecipe(DaiquiriRecipe, recipeSizes[2]);
    RemoteXY.Daiquiri = 0;
  }
  if (RemoteXY.TomCollins) {
    runRecipe(TomCollinsRecipe, recipeSizes[3]);
    RemoteXY.TomCollins = 0;
  }
  if (RemoteXY.Negroni) {
    runRecipe(NegroniRecipe, recipeSizes[4]);
    RemoteXY.Negroni = 0;
  }
  if (RemoteXY.Margarita) {
    runRecipe(MargaritaRecipe, recipeSizes[5]);
    RemoteXY.Margarita = 0;
  }
  if (RemoteXY.OldFashioned) {
    runRecipe(OldFashionedRecipe, recipeSizes[6]);
    RemoteXY.OldFashioned = 0;
  }
  if (RemoteXY.Manhattan) {
    runRecipe(ManhattanRecipe, recipeSizes[7]);
    RemoteXY.Manhattan = 0;
  }
  if (RemoteXY.Cosmopolitan) {
    runRecipe(CosmopolitanRecipe, recipeSizes[8]);
    RemoteXY.Cosmopolitan = 0;
  }
  if (RemoteXY.Martini) {
    runRecipe(MartiniRecipe, recipeSizes[9]);
    RemoteXY.Martini = 0;
  }
  if (RemoteXY.WhiskeySour) {
    runRecipe(WhiskeySourRecipe, recipeSizes[10]);
    RemoteXY.WhiskeySour = 0;
  }
  if (RemoteXY.TequilaSunrise) {
    runRecipe(TequilaSunriseRecipe, recipeSizes[11]);
    RemoteXY.TequilaSunrise = 0;
  }
}
