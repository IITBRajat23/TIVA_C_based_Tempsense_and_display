# Temperature Monitoring using TIVA C Microcontroller

# Contributor, Rajat Sankhla, 213079008

This project focuses on leveraging the built-in temperature sensor of the TIVA C Microcontroller to accurately monitor changes in room temperature. It involves translating the sensor readings into accurate degrees Celsius measurements and displaying real-time updates on an LCD using Hitachi’s HD44780 LCD controller.

## Features

- Precise monitoring of room temperature using TIVA C Microcontroller's built-in temperature sensor.
- Conversion of sensor readings into accurate degrees Celsius measurements using a sensor formula.
- Real-time updates displayed on an LCD screen through interfacing with Hitachi’s HD44780 LCD controller.

## Getting Started

### Prerequisites

- TIVA C Microcontroller
- LCD screen compatible with Hitachi's HD44780 controller
- Necessary development environment (CCS, TIVAware)

### Installation

1. Clone this repository: `git clone https://github.com/RajatSankhla/temperature-monitor-tiva.git`
2. Navigate to the project directory: `cd temperature-monitor-tiva`
3. Configure your development environment as per the project's requirements.
4. Compile and upload the code to your TIVA C Microcontroller.

## Usage

1. Power up your TIVA C Microcontroller with the connected temperature sensor and LCD screen.
2. The microcontroller will start monitoring the room temperature and displaying updates on the LCD.
3. Enjoy real-time temperature monitoring!

## How to use these files.

1. Create a new project in CCS.
2. Add lcd_name_printing.c, LCD.c, LCD. h, mylib.h into the CCS project environment such that you can see them in the project explorer.

## Sources

1. Embedded Systems Design, EE721, IIT Bombay.
