const fs = require("node:fs");
const https = require("node:https");

const imageURL = "https://upload.wikimedia.org/wikipedia/commons/6/6f/ChessSet.jpg"; // prettier-ignore

const fileStream = fs.createWriteStream("image.jpg");

https.get(imageURL, (response) => {
  if (response.statusCode !== 200) {
    console.error("Failed to download image.");
    return;
  }
  response.pipe(fileStream);
  fileStream
    .on("finish", () => {
      console.log("Finished downloading image.");
      fileStream.close();
    })
    .on("error", () => {
      console.error("Error downloading image");
    });
});
