# Viz-ESP

## Using Arduino-IDE

- Add Board Manager URL "https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json"

- Download Driver (for Mac Only): https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers
  - Port: `/dev/cu.SLAB_USBtoUART`


On-board LED: `GPIO PIN 2`


## Using Python

- Get `esptool.py`: `https://github.com/espressif/esptool`
`pip3 install esptool rshell`

- Erase existing firmware:
`esptool.py --chip esp32 --port /dev/tty.SLAB_USBtoUART erase_flash`

- Download and Flash MicroPython firmware
- Download: `https://micropython.org/download#esp32`
- Flash:
`esptool.py --chip esp32 --port /dev/tty.SLAB_USBtoUART --baud 460800 write_flash -z 0x1000 esp32-idf3-20190529-v1.11.bin`

- Connect to Board using `rshell`
`rshell --port /dev/tty.SLAB_USBtoUART`

```python3
>>> import machine
>>> pin = machine.Pin(2, machine.Pin.OUT)
>>> pin.on()
>>> pin.off()
```

Docs: `https://docs.micropython.org/en/latest/esp32/tutorial/intro.html`

Ref:
- `https://micropython.org/unicorn/`
- 

---

## Using JavaScript

`npm install espruino -g`

- `espruino --list`

- Reset the Board
`espruino -p /dev/tty.SLAB_USBtoUART -b 115200 -e 'reset(); digitalWrite(2, 1); save();'`

- Push the Code and Save
`espruino -p /dev/tty.SLAB_USBtoUART -b 115200 -e 'save()' WiFiConnect.js`

---

## Connect to Board (over the serial port)

- Using `rshell`
`rshell --port /dev/tty.SLAB_USBtoUART`

- Using `screen`
`screen /dev/tty.SLAB_USBtoUART 115200`

- Using `minicom`
`minicom --baudrade 115200 --device /dev/tty.SLAB_USBtoUART`



