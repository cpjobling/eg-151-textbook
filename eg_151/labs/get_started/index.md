---
jupytext:
  cell_metadata_filter: -all
  formats: md:myst
  text_representation:
    extension: .md
    format_name: myst
    format_version: 0.13
    jupytext_version: 1.14.7
kernelspec:
  display_name: Python 3 (ipykernel)
  language: python
  name: python3
---


(getting_started)=
# Microcontroller Programming Laboratory: Getting Started

## Introduction

Microcontrollers are an important topic for the Electronics Engineer. So many modern devices have a microcontroller at their core, even apparently &ldquo;dumb&rdquo; products such as toasters and electric fans. Specifying the right microcontroller for a specific task is a useful skill, so in our Electronic and Electrical Engineering degree program you will be exposed to a number of different microcontrollers.

As an introduction to the subject, we shall learn how to program a popular 8-bit microcontroller in the &ldquo;C&rdquo; language. The specific microcontroller we shall be using is the Arduino Nano, a low-cost board with a range of useful features. Before we can program it, however, we shall have to install the Arduino Integrated Development Environment (IDE) onto your computer. If you are using one of the PCs in room B107, the software is already installed. The software is free, so you can install it on your own computer if you wish. The IDE has been produced in several versions, which can be run on Linux, Windows, and Apple computers.

A vast amount of information about the Arduino project can be found on their website, [arduino.cc](https://arduiono.cc), including downloads for the IDE. Many of you already have some experience using Arduino harware and software, and so may have the IDE already installed.

Our friends in the Swansea Hackspace have an extensive web site, which also offers guidance on getting started with Arduino projects. Their website can be found at [swansea.hackspace.org.uk](https://swansea.hackspace.org.uk). If you click on &ldquo;Activities&rdquo; followed by &ldquo;Learning&rdquo; you will be offered a range of tutorials, including one on the Arduino. Click on &ldquo;Introduction to Arduino&rdquo; and you will find a detailed description of the device. You may find it useful to read through some of these pages before starting on the installation procedure detailed below.

## Installing the Arduino IDE 2 on Your Computer

### Windows

Modern Windows 10 and 11 machines are capable of finding the necessary driver for the CH340 interface chip automatically. A good strategy would be to start the Windows 10 machine, and when it is ready plug in the Arduino Nano board using the supplied lead. After a few minutes, type Device Manager into the search box, and run the application offered to you. You should see a list of devices, including &ldquo;Ports (COM and LPT)&rdquo;. Click on this item and look at the lines following. One of these should read &ldquo;USB-SERIAL CH340 (COM5)&rdquo; or similar. Make a note of the COM port number and close the Device Manager.

Next, unplug the Arduino Nano board. Go to [arduino.cc](https://arduino.cc) ({numref}`fig:1`) and select the tab &ldquo;Software&rdquo. This will bring up a new page of options ({numref}`fig:2`). Move past  &ldquo;Arduino Web Editor&rdquo; and look at the section titled &ldquo;Downloads&rdquo; and the box labelled **Arduino IDE 2.1.1**. Look on the right-hand side and click on &ldquo;Windows Installer for Windows 10 and newer&rdquo;, which is the first item in the list. When the installation file has finished downloading return to the previous page using &ldquo;back&rdquo; on your browser. In the section marked &ldquo;Arduino IDE 2.1.1&rdquo; you will see the words &ldquo;For more details, please refer to the Arduino IDE 2.0 documentation.&rdquo; . Click on the link labelled **Arduino IDE 2.0 documentation** to open the **Arduino IDE 2** dicumentation page (highlighted in {numref}`fig:3`) and then select **Downloading and installing the Arduino IDE 2** from the table of contents to open the **Downloading and installing the Arduino IDE 2** page ({numref:fig:4}). 

Follow the detailed instructions for Windows to start the installer. There will follow quite a lengthy installation procedure, during which you will be offered additional drivers for other members of the Arduino family, including the boards offered by the company Adafruit. We recommend installing these additional drivers. When the installation is complete, plug in the Arduino Nano board and click on the &ldquo;Arduino IDE&rdquo; icon that has appeared on your desktop.</p>

```{figure} pictures/arduino_home.png
:name: fig:1
:align:center
:alt: a screenshot of the web page arduino.cc with software selected in the page menu.
:width: 100%

The homepage arduino.cc with software selected
```

```{figure} pictures/arduino_ide_select.png
:name: fig:2
:align:center
:alt: a screenshot of the software page on arduino.cc with downloads highlighted.
:width: 100%

The software page on arduino.cc
```

```{figure} pictures/downloading.png
:name: fig:3
:align:center
:alt: a screenshot of the Arduino IDE 2 page with the link to downloading and installing the Arduiono IDE 2 highlighted.
:width: 100%

The Arduino IDE 2 page
```

```{figure} pictures/install.png
:name: fig:4
:align:center
:alt: a screenshot of the Arduino IDE 2 downloading and installation instructions page.
:width: 100%

The installation instructions page.
```

### Linux

Fortunately, all Linux systems have the necessary drivers in place already, so it is only necessary to install the Arduino IDE application.

Go to [arduino.cc](https://arduino.cc) and select the tab &ldquo;Software&rdquo;. This will bring up the Arduiono IDE 2 page ({numref}`fig:2`). Move past the instructions for &ldquo;Arduino Web Editor&rdquo; and look at the section titled &ldquo;Downloads&rdquo;. In the section marked &ldquo;Arduino IDE 2.1.1&rdquo; you will see the words &ldquo;For more details, please refer to the Arduino IDE 2.0 documentation.&rdquo; . Click on the link labelled **Arduino IDE 2.0 documentation** to open the **Arduino IDE 2** dicumentation page (highlighted in {numref}`fig:3`) and then select **Downloading and installing the Arduino IDE 2** from the table of contents to open the **Downloading and installing the Arduino IDE 2** page ({numref:fig:4}). Follow the detailed instructions for Linux to start the installer. 

There will follow quite a lengthy installation procedure, involving unpacking the tar file, and running the script &ldquo;install.sh&rdquo;, either from the command line or using &ldquo;Run in terminal&rdquo; from &ldquo;Files&rdquo;. During the installation you will be offered additional drivers for other members of the Arduino family, including the boards offered by the company Adafruit. We recommend installing these additional drivers. When the installation is complete, plug in the Arduino Nano board and click on the &ldquo;Arduino IDE&rdquo; icon that has appeared on your desktop.

### Apple (MacOS)

Once again, go to [arduino.cc](https://arduino.cc) and select the tab &ldquo;Software&rdquo;. This will bring up the Arduiono IDE 2 page ({numref}`fig:2`). Move past the instructions for &ldquo;Arduino Web Editor&rdquo; and look at the section titled &ldquo;Downloads&rdquo;. In the section marked &ldquo;Arduino IDE 2.1.1&rdquo; you will see the words &ldquo;For more details, please refer to the Arduino IDE 2.0 documentation.&rdquo; . Click on the link labelled **Arduino IDE 2.0 documentation** to open the **Arduino IDE 2** dicumentation page (highlighted in {numref}`fig:3`) and then select **Downloading and installing the Arduino IDE 2** from the table of contents to open the **Downloading and installing the Arduino IDE 2** page ({numref:fig:4}). Follow the detailed instructions for MacOS to start the installer. 

## Initial set up

When you are satisfied that the Arduino IDE has been successfully installed, run the application. Assuming that the installation procedure described above has gone to plan, and after the splash screen, the Arduino IDE main screen ({numref}`fig:5`) appears. 

::: {figure} pictures/arduino_ide.png
:name: fig:5
:align: center
:width: 100%
:alt: A screen shot of the Arduino IDE 2 as it appears on first start up

The Ardino IDE 2 Main Screen on First Run
:::

Plug in the Arduino Nano board ({numref}`fig:6`) using the supplied lead. Next look at the dropdown control labelled **Select Board*. Identify the connection which depends on your operating system but will be identified as a USB connection on MAcOS and Linux, or may be labelled COM 5 (or some other number) on Windows (see {numref}`fig:7`).

::: {figure} pictures/arduino_nano_breadboard.png
:name: fig:6
:align: center
:width: 100%
:alt: The Arduino nano microntroller mounted on breadboard

The Arduino nano microntroller mounted on breadboard
:::

::: {figure} pictures/choose_port.png
:name: fig:7
:align: center
:width: 100%
:alt: The select port dialogue when setting up the Arduino IDE 2 to use the plugged in Adrduiono nano board. 

Choose the port that your nano board is connected on. What you will see here depends on your operating system. I have shown what I see on my MacOS machine. 
:::

Once you have selected the correct port, you need to identify the board you are using. Search for nano as shown in {numref}`fig:7`

::: {figure} pictures/select_board.png
:name: fig:8
:align: center
:width: 100%
:alt: Shows the slect board dialogue. We have seached for nano and will the the offered selection "Ardunino Nano".

Search for and select Arduino Nano. 
:::

Once you have set up your board, the board idenitfier changes to **Arduino Nano** in the menu bar as shown in {numref}`fig:9`. You are now ready to compile your first program.

::: {figure} pictures/nano_ready.png
:name: fig:9
:align: center
:width: 100%
:alt: A screenshot of the Arduino IDE 2 fater it has been connected to the Arduino nano board. 

Arduino IDE 2 set up and ready to go.
:::

## On the blink

The first program we shall run rejoices in the unlikely name of Blink. Click on `File` and select `Examples` from the drop-down menu. A further menu appears, with all the example programs. Select `01.Basics`, followed by `Blink` ({numref}`fig:10`). 

::: {figure} pictures/select_blink.png
:name: fig:10
:align: center
:width: 100%
:alt: A screenshot the Arduino IDE 2 will Files> Examples> 01.Basiscs> Blink highlighted. 

Select the blink example.
:::

Select `Blink`. The program appears in a new IDE window ({numref}`fig:11`). The program at this stage is just text. It needs to be compiled in order to create an executable file.

::: {figure} pictures/blink_prog.png
:name: fig:11
:align: center
:width: 100%
:alt: A screenshot the Arduino IDE 2 with the example blink program loaded as blinck.ino. 

Blink program (Arduino sketch blink.ino) loaded in the Arduino IDE 2.
:::

Identify the icon for compiling the program, this is a tick in a blue circle which is called Verify on the Arduino IDE. Click this once, and after a short period of time the message &ldquo;Done compiling&rdquo; should appear near the bottom of the window. Hopefully, as we are compiling an example program, there will be no errors! If there are errors, information on the type of error and where it has occurred in the program can be found in the dialogue box near the bottom of the window.

Next, we need to transfer the executable file to the Arduino Nano board. This is done by identifying the icon Upload, which is a right arrow in a blue circle, and clicking it once. Annoyingly, the IDE insists on re-compiling the program. If all has gone to plan, the message &ldquo;Done Uploading&rdquo; appears. Then after a few seconds the executable file starts running on the Nano board. One of the LEDs begins flashing at a regular rate, one second on, one second off.

## Modifying Blink
So far, so good. 

Now, let us try changing the program. Look at the text screen, the &ldquo;source code&rdquo;. You will find two instances of the instruction &ldquo;delay(1000)&rdquo;. 

Move the cursor and change the argument of the two instructions to &ldquo;100&rdquo;. Now, with your new-found knowledge, re-compile the program and upload it to the Nano. 

When the message &ldquo;Done Uploading&rdquo; appears, look at the LED on the Nano. It should be flashing at ten times the previous rate. 

Congratulations! You have successfully edited the program. 

If you like, you can save the edited program by clicking on File, selecting &ldquo;Save As&rdquo; and when the dialogue appears, give the program a new name, for example &ldquo;myblink&rdquo;.

You are now ready to attempt the first laboratory exercise {ref}`lab_1`.