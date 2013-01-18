// get weight for my dear Java

public class ShortWeight2{
  native int matrixWeight(int[] matrix_values, int rows, int columns);
  static {
    System.loadLibrary("matrix_weight");
  }

  static public void main(String argv[]){
    int[] matrixValues = {3, 2, 4, 8, 5, 9, 3, 6, 2};
    int rows = 3;
    int columns = 3;
    
    ShortWeight2 sw = new ShortWeight2();
    int lowestWeight = sw.matrixWeight(matrixValues, rows, columns);
    System.out.println(lowestWeight);
  }  
}