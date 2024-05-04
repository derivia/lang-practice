const EXAMPLE_STRING = "hello, world!";

// strings can be indexed using [i]
EXAMPLE_STRING[0] // h

// returns the index of the first occurrence of pattern
EXAMPLE_STRING.indexOf("wor") // 7

// returns the index of the last occurrence of pattern
EXAMPLE_STRING.lastIndexOf("l") // 10

// return a section of the string
EXAMPLE_STRING.slice(7) // world!

// the "end" parameter is exclusive (doesn't include the character at position "end")
EXAMPLE_STRING.slice(7, EXAMPLE_STRING.length - 1) // world
