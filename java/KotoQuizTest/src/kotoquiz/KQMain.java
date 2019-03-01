package kotoquiz;

public class KQMain {
    public static void main(String[] args) {
        final int EXEC_MODE_QUIZ = 1;
        final int EXEC_MODE_CHECK = 2;
        final int QUIZ_MAX = 3;

        boolean loopFlg = true;
        int inputNum = 0;
        int execMode = EXEC_MODE_QUIZ;

        int nowQuizNum = 0;
        int correctTotal = 0;

        while (loopFlg) {

            if(execMode == EXEC_MODE_QUIZ) {
                System.out.println("##############ことくいず###############");
                System.out.println("    現在、" + (nowQuizNum + 1) + "問目です ");
                System.out.println("    現在の正解数は" + correctTotal + "です。");
                System.out.println("***************************************");
                System.out.println("");
                System.out.println("＜ 問題です ＞");

                switch (nowQuizNum) {
                    case 0:
                        System.out.println("変数の型でint型の最大値はいくつ?");
                        System.out.println("");
                        System.out.println("--------------------------------");
                        System.out.println("1:256 2:98776342 3:214748367");

                        break;
                    case 1:
                        System.out.println("変数の型を変換するのに使う方法はどれ?");
                        System.out.println("");
                        System.out.println("-------------------------------");
                        System.out.println("1:キャスト　2:スコープ　3:インクリメント");
                        break;
                    case 2:
                        System.out.println("変数aが「4以上でかつ10以下」か「40未満」");
                        System.out.println("正しい条件式はどれ？");
                        System.out.println("");
                        System.out.println("----------------------------------------");
                        System.out.println("1:(a >= 4 || a < 10) && a < 40");
                        System.out.println("2:(a >= 4 || a < = 10) || a < 40");
                        System.out.println("3:(a >= 4 && a < = 10)&& a < 40");
                        break;
                }
                System.out.print("答え >");

                execMode = EXEC_MODE_CHECK;
            }else if(execMode == EXEC_MODE_CHECK) {

                switch (nowQuizNum) {
                    case 0:
                        if (inputNum == 3) {
                            correctTotal = printCorrect(correctTotal);
                        } else {
                            System.out.println("残念！不正解");
                        }

                        break;
                    case 1:
                        if (inputNum == 1) {
                            correctTotal = printCorrect(correctTotal);
                        } else {
                            System.out.println("残念！不正解");
                        }
                        break;
                    case 2:
                        if (inputNum == 3) {
                            correctTotal = printCorrect(correctTotal);
                        } else {
                            System.out.println("残念！不正解");
                        }

                        break;
                }
                System.out.println("");
                System.out.println("--------------------------------------");
                System.out.println("< 1を入力してEnterキーを押してください");


                nowQuizNum += 1;

                if (nowQuizNum >= QUIZ_MAX) {

                    loopFlg = false;
                }
                execMode = EXEC_MODE_QUIZ;
            }

            int tmpInputNum = 0;
            try{

                final int IMPUT_MAX = 3;

                java.util.Scanner sc = new java.util.Scanner(System.in);
                int inputInt = sc.nextInt();

                if(inputInt > 0 && inputInt <= IMPUT_MAX){
                    tmpInputNum = inputInt;
                }else{
                    System.out.println("※ コマンドは"+ IMPUT_MAX+"以下で入力してください");
                }
            }catch(Exception e){
                System.out.println("※　数字以外は入力しないでください※");
            }

            inputNum = tmpInputNum;


            System.out.println("");
            System.out.println("#######################################");
            System.out.println("");

            System.out.println("****************** ことくいず *********************");
            System.out.println("           あなたの正解数は "+correctTotal+"でした             ");
            System.out.println("**************************************************");
            System.out.println("おしまい");


        }
    }

    private static int printCorrect(int seikaiGoukei){

        System.out.println("やったね！正解");
        seikaiGoukei +=1;

        return seikaiGoukei;
    }
}
