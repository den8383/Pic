#ifndef Motor_h
#define Motor_h

// クラスの定義
class Motor
{
public:
  Motor(int pin1,int pin2, float mode);   // コンストラクタ
  void onF();          // Led点灯
  void onR();
  void off();         // Led消灯
  float ac(float val);
  void ChangeStoppingCorrection(float);
  void ChangeSpeed(float);
  void ChangeInitialVelocityCrrection(float);
  void ChangeInitialVelocity(float);
  float divAc;
  float p_val;
  void print();

private:
  int m_MotorPin1;      // クラス内で使用するメンバ変数
  int m_MotorPin2;
  float m_mode;
  int F_st;
  int R_st; 
  float m_ac;
  float m_SpeedMax = 255;
  float m_InitialVelocity = 100;
  float m_InitialVelocityCrrection = 0.5;
  float m_StoppingCorrection = 1;
};

#endif

