public class testMain {
    public static void main(String args[]){
        Television tv1 = new Television();

        tv1.setChannel(1);
    }
}

class Television{
    private int channelNo;
    private int button = 44;

    public
    void setChannel(int newChannelNo){
        channelNo = newChannelNo;
        System.out.println("新しいchannelNo="+ channelNo);
        System.out.println(button);
    }
}