const events = require("events");

const testFunction = () => {
  console.log("hello from testFunction!");
};

const myEmitter = new events.EventEmitter();
myEmitter.on("test", testFunction); // adds a listener to the event emitter object
myEmitter.emit("test"); // prints "hello from testFunction!" to the console
