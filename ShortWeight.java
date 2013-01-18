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

  static public void main(String argv[]){
    int[] matrixValues = {3, 2, 4, 8, 5, 9, 3, 6, 2};
    int rows = 3;
    int columns = 3;
    
    ShortWeight sw = new ShortWeight();
    int lowestWeight = sw.matrixWeight(matrixValues, rows, columns);
    System.out.println(lowestWeight);
  }  

  public static void main(String[] args) {
        setPort(9000);
        // final String filename = "./public/index.html";

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
                System.out.println(request.body());
            }
        });
    }
}