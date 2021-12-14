# CS 225 Fall 2021 Final Project
Contributors: Alam Martinez, Rohan Parekh, Kaushal Dadi

## Overview
Our project looks at the dataset of all pokemon from gen 1 to gen 8 and all their region forms. We got this data set from https://www.kaggle.com/mariotormo/complete-pokemon-dataset-updated-090420, the data format was in a CSV file, which we read and turn into a vector of Pokemon Objects holding numerous pokemon stats. We made these Pokemons into vertices and allows the egdes of these vertices to be pokemons' generation and primary type. Our goal was to see the similarities between generation and pokemons' stats.

Our presentation video: https://youtu.be/s9EcpQwV1tE 

All testing and running of our code can be done within the individual test case files, found under the *tests* folder. The data is under the *data* folder, all **.h** files are under *include*, and all **.cpp** are under *src*. To run the test cases you run **./run.sh**, you can instead run main using **./main** in order to run the main file and run the drawing graph function to display the dataset.
- - - -
## Pokemon 
### Files: Pokemon.h/cpp

The Pokemon file holds a object of pokemon with the stats, name, gen, dexID, type1, type2, height, weight, status, species and, catch rate. We get the these stats from reading the dataset and looking for the dexID,  that the user has given to the Pokemon class constructor. Then we can access all these stats using the class's getters.
- - - -
## Graph
### Files: Graph.h/.cpp vertex.h/.cpp edge.h/.cpp

The Graph is taken care of in 3 files, that take care of the vertices, edges and how to build and travel the graph. Vertex class allows us to hold the ID of the pokemon and info to act as a vertex, the Edge class can store two vertices' ID to create a edge and allows us to creat the graph. The graph class has a number of methods that allows us to create a graph based on how many pokemon the user wants, how to travel the graph and drawing the graph. Along with helper methods that help find the vertices or edges or colors needed
- - - -
## Breadth First Search (BFS)
### Files: Graph.h/.cpp

The BFS algorithm searchs the created graph from a given starting pokemon ID. This algorithm searchs every edge connected to our starting pokemon vertex, making sure not to revisit already visited vertices and adding the new undiscover vertices in a list. This search looks through all vertices and returns a vector of the pokemon names, which are connected to the vertices, in the BFS order. 
- - - -
## Iterative Deepening Depth First Search (IDDFS)
### Files: Graph.h/.cpp

The IDDFS algorithm seraches the created graph from a given starting vertex and searchs for a target vertex. There is maximum range parameter that checks if the target vertex is found in the given number of searches. IDDFS has its own helper function that recursively calls itself until the number of searches left is at 0 or the target node is found. The search always begins at the starting node, even after mutliple nodes have been disovered.

- - - -
## Force Directed Graph
### Files: Graph.h/.cpp

The Force Directed Graph algorithim uses 6 helper functions to correctly determine and draw the locations of the vertices of each pokemon on the graph. The function that creates the Force Directed Graph, drawGraph, utilizes the Image manipulation classes we created in previous mps and labs to draw circle onto a Sticker Sheet. Once the location a Vertice is found we then put it into another function to check whether there is any overlap with o;der Vertices. If so, we randomize and move the Vertice next to that pre-existing Vertice. Next we color the Vertice depending on the type and place each vertice as a sticker onto the StickerSheet. We finally render the complete image and write the resulted image to *MyImage.png*

- - - -
