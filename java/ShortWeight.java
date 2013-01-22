import static spark.Spark.*;
import spark.*;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class ShortWeight{

  native int matrixWeight(int[] matrix_values, int rows, int columns);
  static {
    System.loadLibrary("matrix_weight");
  }

  public static void main(String[] args) {
        setPort(9000);

        get(new Route("/") {
            @Override
            public Object handle(Request request, Response response){
                response.type("text/html");
                return "Hello!";
            }
        });

        post(new Route("/"){
            @Override
            public Object handle(Request request, Response response){
                String[] matrix = request.body().replaceAll("[[","[").replaceAll("]]","]"); 
                int[] matrixValues = parsedMatrix(matrix);
                int minimumWeightPath = calculateShortestPath(matrix, rows, columns);              
                return minimumWeightPath;
            }
        });
    }

    private static int parseMatrix(String matrixString){
        int rows = matrixRows(matrixString);
        int columns = matrixColumns(matrixString);
        String[] matrixItems = matrixString.replaceAll("[","").replaceAll("]","").split(",");

        int[] matrixValues = new int[matrixItems.length];
        for (int i = 0; i < matrixItems.length; i ++){
            try {
                matrixValues[i] = Integer.parseInt(matrixItems[i]);
            } catch(NumberFormatException nfe) { nfe.printStackTrace(); }
        }
        
    }
    private static int calculateShortestPath(int[] matrixValues, int rows, int columns){
        int lowestWeight = matrixWeight(matrixValues, rows, columns);
        return lowestWeight;
    }

    private static int matrixColumns(String matrixString){
        int count = 0;
        for (int i = 0; i < matrixString.length(); i ++){
            if (matrixString.charAt(i) == "["){
                count ++;
            }
        }
        return count;
    }
    private static int matrixRows(String matrixString){
        int count = 0;
        for (int i = 0; i < matrixString.length(); i ++){
            if (matrixString.charAt(i) == ","){
                count ++;
            }
        }
        count ++;
        return count;
    }
}