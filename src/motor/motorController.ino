class motorController{
  private:
  int ENA;
  int ENB;
  int IN1;
  int IN2;
  int IN3;
  int IN4;
  int dir; // stop = 0, left = 1, right = 2, forward = 3, backwards = 4
  int spd;
  const int frequency = 500;
  const int resolution = 8;
  const int channel_A = 0;
  const int channel_B = 1;

  public:
  motorController(int ena = 18, int enb = 19, int in1 = 26, int in2 = 27, int in3 = 25, int in4 = 23){
    dir = 0;
    spd = 1;
    
    ENA = ena;
    ENB = enb;
    IN1 = in1;
    IN2 = in2;
    IN3 = in3;
    IN4 = in4;

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    
    ledcAttachPin(ENA, channel_A);
    ledcSetup(channel_A, frequency, resolution);
    ledcAttachPin(ENB, channel_B);
    ledcSetup(channel_B, frequency, resolution);

  }

  void changeDir(int dir){
    switch(dir){
      case 0:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        ledcWrite(channel_A,(0*spd));
        ledcWrite(channel_B,(0*spd));
        break;
      case 1:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        ledcWrite(channel_A,(255*spd));
        ledcWrite(channel_B,(50*spd));
        break;
      case 2:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        ledcWrite(channel_A,(50*spd));
        ledcWrite(channel_B,(255*spd));
        break;
      case 3:
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        ledcWrite(channel_A,(255*spd));
        ledcWrite(channel_B,(255*spd));
        break;
      case 4:
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        ledcWrite(channel_A,(255*spd));
        ledcWrite(channel_B,(255*spd));
        break;
    }
  }

  void changeSpd(int newSpd){
    spd = newSpd;
  }

  void avoid(){
    changeDir(1);
    delay(1000);
    changeDir(3);
    delay(2000);
    changeDir(2);
    delay(1000);
    changeDir(3);
    delay(8000);
    changeDir(2);
    delay(1000);
    changeDir(3);
    delay(2000);
    changeDir(1);
    delay(1000);
    changeDir(3);
  }
};
