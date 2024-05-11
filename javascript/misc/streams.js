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
const writeStream = fs.createWriteStream("image.jpg"); // creates a write stream on the current directory

// prettier-ignore
https.get(imageURL, (response) => { // sends a get request to ChessSet.jpg
  if (response.statusCode !== 200) {
    console.error("failed to download image.");
    return;
  }
  response.pipe(writeStream); // pipes the response (a readable stream) to the writable stream
  writeStream
    .on("finish", () => {
      console.log("finished downloading image.");
      // writeStream.close();
      // // from node.js docs: if autoClose is set to true (default behavior)
      // on 'error' or 'finish' the file descriptor will be closed automatically.
      // so it's not necessary to close the stream after the finish event.
    })
    .on("error", () => {
      console.error("error writing image");
    });
});

// asynchronous example using pipeline between two streams in order to save a cute cat image.
(async () => {
  try {
    const writeStream = fs.createWriteStream("cat.jpg");
    const response = await fetch(
      "https://cloudfront-us-east-1.images.arcpublishing.com/newr7/AJJNCSONXRPMXFGBEEPB7RVCHM.jpg",
    );
    await pipeline(response.body, writeStream, (err) => {
      if (err) throw err;
    });
  } catch (err) {
    throw err;
  }
})();

