/*
 * 자율주행 자동차가 라인 안쪽에서 벗어나지 않고, 자율주행 할 수 있게 모터의 속도값을 변경하세요.
 * 모터 속도값 범위: 0~255
 * 모터 속도값이 너무 작으면 모터가 돌지 않습니다. 
 * 바닥에 닿지 않게 테스트했을 때와 실제 바닥에 놓고 했을 때 모터의 속도는 차이가 있습니다.
 * 아래 있는 각 함수 
 * Forward(), Backward(), Left1(), Left2(), Left3(), Right1(), Right2(), Right3() 의 함수를 찾아서
 * 모터 속도값 변경
 * 
 * 좌, 우 모터의 속도값이 대칭이어야 할 필요는 없음. 
 * 실제 라인이 그려진 도로에서 테스트 해가면서 적당한 값을 찾아서 입력해주어야 합니다. 
 */



const int EnableL = 5;
const int HighL = 6;       // LEFT SIDE MOTOR
const int LowL =7;

const int EnableR = 10;
const int HighR = 8;       //RIGHT SIDE MOTOR
const int LowR =9;

const int D0 = 0;          // Raspberry pin 21   LSB
const int D1 = 1;          // Raspberry pin 22
const int D2 = 2;          // Raspberry pin 23
const int D3 = 3;          // Raspberry pin 24   MSB

int a,b,c,d,data;

void Data()
{
  a = digitalRead(D0);
  b = digitalRead(D1);
  c = digitalRead(D2);
  d = digitalRead(D3);

  data = 8*d+4*c+2*b+a;
}

void setup() {
  pinMode(EnableL, OUTPUT);
  pinMode(HighL, OUTPUT);
  pinMode(LowL, OUTPUT);
  
  
  pinMode(EnableR, OUTPUT);
  pinMode(HighR, OUTPUT);
  pinMode(LowR, OUTPUT);
  
  pinMode(D0, INPUT_PULLUP);
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
}

void Forward()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,200);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,200);
}


void Backward()
{
  digitalWrite(HighL, HIGH);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL,200);

  digitalWrite(HighR, HIGH);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR,200);
}

void Stop()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, LOW);
  analogWrite(EnableL,0);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, LOW);
  analogWrite(EnableR,0); 
}

void Left1()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,100);
}

void Left2()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,60); 
}

void Left3()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,255);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,40);
}

void Right1()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,140);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,200);  
}

void Right2()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,100);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,200);
}

void Right3()
{
  digitalWrite(HighL, LOW);
  digitalWrite(LowL, HIGH);
  analogWrite(EnableL,80);

  digitalWrite(HighR, LOW);
  digitalWrite(LowR, HIGH);
  analogWrite(EnableR,200);
}

void loop() 
{
  Data();
  if(data==0){
    Forward();
  }else if(data==1){
    Right1();
  }else if(data==2){
    Right2();
  }else if(data==3){
    Right3();
  }else if(data==4){
    Left1();
  }else if(data==5){
    Left2();
  }else if(data==6){
    Left3();
  }else if(data>6){
    Stop();
  }
}
