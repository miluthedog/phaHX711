# Set up: phaHX711
### HX711 library
- Download .zip file
- Let ArduinoIDE set up for you
### Example
- ReadRaw
- AutoScale: input "ratio"
- ManualScale: input reference object "weight" and do set up manually
# Working principles
### Function: __"weight" = A "signal" + B
- This is a linear function, A and B needed to define the function
- To obtain A and B, we need 2 reference point, defined by a "weight" and a "signal"
### Code breakdown
- read(): read "signal" from HX711
- tare(): calculate B and remove from function. Function is "weight" = A "signal" now
- factor(): calculate A (or "ratio")
