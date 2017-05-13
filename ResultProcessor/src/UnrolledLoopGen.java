public class UnrolledLoopGen {
  public static void main1(String...args) {
    for (int i = 0; i < (2097152/4); i++) {
      System.out.println("sum += *ptr;\nptr++;");
    }
  }

  public static void main2(String...args) {
    for (int i = 0; i < 256; i++) {
      System.out.printf("d = ptr[%d];\n", i);
      System.out.printf("d = ptr[%d];\n", 524287 - i);
    }
  }

  public static void main(String...args) {
    for (int i = 0; i < 256; i++) {
      System.out.printf("ptr[%d] = 1;\\\n", i);
      System.out.printf("ptr[%d] = 0;\\\n", 524287 - i);
    }
  }
}
