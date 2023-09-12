public class Main
{
    public static void main(String[] args) {
        var t0 = new Thread(() -> {
            System.out.println("-------");
        });
        var t1 = new Thread(() -> {
            System.out.println("1111111111");
        t0.start();
        // t0.yield();
        Thread.yield();
    }
}