/*
 *
 * @FunctionalInterface is just an informative annotation.
 * A funcional interface has only one abstract method.
 * Default (Java 8+) methods have an implementation.
 *
 * There are three ways of implementing an interface:
 * 1. Implementing the interface abstract methods.
 * 2. Anonymous function of a single interface method.
 * 3. Lambda expression if the interface is functional.
 *
 */

@FunctionalInterface
interface Car {
  void speed(int speed);
}

class CarImpl implements Car {
    public void speed(int speed) {
      System.out.println("The constructor car is going at " + speed);
    }
}

public class Lambda {
  public static void main(String[] args) {
    Car constructorCar = new CarImpl();

    Car anonymousCar = new Car() {
      @Override
      public void speed(int speed) {
        System.out.println("The anonymous car is going at " + speed);
      }
    };

    Car lambdaCar = speed -> {
      System.out.println("The lambda car is going at " + speed);
    };

    constructorCar.speed(200);
    anonymousCar.speed(200);
    lambdaCar.speed(200);
  }
}
