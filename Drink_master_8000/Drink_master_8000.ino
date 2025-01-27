#include <BLEDevice.h>
#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_MODE__ESP32CORE_BLE
#define REMOTEXY_BLUETOOTH_NAME "BN_DrinkMaster8000"

// RemoteXY GUI configuration
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = { /* Your RemoteXY GUI config here */ };

struct {
  uint8_t clean_program;
  uint8_t AperolSpritz;
  uint8_t Mojito;
  uint8_t Daiquiri;
  uint8_t TomCollins;
  uint8_t Negroni;
  uint8_t Margarita;
  uint8_t OldFashioned;
  uint8_t Manhattan;
  uint8_t Cosmopolitan;
  uint8_t Martini;
  uint8_t WhiskeySour;
  uint8_t TequilaSunrise;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)

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
  RemoteXY_Init();
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
