import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MemLatencyAnalyzer {
  public static List<List<Double>> getLists(String path) {
    List<List<Double>> lists = new ArrayList<>();
    List<Double> currList = null;
    try (BufferedReader br = new BufferedReader(new FileReader(path))) {
      String line;
      while ((line = br.readLine()) != null) {
        if (line.startsWith("arraySize")) {
          if (currList != null) {
            lists.add(currList);
          }
          currList = new ArrayList<>();
        } else {
          currList.add(Double.parseDouble(line));
        }
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
    return lists;
  }

  public static double avg(List<Double> list) {
    double total = 0;
    for (double value : list) {
      total += value;
    }
    return total / list.size();
  }

  public static double avgNoOutliers(List<Double> list, List<Double> nonoutliers, double threshold) {
    double total = 0;
    int count = 0;
    for (double value : list) {
      if (value < threshold) {
        total += value;
        count++;
        nonoutliers.add(value);
      }
    }
    return total / count;
  }

  public static void main(String...args) {
    List<List<Double>> lists = getLists("/Users/lee/Dropbox/CSE221/project/temp_result_op2/mem_latency_random");
    int size = 4;
    for (List<Double> list : lists) {
      double initAvg = avg(list);
      List<Double> nonoutliders = new ArrayList<>();
      double correctedAvg = avgNoOutliers(list, nonoutliders, initAvg * 2);
      double sd = SDCalculator.calculate(nonoutliders);
      System.out.printf("arraySize: %-17d initial avg: %-17f corrected average: %-17f sd: %-17f\n", size *= 2, initAvg, correctedAvg, sd);
    }
  }
}
