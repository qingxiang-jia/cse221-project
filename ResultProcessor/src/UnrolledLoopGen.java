public class UnrolledLoopGen {
  public static void main(String...args) {
    for (int i = 0; i < (2097152/4); i++) {
      System.out.println("sum += *ptr;\nptr++;");
    }
  }
}
