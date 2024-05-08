"use strict";

const request = fetch("https://api.breakingbadquotes.xyz/v1/quotes")
  .then((response) => response.json())
  .catch((err) => console.error(err));
  // the parameter of .then() is the name given to the fulfilled promise object.
  // chained methods only are executed after the Promise state gets to fulfilled.
  // catch is only executed if there is an error.

(async () => {
  console.log(await request);
})();
// there is no reason to do this, but since nothing stopped the promise chain
// request is a promise from response.json()
// so the iife that logs it works.
