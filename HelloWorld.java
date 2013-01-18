// Hello there

public class HelloWorld {
  native int helloFromC(int[] test_in, int value);
  static {
    System.loadLibrary("ctest");
  }
  static public void main(String argv[]){
    int[] myTestArray = { 6, 1, 4, 1, 2, 3};

    HelloWorld helloWorld = new HelloWorld();
    int result = helloWorld.helloFromC(myTestArray, 45);
    System.out.println(result);
  }
}
