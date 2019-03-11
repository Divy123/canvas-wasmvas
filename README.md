Canvas-Wasmwas
====

## A Brief Insight:
This is a simple wasm practice project which uses `HTML5` canvas element to create an animation consisting of many circles colliding with the edges of the canvas walls/edges.

No CSS has been used except for setting the dimensions of canvas element. Its purely JS, WASM and C.Also I have used Emscripten as the toolset for using various WASM API with an extraordinary easy and that also makes the code more readable and reliable.

## What is Emscripten?

![Alt Text](https://media.giphy.com/media/2WjreYqybFKgXoICJl/giphy.gif)

Emscripten is an Open Source LLVM to JavaScript compiler. Using Emscripten you can:    


 - Compile C and C++ code into JavaScript


 - Compile any other code that can be translated into LLVM bitcode into JavaScript.


 - Compile the C/C++ runtimes of other languages into JavaScript, and then run code in those other languages in an indirect way (this has been done for Python and Lua)!

says Official Emscripten Documentation.

For a fast tutorial: 
**https://medium.com/@labruillere/emscripten-fast-tutorial-a42c701c23e0**

## Project Installation

Clone the repository by :

`git clone https://www.github.com/Divy123/canvas-wasmwas.git`

Install Emscripten (in case you don't already have it) by following the official documentation:

https://emscripten.org/docs/getting_started/downloads.html

Install node packages by doing npm install

And you are all set to go!!

## Quick Usage

Navigate to canvas-wasmwas directory

and run the following command:

`emcc lib/canvas.c -s WASM=1 -s EXPORTED_FUNCTIONS="['_main','_getCircles']" -o public/canvas.js`

and then npm start.

After this is done start up your express server by running npm start,and 
HIT open your localhost:2222

And the magic is there.

A whole lot of 500 circles colliding with walls of our canvas.

In fact, this all can be edited very easily..

![ALT TEXT](https://media.giphy.com/media/vQqeT3AYg8S5O/giphy.gif)

Just navigate to demo.c file inside lib directory and :

* Change the number of circles:  change `#define NUM_CIRCLES 500` to `#define NUM_CIRCLES x` : x being the desired number
* change the y-direction: change  `animationData[i].yd = 0;` to 1 to move circles upward initially instead of downwards and vice-versa
* change the y-direction: change  `animationData[i].xd = 1;` to 0 to move circles backward initially instead of downwards and vice-versa

Thanks for playing around :smile:
