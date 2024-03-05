pub fn fizzbuzz(max_number: u32) {
    let mut start = 1;
    while start <= max_number {
        if start % 3 == 0 && start % 5 == 0 {
            println!("fizzbuzz");
        } else if start % 3 == 0 {
            println!("fizz");
        } else if start % 5 == 0 {
            println!("buzz");
        } else {
            println!("{}", start);
        }
        start += 1;
    }
}

pub fn fibonacci(max_number: u32) {
    let mut left = 0;
    let mut middle = 1;
    let mut right = 1;
    let mut count = 0;
    while count < max_number {
        println!("{}", left);
        left = middle;
        middle = right;
        right = left + middle;
        count = count + 1;
    }
}

pub fn add_two_array_numbers() {
    let arr = [1, 3, 6];
    println!(
        "The first and second element of the array arr added: {}",
        arr[0] + arr[1]
    );
}

pub fn print_first_two_elements() {
    let tup = (250, 'a', "Hello");
    println!("First tuple element: {}", tup.0);
    println!("Second tuple element: {}", tup.1);
}

pub fn exponent(num1: u32, num2: u32) -> u32 {
    let mut result = 1;
    let mut count = 0;
    while count < num2 {
        result *= num1;
        count += 1;
    }
    result
}

pub fn reverse_array<T>(arr: &mut [T]) {
    let mut left = 0;
    let mut right = arr.len() - 1;
    while left < right {
        arr.swap(left, right);
        left += 1;
        right -= 1;
    }
}

pub fn countdown() {
    println!("starting countdown!");
    // here <num1>..<num2> means: from the num1 until num2 - 1
    // and .rev reverses the order, so the countdown goes: 3, 2, 1.
    for number in (1..4).rev() {
        println!("{number}");
    }
    println!("program execution finished!");
}
