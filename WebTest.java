import static spark.Spark.*;
import spark.*;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class WebTest {

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
                // response.type("text/html");
                String myString = "REEAAAAAAAAAAAAAAAAAAADDD MEEEEE!!!\n";
                return myString;
            }
        });
    }
}
