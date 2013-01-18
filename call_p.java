// Hello there

public class HelloWorld {
  native void helloFromC();
  static {
    System.loadLibrary("ctest");
  }
  static public void main(String argv[]){
    HelloWorld helloWorld = new HelloWorld();
    helloWorld.helloFromC();
  }
}