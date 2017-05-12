import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MemBandwidthAnalyzer {
  public static List<List<Double>> getLists(String path) {
    List<List<Double>> lists = new ArrayList<>();
    List<Double> currList = new ArrayList<>();
    try (BufferedReader br = new BufferedReader(new FileReader(path))) {
      String line;
      while ((line = br.readLine()) != null) {
        currList.add(Double.parseDouble(line));
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
    lists.add(currList);
    return lists;
  }

  public static void main(String...args) {
    List<List<Double>> lists = getLists("/Users/lee/Dropbox/CSE221/project/mem_bandwidth_read_final");
    for (List<Double> list : lists) {
      double initAvg = MemLatencyAnalyzer.avg(list);
      double correctedAvg = MemLatencyAnalyzer.avgNoOutliers(list, initAvg * 2);
      System.out.printf("initial avg: %-17f corrected average %f\n", initAvg, correctedAvg);
    }
  }
}
