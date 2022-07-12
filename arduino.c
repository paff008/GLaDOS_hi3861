typedef struct {
  float during;
  int x_fre;
  int y_fre;
  int z_fre;
  int a_fre;
  int m_fre;
} MIDI;

#define EN        8       //步进电机使能端，低电平有效
#define X_DIR     6       //X轴 步进电机方向控制
#define Y_DIR     5       //y轴 步进电机方向控制
#define Z_DIR     7       //z轴 步进电机方向控制
#define X_STP     3       //x轴 步进控制
#define Y_STP     2       //y轴 步进控制
#define Z_STP     4       //z轴 步进控制

#define GPIO_IN_1 9
#define GPIO_OUT_1 10
#define GPIO_SING 11
/*
//函数：step    功能：控制步进电机方向，步数。
//参数：dir 方向控制, dirPin对应步进电机的DIR引脚，stepperPin 对应步进电机的step引脚， steps 步进的步数
//无返回值
*/
#define NOTE_NUMBER 1000
const MIDI NOTE_INFO[NOTE_NUMBER] PROGMEM = {
297.3832,211,211,0,0,0,
594.7663,317,266,158,0,0,
297.3834,317,266,266,0,0,
297.3829,317,266,158,0,0,
0.0002,158,158,0,0,0,
594.7661,356,282,133,0,0,
297.3832,356,282,282,0,0,
297.3832,356,282,133,0,0,
297.3832,399,317,105,0,0,
297.3832,399,317,105,0,0,
297.3832,399,317,118,0,0,
297.3832,399,317,133,0,0,
594.7663,423,282,141,0,0,
0.0005,423,423,0,0,0,
297.3832,423,237,237,0,0,
297.3827,423,237,211,0,0,
0.0005,237,211,211,0,0,
594.7659,317,266,158,0,0,
297.3832,317,266,266,0,0,
297.3832,317,266,158,0,0,
148.6925,356,317,282,133,466,
446.0738,356,282,133,0,0,
297.3832,356,282,282,0,0,
297.3832,356,282,133,0,0,
297.3832,399,317,105,0,0,
297.3832,399,317,105,0,0,
297.3832,399,317,118,0,0,
297.3832,399,317,133,0,0,
594.7663,423,282,141,0,0,
297.3832,423,336,336,0,0,
297.3832,423,336,105,0,0,
594.7663,399,317,99,0,0,
0.0009,399,399,0,0,0,
297.3832,399,317,317,0,0,
297.3822,399,317,133,0,0,
0.0009,317,133,133,0,0,
594.7663,475,237,141,0,0,
297.3832,475,237,237,0,0,
297.3832,475,237,99,0,0,
297.3832,423,336,105,0,0,
297.3832,423,336,118,0,0,
297.3832,423,336,105,0,0,
297.3822,423,336,141,0,0,
594.7663,317,266,158,0,0,
297.3832,317,266,266,0,0,
297.3832,317,266,105,0,0,
594.7663,475,399,118,0,0,
297.3832,475,399,399,0,0,
297.3832,475,399,158,0,0,
297.3832,423,282,168,0,0,
297.3832,423,282,282,0,0,
297.3832,423,282,282,0,0,
297.3832,423,282,118,0,0,
297.3832,317,266,133,0,0,
297.3832,317,266,141,0,0,
297.3832,317,266,133,0,0,
297.3832,317,266,118,0,0,
297.3832,423,336,105,0,0,
297.3832,423,336,112,0,0,
297.3832,423,336,105,0,0,
297.3832,423,336,89,0,0,
594.7663,399,317,99,0,0,
297.3832,399,317,317,0,0,
297.3832,399,317,133,0,0,
594.7663,475,237,141,0,0,
297.3832,475,237,237,0,0,
297.3832,475,237,99,0,0,
297.3832,423,336,105,0,0,
0.0018,423,336,336,0,0,
297.3813,423,336,118,0,0,
0.0018,423,118,118,0,0,
297.3832,423,336,105,0,0,
297.3813,423,336,141,0,0,
0.0018,336,141,141,0,0,
594.7663,317,266,158,0,0,
297.3832,317,266,266,0,0,
297.3832,317,266,105,0,0,
594.7663,475,399,118,0,0,
297.3832,475,399,399,0,0,
297.3832,475,399,158,0,0,
297.3832,423,336,168,0,0,
297.3832,423,336,336,0,0,
297.3832,423,336,336,0,0,
297.3832,423,336,118,0,0,
297.3832,317,266,133,0,0,
297.3832,317,266,141,0,0,
297.3832,317,266,133,0,0,
297.3832,317,266,118,0,0,
594.7663,423,282,105,0,0,
297.3832,423,336,336,0,0,
297.3813,423,336,211,105,587,
594.7663,317,266,158,0,0,
297.3850,317,317,0,0,0,
297.3813,317,266,158,0,0,
594.7663,356,282,133,0,0,
297.3850,356,356,0,0,0,
297.3813,356,282,133,0,0,
297.3850,399,266,105,0,0,
297.3813,399,266,105,0,0,
0.0037,399,282,266,118,587,
297.3777,399,282,118,0,0,
0.0037,399,399,0,0,0,
297.3813,399,317,133,0,0,
594.7663,141,141,0,0,0,
297.3850,0,0,0,0,0,
297.3813,336,211,105,0,0,
594.7663,317,266,158,0,0,
297.3850,317,317,0,0,0,
297.3813,317,266,158,0,0,
594.7663,356,282,133,0,0,
297.3850,356,356,0,0,0,
297.3813,356,282,133,0,0,
297.3850,399,317,105,0,0,
297.3813,399,317,105,0,0,
0.0037,399,317,282,118,587,
297.3777,399,282,118,0,0,
0.0037,399,399,0,0,0,
297.3813,399,317,133,0,0,
594.7663,141,141,0,0,0,
297.3850,0,0,0,0,0,
297.3813,336,105,105,0,0,
594.7663,399,317,99,0,0,
297.3850,0,0,0,0,0,
297.3813,133,133,0,0,0,
594.7663,141,141,0,0,0,
297.3850,0,0,0,0,0,
297.3813,317,99,99,0,0,
297.3850,336,105,105,0,0,
297.3813,317,118,118,0,0,
};
int  x_frequency = 0, y_frequency = 0, z_frequency = 0, a_frequency = 0, m_frequency = 0;
int x_number_counter = 0, y_number_counter = 0, z_number_counter = 0, a_number_counter = 0, m_number_counter = 0;
#define TIMER1_FREQUENCY (62200)
#define ENABLE PCINT0   //使能脚位，相当于DRV8825 1脚置于低电平，对应uno 8号脚
#define X_MOTOR_PULSE PCINT18  //X电机脉冲，对应uno 2号脚
#define Y_MOTOR_PULSE PCINT19  //Y电机脉冲，对应uno 3号脚
#define Z_MOTOR_PULSE PCINT20  //Z电机脉冲，对应uno 4号脚
#define A_MOTOR_PULSE PCINT4   //A电机脉冲，对应uno 12号脚
#define M_MOTOR_PULSE PCINT2   //M电机脉冲，对应uno 9号脚
#define X_MOTOR_DIRECTION PCINT21    //X电机方向，对应uno 5号脚
#define Y_MOTOR_DIRECTION PCINT22    //Y电机方向，对应uno 6号脚
#define Z_MOTOR_DIRECTION PCINT23    //Z电机方向，对应uno 7号脚
#define A_MOTOR_DIRECTION PCINT5     //A电机方向，对应uno 13号脚
#define M_MOTOR_DIRECTION PCINT3     //M电机方向，对应uno 10号脚

void step(boolean dir, byte dirPin, byte stepperPin,byte dirPin1, byte stepperPin1, int steps)
{
  digitalWrite(dirPin, dir);
  digitalWrite(dirPin1, dir);
  delay(50);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    digitalWrite(stepperPin1, HIGH);
    delayMicroseconds(800);  
    digitalWrite(stepperPin, LOW);
    digitalWrite(stepperPin1, LOW);
    delayMicroseconds(800);  
  }
}

void setup(){//将步进电机用到的IO管脚设置成输出
  TCCR1A = 0; //ATmega328p手册 p133左右
  TCCR1B |= (1 << WGM12); //  Clear Timer on Compare Match (CTC) Mode
  TCCR1B |= (1 << CS10) | (1 << CS11); // Prescaler == 64
  TCNT1 &= ~0xff;//定时器1计数器寄存器清空
  OCR1A = 1;//比较寄存器设置为1
  TIMSK1 |= _BV(OCIE1A);//开启定时器1中断
  DDRB |= _BV(ENABLE) | _BV(A_MOTOR_PULSE) | _BV(A_MOTOR_DIRECTION) | _BV(M_MOTOR_PULSE) | _BV(M_MOTOR_DIRECTION);
  DDRD |= _BV(X_MOTOR_PULSE) | _BV(Y_MOTOR_PULSE) | _BV(X_MOTOR_DIRECTION) | _BV(Y_MOTOR_DIRECTION) | _BV(Z_MOTOR_PULSE) | _BV(Z_MOTOR_DIRECTION) ;
  PORTD = 0;
  
  Serial.begin(9600);
  pinMode(GPIO_IN_1,INPUT);
  pinMode(GPIO_OUT_1,OUTPUT);
  pinMode(GPIO_SING,INPUT);
  
  pinMode(X_DIR, OUTPUT);
  pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);
  pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);
} 

void sing_loop(){
    for (int i = 0; i < NOTE_NUMBER; i++) {
      x_frequency =  pgm_read_dword(&NOTE_INFO[i].x_fre);
      y_frequency = pgm_read_dword(&NOTE_INFO[i].y_fre);
      z_frequency = pgm_read_dword(&NOTE_INFO[i].z_fre);
      a_frequency = pgm_read_dword(&NOTE_INFO[i].a_fre);
      //m_frequency = pgm_read_float(&NOTE_INFO[i].m_fre);
      tone(10, pgm_read_dword(&NOTE_INFO[i].m_fre), pgm_read_float(&NOTE_INFO[i].during)) ;
      delay(pgm_read_float(&NOTE_INFO[i].during));
      noTone(10);
    }
}
void touch(){
  step(true, X_DIR, X_STP,Y_DIR, Y_STP, 10000); //X轴电机 正转1圈，200步为一圈
  Serial.print("1start\n");
  digitalWrite(GPIO_OUT_1, HIGH);
  delay(2000);
  step(false, X_DIR, X_STP,Y_DIR, Y_STP, 10000); //X轴电机 正转1圈，200步为一圈
  Serial.print("2start\n");
  delay(2000);
}
void loop(){
  digitalWrite(GPIO_OUT_1, LOW);
  //int gpio_in_state = 0;
  int gpio_in_state = digitalRead(GPIO_IN_1);
  Serial.println(gpio_in_state);
  if(gpio_in_state == HIGH){
    delay(500);
    int gpio_in_state = digitalRead(GPIO_IN_1);
    if(gpio_in_state == HIGH){
      touch();
    }
  }
  int gpio_sing_state = digitalRead(GPIO_SING);
   if(gpio_sing_state == HIGH){
    delay(500);
    int gpio_sing_state = digitalRead(GPIO_SING);
    if(gpio_sing_state == HIGH){
      Serial.print("sing\n");
      sing_loop();
    }
  }
}
ISR(TIMER1_COMPA_vect) { //中断请求 interrupt service require
  if (x_frequency != 0) {
    if (++x_number_counter >= (x_frequency)) {
      x_number_counter = 0;
      if (bitRead(PORTD, X_MOTOR_PULSE))
        bitClear(PORTD, X_MOTOR_PULSE);
      else
        bitSet(PORTD, X_MOTOR_PULSE);
    }
  }
  if (y_frequency != 0) {
    if (++y_number_counter >= (y_frequency)) {
      y_number_counter = 0;
      if (bitRead(PORTD, Y_MOTOR_PULSE))
        bitClear(PORTD, Y_MOTOR_PULSE);
      else
        bitSet(PORTD, Y_MOTOR_PULSE);
    }
  }
  if (z_frequency != 0) {
    if (++z_number_counter >= (z_frequency)) {
      z_number_counter = 0;
      if (bitRead(PORTD, Z_MOTOR_PULSE))
        bitClear(PORTD, Z_MOTOR_PULSE);
      else
        bitSet(PORTD, Z_MOTOR_PULSE);
    }
  }
  if (a_frequency != 0) {
    if (++a_number_counter >= (a_frequency)) {
      a_number_counter = 0;
      if (bitRead(PORTB, A_MOTOR_PULSE))
        bitClear(PORTB, A_MOTOR_PULSE);
      else
        bitSet(PORTB, A_MOTOR_PULSE);
    }
  }
}
