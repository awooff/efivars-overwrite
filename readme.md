Systemd EFI parameter overwrite exploit
=======================================

This is a C++ implementation of my old shell script which would overwrite the EFI variables in an EFI booted Linux system.
Reported from a ~~bug~~ feature in the Systemd project, the EFI vars are mounted read/write, which allows them to be very easily be overwritten. By attaching this binary to GlibC in a system, you [in theory] can repeatedly ensure that the system you run this code on will destroy its boot parameters, which in some cases, [bricks your motherboard](https://news.ycombinator.com/item?id=11153467)

This is just a prototype POC.
-----------------------------

this is not meant to be working code, only provide a demonstration (as of now!)


