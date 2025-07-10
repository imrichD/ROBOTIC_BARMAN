// --- Built-in LED Configuration ---
const int BUILTIN_LED_PIN = 2; // GPIO 2 is common for built-in LED
unsigned long ledTurnOnMillis = 0;
bool isLedActive = false;
const unsigned long ledActiveDuration = 5000; // 5 seconds

// --- Motor and Liquid Configuration ---
const int pwmPins[10] = { 12, 14, 27, 26, 25, 33, 32, 35, 23, 22 };

enum Liquids {
  LIQ_APEROL = 0, // Renamed to avoid conflict with RemoteXY struct members if any were kept
  LIQ_PROSECCO,
  LIQ_SODA_WATER,
  LIQ_VODKA,
  LIQ_GIN,
  LIQ_WHITE_RUM,
  LIQ_TEQUILA,
  LIQ_BOURBON,
  LIQ_TRIPLE_SEC,
  LIQ_SWEET_VERMOUTH
};

float ml_to_ms = 17.0; // Calibration: milliseconds per ml
const int MOTOR_PWM_SPEED = 64; // Motor speed (0-255)

struct Motor {
  bool isRunning;
  unsigned long startTime;
  unsigned long duration;
} motorState[10];

struct RecipeStep {
  int liquidIndex;
  int ml;
};

// --- RECIPE DEFINITIONS (Aligned with Python's Veci_s_Drinks.drinks_names) ---
// IDs 0-27 for drinks, ID 28 for cleaning (handled separately)

// ID 0: Aperol Spritz
const RecipeStep recipe0_AperolSpritz[] = {
  { LIQ_APEROL, 50 }, { LIQ_PROSECCO, 50 }, { LIQ_SODA_WATER, 30 }
};

// ID 1: Mojito (Simplified: Rum, Soda, Sweet Vermouth for lime/sugar)
const RecipeStep recipe1_Mojito[] = {
  { LIQ_WHITE_RUM, 60 }, { LIQ_SODA_WATER, 90 }, { LIQ_SWEET_VERMOUTH, 15 }
};

// ID 2: Sweet Martini
const RecipeStep recipe2_SweetMartini[] = {
  { LIQ_GIN, 60 }, { LIQ_SWEET_VERMOUTH, 20 }
};

// ID 3: Manhattan
const RecipeStep recipe3_Manhattan[] = {
  { LIQ_BOURBON, 50 }, { LIQ_SWEET_VERMOUTH, 25 } // Original had 50, adjusted for balance
};

// ID 4: Margarita (Simplified: Tequila, Triple Sec, Sweet Vermouth for lime)
const RecipeStep recipe4_Margarita[] = {
  { LIQ_TEQUILA, 50 }, { LIQ_TRIPLE_SEC, 25 }, { LIQ_SWEET_VERMOUTH, 15 }
};

// ID 5: Tom Collins (Simplified: Gin, Soda, Sweet Vermouth for lemon/sugar)
const RecipeStep recipe5_TomCollins[] = {
  { LIQ_GIN, 50 }, { LIQ_SODA_WATER, 100 }, { LIQ_SWEET_VERMOUTH, 15 }
};

// ID 6: Cosmopolitan (Simplified: Vodka, Triple Sec, Soda for cranberry, Sweet Vermouth for lime)
const RecipeStep recipe6_Cosmopolitan[] = {
  { LIQ_VODKA, 40 }, { LIQ_TRIPLE_SEC, 20 }, { LIQ_SODA_WATER, 30 }, { LIQ_SWEET_VERMOUTH, 10 }
};

// ID 7: Sidecar (Simplified: Bourbon for Brandy, Triple Sec, Sweet Vermouth for lemon)
const RecipeStep recipe7_Sidecar[] = {
  { LIQ_BOURBON, 50 }, { LIQ_TRIPLE_SEC, 20 }, { LIQ_SWEET_VERMOUTH, 10 }
};

// ID 8: Rum Sour (Simplified: Rum, Sweet Vermouth for lemon/sugar, touch of Soda)
const RecipeStep recipe8_RumSour[] = {
  { LIQ_WHITE_RUM, 50 }, { LIQ_SWEET_VERMOUTH, 25 }, { LIQ_SODA_WATER, 25 }
};

// ID 9: Long Island Iced Tea (Simplified: 5 spirits, Soda for sour/cola)
const RecipeStep recipe9_LongIsland[] = {
  { LIQ_VODKA, 15 }, { LIQ_GIN, 15 }, { LIQ_WHITE_RUM, 15 }, { LIQ_TEQUILA, 15 },
  { LIQ_TRIPLE_SEC, 15 }, { LIQ_SODA_WATER, 50 } // Soda for volume and some fizz
};

// ID 10: Negroni
const RecipeStep recipe10_Negroni[] = {
  { LIQ_GIN, 30 }, { LIQ_SWEET_VERMOUTH, 30 }, { LIQ_APEROL, 30 }
};

// ID 11: Boulevardier Variation (Bourbon, Sweet Vermouth, Aperol for Campari)
const RecipeStep recipe11_Boulevardier[] = {
  { LIQ_BOURBON, 30 }, { LIQ_SWEET_VERMOUTH, 30 }, { LIQ_APEROL, 30 }
};

// ID 12: French 75 (Simplified: Gin, Prosecco, Sweet Vermouth for lemon/sugar)
const RecipeStep recipe12_French75[] = {
  { LIQ_GIN, 30 }, { LIQ_PROSECCO, 60 }, { LIQ_SWEET_VERMOUTH, 10 }
};

// ID 13: Gin Fizz (Simplified: Gin, Sweet Vermouth for lemon/sugar, Soda)
const RecipeStep recipe13_GinFizz[] = {
  { LIQ_GIN, 50 }, { LIQ_SWEET_VERMOUTH, 15 }, { LIQ_SODA_WATER, 80 }
};

// ID 14: Tequila Sunrise (Simplified: Tequila, Soda for OJ, Aperol for Grenadine)
const RecipeStep recipe14_TequilaSunrise[] = {
  { LIQ_TEQUILA, 50 }, { LIQ_SODA_WATER, 100 }, { LIQ_APEROL, 15 }
};

// ID 15: Rum Punch (Simplified: Rum, Triple Sec, Soda for juices, Aperol for color)
const RecipeStep recipe15_RumPunch[] = {
  { LIQ_WHITE_RUM, 50 }, { LIQ_TRIPLE_SEC, 20 }, { LIQ_SODA_WATER, 80 }, { LIQ_APEROL, 10 }
};

// ID 16: Gimlet (Simplified: Gin, Sweet Vermouth for lime cordial)
const RecipeStep recipe16_Gimlet[] = {
  { LIQ_GIN, 60 }, { LIQ_SWEET_VERMOUTH, 20 }
};

// ID 17: Vodka Spritz
const RecipeStep recipe17_VodkaSpritz[] = {
  { LIQ_VODKA, 50 }, { LIQ_PROSECCO, 50 }, { LIQ_SODA_WATER, 30 }
};

// ID 18: Gin Spritz
const RecipeStep recipe18_GinSpritz[] = {
  { LIQ_GIN, 50 }, { LIQ_PROSECCO, 50 }, { LIQ_SODA_WATER, 30 }
};

// ID 19: Rum Spritz
const RecipeStep recipe19_RumSpritz[] = {
  { LIQ_WHITE_RUM, 50 }, { LIQ_PROSECCO, 50 }, { LIQ_SODA_WATER, 30 }
};

// ID 20: Tequila Spritz
const RecipeStep recipe20_TequilaSpritz[] = {
  { LIQ_TEQUILA, 50 }, { LIQ_PROSECCO, 50 }, { LIQ_SODA_WATER, 30 }
};

// ID 21: Bourbon Spritz
const RecipeStep recipe21_BourbonSpritz[] = {
  { LIQ_BOURBON, 50 }, { LIQ_PROSECCO, 50 }, { LIQ_SODA_WATER, 30 }
};

// ID 22: Soda
const RecipeStep recipe22_Soda[] = {
  { LIQ_SODA_WATER, 150 }
};

// ID 23: Vodka Highball
const RecipeStep recipe23_VodkaHighball[] = {
  { LIQ_VODKA, 50 }, { LIQ_SODA_WATER, 120 }
};

// ID 24: Gin Highball
const RecipeStep recipe24_GinHighball[] = {
  { LIQ_GIN, 50 }, { LIQ_SODA_WATER, 120 }
};

// ID 25: Rum Highball
const RecipeStep recipe25_RumHighball[] = {
  { LIQ_WHITE_RUM, 50 }, { LIQ_SODA_WATER, 120 }
};

// ID 26: Tequila Highball
const RecipeStep recipe26_TequilaHighball[] = {
  { LIQ_TEQUILA, 50 }, { LIQ_SODA_WATER, 120 }
};

// ID 27: Bourbon Highball
const RecipeStep recipe27_BourbonHighball[] = {
  { LIQ_BOURBON, 50 }, { LIQ_SODA_WATER, 120 }
};

// --- Master Recipe List (Order MUST match Python IDs 0-27) ---
const RecipeStep* recipes[] = {
  recipe0_AperolSpritz,    // ID 0
  recipe1_Mojito,          // ID 1
  recipe2_SweetMartini,    // ID 2
  recipe3_Manhattan,       // ID 3
  recipe4_Margarita,       // ID 4
  recipe5_TomCollins,      // ID 5
  recipe6_Cosmopolitan,    // ID 6
  recipe7_Sidecar,         // ID 7
  recipe8_RumSour,         // ID 8
  recipe9_LongIsland,      // ID 9
  recipe10_Negroni,        // ID 10
  recipe11_Boulevardier,   // ID 11
  recipe12_French75,       // ID 12
  recipe13_GinFizz,        // ID 13
  recipe14_TequilaSunrise, // ID 14
  recipe15_RumPunch,       // ID 15
  recipe16_Gimlet,         // ID 16
  recipe17_VodkaSpritz,    // ID 17
  recipe18_GinSpritz,      // ID 18
  recipe19_RumSpritz,      // ID 19
  recipe20_TequilaSpritz,  // ID 20
  recipe21_BourbonSpritz,  // ID 21
  recipe22_Soda,           // ID 22
  recipe23_VodkaHighball,  // ID 23
  recipe24_GinHighball,    // ID 24
  recipe25_RumHighball,    // ID 25
  recipe26_TequilaHighball,// ID 26
  recipe27_BourbonHighball // ID 27
};

// --- Recipe Sizes (Automatically calculated for each recipe) ---
const int recipeSizes[] = {
  sizeof(recipe0_AperolSpritz) / sizeof(RecipeStep),
  sizeof(recipe1_Mojito) / sizeof(RecipeStep),
  sizeof(recipe2_SweetMartini) / sizeof(RecipeStep),
  sizeof(recipe3_Manhattan) / sizeof(RecipeStep),
  sizeof(recipe4_Margarita) / sizeof(RecipeStep),
  sizeof(recipe5_TomCollins) / sizeof(RecipeStep),
  sizeof(recipe6_Cosmopolitan) / sizeof(RecipeStep),
  sizeof(recipe7_Sidecar) / sizeof(RecipeStep),
  sizeof(recipe8_RumSour) / sizeof(RecipeStep),
  sizeof(recipe9_LongIsland) / sizeof(RecipeStep),
  sizeof(recipe10_Negroni) / sizeof(RecipeStep),
  sizeof(recipe11_Boulevardier) / sizeof(RecipeStep),
  sizeof(recipe12_French75) / sizeof(RecipeStep),
  sizeof(recipe13_GinFizz) / sizeof(RecipeStep),
  sizeof(recipe14_TequilaSunrise) / sizeof(RecipeStep),
  sizeof(recipe15_RumPunch) / sizeof(RecipeStep),
  sizeof(recipe16_Gimlet) / sizeof(RecipeStep),
  sizeof(recipe17_VodkaSpritz) / sizeof(RecipeStep),
  sizeof(recipe18_GinSpritz) / sizeof(RecipeStep),
  sizeof(recipe19_RumSpritz) / sizeof(RecipeStep),
  sizeof(recipe20_TequilaSpritz) / sizeof(RecipeStep),
  sizeof(recipe21_BourbonSpritz) / sizeof(RecipeStep),
  sizeof(recipe22_Soda) / sizeof(RecipeStep),
  sizeof(recipe23_VodkaHighball) / sizeof(RecipeStep),
  sizeof(recipe24_GinHighball) / sizeof(RecipeStep),
  sizeof(recipe25_RumHighball) / sizeof(RecipeStep),
  sizeof(recipe26_TequilaHighball) / sizeof(RecipeStep),
  sizeof(recipe27_BourbonHighball) / sizeof(RecipeStep)
};

const int numRecipes = sizeof(recipes) / sizeof(recipes[0]); // Total number of defined drink recipes

// --- Functions ---
void nalievaj(int liquidIndex, int ml) {
  if (liquidIndex < 0 || liquidIndex >= 10) {
    Serial.print("Error: Invalid liquidIndex in nalievaj: ");
    Serial.println(liquidIndex);
    return;
  }
  if (!motorState[liquidIndex].isRunning) {
    motorState[liquidIndex].isRunning = true;
    motorState[liquidIndex].startTime = millis();
    motorState[liquidIndex].duration = (unsigned long)ml * ml_to_ms; // Cast to unsigned long for safety
    analogWrite(pwmPins[liquidIndex], MOTOR_PWM_SPEED);
    Serial.print("Dispensing Liquid: "); Serial.print(liquidIndex);
    Serial.print(", Amount (ms): "); Serial.println(motorState[liquidIndex].duration);
  }
}

void updateMotors() {
  unsigned long currentTime = millis();
  for (int i = 0; i < 10; i++) {
    if (motorState[i].isRunning && (currentTime - motorState[i].startTime >= motorState[i].duration)) {
      analogWrite(pwmPins[i], 0);
      motorState[i].isRunning = false;
      Serial.print("Stopped Liquid: "); Serial.println(i);
    }
  }
}

void runRecipe(const RecipeStep* recipe, int size) {
  Serial.println("Starting recipe...");
  for (int i = 0; i < size; i++) {
    nalievaj(recipe[i].liquidIndex, recipe[i].ml);
  }
}

void cleanAll() {
  Serial.println("Starting cleaning cycle for all motors...");
  for (int i = 0; i < 10; i++) {
    nalievaj(i, 100); // Dispense 100ml equivalent for cleaning
  }
}

void setup() {
  Serial.begin(115200);
  while (!Serial); // Optional: wait for serial connection

  pinMode(BUILTIN_LED_PIN, OUTPUT);
  digitalWrite(BUILTIN_LED_PIN, LOW);

  Serial.println("DrinkMaster 8000 Initializing...");
  Serial.print("Number of recipes configured: "); Serial.println(numRecipes);

  for (int i = 0; i < 10; i++) {
    pinMode(pwmPins[i], OUTPUT);
    analogWrite(pwmPins[i], 0);
    motorState[i] = { false, 0, 0 };
  }
}

void loop() {
  updateMotors();     // Continuously update motor states

  // --- LED Blinking Logic ---
  if (isLedActive) {
    if (millis() - ledTurnOnMillis >= ledActiveDuration) {
      digitalWrite(BUILTIN_LED_PIN, LOW);
      isLedActive = false;
      // Serial.println("LED OFF"); // Optional: for debugging
    }
  }

  // --- Serial Command Handling from Raspberry Pi ---
  if (Serial.available()) {
    String inputString = Serial.readStringUntil('\n');
    inputString.trim();
    
    // Attempt to parse the command string to an integer
    // toInt() returns 0 if conversion fails AND the string is not "0"
    long parsedNum = inputString.toInt(); 
    int receivedCommandId = -1; // Default to invalid

    if (inputString == "0") { // toInt() returns 0 for "0", which is valid
        receivedCommandId = 0;
    } else if (parsedNum != 0) { // toInt() returns non-zero for other valid numbers
        receivedCommandId = (int)parsedNum;
    }
    // else: conversion failed for non-"0" strings that don't parse to non-zero int,
    // or input was not a number. receivedCommandId remains -1.

    if (receivedCommandId != -1) {
        Serial.print("Received RPi Command ID: ");
        Serial.println(receivedCommandId);

        // Activate LED
        digitalWrite(BUILTIN_LED_PIN, HIGH);
        isLedActive = true;
        ledTurnOnMillis = millis();
        Serial.println("LED ON");

        if (receivedCommandId == 28) { // Python ID 28 for "Clean program"
            Serial.println("Executing Clean Program via RPi command.");
            cleanAll();
        } else if (receivedCommandId >= 0 && receivedCommandId < numRecipes) {
            Serial.print("Executing recipe index ");
            Serial.print(receivedCommandId);
            Serial.println(" via RPi command.");
            runRecipe(recipes[receivedCommandId], recipeSizes[receivedCommandId]);
        } else {
            Serial.print("Invalid or unmapped RPi drink command ID: ");
            Serial.println(receivedCommandId);
        }
    } else {
        Serial.print("Failed to parse RPi command: '");
        Serial.print(inputString);
        Serial.println("'");
    }
  }
}
