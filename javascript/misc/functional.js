let animals = [
	{
		name: "billy",
		species: "dog",
	},
	{
		name: "mandy",
		species: "cat",
	},
	{
		name: "arthur",
		species: "dog",
	},
	{
		name: "sophie",
		species: "pig",
	},
	{
		name: "john",
		species: "monkey",
	},
];

// Add a method "myFilter" to the Array prototype
Array.prototype.myFilter = function (callback, thisArg) {
	// Array to store result
	let result = [];

	// Iterate over each element in `this` (the array in which the function is being called)
	for (let i = 0; i < this.length; i++) {
		// Check for empty space in array
		if (i in this) {
			// Execute the callback function
			// .call executes a function with a specific `this`
			// - `thisArg` becames `this` value of `callback`
			//
			// The rest are arguments:
			// - `this[i]`: the current element in the array
			// - `i`: the current index of the element in the array
			// - `this`: the array being iterated over
			if (callback.call(thisArg, this[i], i, this)) {
				result.push(this[i]);
			}
		}
	}
	return result;
};

let dogs = animals.myFilter((animal) => animal.species === "dog");

// Add a method "reverse" to the String prototype
String.prototype.reverse = function () {
	// Split the string into an array
	let result = this.split("");

	// From the beginning til the middle of the array
	for (let i = 0; i < Math.floor(result.length / 2); i++) {
		// Swap the chars
		let tmp = result[i];
		result[i] = result[result.length - 1 - i];
		result[result.length - 1 - i] = tmp;
	}

	// Return the array as a string
	return result.join("");
};

// Add a method "myMap" to the Array prototype
Array.prototype.myMap = function (callback, thisArg) {
	// Array to store result
	let result = [];

	// Iterate over each element in `this` (the array in which the function is being called)
	for (let i = 0; i < this.length; i++) {
		// Check for empty space in array
		if (i in this) {
			// For the current element, call the function and store the result in `r`
			let r = callback.call(thisArg, this[i], i, this);
			// Push the result into the the `result array`
			result.push(r);
		}
	}
	return result;
};
