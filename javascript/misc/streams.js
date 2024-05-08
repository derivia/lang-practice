const fs = require("node:fs");
const https = require("node:https");
const server = require("node:http").createServer();

"use strict";

// http server example that handles requests sending the content of test-file.txt
// in different ways, the best i guess is to just use the fs readStream
// and pipe the content into the response
server.on("request", (req, res) => {
  // even though the function is async, it tries to send all the data at once
  // fs.readFile("test-file.txt", (err, data) => {
  //   if (err) console.error(err);
  //   res.end(data);
  // });

  // readable stream that loads chunk-by-chunk the test-file.txt
  // and sends the chunks using the server response object write method
  // const readable = fs.createReadStream("test-file.txt");
  // readable.on("data", (chunk) => {
  //   res.write(chunk);
  // });
  // readable.on("end", () => {
  //   res.end();
  // });

  const readable = fs.createReadStream("test-file.txt");
  readable.pipe(res);
  // readable in this case is the file being opened
  // res is the writable stream that we are piping (writing) the file into
});

server.listen(8000, "127.0.0.1", () => {
  console.log("listening on localhost:8000");
});

// https get example that saves a image 
// to the current directory piping the readStream 
// from the request to a writeStream
const imageURL = "https://upload.wikimedia.org/wikipedia/commons/6/6f/ChessSet.jpg"; // prettier-ignore
const fileStream = fs.createWriteStream("image.jpg"); // creates a write stream on the current directory

// prettier-ignore
https.get(imageURL, (response) => { // sends a get request to ChessSet.jpg
  if (response.statusCode !== 200) { 
    console.error("Failed to download image.");
    return;
  }
  response.pipe(fileStream); // pipes the response to the writable stream
  fileStream
    .on("finish", () => { 
      console.log("Finished downloading image.");
      fileStream.close(); // @TODO: don't know if this is necessary 
    })
    .on("error", () => {
      console.error("Error writing image");
    });
});
