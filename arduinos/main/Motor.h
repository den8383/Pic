#ifndef Motor_h
#define Motor_h

// クラスの定義
class Motor
{
public:
  Motor(int pin1,int pin2, bool mode);   // コンストラクタ
  void onF();          // Led点灯
  void onR();
  void off();         // Led消灯
  int ac(int val);
  int p_val;
  void print();

private:
  int m_MotorPin1;      // クラス内で使用するメンバ変数
  int m_MotorPin2;
  bool m_mode;
  int F_st;
  int R_st; 
  int m_ac;
};

#endif

