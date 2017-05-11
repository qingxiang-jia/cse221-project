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

  public static double avgNoOutliers(List<Double> list, double threshold) {
    double total = 0;
    int count = 0;
    for (double value : list) {
      if (value < threshold) {
        total += value;
        count++;
      }
    }
    return total / count;
  }

  public static void main(String...args) {
    List<List<Double>> lists = getLists("/Users/lee/Dropbox/CSE221/project/mem_latency_random");
    int size = 4;
    for (List<Double> list : lists) {
      double initAvg = avg(list);
      double correctedAvg = avgNoOutliers(list, initAvg * 2);
      System.out.printf("arraySize: %-17d initial avg: %-17f corrected average %f\n", size *= 2, initAvg, correctedAvg);
    }
  }
}
