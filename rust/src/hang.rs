use rand::Rng;
use std::env;
use std::fs;
use std::io;

const INITIAL_LIFES: u32 = 5;

// Assumes the words.txt file is passed
fn get_word() -> Option<String> {
    // Creates a vector containing argv
    let args: Vec<String> = env::args().collect();
    // Get the words from the first argument passed to the binary, arg[1]
    let words_file = fs::read_to_string(&args[1]).expect("the words.txt file couldn't be readed");
    // From the words collected, make a string with them separated by line
    let words: Vec<&str> = words_file.lines().collect();
    // Creates a rng using the system as seeder
    let mut rng = rand::thread_rng();
    // Generates a random number from the range 0 until words.len()
    let index = rng.gen_range(0..words.len());
    // Returns a random word
    Some(words[index].to_string())
}

fn get_guess() {
    // @TODO
}

fn finish_game() {
    // @TODO
}

fn show_word(word: String) {
    // @TODO
}

fn start_game() {
    // @TODO
}
