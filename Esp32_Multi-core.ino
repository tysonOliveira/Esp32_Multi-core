//variaveis que indicam o núcleo
static uint8_t taskCoreZero = 0;
static uint8_t taskCoreOne  = 1;

void setup() {
  Serial.begin(115200);

  xTaskCreatePinnedToCore(
    coreTaskOne,              // Função que implementa a tarefa
    "coreTaskOne",            // Nome da tarefa
    10000,                    // Número de palavras a serem alocadas para uso com a pilha da tarefa
    NULL,                     // Parâmetro de entrade para a tarefa (pode ser NULL)
    1,                        // Prioridade da tarefa (0 a N)
    NULL,                     // Referência para a tarefa (pode ser NULL)
    taskCoreOne               // Núcleo que executará a tarefa
  );

  // Tempo para a tarefa iniciar
  delay(500);

  xTaskCreatePinnedToCore(
    coreTaskZero,
    "coreTaskZero", 
    10000, 
    NULL, 
    2, 
    NULL, 
    taskCoreZero
  );
}

void loop() {}

void coreTaskZero( void * pvParameters ){
  while(1) {    
    Serial.print("Core Zero: ");
    Serial.println(hallRead());
    delay(10000); 
  }  
}

void coreTaskOne( void * pvParameters ){
  while(1) {
    Serial.print("Core One: ");
    Serial.println(hallRead());
    delay(1000); 
  }
}
