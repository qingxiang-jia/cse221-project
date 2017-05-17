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

  public static double cycleToSecond(double cycle) {
    return cycle / 2.4e9;
  }

  public static void main(String...args) {
    List<Double> list = SDCalculator.getList("/Users/lee/Dropbox/CSE221/project/mem_write_raw");
    double initAvg = MemLatencyAnalyzer.avg(list);
    ArrayList<Double> nonoutliers = new ArrayList<>();
    double correctedAvg = MemLatencyAnalyzer.avgNoOutliers(list, nonoutliers, initAvg * 2);
    System.out.printf("For 4KB data\ninitial avg: %-17f corrected average: %-17f sd: %-17f\n", initAvg, correctedAvg, SDCalculator.calculate(nonoutliers));
  }
}
