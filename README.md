# IR to GPIO converter for Arduino

I wanted to convert my RF based remote for my projector screen to work with my Logitech Harmony hub. My screen was a cheap, unbranded one so it wasn't in the Harmony DB.

Instead, I took my remote to pieces and connected it to an arduino and a basic circuit (just an IR receiver module really).

The code in this repo is the code which makes it work.

## Dependencies

- [IRLib2](https://github.com/cyborg5/IRLib2)

## How to use

Install the IRLib2 dependenices into your library folder and then uncomment the following line:

`// myDecoder.dumpResults(true);`

Then save and upload the sketch to your Arduino, it will run automatically.

If you open your serial monitor, you should see `Ready to receive IR signals`, at this point, if you point an IR transmitter at your receiver, you should receive an output from the buffer. You want to find a hex string which will look something like this `40bf807f`.

That is the string for whichever button you pressed on your transmitter and you should add it to the `switch` section in order to do whatever you need it to do.

