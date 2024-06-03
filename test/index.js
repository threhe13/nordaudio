const { Nordaudio } = require("bindings")("nordaudio");

var nordaudio = new Nordaudio();

console.log("[Nordaudio] ", nordaudio);
console.log("[Nordaudio] Current Version : ", nordaudio.GetVersion());
console.log("[Nordaudio] Device List : ", nordaudio.GetDevices());
