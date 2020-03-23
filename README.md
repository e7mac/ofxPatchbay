# ofxPatchbay

Openframeworks addon that allows you to quickly and easily plug various controllers (MIDI controller, audio, mouse, keyboard) to parameters that you can define in your code.

## Usage

Let's say you want to control the size of a rectangle that you defined somewhere (`ofRectangle rect`). Register a lambda function with the patchbay, giving it a human-readable name. The closure should accept a parameter `value`, which will be a `float` in the range `[0,1]`

```
patchbay.registerControllable1f("rect-size", [&] (float value) {
    rect.setHeight(100 * value);
    rect.setWidth(100 * value);    
});
```

Now you can connect the x-position of the mouse to the registered parameter:

`patchbay.connect1f("mouse-x", "rect-size");`

You can disconnect them like this:

`patchbay.disconnect1f("mouse-x", "rect-size");`

And hook it up to a MIDI controller:

`patchbay.connect1f("midi-cc-10", "rect-size");`

Or even audio:

`patchbay.connect1f("audio-rms", "rect-size");`

## Installation

Define this object in ofApp.h

```
ofxPatchbay patchbay;
```

And add this line to `ofApp::update()`

`patchbay.update();`

## Dependencies

Uses [ofxMidi](https://github.com/danomatika/ofxMidi) for MIDI controller input.
Uses [BlackHole](https://github.com/ExistentialAudio/BlackHole) 16ch as the default Audio input. This can be changed in `ofxAudioInput.h`