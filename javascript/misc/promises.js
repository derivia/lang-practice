"use strict";

const request = fetch("https://api.breakingbadquotes.xyz/v1/quotes")
  .then((response) => response.json()) // Response from API
  .then((data) => console.log(data[0])) // Logging the object returned inside the array
  .catch((err) => console.error(err)); 

// The parameter of .then() is the name given to the fulfilled promise object
// The chained methods only are executed after the Promise state gets to fulfilled.
// The catch method only is executed if there is an error.
