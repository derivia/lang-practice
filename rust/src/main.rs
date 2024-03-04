//  Rust functions start with fn, have the parameters defined inside () and the return type after ->
//  Variables are constant by default and adding mut before their definition changes this.
//  The type can be explicity passed by using <variable_name>: <type>
//
//  Constants can only be set to expressions that evaluate in compile-time
//
//  Tuples are arrays-objects that can hold multiple elements of different types
//  Arrays are like arrays... they have fixed size
//  Vectors are like in C++, they have mutable size
//  Rust will not automatically try to convert non-Boolean types to a Boolean

const PI: f64 = 3.151592;

// To get the functions from another file:
mod funcs;
use funcs::fizzbuzz;
use funcs::countdown;
use funcs::add_two_array_numbers;
use funcs::print_first_two_elements;
use funcs::exponent;

fn main() {
    print_first_two_elements();
    add_two_array_numbers();
    println!("The value of PI is something like: {}", PI);
    println!("and 4^3 = {}", exponent(4, 3));
    countdown();
    fizzbuzz(32);
}
