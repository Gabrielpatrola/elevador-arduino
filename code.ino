//CODIGO
const int pinoLedPorta = 0;
const int pinoSensorTerreo = 8; // define o pino 8 como sensor do andar terreo
const int pinoSensor1 = 9;      // define o pino 9 como sensor do andar 1
const int pinoSensor2 = 10;     // define o pino 10 como sensor do andar 2

const int pinoBotaoTerreo = 11; // define o pino 11 como botão do andar terreo
const int pinoBotao1 = 12;      // define o pino 12 como botão do andar 1
const int pinoBotao2 = 13;      // define o pino 13 como botão do andar 2

const int motorDireito = 5;  //define o pino 5 para motor girar para direita
const int motorEsquerdo = 6; //define o pino 6 para motor girar para esquerda

//Variaveis utilizadas na aplicação
int Display = 0;
int sensorTerreo = 0;
int sensor1 = 0;
int sensor2 = 0;
int botao = 0;
int botaoTerreo = 0;
int botao1 = 0;
int botao2 = 0;

void setup()
{
  //Definindo entradas e saidas de dados
  pinMode(pinoLedPorta, OUTPUT);
  pinMode(1, OUTPUT); //define pino 3 como 0001 em binario
  pinMode(2, OUTPUT); //define pino 4 como 0010 em binario
  pinMode(3, OUTPUT); //define pino 5 como 0100 em binario
  pinMode(4, OUTPUT); //define pino 6 como 1000 em binario
  pinMode(pinoSensorTerreo, INPUT);
  pinMode(pinoSensor1, INPUT);
  pinMode(pinoSensor2, INPUT);
  pinMode(pinoBotaoTerreo, INPUT);
  pinMode(pinoBotao1, INPUT);
  pinMode(pinoBotao2, INPUT);
  pinMode(motorDireito, OUTPUT);
  pinMode(motorEsquerdo, OUTPUT);
}

void loop()
{

  botaoTerreo = digitalRead(pinoBotaoTerreo);
  botao1 = digitalRead(pinoBotao1);
  botao2 = digitalRead(pinoBotao2);

  sensorTerreo = digitalRead(pinoSensorTerreo);
  sensor1 = digitalRead(pinoSensor1);
  sensor2 = digitalRead(pinoSensor2);

  if (botaoTerreo == HIGH)
  {
    botao = 0;
  }
  else if (botao1 == HIGH)
  {
    botao = 1;
  }
  else if (botao2 == HIGH)
  {
    botao = 2;
  }

  if (sensorTerreo == HIGH)
  {
    Display = 0;
    mostraDisplay();

    if (Display == botao)
    {
      paraElevador();
      abriPorta();
    }
    else
    {
      fechaPorta();
      sobeElevador();
    }
  }
  else if (sensor1 == HIGH)
  {
    Display = 1;
    mostraDisplay();

    if (Display == botao)
    {
      paraElevador();
      abriPorta();
    }
    else if (botao > Display)
    {
      fechaPorta();
      sobeElevador();
    }
    else
    {
      fechaPorta();
      desceElevador();
    }
  }
  else if (sensor2 == HIGH)
  {
    Display = 2;
    mostraDisplay();

    if (Display == botao)
    {
      paraElevador();
      abriPorta();
    }
    else
    {
      fechaPorta();
      desceElevador();
    }
  }
}

void paraElevador()
{

  digitalWrite(motorDireito, LOW);
  digitalWrite(motorEsquerdo, LOW);
}

void mostraDisplay()
{

  digitalWrite(4, HIGH && (Display & B00001000)); // pino 6
  digitalWrite(3, HIGH && (Display & B00000100)); // pino 5
  digitalWrite(2, HIGH && (Display & B00000010)); // pino 4
  digitalWrite(1, HIGH && (Display & B00000001)); // pino 3
}

void abriPorta()
{
  digitalWrite(pinoLedPorta, HIGH); //led aceso porta aberta
}

void fechaPorta()
{
  digitalWrite(pinoLedPorta, LOW); // led apagado porta fechada
}

void sobeElevador()
{
  digitalWrite(motorEsquerdo, LOW);
  digitalWrite(motorDireito, HIGH);
}

void desceElevador()
{
  digitalWrite(motorDireito, LOW);
  digitalWrite(motorEsquerdo, HIGH);
}
