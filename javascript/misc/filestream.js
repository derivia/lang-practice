"use strict";

const fs = require("node:fs");
const https = require("node:https");

const imageURL = "https://upload.wikimedia.org/wikipedia/commons/6/6f/ChessSet.jpg"; // prettier-ignore

const fileStream = fs.createWriteStream("image.jpg"); // creates a write stream on the current directory

https.get(imageURL, (response) => { // sends a get request to ChessSet.jpg
  if (response.statusCode !== 200) { // handles HTTP status 200
    console.error("Failed to download image.");
    return;
  }
  response.pipe(fileStream); // pipes the response to the writable stream
  fileStream
    .on("finish", () => { 
      console.log("Finished downloading image.");
      fileStream.close();
    })
    .on("error", () => {
      console.error("Error writing image");
    });
});
