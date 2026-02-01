🚀 Interplanetary Travel Simulation (C - MinGW)

📌 Overview

This project is a C console application (compiled with MinGW) that simulates people traveling between planets using spacecraft. The program reads passenger information from a file (Kisiler.txt) and tracks their remaining lifetime in hours. If a person's lifetime reaches zero, they are considered deceased and excluded from the population count.

While traveling, lifetime decreases normally.

On planets, aging rate depends on planet type (defined in assignment).

🚀 Features

Read passenger data from Kisiler.txt.

Simulate travel between planets using spacecraft.

Apply planet-based aging rules (lifetime reduction depends on planet type).

Track each passenger’s remaining lifetime.

Exclude deceased passengers (when lifetime = 0).

Display updated population after each simulation step.

⚙️ Requirements

MinGW Compiler (for Windows)

Standard C language (ANSI C)

Console application environment

🖥️ Compilation & Usage

Place the Kisiler.txt file in the project directory.

Compile the program using MinGW:

gcc main.c -o interplanetary.exe

Run the executable:

./interplanetary.exe

The program will:

Load all people from the text file.

Simulate interplanetary travel.

Apply planet-based lifetime reduction.

Exclude deceased passengers.

🔮 Future Improvements

Add different spacecrafts with capacity management.

Add random destination assignment.

Export results to an output file.

Improve planet rules with configurable aging rates.

📜 License

This project is licensed under the MIT License – free to use, modify, and distribute.
