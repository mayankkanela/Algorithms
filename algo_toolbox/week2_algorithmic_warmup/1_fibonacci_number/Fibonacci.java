import java.util.Scanner;

public class Fibonacci {
  private static long calc_fib(long n) {
    if (n <= 1)
      return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
  }

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    long n = in.nextInt();
    in.close();

    System.out.println(calc_fib(n));
  }
}
