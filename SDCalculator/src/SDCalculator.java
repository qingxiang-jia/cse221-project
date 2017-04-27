import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class SDCalculator {
  public static void calculate(List<Double> numbers) {
    int n = numbers.size();
    double mean;
    double sum = 0;
    for (Double number : numbers) {
      sum += number;
    }
    mean = sum / n;
    sum = 0;
    for (Double number : numbers) {
      sum += Math.pow(((double) number) - mean, 2.0);
    }
    System.out.println("Mean: " + mean);
    System.out.println("SD: " + Math.sqrt(sum / (double) n));
  }

  public static List<Double> getList(String path) {
    List<Double> numbers = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader(path))) {
      String line;
      while ((line = br.readLine()) != null) {
        numbers.add(Double.parseDouble(line));
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
    return numbers;
  }

  public static void main(String... args) {
//    System.out.println("\nmeasureReadTimeOverhead");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureReadTimeOverhead"));
//
//    System.out.println("\nmeasureLoopOverhead");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureLoopOverhead"));
//
//    System.out.println("\nmeasure0arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure0arg"));
//
//    System.out.println("\nmeasure1arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure1arg"));
//
//    System.out.println("\nmeasure2arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure2arg"));
//
//    System.out.println("\nmeasure3arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure3arg"));
//
//    System.out.println("\nmeasure4arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure4arg"));
//
//    System.out.println("\nmeasure5arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure5arg"));
//
//    System.out.println("\nmeasure6arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure6arg"));
//
//    System.out.println("\nmeasure7arg");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measure7arg"));
//
//    System.out.println("\nmeasureSystemCallOverhead");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureSystemCallOverhead"));
//
//    System.out.println("\nmeasureProcessCreationTime");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureProcessCreationTime"));
//
//    System.out.println("\nmeasureThreadCreationTime");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureThreadCreationTime"));
//
//    System.out.println("\nmeasureContextSwitchBetweenProcesses");
//    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureContextSwitchBetweenProcesses"));
//
    System.out.println("\nmeasureContextSwitchBetweenThreads");
    calculate(getList("/Users/lee/Dropbox/CSE221/project/measureContextSwitchBetweenThreads"));
  }
}
