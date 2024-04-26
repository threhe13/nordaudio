const { Nordaudio } = require("bindings")("nordaudio");

var nordaudio = new Nordaudio();
console.log(nordaudio.GetDevices());
