HYPPO-X
=======

This is a hypothesis extraction tool from high dimensional phenomix dataset. This tool is mainly built in `C++`. The object that we generate from our method is a graph and we use `igraph` package of `R` to visually represent the graph. We also use `HTML canvas` to represent the graph more meaningfully using pie chart and colors.

## Contents
- [Filter functions](#filter-functions)
- [Input data format](#input-data-format)
- [Output](#output)
- [Change configuration](#change-configuration)
- [Project setup](#project-setup)
- [How to Build object](#how-to-build-object)


## Filter functions
###### ([Back to content list](#contents))

We implemented the process of generating a `topological object` using both `single filter function` and `double filter function` in `C++`. The source codes are in the `src` folder and the test datasets are in the `data` folder.

### Single filter function
The source codes and datasets available for single filter function are [here](https://github.com/xperthut/HYPPOX/tree/master/Single_filter). Based on our dataset, we can use following attributes as a filter function.

1. DAP
2. Humidity
3. Temperature
4. Solar radiation


### Double filter function
The source codes and datasets available for double filter function are [here](https://github.com/xperthut/HYPPOX/tree/master/Double_filter). We have option to choose any two attributes among the above four attributes. In our experiment, we used `DAP` as the first filter and one of the environmental attributes `(humidity, temperature and solar radiation)` as the second filter.

###### ([Back to content list](#contents))


## Input data format
###### ([Back to content list](#contents))

Our `C++` project reads data from a `csv` formatted data file contained following columns. One can change the column name and the value but can't expand the columns or change the type of the value. For instance, `Time` column accepts integer values like `1,2,...` and does not allow any `text` here.

1. Time, integer type. (i.e. Days After Planting (DAP))
2. Genotype, string/text type
3. Location, string/text type
4. Individual id, see [Individual id](#individual-id)
5. Date, string/text type
6. Phenotypic value, float/real type
7. Environmental attribute 1, float/real type. (i.e. Temperature)
8. Environmental attribute 2, float/real type. (i.e. Solar radiation)
9. Environmental attribute 3, float/real type. (i.e. Humidity)


### Individual id
The default value is an integer. If there have multiple individuals under same `genotype` and `location` combination then one can place it by ` # ` separator, i.e. `1 # 3 # 4`.

###### ([Back to content list](#contents))




## Output
Output is a `gml` formatted file with prefix `graph_COMPOSITE`.

###### ([Back to content list](#contents))


## Change configuration
###### ([Back to content list](#contents))

The file named `config.h`contains the settings. One can change the value of the configuration file to make change in the code and change the output. Necessary configurations are here: 

##### Set the value of first filter using following constant. Our program accepts four values `0-3`.
```cpp
#define FILTER_1 VALUE
```

##### Set the value of second filter using following constant. For `Single filter` the value for this constant is `1`.  For `Double filter function` our program accepts four values `0-3`.
```cpp
#define FILTER_2 VALUE
```

##### Set the link of your source data file. Currently, our program accepts only comma `(,)` separated `csv` formatted data file.
```cpp
// Specify full path of the data file
#define DATA_FILE_NAME "FILENAME.csv"
```

##### Set the number of windows along the filter for `single filter function`. For `double filter function`, set the number of windows along the `first filter`.
```cpp
#define WINDOW_X VALUE
``` 

##### Set the number of windows along the `second filter` for `double filter function`. For `single filter function`, the value of this constant must be `1`.
```cpp
#define WINDOW_Y VALUE
``` 

##### Set the cluster radius. It accepts `real/float` value.
```cpp
#define CLUSTER_RADIUS VALUE
```

##### Set the overlap value. It accepts `real/float` value.
```cpp
#define OVERLAP VALUE
```

##### Enable flag to print simplex timeline statements. Copy these statements to our barcode generated `Barcode.java` file to generate barcode image.
```cpp
#define PRINT_BARCODE true
```

##### Enable flag to print `JSON` data which is used to create `pie chart` and coloring nodes based on different measuring attribute `i.e. time, phenotype, environment`.
```cpp
#define PIE_CHART_CODE true
```

##### Adjust the node size of the generated topological object using following constants.
```cpp
#define NODE_SIZE_MAX MAX_SIZE
#define NODE_SIZE_MIN MIN_SIZE
```

##### Set the following constant when you want to see all the `interesting paths`. For `single filter function`, unset this constant's value.
```cpp
#define PRINT_ALL_PATHS true
```

##### If you want to show and color selected interesting paths then set the following flag. Unset this flag if you want to see all interesting paths with default colors.
```cpp
#define ASSIGN_PATH_COLOR_MANUAL false
```

##### Print the order of sub graphs or connected compoments (CCs) of a topological object by setting the following flag. You will also get the path information of a CC. The format of the order of a CC is `CC:XX`, where `XX` is the order of a CC and it starts from `1`. The format of a path is: `Path_YY_[SCORE,COLOR] : node1#node2,node2#node3,...,node(n-1)#node(n)`. Here, `YY` is the order of a path in a CC. `SCORE` is the interestingness score of that path. `COLOR` is the automatically geneated color from our code. If you enable manual coloring flag (see below) then all the color code will be `#000000`. `node1#node2` means the terminal nodes of an edge along this path.
```cpp
#define PRINT_CC_PATH true
```

##### If you set the flag `ASSIGN_PATH_COLOR_MANUAL` then you must have to set the following two constants with proper values. The values placed in the array are in following format: `{Number of connected components on which the selected paths exist, Order of selected connected component, Number of selected paths, order of a path belongs in a CC}`. For instance, the topological object contructed by double filter function of `DAP and Temperature` (in supplementary document) has four sub graphs or connected compoments (CC). The array content to print specific paths are as: `{2,2,4,1,2,3,4,4,4,1,2,3,4}`. Here, (start from left most element) the first element `2` means that all the paths which we want to color manually belong in `two` out of `four` sub graphs or connected compoments. Next `2` is the order of a CC (see previous flag). Next `4` means the number of paths we want to maually color. Following `1,2,3,4` are the order of paths under `CC 2`. The eighth element `4` indicates the order of next CC. The very next `4` means that we want to color four paths. The last four elements are the order of the paths of `CC 4`. The array format of color is same as the array format of path_list. Here we assign each path order with a color and replace other digits by empty string.
```cpp
#define PATH_LIST {2,2,4,1,2,3,4,4,4,1,2,3,4}
#define PATH_COLOR {"","","","#da2577","#b7a511","#0eafc9","#0000ff","","","#ff0000","#8e44ad","#0ec92d","#fead54"}
```

###### ([Back to content list](#contents))



## Project setup
###### ([Back to content list](#contents))

### Setup for Mac users

1. Create an empty `C++` project in `xcode` and run it.
2. Open the project folder. Copy all the files from `src` named folder to your project's source folder.
3. Copy the data files to `[project folder]/Build/Products/Debug/` folder.
4. Open `config.h` file and adjust all csv file path.

### Setup for Windows users

1. Create an empty `console` project in `Visual studio` and run the project.
2. In `solution explorer`, right click on the `source` and select `add existing item`. Select all `.cpp` extended files of our `src` folder.
3. In `solution explorer`, right click on the `header` and select `add existing item`. Select all `.h` extended files of our `src` folder.
4. In `solution explorer`, right click on the `resource` and select `add existing item`. Select all `.csv` extended files in our `data` folder.
5. Open `config.h` file and adjust all csv file path.

### Setup for Unix system user (Linux, ubontu, etc)

1. Download any free editor, i.e. `eclipse, netbeans`, etc.
2. Setup the project.
3. Open `config.h` file and adjust all csv file path.
4. Run.

### Run from terminal

1. Open the terminal.
2. write `cd [The path of src folder]` and press `ENTER`.
3. Write `make all` command to compile all source files.
4. Write `./main` to run the project.
5. Write `make clean` to clean all object and output files.
6. Each time you `change` to any file, repeat `step 5` and then `step 3`.

###### ([Back to content list](#contents))


## How to Build object
###### ([Back to content list](#contents))

1. Configure `DATA_FILE_NAME`
2. Configure `FILTER_1` and `FILTER_2`
3. Configure `WINDOW_X` and `WINDOW_Y`
4. Configure `CLUSTER_RADIUS`
5. Set barcode flag `PRINT_BARCODE`
6. Run the program to generate simplex timeline code in Java syntex. For instance, the output will be as follows: 
```java
/************ Start from here *************/
stream.addVertex(1, 0.000);
stream.addVertex(2, 0.000);
...
stream.addElement(new int[]{53,54},  45.00);
/************ End here *************/
```
7. Copy this code block and paste it in the `Homology/src/Barcode.java` file at following position:
```java
public void GetStreamForData(ExplicitSimplexStream stream) {
   /*
        Add the simplex code generated from our main project writen in C++
    */
}
```
8. Install any opensource Java editor (e.g. [Netbeans](https://netbeans.org/), [Eclipse](https://eclipse.org/), etc), create an empty project. Add `Homology/src/Barcode.java` file to the source folder of your project and add `Javaplex` jar as an external library. Run your project to generate barcode. The output of this project is barcode image. Open all the barcode images. For each barcode image, identify the overlapping value (along X axis) after which the barcode line persists. Pick the maximum overlapping value among all the identified persistent overlapping value from all barcode images. For instance, for below two barcode images (dimension-0 and dimension-1), we chose `46%` overlapping. We doubled the overlapping value `((2X46)/100=0.92)` and use it for constaint `OVERLAP` in `config.h` file of our `C++` project.
![Barcode Image](https://github.com/xperthut/HYPPOX/blob/master/images/barcode.jpg)

9. Unset barcode flag `PRINT_BARCODE`
10. Run the program to generate the output which is a `gml` formatted file with prefix `graph_COMPOSITE`. Open this `gml` file using R. The command is as below:
```R
library(igraph)
g = read.graph(file.choose(),"gml")
id = tkplot(g, canvas.width = 1455, canvas.height = 777)
```
The file will open as a graph in `XQuartz` terminal where you can change the node position. The tab `view` at top of the `XQuartz` panel has a option to show or hide the labels in the graph. Hide all the labels and save the image. The image will save in `eps` format. After rearranging the graph nodes, run the following codes in R console to generate and save the list of coordinates of the nodes in a `csv` formatted file.
```R
coord = tkplot.getcoords(id)
tk_set_coords(id, coord)
coord = tkplot.getcoords(id)
coord[,2]=coord[,2]+X # Here X can be replaced with any numerical value to adjust the graph's vertical position in XQuartz
coord = tkplot.getcoords(id)

# File name is any csv formated file
# File path is the absolute path of the above file
graph_coordinate_to_html_coordinate(g,coord,[file name],[file path]) 
```
You can save the `coord` variable and use it later to avoid the rearrangement of the graph nodes. Check this out for details [here](https://github.com/xperthut/HYPPOX/tree/master/Graph_plot). In our experiement, the graph and coordinate loading codes are [here](https://github.com/xperthut/HYPPOX/tree/master/Graph_plot/R), the csv files for graph node coordinates are [here](https://github.com/xperthut/HYPPOX/tree/master/Graph_plot/R/data). The suffix of each file name identify the filter function.

11. Open the `csv` file generated using method `graph_coordinate_to_html_coordinate` in earlier step and remove the first blank row and save it. Copy this file to the `C++ project` folder and add its reference in the project editor (xcode or MS Visual studio).

12. Configure this file name with path here:
```cpp
// Specify full path of the data file
#define COORDINATE_FILE_NAME [file name with path]
```
13. Set the flag `PIE_CHART_CODE` to generate JSON code for drawing pie chart and coloring the nodes. Run the program again. The javascript variable (`i.e. var data`) holds the JSON data for pie chart. If there have multiple graphs for a topological object then our code generates JSON data for each graph separately. You have to merge all the JSON data to form a single JSON data before use it in the HTML file. You can merge the JSON data as follows:`
```javascript
// Before merging
var data = [{id:value, p:{}, d:[{}]}];
var data = [{id:value, p:{}, d:[{}]}];

// After merging
var data = [{id:value, p:{}, d:[{}]}, {id:value, p:{}, d:[{}]}];
```
See [README.md](https://github.com/xperthut/HYPPOX/tree/master/Pie_chart) for details construction of a HTML file using this data. You can save the pie chart in a `png` formatted image.

14. When you enable the flag `PIE_CHART_CODE` for `double filter function` then you will get three more JSON variables. Declaration of one of those variables is `var ph`. The declaration of other two variables are `var f1` and `var f2`. Here, `f1` variables holds JSON data for first filter attribute and `f2` variable stores JSON data for sencond filter attribute. As discussed in previous step, you have to merge the data of a variable if it appears in multiple times. These variables are used to color the nodes. See [README.md](https://github.com/xperthut/HYPPOX/tree/master/Pie_chart) for details construction of a HTML file using the data of these variables. The HTML will generate an image, which you can save in `png` format.

###### ([Back to content list](#contents))

