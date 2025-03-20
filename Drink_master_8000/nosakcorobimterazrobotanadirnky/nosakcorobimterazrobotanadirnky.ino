// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_POINT

#include <WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 789 bytes
  { 255,30,0,0,0,14,3,19,0,0,0,0,24,1,106,200,4,1,0,0,
  0,5,0,131,22,47,62,32,3,163,2,31,67,108,97,115,115,105,99,115,
  0,166,129,9,7,84,23,64,218,72,73,72,73,45,72,65,0,131,22,92,
  62,32,3,51,2,31,83,112,114,105,116,122,32,67,111,99,107,116,97,105,
  108,115,0,106,131,22,138,62,32,1,134,2,31,69,120,112,101,114,105,109,
  101,110,116,97,108,0,106,1,23,178,61,18,2,28,31,99,108,101,97,110,
  95,112,114,111,103,114,97,109,0,10,0,1,0,0,54,40,1,2,31,65,
  112,101,114,111,108,32,83,112,114,105,116,122,0,1,53,0,54,40,1,4,
  31,77,111,106,105,116,111,0,1,0,39,54,40,1,5,31,83,119,101,101,
  116,32,77,97,114,116,105,110,105,0,1,53,39,54,40,1,6,31,77,97,
  110,104,97,116,116,97,110,0,1,0,79,54,40,1,7,31,77,97,114,103,
  97,114,105,116,97,0,1,53,79,54,40,1,8,31,84,111,109,67,111,108,
  108,105,110,115,0,1,0,119,54,40,1,9,31,67,111,115,109,111,112,111,
  108,105,116,97,110,0,1,53,119,54,40,1,11,31,83,105,100,101,99,97,
  114,0,131,59,160,43,38,2,65,1,31,80,97,103,101,50,0,154,131,6,
  162,43,38,2,12,1,31,72,111,109,101,0,169,10,0,1,0,0,54,40,
  1,2,31,82,117,109,32,83,111,117,114,0,1,53,0,54,40,1,4,31,
  76,111,110,103,32,73,115,108,97,110,100,32,73,99,101,100,32,84,101,97,
  0,1,0,39,54,40,1,5,31,78,101,103,114,111,110,105,32,86,97,114,
  105,46,0,1,53,39,54,40,1,6,31,66,111,117,108,101,118,97,114,100,
  105,101,114,32,86,97,114,105,46,0,1,0,79,54,40,1,7,31,70,114,
  101,110,99,104,32,55,53,0,1,53,79,54,40,1,8,31,71,105,110,32,
  70,105,122,122,0,1,0,119,54,40,1,9,31,84,101,113,117,105,108,97,
  32,83,117,110,114,105,115,101,0,1,53,119,54,40,1,11,31,82,117,109,
  32,80,117,110,99,104,0,131,52,160,56,37,2,12,1,31,72,111,109,101,
  0,169,1,1,159,54,40,1,164,31,71,105,109,108,101,116,0,13,0,1,
  1,0,39,25,1,164,31,86,111,100,107,97,32,83,112,114,105,116,122,0,
  1,40,0,32,25,1,4,31,71,105,110,32,83,112,114,105,116,122,0,1,
  255,25,41,29,1,5,31,82,117,109,32,83,112,114,105,116,122,0,1,71,
  0,34,25,1,6,31,84,101,113,117,105,108,97,32,83,112,114,105,116,122,
  0,1,70,25,37,29,1,7,31,66,111,117,114,98,111,110,32,83,112,114,
  105,116,122,0,1,40,25,32,28,1,2,31,65,112,101,114,111,108,32,83,
  112,114,105,116,122,0,131,1,84,43,38,2,12,1,31,72,111,109,101,0,
  169,1,255,54,41,28,1,120,31,83,111,100,97,0,1,39,169,33,30,1,
  2,31,86,111,100,107,97,32,72,105,103,104,98,97,108,108,0,1,0,126,
  54,42,1,4,31,71,105,110,32,72,105,103,104,98,97,108,108,0,1,255,
  168,40,31,1,5,31,82,117,109,32,72,105,103,104,98,97,108,108,0,1,
  55,126,50,41,1,6,31,84,101,113,117,105,108,97,32,72,105,103,104,98,
  97,108,108,0,1,72,168,35,31,1,7,31,66,111,117,114,98,111,110,32,
  72,105,103,104,98,97,108,108,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
    uint8_t clean_program; // =1 if button pressed, else =0
    uint8_t Aperol_Spritz; // =1 if button pressed, else =0
    uint8_t Mojito; // =1 if button pressed, else =0
    uint8_t Sweet_Martini; // =1 if button pressed, else =0
    uint8_t Manhattan; // =1 if button pressed, else =0
    uint8_t Margarita; // =1 if button pressed, else =0
    uint8_t TomCollins; // =1 if button pressed, else =0
    uint8_t Cosmopolitan; // =1 if button pressed, else =0
    uint8_t Sidecar; // =1 if button pressed, else =0
    uint8_t Rum_Sour; // =1 if button pressed, else =0
    uint8_t Long_Island_Iced_Tea; // =1 if button pressed, else =0
    uint8_t Negroni; // =1 if button pressed, else =0
    uint8_t Boulevardier_Variation; // =1 if button pressed, else =0
    uint8_t French_75; // =1 if button pressed, else =0
    uint8_t Gin_Fizz; // =1 if button pressed, else =0
    uint8_t Tequila_Sunrise; // =1 if button pressed, else =0
    uint8_t Rum_Punch; // =1 if button pressed, else =0
    uint8_t Gimlet; // =1 if button pressed, else =0
    uint8_t Vodka_Spritz; // =1 if button pressed, else =0
    uint8_t Gin_Spritz; // =1 if button pressed, else =0
    uint8_t Rum_Spritz; // =1 if button pressed, else =0
    uint8_t Tequila_Spritz; // =1 if button pressed, else =0
    uint8_t Bourbon_Spritz; // =1 if button pressed, else =0
    uint8_t Aperol_spritz; // =1 if button pressed, else =0
    uint8_t Soda; // =1 if button pressed, else =0
    uint8_t Vodka_Highball; // =1 if button pressed, else =0
    uint8_t Gin_Highball; // =1 if button pressed, else =0
    uint8_t Rum_Highball; // =1 if button pressed, else =0
    uint8_t Tequila_Highball; // =1 if button pressed, else =0
    uint8_t Bourbon_Highball; // =1 if button pressed, else =0

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)

// Motor Control Pins for 10 Liquids
const int pwmPins[10] = {12 , 14, 27, 26, 25, 33, 32, 35, 23, 22}; // Assign each liquid to a PWM pin

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
float ml_to_ms = 200.0; // Example: 200 milliseconds per ml for power 50/255 (calibration needed)
float SODA_ml_to_ms = 100.0;

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

//-------------------------------------------------------
// 1. Aperol Spritz
//-------------------------------------------------------
const RecipeStep AperolSpritzRecipe[] = {
  {APEROL, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

//-------------------------------------------------------
// 2. Vodka Soda
//-------------------------------------------------------
const RecipeStep VodkaSodaRecipe[] = {
  {VODKA, 50},
  {SODA_WATER, 150}
};

//-------------------------------------------------------
// 3. Gin & Soda
//-------------------------------------------------------
const RecipeStep GinSodaRecipe[] = {
  {GIN, 50},
  {SODA_WATER, 150}
};

//-------------------------------------------------------
// 4. Rum & Soda
//-------------------------------------------------------
const RecipeStep RumSodaRecipe[] = {
  {WHITE_RUM, 50},
  {SODA_WATER, 150}
};

//-------------------------------------------------------
// 5. Tequila Soda
//-------------------------------------------------------
const RecipeStep TequilaSodaRecipe[] = {
  {TEQUILA, 50},
  {SODA_WATER, 150}
};

//-------------------------------------------------------
// 6. Bourbon & Soda
//-------------------------------------------------------
const RecipeStep BourbonSodaRecipe[] = {
  {BOURBON, 50},
  {SODA_WATER, 150}
};

//-------------------------------------------------------
// 7. Sweet Martini (using Gin variant)
//    (Note: Traditionally 2.5 oz gin & 0.5 oz sweet vermouth)
//-------------------------------------------------------
const RecipeStep SweetMartiniRecipe[] = {
  {GIN, 60},
  {SWEET_VERMOUTH, 15}
};

//-------------------------------------------------------
// 8. Manhattan
//    (Typically Bourbon & Sweet Vermouth; bitters are omitted.)
//-------------------------------------------------------
const RecipeStep ManhattanRecipe[] = {
  {BOURBON, 60},
  {SWEET_VERMOUTH, 30}
};

//-------------------------------------------------------
// 9. Margarita
//    (Uses Tequila & Triple Sec. Note: Lime Juice is required but not dispensed.)
//-------------------------------------------------------
const RecipeStep MargaritaRecipe[] = {
  {TEQUILA, 50},
  {TRIPLE_SEC, 20}
};

//-------------------------------------------------------
// 10. Cosmopolitan
//     (Requires Vodka & Triple Sec. Note: Cranberry & Lime Juice are not included.)
//-------------------------------------------------------
const RecipeStep CosmopolitanRecipe[] = {
  {VODKA, 40},
  {TRIPLE_SEC, 15}
};

//-------------------------------------------------------
// 11. Sidecar
//     (Using Bourbon instead of brandy. Note: Lemon Juice is missing.)
//-------------------------------------------------------
const RecipeStep SidecarRecipe[] = {
  {BOURBON, 50},
  {TRIPLE_SEC, 20}
};

//-------------------------------------------------------
// 12. Gimlet
//     (Typically Gin with Lime Juice & Simple Syrup; additional ingredients not dispensed.)
//-------------------------------------------------------
const RecipeStep GimletRecipe[] = {
  {GIN, 50}
  // Additional ingredients (Lime Juice, Simple Syrup) would be needed.
};

//-------------------------------------------------------
// 13. Rum Sour
//     (Requires White Rum; note: citrus, simple syrup, and optionally egg white are not dispensed.)
//-------------------------------------------------------
const RecipeStep RumSourRecipe[] = {
  {WHITE_RUM, 50}
  // Additional ingredients (Lemon/Lime Juice, Simple Syrup, Egg White) required.
};

//-------------------------------------------------------
// 14. Long Island Iced Tea
//     (Combines several spirits. Note: Sour Mix and Cola are not available.)
//-------------------------------------------------------
const RecipeStep LongIslandRecipe[] = {
  {VODKA, 15},
  {GIN, 15},
  {TEQUILA, 15},
  {WHITE_RUM, 15},
  {TRIPLE_SEC, 15}
  // Add Sour Mix and a splash of Cola externally.
};

//-------------------------------------------------------
// 15. Negroni Variation (Aperol Negroni)
//     (Using Gin, Sweet Vermouth, & Aperol in place of Campari.)
//-------------------------------------------------------
const RecipeStep NegroniVariationRecipe[] = {
  {GIN, 30},
  {SWEET_VERMOUTH, 30},
  {APEROL, 30}
};

//-------------------------------------------------------
// 16. Boulevardier Variation
//     (Bourbon, Sweet Vermouth, & Aperol; a twist on the classic Boulevardier.)
//-------------------------------------------------------
const RecipeStep BoulevardierVariationRecipe[] = {
  {BOURBON, 30},
  {SWEET_VERMOUTH, 30},
  {APEROL, 30}
};

//-------------------------------------------------------
// 17. French 75
//     (Uses Gin & Prosecco. Note: Lemon Juice and Simple Syrup are not dispensed.)
//-------------------------------------------------------
const RecipeStep French75Recipe[] = {
  {GIN, 30},
  {PROSECCO, 60}
  // Additional ingredients (Lemon Juice, Simple Syrup) required.
};

//-------------------------------------------------------
// 18. Tom Collins
//     (Based on Gin; Note: Lemon Juice and Simple Syrup are required but not dispensed.)
//-------------------------------------------------------
const RecipeStep TomCollinsRecipe[] = {
  {GIN, 50},
  {SODA_WATER, 100}
};

//-------------------------------------------------------
// 19. Gin Fizz
//     (Similar to Tom Collins but typically shaken. Note: Lemon Juice and Simple Syrup are omitted.)
//-------------------------------------------------------
const RecipeStep GinFizzRecipe[] = {
  {GIN, 50},
  {SODA_WATER, 100}
};

//-------------------------------------------------------
// 20. Mojito
//     (Uses White Rum; Note: Requires Lime Juice, Simple Syrup (or sugar), and Mint, which are not dispensed.)
//-------------------------------------------------------
const RecipeStep MojitoRecipe[] = {
  {WHITE_RUM, 50},
  {SODA_WATER, 50}
  // Muddle Mint & add Lime Juice/Simple Syrup manually.
};

//-------------------------------------------------------
// 21. Tequila Sunrise
//     (Uses Tequila. Note: Orange Juice and Grenadine are not dispensed.)
//-------------------------------------------------------
const RecipeStep TequilaSunriseRecipe[] = {
  {TEQUILA, 50}
  // Additional ingredients (Orange Juice, Grenadine) required.
};

//-------------------------------------------------------
// 22. Rum Punch
//     (Based on White Rum & Triple Sec; Note: Requires a mix of fruit juices and grenadine not dispensed.)
//-------------------------------------------------------
const RecipeStep RumPunchRecipe[] = {
  {WHITE_RUM, 50},
  {TRIPLE_SEC, 20}
  // Additional ingredients (Orange, Pineapple, Lime Juices, Grenadine) required.
};

//-------------------------------------------------------
// Spritz Recipes (Base Spirit + Prosecco + Soda Water)
//-------------------------------------------------------

// Vodka Spritz Recipe
const RecipeStep VodkaSpritzRecipe[] = {
  {VODKA, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

// Gin Spritz Recipe
const RecipeStep GinSpritzRecipe[] = {
  {GIN, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

// Rum Spritz Recipe
const RecipeStep RumSpritzRecipe[] = {
  {WHITE_RUM, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

// Tequila Spritz Recipe
const RecipeStep TequilaSpritzRecipe[] = {
  {TEQUILA, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

// Bourbon Spritz Recipe
const RecipeStep BourbonSpritzRecipe[] = {
  {BOURBON, 50},
  {PROSECCO, 50},
  {SODA_WATER, 30}
};

//-------------------------------------------------------
// Customized Highball Recipes (Base Spirit + Soda Water)
//-------------------------------------------------------

// Vodka Highball Recipe
const RecipeStep VodkaHighballRecipe[] = {
  {VODKA, 50},
  {SODA_WATER, 150}
};

// Gin Highball Recipe
const RecipeStep GinHighballRecipe[] = {
  {GIN, 50},
  {SODA_WATER, 150}
};

// Rum Highball Recipe
const RecipeStep RumHighballRecipe[] = {
  {WHITE_RUM, 50},
  {SODA_WATER, 150}
};

// Tequila Highball Recipe
const RecipeStep TequilaHighballRecipe[] = {
  {TEQUILA, 50},
  {SODA_WATER, 150}
};

// Bourbon Highball Recipe
const RecipeStep BourbonHighballRecipe[] = {
  {BOURBON, 50},
  {SODA_WATER, 150}
};

const RecipeStep SodaRecipe[] = {
  {SODA_WATER, 150}  // Adjust the amount (in mL) as needed
};

// Updated Recipe List
const RecipeStep* recipes[] = {
  // Standard Recipes (1–22)
  AperolSpritzRecipe,         // 1
  VodkaSodaRecipe,            // 2
  GinSodaRecipe,              // 3
  RumSodaRecipe,              // 4
  TequilaSodaRecipe,          // 5
  BourbonSodaRecipe,          // 6
  SweetMartiniRecipe,         // 7
  ManhattanRecipe,            // 8
  MargaritaRecipe,            // 9
  CosmopolitanRecipe,         // 10
  SidecarRecipe,              // 11
  GimletRecipe,               // 12
  RumSourRecipe,              // 13
  LongIslandRecipe,           // 14
  NegroniVariationRecipe,     // 15
  BoulevardierVariationRecipe,// 16
  French75Recipe,             // 17
  TomCollinsRecipe,           // 18
  GinFizzRecipe,              // 19
  MojitoRecipe,               // 20
  TequilaSunriseRecipe,       // 21
  RumPunchRecipe,             // 22

  // Spritz Recipes (23–27)
  VodkaSpritzRecipe,          // 23
  GinSpritzRecipe,            // 24
  RumSpritzRecipe,            // 25
  TequilaSpritzRecipe,        // 26
  BourbonSpritzRecipe,        // 27

  // Customized Highball Recipes (28–32)
  VodkaHighballRecipe,        // 28
  GinHighballRecipe,          // 29
  RumHighballRecipe,          // 30
  TequilaHighballRecipe,      // 31
  BourbonHighballRecipe,      // 32

  SodaRecipe                  // 33
};

// Updated Recipe Sizes Array
const int recipeSizes[] = {
  sizeof(AperolSpritzRecipe) / sizeof(RecipeStep),         // 1. Aperol Spritz (3 steps)
  sizeof(VodkaSodaRecipe) / sizeof(RecipeStep),            // 2. Vodka Soda (2 steps)
  sizeof(GinSodaRecipe) / sizeof(RecipeStep),              // 3. Gin & Soda (2 steps)
  sizeof(RumSodaRecipe) / sizeof(RecipeStep),              // 4. Rum & Soda (2 steps)
  sizeof(TequilaSodaRecipe) / sizeof(RecipeStep),          // 5. Tequila Soda (2 steps)
  sizeof(BourbonSodaRecipe) / sizeof(RecipeStep),          // 6. Bourbon & Soda (2 steps)
  sizeof(SweetMartiniRecipe) / sizeof(RecipeStep),         // 7. Sweet Martini (2 steps)
  sizeof(ManhattanRecipe) / sizeof(RecipeStep),            // 8. Manhattan (2 steps)
  sizeof(MargaritaRecipe) / sizeof(RecipeStep),            // 9. Margarita (2 steps)
  sizeof(CosmopolitanRecipe) / sizeof(RecipeStep),         // 10. Cosmopolitan (2 steps)
  sizeof(SidecarRecipe) / sizeof(RecipeStep),              // 11. Sidecar (2 steps)
  sizeof(GimletRecipe) / sizeof(RecipeStep),               // 12. Gimlet (1 step)
  sizeof(RumSourRecipe) / sizeof(RecipeStep),              // 13. Rum Sour (1 step)
  sizeof(LongIslandRecipe) / sizeof(RecipeStep),           // 14. Long Island Iced Tea (5 steps)
  sizeof(NegroniVariationRecipe) / sizeof(RecipeStep),     // 15. Negroni Variation (3 steps)
  sizeof(BoulevardierVariationRecipe) / sizeof(RecipeStep),// 16. Boulevardier Variation (3 steps)
  sizeof(French75Recipe) / sizeof(RecipeStep),             // 17. French 75 (2 steps)
  sizeof(TomCollinsRecipe) / sizeof(RecipeStep),           // 18. Tom Collins (2 steps)
  sizeof(GinFizzRecipe) / sizeof(RecipeStep),              // 19. Gin Fizz (2 steps)
  sizeof(MojitoRecipe) / sizeof(RecipeStep),               // 20. Mojito (2 steps)
  sizeof(TequilaSunriseRecipe) / sizeof(RecipeStep),       // 21. Tequila Sunrise (1 step)
  sizeof(RumPunchRecipe) / sizeof(RecipeStep),             // 22. Rum Punch (2 steps)

  sizeof(VodkaSpritzRecipe) / sizeof(RecipeStep),          // 23. Vodka Spritz (3 steps)
  sizeof(GinSpritzRecipe) / sizeof(RecipeStep),            // 24. Gin Spritz (3 steps)
  sizeof(RumSpritzRecipe) / sizeof(RecipeStep),            // 25. Rum Spritz (3 steps)
  sizeof(TequilaSpritzRecipe) / sizeof(RecipeStep),        // 26. Tequila Spritz (3 steps)
  sizeof(BourbonSpritzRecipe) / sizeof(RecipeStep),        // 27. Bourbon Spritz (3 steps)

  sizeof(VodkaHighballRecipe) / sizeof(RecipeStep),        // 28. Vodka Highball (2 steps)
  sizeof(GinHighballRecipe) / sizeof(RecipeStep),          // 29. Gin Highball (2 steps)
  sizeof(RumHighballRecipe) / sizeof(RecipeStep),          // 30. Rum Highball (2 steps)
  sizeof(TequilaHighballRecipe) / sizeof(RecipeStep),      // 31. Tequila Highball (2 steps)
  sizeof(BourbonHighballRecipe) / sizeof(RecipeStep),      // 32. Bourbon Highball (2 steps)
  sizeof(SodaRecipe) / sizeof(RecipeStep)                  // 33. soda recipie (1 step)
};


// Non-blocking Motor Control Function
void nalievaj(int liquidIndex, int ml) {
  if (!motorState[liquidIndex].isRunning) {
    motorState[liquidIndex].isRunning = true;
    motorState[liquidIndex].startTime = millis();
    motorState[liquidIndex].duration = ml * ml_to_ms;
    
    // Use a different PWM value for soda water
    if (liquidIndex == SODA_WATER) {  
      analogWrite(pwmPins[liquidIndex], 72);  // Example: run soda at lower power (x% speed)
    } else {
      analogWrite(pwmPins[liquidIndex], 50);  // Default for other motors (x% speed)
    }
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
  // Initialize motor pins
  for (int i = 0; i < 10; i++) {
    pinMode(pwmPins[i], OUTPUT);
    analogWrite(pwmPins[i], 0); // Ensure motors are off at start
    motorState[i] = {false, 0, 0}; // Initialize motor states
  }


  RemoteXY_Init();  // Initialize RemoteXY
}

// Main Loop
void loop() {
  updateMotors();            // Update motor states
  RemoteXY_Handler();        // Process RemoteXY events

  // Cleaning function (if the clean button is pressed)
  if (RemoteXY.clean_program) {
    cleanAll();
    RemoteXY.clean_program = 0;
  }

  // Standard Cocktails (recipes indices 0 to 21)
  if (RemoteXY.Aperol_Spritz) {  // Button for Aperol Spritz
    runRecipe(AperolSpritzRecipe, recipeSizes[0]);
    RemoteXY.Aperol_Spritz = 0;
  }
  if (RemoteXY.Mojito) {         // Button for Mojito
    runRecipe(MojitoRecipe, recipeSizes[19]);  // Mojito is standard recipe index 19
    RemoteXY.Mojito = 0;
  }
  if (RemoteXY.Sweet_Martini) {  // Button for Sweet Martini
    runRecipe(SweetMartiniRecipe, recipeSizes[6]); // Standard index 6
    RemoteXY.Sweet_Martini = 0;
  }
  if (RemoteXY.Manhattan) {      // Button for Manhattan
    runRecipe(ManhattanRecipe, recipeSizes[7]); // Standard index 7
    RemoteXY.Manhattan = 0;
  }
  if (RemoteXY.Margarita) {      // Button for Margarita
    runRecipe(MargaritaRecipe, recipeSizes[8]); // Standard index 8
    RemoteXY.Margarita = 0;
  }
  if (RemoteXY.TomCollins) {     // Button for Tom Collins
    runRecipe(TomCollinsRecipe, recipeSizes[17]); // Standard index 17
    RemoteXY.TomCollins = 0;
  }
  if (RemoteXY.Cosmopolitan) {   // Button for Cosmopolitan
    runRecipe(CosmopolitanRecipe, recipeSizes[9]); // Standard index 9
    RemoteXY.Cosmopolitan = 0;
  }
  if (RemoteXY.Sidecar) {        // Button for Sidecar
    runRecipe(SidecarRecipe, recipeSizes[10]); // Standard index 10
    RemoteXY.Sidecar = 0;
  }
  if (RemoteXY.Rum_Sour) {       // Button for Rum Sour
    runRecipe(RumSourRecipe, recipeSizes[12]); // Standard index 12
    RemoteXY.Rum_Sour = 0;
  }
  if (RemoteXY.Long_Island_Iced_Tea) {  // Button for Long Island Iced Tea
    runRecipe(LongIslandRecipe, recipeSizes[13]); // Standard index 13
    RemoteXY.Long_Island_Iced_Tea = 0;
  }
  if (RemoteXY.Negroni) {        // Button for Negroni Variation
    runRecipe(NegroniVariationRecipe, recipeSizes[14]); // Standard index 14
    RemoteXY.Negroni = 0;
  }
  if (RemoteXY.Boulevardier_Variation) {  // Button for Boulevardier Variation
    runRecipe(BoulevardierVariationRecipe, recipeSizes[15]); // Standard index 15
    RemoteXY.Boulevardier_Variation = 0;
  }
  if (RemoteXY.French_75) {      // Button for French 75
    runRecipe(French75Recipe, recipeSizes[16]); // Standard index 16
    RemoteXY.French_75 = 0;
  }
  if (RemoteXY.Gin_Fizz) {       // Button for Gin Fizz
    runRecipe(GinFizzRecipe, recipeSizes[18]); // Standard index 18
    RemoteXY.Gin_Fizz = 0;
  }
  if (RemoteXY.Tequila_Sunrise) { // Button for Tequila Sunrise
    runRecipe(TequilaSunriseRecipe, recipeSizes[20]); // Standard index 20
    RemoteXY.Tequila_Sunrise = 0;
  }
  if (RemoteXY.Rum_Punch) {      // Button for Rum Punch
    runRecipe(RumPunchRecipe, recipeSizes[21]); // Standard index 21
    RemoteXY.Rum_Punch = 0;
  }
  if (RemoteXY.Gimlet) {         // Button for Gimlet
    runRecipe(GimletRecipe, recipeSizes[11]); // Standard index 11
    RemoteXY.Gimlet = 0;
  }

  // Spritz Cocktails (recipes indices 22 to 26)
  if (RemoteXY.Vodka_Spritz) {   // Button for Vodka Spritz
    runRecipe(VodkaSpritzRecipe, recipeSizes[22]);
    RemoteXY.Vodka_Spritz = 0;
  }
  if (RemoteXY.Gin_Spritz) {     // Button for Gin Spritz
    runRecipe(GinSpritzRecipe, recipeSizes[23]);
    RemoteXY.Gin_Spritz = 0;
  }
  if (RemoteXY.Rum_Spritz) {     // Button for Rum Spritz
    runRecipe(RumSpritzRecipe, recipeSizes[24]);
    RemoteXY.Rum_Spritz = 0;
  }
  if (RemoteXY.Tequila_Spritz) { // Button for Tequila Spritz
    runRecipe(TequilaSpritzRecipe, recipeSizes[25]);
    RemoteXY.Tequila_Spritz = 0;
  }
  if (RemoteXY.Bourbon_Spritz) { // Button for Bourbon Spritz
    runRecipe(BourbonSpritzRecipe, recipeSizes[26]);
    RemoteXY.Bourbon_Spritz = 0;
  }
  // Duplicate Aperol Spritz button (mapped again)
  if (RemoteXY.Aperol_spritz) {
    runRecipe(AperolSpritzRecipe, recipeSizes[0]);
    RemoteXY.Aperol_spritz = 0;
  }
  // "Soda" button mapped to Vodka Soda
  if (RemoteXY.Soda) {
    runRecipe(VodkaSodaRecipe, recipeSizes[1]);
    RemoteXY.Soda = 0;
  }

  // Customized Highball Cocktails (recipes indices 27 to 31)
  if (RemoteXY.Vodka_Highball) { // Button for Vodka Highball
    runRecipe(VodkaHighballRecipe, recipeSizes[27]);
    RemoteXY.Vodka_Highball = 0;
  }
  if (RemoteXY.Gin_Highball) {    // Button for Gin Highball (note: "Highbal" assumed typo)
    runRecipe(GinHighballRecipe, recipeSizes[28]);
    RemoteXY.Gin_Highball = 0;
  }
  if (RemoteXY.Rum_Highball) {   // Button for Rum Highball
    runRecipe(RumHighballRecipe, recipeSizes[29]);
    RemoteXY.Rum_Highball = 0;
  }
  if (RemoteXY.Tequila_Highball) { // Button for Tequila Highball
    runRecipe(TequilaHighballRecipe, recipeSizes[30]);
    RemoteXY.Tequila_Highball = 0;
  }
  if (RemoteXY.Bourbon_Highball) { // Button for Bourbon Highball
    runRecipe(BourbonHighballRecipe, recipeSizes[31]);
    RemoteXY.Bourbon_Highball = 0;
  }

  if (RemoteXY.Soda) {
    runRecipe(SodaRecipe, recipeSizes[32]);
    RemoteXY.Soda = 0;
  }
}