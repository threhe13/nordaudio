const { Nordaudio } = require("bindings")("nordaudio");

var nordaudio = new Nordaudio();
console.log("[Nordaudio] ", nordaudio);
console.log(nordaudio.GetDevices());
console.log(nordaudio.GetVersion());
